#include "DataCenter.h"
#include "DataSource.h"

/*
*����������������������������������������������������������������������������������������������������
*������    ������Ҫ����Զ�����!������Ƭ�Σ�
*������    �ߣ�bin
*������    ����1.0
*��������ʱ�䣺2020-3-13 20:26:27
*����������������������������������������������������������������������������������������������������
*/

/*
	����ƽʱ��mainʵ��
	�߶�������������࣬��Ϊ���������ġ�
*/

/*
* ��C������ ֻ����struct ������c++�� Ӧ����class
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
	�������� ͼƬ����Ҳ��һ������
*/
#include <qvector.h>

#include "UdpSocketDataSource.h"
#include "SerialDataSource.h"
//������Ҫ����ʵ��һ������?��������dataSource
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
