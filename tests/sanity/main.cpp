#include <ssh/sftpchannel.h>
#include <ssh/sshconnection.h>
#include <ssh/sshremoteprocess.h>

#include <QCoreApplication>
#include <QList>
#include <QObject>
#include <QPair>
#include <QTimer>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	// This test just ensures we can import the library
    return a.exec();
}
