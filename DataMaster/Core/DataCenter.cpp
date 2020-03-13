#include "DataCenter.h"
#include "DataSource.h"

/*
*┌────────────────────────────────────────────────┐
*│　描    述：需要添加自动构建!（代码片段）
*│　作    者：bin
*│　版    本：1.0
*│　创建时间：2020-3-13 20:26:27
*└────────────────────────────────────────────────┘
*/

/*
	就是平时的main实例
	高度耦合面向对象的类，作为“数据中心”
*/

/*
* 在C语言中 只能用struct 而到了c++中 应该是class
*/
extern "C"
{
#define PKG_IMAGE_SIZE 600
	struct dataItem{
		struct pkg_h {
			int h1;
		}pkg;
		uint8_t image[PKG_IMAGE_SIZE];
	};

}

/*
	数据中心 图片数据也是一种数据
*/
#include <qvector.h>

#include "UdpSocketDataSource.h"
#include "SerialDataSource.h"
//这里需要重新实现一个东西?用来管理dataSource
static QVector<DataSource*> ds;

DataCenter::DataCenter(QObject *parent)
	: QObject(parent)
{
	ds.append(new UdpSocketDataSource("udpSocket", this));

	ds.append(new SerialDataSource("Serial", this));
}

DataCenter::~DataCenter()
{
}
