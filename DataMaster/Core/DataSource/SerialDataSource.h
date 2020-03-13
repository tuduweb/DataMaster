#pragma once
#include <QObject>
#include "DataSource.h"
#include <QSerialPortInfo>

class SerialDataSource : public DataSource
{
	Q_OBJECT

public:
	SerialDataSource(QString name, QObject* parent);
	~SerialDataSource();
};
