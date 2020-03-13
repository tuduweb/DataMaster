#include "SerialDataSource.h"
#include <qobject.h>
#include <QTextStream>


SerialDataSource::SerialDataSource(QString name, QObject* parent)
	: DataSource(name, parent)
{
    const QString blankString = "N/A";
    QTextStream out(stdout);
    const auto serialPortInfos = QSerialPortInfo::availablePorts();

    out << "Total number of ports available: " << serialPortInfos.count() << endl;

    QString description;
    QString manufacturer;
    QString serialNumber;
    /*
    Port: COM3
    Location: \\.\COM3
    Description: USB-SERIAL CH340
    Manufacturer: wch.cn
    Serial number: N/A
    Vendor Identifier: 1a86
    Product Identifier: 7523
    Busy: No
    */
    for (const QSerialPortInfo& serialPortInfo : serialPortInfos) {
        description = serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber = serialPortInfo.serialNumber();
        out << endl
            << "Port: " << serialPortInfo.portName() << endl
            << "Location: " << serialPortInfo.systemLocation() << endl
            << "Description: " << (!description.isEmpty() ? description : blankString) << endl
            << "Manufacturer: " << (!manufacturer.isEmpty() ? manufacturer : blankString) << endl
            << "Serial number: " << (!serialNumber.isEmpty() ? serialNumber : blankString) << endl
            << "Vendor Identifier: " << (serialPortInfo.hasVendorIdentifier()
                ? QByteArray::number(serialPortInfo.vendorIdentifier(), 16)
                : blankString) << endl
            << "Product Identifier: " << (serialPortInfo.hasProductIdentifier()
                ? QByteArray::number(serialPortInfo.productIdentifier(), 16)
                : blankString) << endl
            << "Busy: " << (serialPortInfo.isBusy() ? "Yes" : "No") << endl;
    }

    //如果要 : 抽象成公用的..Wow
}

SerialDataSource::~SerialDataSource()
{
}
