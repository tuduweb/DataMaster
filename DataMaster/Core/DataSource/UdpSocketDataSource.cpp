#include "UdpSocketDataSource.h"
#include "qdebug.h"
#include <QNetworkInterface>

UdpSocketDataSource::UdpSocketDataSource(QString name,QObject *parent)
	: DataSource(name,parent)
{
	//����
	qDebug() << "UdpSocketDS";

	//��ȡ������ַ�б� QList
    QString strIpAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // ��ȡ��һ����������IPv4��ַ..
    for (int i = 0,nListSize = ipAddressesList.size(); i < nListSize; ++i)
    {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address()) {
               if (strIpAddress.isEmpty())
               {
                   strIpAddress = ipAddressesList.at(i).toString();
                   //break;
               }
               //�б��� �����Ӧ���Ǹ�ɶ?
               //localHostAddrComboBox->addItem(strIpAddress);
               //����������Ҫ�ĵ�ϵͳ��־��..
               qDebug()<<"["<<i<<"]"<<ipAddressesList.at(i).toString();

           }
    }

     //���û���ҵ������Ա���IP��ַΪIP
    if (strIpAddress.isEmpty())
    {
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
        //localHostAddrComboBox->addItem(strIpAddress);
    }


}

UdpSocketDataSource::~UdpSocketDataSource()
{
	//��������
}
