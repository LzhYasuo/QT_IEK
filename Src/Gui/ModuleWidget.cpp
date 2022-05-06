#include "ModuleWidget.h"
#include <QHBoxLayout>
#include <QLabel>

#include <QTime>
#include "../Pub/PubCss.h"
#include "../Chart/ChartBar.h"
#include "../Chart/ChartLine.h"
#include "../Chart/ChartPie.h"
#include "../Control/ControlRoundProBar.h"
#include "../Model/MoldProTableView.h"
#include "../Model/LoadDistributionTableView.h"
#include "../Model/PartsInventoryTableView.h"
#include "../Task/OpenCVVideo.h"
#include "OpenCVGLWidget.h"

ModuleWidget::ModuleWidget(SmallWindowModel model,QWidget *parent)
    :BaseWidget (parent)
{
    qRegisterMetaType<cv::Mat>("cv::Mat");

    QHBoxLayout* mLayout = InitHLayout();
    QWidget* createWidget = Init(model);
    mLayout->addWidget(createWidget);
    this->setLayout(mLayout);

}

ModuleWidget::~ModuleWidget()
{

}

QWidget *ModuleWidget::Init(SmallWindowModel model)
{
    QWidget* mWidget = new QWidget();
    QHBoxLayout* mLayout = InitHLayout();

    QWidget* createWidget = new QWidget();
    switch (model)
    {
        case PRODUCTIONSUM:
        {
            QWidget* Widget = InitWidget1();
            createWidget = Widget;
            break;
        }
        case PLANFORTHEMONTH:
        {
            QWidget* Widget = InitWidget2();
            createWidget = Widget;
            break;
        }
        case DEVICEMONITORING:
        {
            QWidget* Widget = InitWidget3();
            createWidget = Widget;
            break;
        }
        case MOLDPROGRESS:
        {
            QWidget* Widget = InitWidget4();
            createWidget = Widget;
            break;
        }
        case LOADDISTRIBUTION:
        {
            QWidget* Widget = InitWidget5();
            createWidget = Widget;
            break;
        }
        case PASSEDTHEINSPECTION:
        {
            QWidget* Widget = InitWidget6();
            createWidget = Widget;
            break;
        }
        case QUALITYMANAGEMENT:
        {
            QWidget* Widget = InitWidget7();
            createWidget = Widget;
            break;
        }
        case MATERIALMANAGEMENT:
        {
            QWidget* Widget = InitWidget8();
            createWidget = Widget;
            break;
        }
        case VIDEOSURVEILLANCE:
        {
            QWidget* Widget = InitWidget9();
            createWidget = Widget;
            break;
        }
    }

    mLayout->addWidget(createWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget1()
{
    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout();

    QHBoxLayout* topLayout = InitHLayout(7);

    //-----左上部分
    QWidget* leftTopWidget = new QWidget();
    QVBoxLayout* leftTopLayout = InitVLayout();

    QLabel* lblLeftTop = GetLabel("模具产量");
    QWidget* leftTopChart = new QWidget();
    QHBoxLayout* leftTopChartLayout = InitHLayout();

    ChartBar* bar1 = new ChartBar(6);
    ChartPar cPar1 = bar1->GetPar(CPRODUCTIONSUM1);
    AxisPar aPar1 = bar1->GetPar(APRODUCTIONSUM1);
    QList<BarPer> bPar1 = bar1->GetBPar(BPRODUCTIONSUMVALUE1);
    bar1->Set(cPar1);
    bar1->Set(aPar1);
    bar1->Init(bPar1);
    leftTopChartLayout->addWidget(bar1);
    leftTopChart->setLayout(leftTopChartLayout);

    leftTopLayout->addWidget(lblLeftTop);
    leftTopLayout->addWidget(leftTopChart);
    leftTopWidget->setLayout(leftTopLayout);

    //-----右上部分
    QWidget* rightTopWidget = new QWidget();
    QVBoxLayout* rightTopLayout = InitVLayout();

    QLabel* lblRightTop = GetLabel("每月模具产量趋势图");
    QWidget* rightTopChart = new QWidget();
    QHBoxLayout* rightTopChartLayout = InitHLayout();

    ChartLine* line1 = new ChartLine();
    ChartPar cPar2 = bar1->GetPar(CPRODUCTIONSUM1);
    QList<LinePar> lPar1 = line1->GetLPar(LPRODUCTIONSUMVALUE1);
    AxisPar aPar2 = bar1->GetPar(APRODUCTIONSUM2);
    line1->Set(cPar2);
    line1->Set(aPar2);
    line1->Init(lPar1);
    rightTopChartLayout->addWidget(line1);
    rightTopChart->setLayout(rightTopChartLayout);

    rightTopLayout->addWidget(lblRightTop);
    rightTopLayout->addWidget(rightTopChart);
    rightTopWidget->setLayout(rightTopLayout);

    topLayout->addWidget(leftTopWidget);
    topLayout->addWidget(rightTopWidget);

    QHBoxLayout* bottomLayout = InitHLayout(7);

    //-----左下部分
    QWidget* leftBottomWidget = new QWidget();
    QVBoxLayout* leftBottomLayout = InitVLayout();

    QLabel* lblLeftBottom = GetLabel("模具产量");
    QWidget* leftBottomChart = new QWidget();
    QHBoxLayout* leftBottomChartLayout = InitHLayout();

    ChartBar* bar2 = new ChartBar(6);
    ChartPar cPar3 = bar1->GetPar(CPRODUCTIONSUM3);
    QList<BarPer> bPar2 = bar2->GetBPar(BPRODUCTIONSUMVALUE2);
    AxisPar aPar3 = bar2->GetPar(APRODUCTIONSUM3);
    bar2->Set(cPar3);
    bar2->Set(aPar3);
    bar2->Init(bPar2);
    leftBottomChartLayout->addWidget(bar2);
    leftBottomChart->setLayout(leftBottomChartLayout);

    leftBottomLayout->addWidget(lblLeftBottom);
    leftBottomLayout->addWidget(leftBottomChart);
    leftBottomWidget->setLayout(leftBottomLayout);

    //右下部分
    QWidget* rightBottomWidget = new QWidget();
    QVBoxLayout* rightBottomLayout = InitVLayout();

    QLabel* lblRightBottom = GetLabel("每月模具产量趋势图");
    QWidget* rightBottomChart = new QWidget();
    QHBoxLayout* rightBottomChartLayout = InitHLayout();

    ChartLine* line2 = new ChartLine();
    ChartPar cPar4 = bar1->GetPar(CPRODUCTIONSUM4);
    QList<LinePar> lPar2 = line2->GetLPar(LPRODUCTIONSUMVALUE2);
    AxisPar aPar4 = line2->GetPar(APRODUCTIONSUM4);
    line2->Set(cPar4);
    line2->Set(aPar4);
    line2->Init(lPar2);
    rightBottomChartLayout->addWidget(line2);
    rightBottomChart->setLayout(rightBottomChartLayout);

    rightBottomLayout->addWidget(lblRightBottom);
    rightBottomLayout->addWidget(rightBottomChart);
    rightBottomWidget->setLayout(rightBottomLayout);

    //总布局
    bottomLayout->addWidget(leftBottomWidget);
    bottomLayout->addWidget(rightBottomWidget);

    mLayout->addLayout(topLayout);
    mLayout->addLayout(bottomLayout);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget2()
{
    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout();

    QHBoxLayout* topLayout = InitHLayout();

    //左上
    QWidget* leftTopWidget = new QWidget();
    QVBoxLayout* leftTopLayout = InitVLayout();

    QLabel* lblLeftTop = GetLabel("");
    QWidget* leftTopChartWidget = new QWidget();
    QHBoxLayout* leftTopChartLayout = InitHLayout();
    ContorlRoundProBar* bar = new ContorlRoundProBar();
    bar->setFixedSize(150,150);
    leftTopChartLayout->addWidget(bar);
    leftTopChartWidget->setLayout(leftTopChartLayout);

    leftTopLayout->addWidget(lblLeftTop);
    leftTopLayout->addWidget(leftTopChartWidget);
    leftTopWidget->setLayout(leftTopLayout);


    //中上
    QWidget* midTopWidget = new QWidget();
    QVBoxLayout* midTopLayout = InitVLayout();

    QLabel* lblMidTop = GetLabel("");
    QWidget* midTopChartWidget = new QWidget();
    QHBoxLayout* midTopChartLayout = InitHLayout();
    ChartBar* bar1 = new ChartBar(3);
    ChartPar cPar1 = bar1->GetPar(CPLANFORTHEMONTH1);
    QList<BarPer> bPar1 = bar1->GetBPar(BPLANFORTHEMONTHVALUE1);
    AxisPar aPar1 = bar1->GetPar(APLANFORTHEMONTH1);
    bar1->Set(cPar1);
    bar1->Set(aPar1);
    bar1->Init(bPar1);
    midTopChartLayout->addWidget(bar1);
    midTopChartWidget->setLayout(midTopChartLayout);
    midTopLayout->addWidget(lblMidTop);
    midTopLayout->addWidget(midTopChartWidget);
    midTopWidget->setLayout(midTopLayout);

    //右上
    QWidget* rightTopWidget = new QWidget();
    QVBoxLayout* rightTopLayout = InitVLayout();

    QLabel* lblRightTop = GetLabel("");
    QWidget* RightTopChartWidget = new QWidget();
    QHBoxLayout* RightTopChartLayout = InitHLayout();
    ContorlRoundProBar* bar2 = new ContorlRoundProBar();
    bar2->setFixedSize(150,150);
    RightTopChartLayout->addWidget(bar2);
    RightTopChartWidget->setLayout(RightTopChartLayout);
    rightTopLayout->addWidget(lblRightTop);
    rightTopLayout->addWidget(RightTopChartWidget);
    rightTopWidget->setLayout(rightTopLayout);

    topLayout->addWidget(leftTopWidget);
    topLayout->addWidget(midTopWidget);
    topLayout->addWidget(rightTopWidget);

    //下面
    QWidget* bottomWidget = new QWidget();
    QVBoxLayout* bottomLayout = InitVLayout();

    QLabel* lblBottom = GetLabel("");
    QWidget* bottomChartWidget = new QWidget();
    QHBoxLayout* bottomChartLayout = InitHLayout();

    ChartBar* bar3 = new ChartBar(2);
    ChartPar cPar2 = bar3->GetPar(CPLANFORTHEMONTH2);
    QList<BarPer> bPar2 = bar3->GetBPar(BPLANFORTHEMONTHVALUE2);
    AxisPar aPar2 = bar3->GetPar(APLANFORTHEMONTH2);
    bar3->Set(cPar2);
    bar3->Set(aPar2);
    bar3->Init(bPar2);
    bottomChartLayout->addWidget(bar3);
    bottomChartWidget->setLayout(bottomChartLayout);
    bottomLayout->addWidget(lblBottom);
    bottomLayout->addWidget(bottomChartWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addLayout(topLayout);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget3()
{
    const QString cyanColor = "0,176,180";
    const QString redColor = "214,77,84";
    const QString yellowColor = "255,192,0";
    const QString greyColor = "210,210,210";
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);
    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout();

    //上半段
    QWidget* topWidget = new QWidget();
    QHBoxLayout* topLayout = InitHLayout(7);

    const QStringList topColorList = QStringList()  << cyanColor << greyColor << redColor << cyanColor
                                                    << cyanColor << yellowColor << yellowColor << greyColor;
    const QStringList topNameList = QStringList()   << "TID11" << ""      << "TID13" << "TID14"
                                                    << "TID15" << "TID16" << "TID17" << "";
    const QStringList topNameList1 = QStringList()  << "PID11"  << ""      << "PID13" << "PID14"
                                                    << "PID15" << "PID16" << "PID17" << "";
    const QStringList topBottomList = QStringList() << "CNC1"  << ""      << "CNC3"  << "CNC4"
                                                    << "CNC5"  << "CNC6"  << "CNC7"  << "";
    const QList<bool> topBoolList = QList<bool>()   << 0 << 1 << 0 << 0 << 0 << 0 << 0 << 1;
    const QStringList topRightNList = QStringList() << "稼动率" << "开机数量" << "待机数量" << "维护数量";
    const QStringList topRightVList = QStringList() << "85%"   << "3"  << "2" << "1";

    QWidget* topLeftWidget = new QWidget();
    QVBoxLayout* topLeftLayout = InitVLayout();
    QLabel* lblTopLeftTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* topLeftBodyWidget = Device_InitBodyWidget(topColorList,topNameList,topNameList1,topBoolList);
    QWidget* topLeftBottomWidget = Device_InitBottomWidget(topBottomList);
    topLeftBottomWidget->setFixedHeight(25);
    topLeftLayout->addWidget(lblTopLeftTitle);
    topLeftLayout->addWidget(topLeftBodyWidget);
    topLeftLayout->addWidget(topLeftBottomWidget);
    topLeftWidget->setLayout(topLeftLayout);

    QWidget* topRightWidget = new QWidget();
    topRightWidget->setFixedWidth(110);
    QVBoxLayout* topRightLayout = InitVLayout();
    QLabel* lblTopRightTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* topRightBodyWidget = Device_InitRightWidget(topRightNList,topRightVList);
    topRightLayout->addWidget(lblTopRightTitle);
    topRightLayout->addWidget(topRightBodyWidget);
    topRightWidget->setLayout(topRightLayout);

    topLayout->addWidget(topLeftWidget);
    topLayout->addWidget(topRightWidget);
    topWidget->setLayout(topLayout);

    //中间段
    QWidget* bodyWidget = new QWidget();
    QHBoxLayout* bodyLayout = InitHLayout(7);

    const QStringList bodyColorList = QStringList()  << greyColor << greyColor << cyanColor << greyColor
                                                     << redColor  << cyanColor << cyanColor << greyColor;
    const QStringList bodyNameList = QStringList()   << ""     << ""      << "TID23" << ""
                                                     << "TID25" << "TID26" << "TID27" << "";
    const QStringList bodyNameList1 = QStringList()  <<""      << ""      << "PID23" << ""
                                                     << "PID25" << "PID26" << "PID27" << "";
    const QStringList bodyBottomList = QStringList() << ""      << ""      << "EDM3"  << ""
                                                     << "EDM5"  << "EDM6"  << "EDM7"  << "";
    const QList<bool> bodyBoolList = QList<bool>()   << 1 << 1 << 0 << 1 << 0 << 0 << 0 << 1;
    const QStringList bodyRightNList = QStringList() << "稼动率" << "开机数量" << "待机数量" << "维护数量";
    const QStringList bodyRightVList = QStringList() << "90%"   << "3"  << "0" << "1";
    QWidget* bodyLeftWidget = new QWidget();
    QVBoxLayout* bodyLeftLayout = InitVLayout();
    QLabel* bodyTopLeftTitle = InitLabel("EDM",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* bodyLeftBodyWidget = Device_InitBodyWidget(bodyColorList,bodyNameList,bodyNameList1,bodyBoolList);
    QWidget* bodyLeftBottomWidget = Device_InitBottomWidget(bodyBottomList);
    bodyLeftBottomWidget->setFixedHeight(25);
    bodyLeftLayout->addWidget(bodyTopLeftTitle);
    bodyLeftLayout->addWidget(bodyLeftBodyWidget);
    bodyLeftLayout->addWidget(bodyLeftBottomWidget);
    bodyLeftWidget->setLayout(bodyLeftLayout);

    QWidget* bodyRightWidget = new QWidget();
    bodyRightWidget->setFixedWidth(110);
    QVBoxLayout* bodyRightLayout = InitVLayout();
    QLabel* lblBodyRightTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* bodyRightBodyWidget = Device_InitRightWidget(bodyRightNList,bodyRightVList);
    bodyRightLayout->addWidget(lblBodyRightTitle);
    bodyRightLayout->addWidget(bodyRightBodyWidget);
    bodyRightWidget->setLayout(bodyRightLayout);

    bodyLayout->addWidget(bodyLeftWidget);
    bodyLayout->addWidget(bodyRightWidget);
    bodyWidget->setLayout(bodyLayout);

    //底部
    QWidget* bottomWidget = new QWidget();
    QHBoxLayout* bottomLayout = InitHLayout(7);

    const QStringList bottomColorList = QStringList()  << yellowColor << yellowColor << yellowColor << greyColor
                                                       << cyanColor   << redColor    << cyanColor   << yellowColor;
    const QStringList bottomNameList = QStringList()   << "TID31" << "TID32" << "TID33" << ""
                                                       << "TID35" << "TID36" << "TID37" << "TID38";
    const QStringList bottomNameList1 = QStringList()  << "PID31" << "PID32" << "PID33" << ""
                                                       << "PID35" << "PID36" << "PID37" << "PID38";
    const QStringList bottomBottomList = QStringList() << "WEDM1" << "WEDM2" << "WEDM3" << ""
                                                       << "WEDM5" << "WEDM6" << "WEDM7" << "WEDM8";
    const QList<bool> bottomBoolList = QList<bool>()   << 1 << 1 << 0 << 1 << 0 << 0 << 0 << 1;
    const QStringList bottomRightNList = QStringList() << "稼动率" << "开机数量" << "待机数量" << "维护数量";
    const QStringList bottomRightVList = QStringList() << "95%"   << "2"  << "4" << "1";
    QWidget* bottomLeftWidget = new QWidget();
    QVBoxLayout* bottomLeftLayout = InitVLayout();
    QLabel* bottomTopLeftTitle = InitLabel("EDM",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* bottomLeftBodyWidget = Device_InitBodyWidget(bottomColorList,bottomNameList,bottomNameList1,bottomBoolList);
    QWidget* bottomLeftBottomWidget = Device_InitBottomWidget(bottomBottomList);
    bottomLeftBottomWidget->setFixedHeight(25);
    bottomLeftLayout->addWidget(bottomTopLeftTitle);
    bottomLeftLayout->addWidget(bottomLeftBodyWidget);
    bottomLeftLayout->addWidget(bottomLeftBottomWidget);
    bottomLeftWidget->setLayout(bottomLeftLayout);

    QWidget* bottomRightWidget = new QWidget();
    bottomRightWidget->setFixedWidth(110);
    QVBoxLayout* bottomRightLayout = InitVLayout();
    QLabel* lblBottomRightTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* bottomRightBodyWidget = Device_InitRightWidget(bottomRightNList,bottomRightVList);
    bottomRightLayout->addWidget(lblBottomRightTitle);
    bottomRightLayout->addWidget(bottomRightBodyWidget);
    bottomRightWidget->setLayout(bottomRightLayout);

    bottomLayout->addWidget(bottomLeftWidget);
    bottomLayout->addWidget(bottomRightWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addWidget(topWidget);
    mLayout->addWidget(bodyWidget);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget4()
{
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);

    QWidget* mWidget = new QWidget();
    QHBoxLayout* mLayout = InitHLayout();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
    QList<QStringList> list;
    QList<QVariantList> list1;
    for(int i = 0; i < 21; i++)
    {
        QStringList msg;
        msg.push_back(QString::number(i + 1));
        msg.push_back("FK" + QString::number(i + 1));
        msg.push_back("V" + QString::number(i + 1));
        msg.push_back("修膜");
        msg.push_back("加工中");
        msg.push_back("面板");
        msg.push_back("2020-01-01");
        QVariantList valueList;
        int j = qrand()%(20);
        int k = qrand()%(20);
        int l = qrand()%(20);
        valueList << j << k << l;
        list.push_back(msg);
        list1.push_back(valueList);
    }

    QWidget* leftWidget = new QWidget();
    QVBoxLayout* leftLayout = InitVLayout();
    QLabel* lbLeftlTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    MoldProTableView* view = new MoldProTableView();
    view->Set_Model_Data(list,list1);
    leftLayout->addWidget(lbLeftlTitle);
    leftLayout->addWidget(view);
    leftWidget->setLayout(leftLayout);

    //右边 上面
    QWidget* rightWdget = new QWidget();
    rightWdget->setFixedWidth(300);
    QVBoxLayout* rightLayout = InitVLayout();

    QWidget* rightTopWidget = new QWidget();
    rightTopWidget->setFixedHeight(300);
    QVBoxLayout* rightTopLayout = InitVLayout();
    QLabel* lblRightTopTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* rightTopChartWidget = new QWidget();
    QHBoxLayout* rightTopChartLayout = InitHLayout();
    ChartPie* pie = new ChartPie();
    ChartPar cPar = pie->GetPar(CLOADDISTRIBUTION1);
    QList<QColor> colorList = QList<QColor>() << QColor(65,176,254) << QColor(0,175,80) << QColor(255,192,0);
    QStringList nameList = QStringList() << "加工中" << "正常支付" << "延期";
    QList<int> valueList = QList<int>() << 45 << 27 << 27;
    pie->Set(cPar);
    pie->Init(colorList,nameList,valueList,99);
    rightTopChartLayout->addWidget(pie);
    rightTopChartWidget->setLayout(rightTopChartLayout);
    rightTopLayout->addWidget(lblRightTopTitle);
    rightTopLayout->addWidget(rightTopChartWidget);
    rightTopWidget->setLayout(rightTopLayout);

    //右边 下面
    QWidget* rightBottomWidget = new QWidget();
    QVBoxLayout* rightBottomLayout = InitVLayout();

    QLabel* lblRightBottomTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* RightBottomChartWidget = new QWidget();
//            RightBottomChartWidget->setStyleSheet("background-color:rgb(48,48,85);");
    QHBoxLayout* RightBottomChartLayout = new QHBoxLayout();
    ContorlRoundProBar* bar = new ContorlRoundProBar();
    bar->setStyleSheet("background-color:rgb(48,42,76);");
    RightBottomChartLayout->addWidget(bar);
    RightBottomChartWidget->setLayout(RightBottomChartLayout);
    rightBottomLayout->addWidget(lblRightBottomTitle);
    rightBottomLayout->addWidget(RightBottomChartWidget);
    rightBottomWidget->setLayout(rightBottomLayout);

    rightLayout->addWidget(rightTopWidget);
    rightLayout->addWidget(rightBottomWidget);
    rightWdget->setLayout(rightLayout);

    mLayout->addWidget(leftWidget);
    mLayout->addWidget(rightWdget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget5()
{
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);

    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout(7);

    //上面
    QWidget* TopWidget = new QWidget();
    QVBoxLayout* TopLayout = InitVLayout();

    QLabel* lblTopTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* TopViewWidget = new QWidget();
    QVBoxLayout* TopViewLayout = InitVLayout();
    LoadDistributionTableView* view = new LoadDistributionTableView();
    QList<QStringList> valueList;
    for(int i = 0; i < 9; i++)
    {
        QStringList list;
        list << "CNC粗" << "50H" << "123H" << "50H" << "100H" << "80H" << "100H" << "138H";
        valueList.push_back(list);
    }
    view->Set_Model_Data(valueList);
    TopViewLayout->addWidget(view);
    TopViewWidget->setLayout(TopViewLayout);

    TopLayout->addWidget(lblTopTitle);
    TopLayout->addWidget(TopViewWidget);
    TopWidget->setLayout(TopLayout);

    //下面
    QWidget* bottomWidget = new QWidget();
    QHBoxLayout* bottomLayout = InitHLayout(7);

    QWidget* LeftBottomWidget = new QWidget();
    QVBoxLayout* LeftBottomLayout = InitVLayout();

    QLabel* lblLeftBottomTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* leftBottomChartWidget = new QWidget();
    QHBoxLayout* leftBottomChartLayout = InitHLayout();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
    ChartBar* bar1 = new ChartBar(2);
    ChartPar cPar1 = bar1->GetPar(CLOADDISTRIBUTION1);
    QList<BarPer> bPar1 = bar1->GetBPar(BLOADDISTRIBUTIONVALUE1);
    AxisPar aPar1 = bar1->GetPar(ALOADDISTRIBUTION1);
    bar1->Set(cPar1);
    bar1->Set(aPar1);
    bar1->Init(bPar1);
    leftBottomChartLayout->addWidget(bar1);
    leftBottomChartWidget->setLayout(leftBottomChartLayout);
    LeftBottomLayout->addWidget(lblLeftBottomTitle);
    LeftBottomLayout->addWidget(leftBottomChartWidget);
    LeftBottomWidget->setLayout(LeftBottomLayout);

    //右下
    QWidget* rightBottomWidget = new QWidget();
    QVBoxLayout* rightBottomLayout = InitVLayout();

    QLabel* lblrightBottomTitle = InitLabel("CNC",0,30,ModuleWidget::POSLEFT,titleStyle);
    QWidget* rightBottomChart = new QWidget();
    QHBoxLayout* rightBottomChartLayout = InitHLayout();

    ChartLine* line1 = new ChartLine();
    ChartPar cPar2 = bar1->GetPar(CLOADDISTRIBUTION2);
    QList<LinePar> lPar1 = line1->GetLPar(LLOADDISTRIBUTIONVALUE1);
    AxisPar aPar2 = line1->GetPar(ALOADDISTRIBUTION2);
    line1->Set(cPar2);
    line1->Set(aPar2);
    line1->Init(lPar1);
    rightBottomChartLayout->addWidget(line1);
    rightBottomChart->setLayout(rightBottomChartLayout);

    rightBottomLayout->addWidget(lblrightBottomTitle);
    rightBottomLayout->addWidget(rightBottomChart);
    rightBottomWidget->setLayout(rightBottomLayout);

    bottomLayout->addWidget(LeftBottomWidget);
    bottomLayout->addWidget(rightBottomWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addWidget(TopWidget);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget6()
{
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);
    QWidget* mWidget = new QWidget();

    QVBoxLayout* mLayout = InitVLayout();

    //上
    QWidget* topWidget = new QWidget();
    QHBoxLayout* topLayout = InitHLayout();

    //左上
    QWidget* leftTopWidget = new QWidget();
    QVBoxLayout* leftTopLayout = InitVLayout();
    QLabel* lblLeftTopTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //左上图表
    QWidget* leftTopChartWidget = new QWidget();
    QHBoxLayout* leftTopChartLayout = InitHLayout();
    ChartLine* line1 = new ChartLine();
    ChartPar cPar1 = line1->GetPar(CPASSEDTHEINSPECTION1);
    AxisPar aPar1 = line1->GetPar(APASSEDTHEINSPECTION1);
    QList<LinePar> lPar1 = line1->GetLPar(LPASSEDTHEINSPECTIONVALUE1);
    line1->Set(cPar1);
    line1->Set(aPar1);
    line1->Init(lPar1);
    leftTopChartLayout->addWidget(line1);
    leftTopChartWidget->setLayout(leftTopChartLayout);

    leftTopLayout->addWidget(lblLeftTopTitle);
    leftTopLayout->addWidget(leftTopChartWidget);
    leftTopWidget->setLayout(leftTopLayout);

    //右上
    QWidget* rightTopWidget = new QWidget();
    QVBoxLayout* rightTopLayout = InitVLayout();
    QLabel* lblRightTopTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //右上图表
    QWidget* rightTopChartWidget = new QWidget();
    QHBoxLayout* rightTopChartLayout = InitHLayout();
    ChartLine* line2 = new ChartLine();
    ChartPar cPar2 = line2->GetPar(CPASSEDTHEINSPECTION2);
    AxisPar aPar2 = line2->GetPar(APASSEDTHEINSPECTION2);
    QList<LinePar> lPar2 = line2->GetLPar(LPASSEDTHEINSPECTIONVALUE2);
    line2->Set(cPar2);
    line2->Set(aPar2);
    line2->Init(lPar2);
    rightTopChartLayout->addWidget(line2);
    rightTopChartWidget->setLayout(rightTopChartLayout);

    rightTopLayout->addWidget(lblRightTopTitle);
    rightTopLayout->addWidget(rightTopChartWidget);
    rightTopWidget->setLayout(rightTopLayout);

    topLayout->addWidget(leftTopWidget);
    topLayout->addWidget(rightTopWidget);
    topWidget->setLayout(topLayout);

    //下
    QWidget* bottomWidget = new QWidget();
    QHBoxLayout* bottomLayout = InitHLayout();

    //左下
    QWidget* leftBottomWidget = new QWidget();
    QVBoxLayout* leftBottomLayout = InitVLayout();
    QLabel* lblLeftBottomTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //左下图表
    QWidget* leftBottomChartWidget = new QWidget();
    QHBoxLayout* leftBottomChartLayout = InitHLayout();
    ContorlRoundProBar* bar1 = new ContorlRoundProBar();
    bar1->setStyleSheet("background-color:rgb(45,45,85);");
    bar1->setFixedWidth(300);
    leftBottomChartLayout->addWidget(bar1);
    leftBottomChartWidget->setLayout(leftBottomChartLayout);
    leftBottomLayout->addWidget(lblLeftBottomTitle);
    leftBottomLayout->addWidget(leftBottomChartWidget);
    leftBottomWidget->setLayout(leftBottomLayout);

    //右下
    QWidget* rightBottomWidget = new QWidget();
    QVBoxLayout* rightBottomLayout = InitVLayout();
    QLabel* lblRightBottomTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //右下图表
    QWidget* rightBottomChartWidget = new QWidget();
    QHBoxLayout* rightBottomChartLayout = InitHLayout();
    ChartBar* bar2 = new ChartBar(1);
    ChartPar cPar3 = bar2->GetPar(CPASSEDTHEINSPECTION3);
    AxisPar aPar3 = bar2->GetPar(APASSEDTHEINSPECTION3);
    QList<BarPer> bPar3 = bar2->GetBPar(BPASSEDTHEINSPECTIONVALUE1);
    bar2->Set(cPar3);
    bar2->Set(aPar3);
    bar2->Init(bPar3);
    rightBottomChartLayout->addWidget(bar2);
    rightBottomChartWidget->setLayout(rightBottomChartLayout);

    rightBottomLayout->addWidget(lblRightBottomTitle);
    rightBottomLayout->addWidget(rightBottomChartWidget);
    rightBottomWidget->setLayout(rightBottomLayout);

    bottomLayout->addWidget(leftBottomWidget);
    bottomLayout->addWidget(rightBottomWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addWidget(topWidget);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget7()
{
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);
    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout();

    //上
    QWidget* topWidget = new QWidget();
    QHBoxLayout* topLayout = InitHLayout();

    //左上
    QWidget* leftTopWidget = new QWidget();
    QVBoxLayout* leftTopLayout = InitVLayout();
    QLabel* lblLeftTopTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //左上图表
    QWidget* leftTopChartWidget = new QWidget();
    QVBoxLayout* leftTopChartLayout = InitVLayout();
    ChartPie* pie1 = new ChartPie();
    QList<QColor> colorList = QList<QColor>() << QColor(65,176,254) << QColor(0,175,80) << QColor(255,192,0) << QColor(254,0,0);
    QStringList nameList = QStringList() << "" << "" << "" << "";
    QList<int> valueList = QList<int>() << 35 << 14 << 36 << 14;
    ChartPar cPar1 = pie1->GetPar(CQUALITYMANAGEMENT1);
    pie1->Init(colorList,nameList,valueList,99);
    leftTopChartLayout->addWidget(pie1);
    leftTopChartWidget->setLayout(leftTopChartLayout);

    leftTopLayout->addWidget(lblLeftTopTitle);
    leftTopLayout->addWidget(leftTopChartWidget);
    leftTopWidget->setLayout(leftTopLayout);

    //右上
    QWidget* rightTopWidget = new QWidget();
    QVBoxLayout* rightTopLayout = InitVLayout();
    QLabel* lblRightTopTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //右上图表
    QWidget* rightTopChartWidget = new QWidget();
    QVBoxLayout* rightTopChartLayout = InitVLayout();
    ChartBar* bar2 = new ChartBar(1);
    ChartPar cPar2 = bar2->GetPar(CQUALITYMANAGEMENT2);
    AxisPar aPar2 = bar2->GetPar(AQUALITYMANAGEMENT2);
    QList<BarPer> bPar2 = bar2->GetBPar(BQUALITYMANAGEMENTVALUE1);
    bar2->Set(cPar2);
    bar2->Set(aPar2);
    bar2->SetMax(79);
    bar2->SetMaxColor(QColor(255,192,0));
    bar2->Init(bPar2);
    rightTopChartLayout->addWidget(bar2);
    rightTopChartWidget->setLayout(rightTopChartLayout);

    rightTopLayout->addWidget(lblRightTopTitle);
    rightTopLayout->addWidget(rightTopChartWidget);
    rightTopWidget->setLayout(rightTopLayout);

    topLayout->addWidget(leftTopWidget);
    topLayout->addWidget(rightTopWidget);
    topWidget->setLayout(topLayout);

    //下
    QWidget* bottomWidget = new QWidget();
    QVBoxLayout* bottomLayout = InitVLayout();
    QLabel* lblBottomTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    //下图表
    QWidget* bottomChartWidget = new QWidget();
    QHBoxLayout* bottomChartLayout = InitHLayout();
    ChartLine* line3 = new ChartLine();
    ChartPar cPar3 = line3->GetPar(CQUALITYMANAGEMENT3);
    AxisPar aPar3 = line3->GetPar(AQUALITYMANAGEMENT3);
    QList<LinePar> lPar3 = line3->GetLPar(LQUALITYMANAGEMENTVALUE1);
    line3->Set(cPar3);
    line3->Set(aPar3);
    line3->Init(lPar3);
    bottomChartLayout->addWidget(line3);
    bottomChartWidget->setLayout(bottomChartLayout);

    bottomLayout->addWidget(lblBottomTitle);
    bottomLayout->addWidget(bottomChartWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addWidget(topWidget);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget8()
{
    const QString titleStyle = PubCss::Get()->GetStr(DEVICEMONITORING_BOTTOMLABEL);
    QWidget* mWidget = new QWidget();
    QVBoxLayout* mLayout = InitVLayout();

    QWidget* topWidget = new QWidget();
    QHBoxLayout* topLayout = InitHLayout(7);

    //上 左
    QWidget* leftTopWidget = new QWidget();
    QVBoxLayout* leftTopLayout = InitVLayout();
    QLabel* lblLeftTopTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* leftTopChartWidget = new QWidget();
    QVBoxLayout* leftTopChartLayout = InitVLayout();
    ContorlRoundProBar* bar1 = new ContorlRoundProBar();
    bar1->setFixedHeight(200);
    bar1->setStyleSheet("background-color:rgb(45,45,85);");
    leftTopChartLayout->addWidget(bar1);

    leftTopChartWidget->setLayout(leftTopChartLayout);
    leftTopLayout->addWidget(lblLeftTopTitle);
    leftTopLayout->addWidget(leftTopChartWidget);
    leftTopWidget->setLayout(leftTopLayout);

    //上 中
    QWidget* midTopWidget1 = new QWidget();
    QVBoxLayout* midTopLayout1 = InitVLayout();
    QLabel* lblMidTopTitle1 = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* midTopChartWidget1 = new QWidget();
    QVBoxLayout* midTopChartLayout1 = InitVLayout();
    ContorlRoundProBar* bar2 = new ContorlRoundProBar();
    midTopChartLayout1->addWidget(bar2);

    midTopChartWidget1->setLayout(midTopChartLayout1);
    midTopLayout1->addWidget(lblMidTopTitle1);
    midTopLayout1->addWidget(midTopChartWidget1);
    midTopWidget1->setLayout(midTopLayout1);

    //上 中
    QWidget* midTopWidget2 = new QWidget();
    QVBoxLayout* midTopLayout2 = InitVLayout();
    QLabel* lblMidTopTitle2 = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* midTopChartWidget2 = new QWidget();
    QVBoxLayout* midTopChartLayout2 = InitVLayout();
    ContorlRoundProBar* bar3 = new ContorlRoundProBar();
    midTopChartLayout2->addWidget(bar3);

    midTopChartWidget2->setLayout(midTopChartLayout2);
    midTopLayout2->addWidget(lblMidTopTitle2);
    midTopLayout2->addWidget(midTopChartWidget2);
    midTopWidget2->setLayout(midTopLayout2);

    //上 右
    QWidget* rightTopWidget = new QWidget();
    QVBoxLayout* rightTopLayout = InitVLayout();
    QLabel* lblRightTopTitle1 = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* rightTopChartWidget = new QWidget();
    QVBoxLayout* rightTopChartLayout = InitVLayout();
    ContorlRoundProBar* bar4 = new ContorlRoundProBar();
    rightTopChartLayout->addWidget(bar4);

    rightTopChartWidget->setLayout(rightTopChartLayout);
    rightTopLayout->addWidget(lblRightTopTitle1);
    rightTopLayout->addWidget(rightTopChartWidget);
    rightTopWidget->setLayout(rightTopLayout);

    topLayout->addWidget(leftTopWidget);
    topLayout->addWidget(midTopWidget1);
    topLayout->addWidget(midTopWidget2);
    topLayout->addWidget(rightTopWidget);
    topWidget->setLayout(topLayout);

    //下
    QWidget* bottomWidget = new QWidget();
    QVBoxLayout* bottomLayout = InitVLayout();
    QLabel* lblBottomTitle = InitLabel("钢件合格率",0,30,ModuleWidget::POSLEFT,titleStyle);

    QWidget* bottomChartWidget = new QWidget();
    QHBoxLayout* bottomChartLayout = InitHLayout();
    PartsInventoryTableView* view = new PartsInventoryTableView();
    QList<QStringList> msgList;
    QList<QVariantList> valuelist;
    for(int i = 0; i < 13; i++)
    {
        QStringList msg;
        msg.push_back(QString::number(i + 1));
        msg.push_back("SSD");
        msg.push_back("材料1");
        msg.push_back("规格1");
        msg.push_back("材料1");
        msg.push_back("32*52*1");
        msg.push_back("100");
        msg.push_back("65");
        msg.push_back("65%");
        QVariantList list = QVariantList() << 30 << 50;
        valuelist.push_back(list);
        msgList.push_back(msg);
    }
    view->Set_Model_Data(msgList,valuelist);
    bottomChartLayout->addWidget(view);

    bottomChartWidget->setLayout(bottomChartLayout);
    bottomLayout->addWidget(lblBottomTitle);
    bottomLayout->addWidget(bottomChartWidget);
    bottomWidget->setLayout(bottomLayout);

    mLayout->addWidget(topWidget);
    mLayout->addWidget(bottomWidget);
    mWidget->setLayout(mLayout);

    return mWidget;
}

QWidget *ModuleWidget::InitWidget9()
{
    QWidget* mWidget = new QWidget();
    QHBoxLayout* mLayout = InitHLayout();

    OpenCVGLWidget* OpenGLWidget = new OpenCVGLWidget();

    OpenCV_PV_Thread* Thread = new OpenCV_PV_Thread();
    Thread->start();
    bool isOpen = Thread->Open();
    if(!isOpen)
    {
        Thread->deleteLater();
    }
    this->connect(Thread,&OpenCV_PV_Thread::ShowCamera,OpenGLWidget,&OpenCVGLWidget::ShowImg);

    mLayout->addWidget(OpenGLWidget);
    mWidget->setLayout(mLayout);

    return mWidget;

}

QWidget* ModuleWidget::Device_InitRightWidget(QStringList nameList, QStringList valueList)
{
    const QString LabelStyle = "color:rgb(255,255,255);"
                               "font ""黑体"" 12pt;";
    QWidget* rightWidget = new QWidget();
    QVBoxLayout* rightLayout = InitVLayout(20,10,20);

    if(nameList.size() != valueList.size())
        return rightWidget;

    for(int i = 0; i <nameList.size(); i++)
    {
        QLabel* lbl = InitLabel(nameList.at(i) + ":" + valueList.at(i),0,0,ModuleWidget::POSLEFT,LabelStyle);
        rightLayout->addWidget(lbl);
    }
    rightLayout->addStretch();
    rightWidget->setLayout(rightLayout);

    return rightWidget;
}

QWidget* ModuleWidget::Device_InitBodyWidget(QStringList colorList,QStringList nameList, QStringList nameList1, QList<bool> boolList)
{

    QWidget* bodyWidget = new QWidget();
    QHBoxLayout* bodyLayout = InitHLayout(5);
    if(colorList.size() != nameList.size() && colorList.size() != nameList1.size() && colorList.size() != boolList.size())
        return bodyWidget;
    for(int i = 0; i < colorList.size(); i++)
    {
         QWidget* topWidget1 = GetColorWidget(colorList.at(i),nameList.at(i),nameList1.at(i),boolList.at(i));
         bodyLayout->addWidget(topWidget1);
    }
    bodyWidget->setLayout(bodyLayout);
    return bodyWidget;
}

QWidget *ModuleWidget::Device_InitBottomWidget(QStringList list)
{
    const QString LabelStyle = "color:rgb(255,255,255);";
    QWidget* topBottomWidget = new QWidget();
    QHBoxLayout* topBottomLayout = InitHLayout(5);
    for(auto &i : list)
    {
        QLabel* lbl = InitLabel(i,0,0,ModuleWidget::POSCENTER,LabelStyle);
        topBottomLayout->addWidget(lbl);
    }
    topBottomWidget->setLayout(topBottomLayout);

    return topBottomWidget;
}

QWidget *ModuleWidget::GetColorWidget(QString color, QString text, QString text1, bool isActivation)
{
    const QString css = QString("#mWidget{background-color:rgb(%1);}").arg(color);
    const QString labelCss = QString("color:rgb(235,235,235);");
    QWidget* mWidget = new QWidget();
    mWidget->setObjectName("mWidget");
    mWidget->setStyleSheet(css);
    if(isActivation)
    {
//        qDebug() << text << " : false";
        return mWidget;
    }

    QVBoxLayout* mLayout = InitVLayout();

    QLabel* lblText = InitLabel(text,0,35,ModuleWidget::POSCENTER,labelCss);
    QLabel* lblText1 = InitLabel(text1,0,35,ModuleWidget::POSCENTER,labelCss);

    mLayout->addWidget(lblText);
    mLayout->addWidget(lblText1);

    mWidget->setLayout(mLayout);

    return mWidget;
}

QLabel *ModuleWidget::GetLabel(QString name)
{
    {
        const QString css = PubCss::Get()->GetStr(SMALLWINDOW_TITLELABEL);
        QLabel* lbl = InitLabel(name,0,0,ModuleWidget::POSLEFT,css);

        return lbl;
    }
}
