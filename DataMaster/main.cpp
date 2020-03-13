#include <QtCore/QCoreApplication>
#include <qdebug.h>

#include "DataCenter.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	qDebug() << "mytest";

	DataCenter *ins = new DataCenter();

	return a.exec();
}
