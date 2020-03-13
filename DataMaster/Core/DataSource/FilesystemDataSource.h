#pragma once

#include <QObject>
#include <DataSource.h>

class FilesystemDataSource : public DataSource
{
	Q_OBJECT

public:
	FilesystemDataSource(QObject *parent);
	~FilesystemDataSource();
};
