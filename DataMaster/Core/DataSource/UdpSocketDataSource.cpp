#include "UdpSocketDataSource.h"
#include "qdebug.h"
#include <QNetworkInterface>

UdpSocketDataSource::UdpSocketDataSource(QString name,QObject *parent)
	: DataSource(name,parent)
{
	//构造
	qDebug() << "UdpSocketDS";

	//获取主机地址列表 QList
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 获取第一个本主机的IPv4地址..
    for (int i = 0,nListSize = ipAddressesList.size(); i < nListSize; ++i)
    {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
               if (strIpAddress.isEmpty())
               {
                   strIpAddress = ipAddressesList.at(i).toString();
                   //break;
               }
               //列表构造 构造的应该是个啥?
               //localHostAddrComboBox->addItem(strIpAddress);
               //把以下内容要改到系统日志中..
               qDebug()<<"["<<i<<"]"<<ipAddressesList.at(i).toString();

           }
    }

     //如果没有找到，则以本地IP地址为IP
    if (strIpAddress.isEmpty())
    {
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
        //localHostAddrComboBox->addItem(strIpAddress);
    }


}

UdpSocketDataSource::~UdpSocketDataSource()
{
	//析构函数
}
