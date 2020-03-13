#include "DataSource.h"
#include "qdebug.h"


//数据来源
DataSource::DataSource(QString name,QObject *parent)
	: QObject(parent), dsName(name)
{
	qDebug() << "new data source" << name << ".";
}

DataSource::~DataSource()
{
}
