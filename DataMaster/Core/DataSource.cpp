#include "DataSource.h"
#include "qdebug.h"


//������Դ
DataSource::DataSource(QString name,QObject *parent)
	: QObject(parent), dsName(name)
{
	qDebug() << "new data source" << name << ".";
}

DataSource::~DataSource()
{
}
