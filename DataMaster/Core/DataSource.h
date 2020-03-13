#pragma once

#include <QObject>

/*
	DataSource
	数据源
		TCP数据源
		UDP数据源
		SD卡数据源
		文件数据源
		拖动数据源 Drag..
		……
	数据源需要些啥?
		接收数据：（关键）以何种方式去接收数据，就需要具体实现。如TCP的那一系列，那么需要初始化。
		数据源的初始化：比如TCP的建立,UDP的建立,选择串口,选择HubID
		处理数据：以何种方式处理数据?解析方式，那么需要具体实现了，所以还可以分层，解析种类。
		完成处理：完成处理怎么办？也许需要个钩子，回调，或者信号槽。区别：信号槽可以跨线程，钩子，回调是在当前线程。
		数据关联：
			完成处理的数据往哪里送？比如一切都发给DataCenter，让DC来处理，或者在数据源内就处理完毕。
			处理的数据需要标上是从哪里来的，比如什么设备？什么数据源（数据源肯定得绑定设备啊！比如双车，那么可能是两个TCP，端口不一致，所以是两个源）
		绑定关联：数据绑定
			数字型数据，还需要有能给 WaveScopeView（波形） 的接口
			图片型数据，给 ImgProc 的接口，给 ImgList 的接口（ImgList又能与ImgProc关联）
			文字型数据，给 TextArea（consoleArea） 的接口
			关键性数据，给 DataPanel 的接口，DataPanel 应该抽象于 “特例” 比如 车面板
			……
			【松耦合】：
				以上为了解耦，是不是应该把接收到的数据包都存放?然后让他们自己去取，毕竟，原始数据是不能修改的！我认为非轻量级数据都不应该直接传出去
				但是不能无限申请内存，所以要做好数据缓存机制，同时要防止自动把内存清理了（或内存溢出了）
			【效率】：
				考虑为了效率，是否需要缓存，毕竟界面程序，刷新太快就是浪费系统资源了。
		日志：
		数据存储：
			数据库类型
			参数类型

	数据源初始化界面?
		[sourceTable]

		[Mode]

*/

class DataSource : public QObject
{
	Q_OBJECT

public:
	QString dsName;
	//DeviceInfo 每种数据源的DeviceInfo都可能不一样啊…

	DataSource(QString name, QObject* parent = nullptr);
	~DataSource();
};
