#pragma once
#include <QObject>
/*
	����ģ����
*/
class DataItem
{
protected:
	//����Դ,ȷ��ָ�벻������
	uint8_t* data;
	//����ʱ��
	quint32 timestamp;
public:
	DataItem();
	virtual void DoSomething() = 0;
	virtual ~DataItem() {}
};

