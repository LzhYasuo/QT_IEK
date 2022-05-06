#include "ChartPie.h"
#include "Chart.h"
#include <QChartView>
#include <QHBoxLayout>
#include <QDebug>
#include <QGraphicsLayout>

ChartPie::ChartPie(QWidget *parent)
    :ChartBaseSeries (parent)
{

}

ChartPie::~ChartPie()
{

}

void ChartPie::Init(QList<QColor> colorList,QStringList nameList,QList<int> valueList,int total)
{
    if(colorList.size() != nameList.size() || colorList.size() != valueList.size() )
        return;
    _total = total;
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);

    QPieSeries* pieSeries = new QPieSeries();
    //孔大小
    pieSeries->setHoleSize(0.0);
    //水平位置
    pieSeries->setHorizontalPosition(0.5);
    //设置文字位置
//    pieSeries->setLabelsPosition(QPieSlice::LabelInsideTangential);
    //设置文字是否可视化
//    pieSeries->setLabelsVisible(true);
    //饼图尺寸
    pieSeries->setPieSize(0.7);
    //设置12方向是几度
    pieSeries->setPieStartAngle(0);
    pieSeries->setVerticalPosition(0.5);
    pieSeries->setVisible(true);
    pieSeries->setUseOpenGL(true);

    for(int i = 0; i < colorList.size(); i++)
    {
         CreatePieSlice(pieSeries,colorList.at(i),nameList.at(i),valueList.at(i),i);
    }
//    CreatePieSlice(pieSeries,QColor(90,180,180),"bcc",30,1);
//    CreatePieSlice(pieSeries,QColor(150,180,180),"ccc",30,2);
//    CreatePieSlice(pieSeries,QColor(210,180,180),"dcc",10,3);

    QChart* chart = new QChart();
    //设置系统主题
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    //是否启用动画
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->layout()->setContentsMargins(0, 0, 0, 0);//设置外边界全部为0
    chart->setMargins(QMargins(0, 0, 0, 0));//设置内边界全部为0
    chart->setBackgroundRoundness(0);//设置背景区域无圆角
//    chart->InitChart();
//    chart->InitLegend();
//    chart->InitAxis();
    chart->addSeries(pieSeries);

    QChartView* view = new QChartView(chart);
    mLayout->addWidget(view);
    this->setLayout(mLayout);
}

void ChartPie::CreatePieSlice(QPieSeries* pieSeries,QColor color,QString name,int value,int index, bool isExploded)
{
    pieSeries->append(name,value);
    QPieSlice* slice = pieSeries->slices().at(index);
    slice->setExploded(isExploded);
    slice->setLabelColor(color);
    slice->setColor(color);
//    qDebug() <<color;
    const float fValue = (slice->value() / _total * 100);
//    qDebug() << fValue;
    QString sValue = QString::number(fValue,'f',2);
    slice->setLabelPosition(QPieSlice::LabelOutside);
    slice->setLabel(slice->label() +  "  -  "+ sValue + "%");
    slice->setLabelFont(QFont("微软雅黑"));
    slice->setLabelVisible(true);
}
