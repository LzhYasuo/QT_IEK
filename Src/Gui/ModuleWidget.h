#ifndef _MODULE_WIDGET_H_
#define _MODULE_WIDGET_H_

#include <QWidget>
#include "BaseWidget.h"

enum SmallWindowModel
{
    PRODUCTIONSUM,          //产量汇总
    PLANFORTHEMONTH,        //当月计划
    DEVICEMONITORING,       //设备监控
    MOLDPROGRESS,           //模具进度
    LOADDISTRIBUTION,       //负荷分布
    PASSEDTHEINSPECTION,    //送检合格
    QUALITYMANAGEMENT,      //品质管理
    MATERIALMANAGEMENT,     //物料管理
    VIDEOSURVEILLANCE,      //视频监控
    LARGESCREENMAP,         //大屏地图
    SYSTEMSETUP,            //系统设置
    LoadDistribution
};

class ModuleWidget : public BaseWidget
{
    Q_OBJECT
public:
    ModuleWidget(SmallWindowModel,QWidget* parent = nullptr);
    ~ModuleWidget();

private:
    QWidget* Init(SmallWindowModel);

    QWidget* InitWidget1();
    QWidget* InitWidget2();
    QWidget* InitWidget3();
    QWidget* InitWidget4();
    QWidget* InitWidget5();
    QWidget* InitWidget6();
    QWidget* InitWidget7();
    QWidget* InitWidget8();
    QWidget* InitWidget9();

    QLabel* GetLabel(QString name);
    QWidget* Device_InitRightWidget(QStringList nameList, QStringList valueList);
    QWidget* Device_InitBodyWidget(QStringList colorList,QStringList nameList, QStringList nameList1, QList<bool> boolList);
    QWidget* Device_InitBottomWidget(QStringList list);
    QWidget* GetColorWidget(QString color, QString text, QString text1, bool isActivation);
};


#endif //_MODULE_WIDGET_H_
