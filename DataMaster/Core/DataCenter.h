#pragma once

#include <QObject>


/*

��������
	����Щģ����Ҫ�������������ţ�
		DataSource
		DataView
		DataBase
		DataStorage

	�����뷨��
		���� - ��ʱϵͳ
		��ʲô����?
			���� ������ʱϵͳ��ʱ�� ������Ҫ������ͣ?

*/

class DataCenter : public QObject
{
	Q_OBJECT

public:
	DataCenter(QObject *parent = nullptr);
	~DataCenter();
};
