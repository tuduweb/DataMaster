#include "ImageDataItem.h"
#include "qdebug.h"


ImageDataItem::~ImageDataItem()
{
	qDebug() << "must to rep";
}

void ImageDataItem::DoSomething()
{
	static int a = 1;
	a++;
}
