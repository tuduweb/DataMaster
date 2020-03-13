#pragma once
#include <QObject>
/*
	数据模板类
*/
class DataItem
{
protected:
	//数据源,确保指针不被回收
	uint8_t* data;
	//数据时间
	quint32 timestamp;
public:
	DataItem();
	virtual void DoSomething() = 0;
	virtual ~DataItem() {}
};

