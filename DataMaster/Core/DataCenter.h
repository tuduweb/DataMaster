#pragma once

#include <QObject>


/*

数据中心
	有哪些模块需要数据中心来做桥？
		DataSource
		DataView
		DataBase
		DataStorage

	特殊想法：
		链接 - 计时系统
		有什么作用?
			比如 触发计时系统的时候 可能需要数据暂停?

*/

class DataCenter : public QObject
{
	Q_OBJECT

public:
	DataCenter(QObject *parent = nullptr);
	~DataCenter();
};
