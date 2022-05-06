#include "Chart.h"
#include <QValueAxis>
#include <QBarCategoryAxis>
#include <QGraphicsGridLayout>

Chart::Chart()
{

}

Chart::~Chart()
{

}

void Chart::InitChart()
{
    //---------------------------------图表----------------------
    //设置系统主题
//    this->setTheme(QChart::ChartThemeBlueCerulean);
    //是否启用动画
//    this->setAnimationOptions(QChart::AllAnimations);
    //背景色设置 背景色 笔
    this->setBackgroundBrush(QBrush(_chartPar._backBrush));
//    this->setBackgroundPen(QPen(_chartPar._pen));
    this->setBackgroundVisible(true);
    //设置数据是否本地化
    this->setLocalizeNumbers(true);
    //设置标题
    this->setTitle("");
    //标题字体
    this->setTitleFont(QFont());
    //标题刷
    this->setTitleBrush(QBrush(QColor()));

    //设置外边界全部为0
    this->layout()->setContentsMargins(0, 0, 0, 0);
    //设置内边界全部为0
    this->setMargins(QMargins(0, 0, 0, 0));
    //设置背景区域无圆角
    this->setBackgroundRoundness(0);
}

void Chart::InitLegend()
{
    //---------------------------------标签-----------------------
    this->legend()->setVisible(true);
    //对齐
    this->legend()->setAlignment(Qt::AlignTop);
    //图例图标分离
    //this->legend()->detachFromChart();
    //设置背景是否可视
    //this->legend()->setBackgroundVisible(true);
    //设置背景自动填充
    //this->legend()->setAutoFillBackground(true);
    //设置标签颜色
    this->legend()->setColor(QColor(255,255,255));
    //设置边距left,top,right,bottom
    //this->legend()->setContentsMargins(10,10,10,10);
    //设置标签颜色
//    this->legend()->setLabelColor(QColor(255,128,255));
    //设置是否可视
    this->legend()->setVisible(true);
    //设置背景色
    //this->legend()->setBrush(QBrush(QColor(128,128,128,255)));
    //设置画笔
    //this->legend()->setPen(QPen(QColor(192,192, 192,192)));
    //设置边框颜色
//    this->legend()->setBorderColor(QColor(255,255,170,185));

//    QFont font1;
//    font1.setItalic(!font1.italic());
//    font1.setPointSizeF(8);
//    font.setFamily("微软雅黑");
//    chart->legend()->setFont(font1);
}

void Chart::InitAxis()
{
    if(_axisPar.xNameList.size() > 0)
    {
        QBarCategoryAxis* axis = new QBarCategoryAxis ();
        axis->setLabelsBrush(QBrush(QColor(235,235,235)));
        axis->append(_axisPar.xNameList);
        this->setAxisX(axis);
    }
    else if(_axisPar.xCount > 0)
    {
        QValueAxis* xAxis = new QValueAxis();
        xAxis->setLabelsBrush(QBrush(QColor(235,235,235)));
        xAxis->setTitleText(_axisPar.xTitle);
        xAxis->setTitleFont(QFont());
        xAxis->setRange(_axisPar.xMin,_axisPar.xMax);
        xAxis->setTickCount(_axisPar.xCount);
        if(!_axisPar.xformat.isEmpty())
        {
            xAxis->setLabelFormat(_axisPar.xformat);
            xAxis->setLabelsVisible(true);
        }
        this->setAxisX(xAxis);
    }

    if(_axisPar.yNameList.size() > 0)
    {
        QBarCategoryAxis* axis = new QBarCategoryAxis();
        axis->setLabelsBrush(QBrush(QColor(235,235,235)));
        axis->append(_axisPar.yNameList);
        this->setAxisY(axis);
    }
    else if(_axisPar.yCount > 0)
    {
        QValueAxis* Axis = new QValueAxis();
        Axis->setLabelsBrush(QBrush(QColor(235,235,235)));
        Axis->setTitleText(_axisPar.yTitle);
        Axis->setTitleFont(QFont());
        Axis->setRange(_axisPar.yMin,_axisPar.yMax);
        Axis->setTickCount(_axisPar.yCount);
        if(!_axisPar.yformat.isEmpty())
        {
            Axis->setLabelFormat(_axisPar.yformat);
            Axis->setLabelsVisible(true);
        }
        this->setAxisY(Axis);
    }

//    QValueAxis* yAxis = new QValueAxis();
//    yAxis->setTitleText("");
//    yAxis->setTitleFont(font);
//    yAxis->setRange(0,120);
//    yAxis->setTickCount(13);

//    chart->addAxis(xAxis,Qt::AlignBottom);
//    chart->addAxis(yAxis,Qt::AlignLeft);


    //    QBarCategoryAxis *pAxisX = new QBarCategoryAxis();
}

void Chart::Set(AxisPar par)
{
    _axisPar = par;
}

void Chart::Set(ChartPar par)
{
    _chartPar = par;
}
