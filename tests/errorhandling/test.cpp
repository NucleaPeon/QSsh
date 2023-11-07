#include "test.h"
#include <QDebug>

Test::Test()
{
	m_timeoutTimer.setSingleShot(true);
        m_connection = new SshConnection(SshConnectionParameters());
        if (m_connection->state() != SshConnection::Unconnected) {
            qDebug("Error: Newly created SSH connection has state %d.",
                m_connection->state());
        }

        if (m_connection->createRemoteProcess(""))
            qDebug("Error: Unconnected SSH connection creates remote process.");
        if (m_connection->createSftpChannel())
            qDebug("Error: Unconnected SSH connection creates SFTP channel.");

        SshConnectionParameters noHost;
        noHost.host = QLatin1String("hgdfxgfhgxfhxgfchxgcf");
        noHost.port = 12345;
        noHost.timeout = 10;
        noHost.authenticationType
                = SshConnectionParameters::AuthenticationTypeTryAllPasswordBasedMethods;

        SshConnectionParameters noUser;
        noUser.host = QLatin1String("localhost");
        noUser.port = 22;
        noUser.timeout = 30;
        noUser.authenticationType
                = SshConnectionParameters::AuthenticationTypeTryAllPasswordBasedMethods;
        noUser.userName = QLatin1String("dumdidumpuffpuff");
        noUser.password = QLatin1String("whatever");

        SshConnectionParameters wrongPwd;
        wrongPwd.host = QLatin1String("localhost");
        wrongPwd.port = 22;
        wrongPwd.timeout = 30;
        wrongPwd.authenticationType
                = SshConnectionParameters::AuthenticationTypeTryAllPasswordBasedMethods;
        wrongPwd.userName = QLatin1String("root");
        noUser.password = QLatin1String("thiscantpossiblybeapasswordcanit");

        SshConnectionParameters invalidKeyFile;
        invalidKeyFile.host = QLatin1String("localhost");
        invalidKeyFile.port = 22;
        invalidKeyFile.timeout = 30;
        invalidKeyFile.authenticationType = SshConnectionParameters::AuthenticationTypePublicKey;
        invalidKeyFile.userName = QLatin1String("root");
        invalidKeyFile.privateKeyFile
            = QLatin1String("somefilenamethatwedontexpecttocontainavalidkey");

        // TODO: Create a valid key file and check for authentication error.

        m_testSet << TestItem("Behavior with non-existing host",
            noHost, ErrorList() << SshSocketError);
        m_testSet << TestItem("Behavior with non-existing user", noUser,
            ErrorList() << SshSocketError << SshTimeoutError
                << SshAuthenticationError);
        m_testSet << TestItem("Behavior with wrong password", wrongPwd,
            ErrorList() << SshSocketError << SshTimeoutError
                << SshAuthenticationError);
        m_testSet << TestItem("Behavior with invalid key file", invalidKeyFile,
            ErrorList() << SshSocketError << SshTimeoutError
                << SshKeyFileError);

        runNextTest();
}

Test::~Test()
{
	delete m_connection;
}

void Test::handleConnected()
{
	qDebug("Error: Received unexpected connected() signal.");
    qApp->quit();
}

void Test::handleDisconnected()
{
        qDebug("Error: Received unexpected disconnected() signal.");
        qApp->quit();
}

void Test::handleDataAvailable(const QString &msg)
{
	qDebug("Error: Received unexpected dataAvailable() signal. "
            "Message was: '%s'.", qPrintable(msg));
        qApp->quit();
}

void Test::handleError(QSsh::SshError error)
{
if (m_testSet.isEmpty()) {
            qDebug("Error: Received error %d, but no test was running.", error);
            qApp->quit();
        }

        const TestItem testItem = m_testSet.takeFirst();
        if (testItem.allowedErrors.contains(error)) {
            qDebug("Received error %d, as expected.", error);
            if (m_testSet.isEmpty()) {
                qDebug("All tests finished successfully.");
                qApp->quit();
            } else {
                runNextTest();
            }
        } else {
            qDebug("Received unexpected error %d.", error);
            qApp->quit();
        }
}

void Test::handleTimeout()
{
if (m_testSet.isEmpty()) {
            qDebug("Error: timeout, but no test was running.");
            qApp->quit();
        }
        const TestItem testItem = m_testSet.takeFirst();
        qDebug("Error: The following test timed out: %s", testItem.description);
}

void Test::runNextTest()
{
	if (m_connection) {
        disconnect(m_connection, 0, this, 0);
        delete m_connection;
    }
        m_connection = new SshConnection(m_testSet.first().params);
        connect(m_connection, SIGNAL(connected()), SLOT(handleConnected()));
        connect(m_connection, SIGNAL(disconnected()), SLOT(handleDisconnected()));
        connect(m_connection, SIGNAL(dataAvailable(QString)), SLOT(handleDataAvailable(QString)));
        connect(m_connection, SIGNAL(error(QSsh::SshError)), SLOT(handleError(QSsh::SshError)));
        const TestItem &nextItem = m_testSet.first();
        m_timeoutTimer.stop();
        m_timeoutTimer.setInterval(qMax(10000, nextItem.params.timeout * 1000));
        qDebug("Testing: %s", nextItem.description);
        m_connection->connectToHost();
}


#include "test.moc"
