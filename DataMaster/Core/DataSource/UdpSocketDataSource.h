#pragma once
#include <QObject>
#include "DataSource.h"

class UdpSocketDataSource : public DataSource
{
	Q_OBJECT

public:
	UdpSocketDataSource(QString name, QObject* parent);
	~UdpSocketDataSource();
};
