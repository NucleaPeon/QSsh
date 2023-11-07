#ifndef ERRORHANDLING_TEST_H
#define ERRORHANDLING_TEST_H

#include <QObject>
#include <ssh/sftpchannel.h>
#include <ssh/sshconnection.h>
#include <ssh/sshremoteprocess.h>

#include <QtCore>
#include <QCoreApplication>

#include <QList>
#include <QObject>
#include <QPair>
#include <QTimer>

using namespace QSsh;

typedef QList<SshError> ErrorList;

struct TestItem {
        TestItem(const char *d, const SshConnectionParameters &p,
            const ErrorList &e) : description(d), params(p), allowedErrors(e) {}

        const char *description;
        SshConnectionParameters params;
        ErrorList allowedErrors;
};

class Test : public QObject {
    Q_OBJECT

public:
    Test();
    ~Test();

private slots:
    void handleConnected();
    void handleDisconnected();
    void handleDataAvailable(const QString &msg);
    void handleError(QSsh::SshError error);
    void handleTimeout();

private:
    void runNextTest();
    QList<TestItem> m_testSet;
    QTimer m_timeoutTimer;
    SshConnection *m_connection;


};

#endif // ERRORHANDLING_TEST_H
