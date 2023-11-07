#include <ssh/sftpchannel.h>
#include <ssh/sshconnection.h>
#include <ssh/sshremoteprocess.h>

#include <QCoreApplication>
#include <QList>
#include <QObject>
#include <QPair>
#include <QTimer>

using namespace QSsh;
int main(int argc, char *argv[])
{
	SshConnectionParameters params = SshConnectionParameters();
	//SshConnection conn(params);  // This fails the tests
}
