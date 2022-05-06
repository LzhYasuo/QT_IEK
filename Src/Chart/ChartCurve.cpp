#include "ChartCurve.h"
#include <QValueAxis>
#include <QHBoxLayout>
#include "Chart.h"
#include "QTime"

ChartCurve::ChartCurve(QWidget *parent)
    :ChartBaseSeries(parent)
{

}


void ReadData()
{

}

ChartCurve::~ChartCurve()
{

}

QList<CurvePar> ChartCurve::GetCuPar(CuParListModel index)
{
    QList<CurvePar> cuPar;
    switch (index)
    {
        case CUCHARTCURVE1:
        {
            QList<CurvePar> valueList;
            QList<QPointF> point1;
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int i = 0; i < 15; i++)
            {
                point1.append(QPointF(i + 1,qrand() % 100));
            }
            valueList.push_back(CurvePar{QColor(73,183,199),"",point1});
            cuPar = valueList;
            break;
        }
        case CUCHARTCURVE2:
        {
            QList<CurvePar> valueList;
            QList<QPointF> point1;
            qsrand(QTime(0,6,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int i = 0; i < 15; i++)
            {
                point1.append(QPointF(i + 1,qrand() % 100));
            }
            valueList.push_back(CurvePar{QColor(96,79,121),"",point1});
            cuPar = valueList;
            break;
        }
        case CUCHARTCURVE3:
        {
            QList<CurvePar> valueList;
            QList<QPointF> point1;
            qsrand(QTime(0,0,3).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int i = 0; i < 15; i++)
            {
                point1.append(QPointF(i + 1,qrand() % 100));
            }
            valueList.push_back(CurvePar{QColor(254,137,44),"",point1});
            cuPar = valueList;
            break;
        }
    }
    return cuPar;
}

void ChartCurve::Init(QList<CurvePar> cuPar)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);

    QList<QAbstractSeries*> SeriesList;
    for(int i = 0; i < cuPar.size(); i++)
    {
        QSplineSeries* lineSeries = InitLine(cuPar.at(i).Color,cuPar.at(i).name,cuPar.at(i).list);
        SeriesList.push_back(lineSeries);
    }
    //生成图表
    Chart* chart = new Chart();
    chart->Set(_cPar);
    chart->Set(_aPar);
    chart->InitChart();
    chart->InitAxis();
    for(auto& i : SeriesList)
    {
        chart->addSeries(i);
        chart->setAxisX(chart->axisX(),i);
        chart->setAxisY(chart->axisY(),i);
    }
    chart->InitLegend();

    //生成View
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mLayout->addWidget(chartView);
    this->setLayout(mLayout);
}

void ChartCurve::SetPointShow(bool isShow)
{
    isPointLabelShow = isShow;
}

QSplineSeries* ChartCurve::InitLine(QColor color,QString name, QList<QPointF> list)
{
    QFont font;
    font.setItalic(!font.italic());
    font.setPointSizeF(15);
    font.setFamily("微软雅黑");

    QSplineSeries* lineSeries = new QSplineSeries();
    //添加数据
    lineSeries->append(list);
    //设置线段的名称
    lineSeries->setName(name);
    //设置线段的颜色
    lineSeries->setColor(QColor());
    //设置线段是否可视话
    lineSeries->setVisible(true);
    //点标签文字是否可见
    lineSeries->setPointLabelsVisible(isPointLabelShow);
    //点标签字体
    lineSeries->setPointLabelsFont(font);
    //点标签颜色
    lineSeries->setPointLabelsColor(QColor(color));
    //点标签格式
    lineSeries->setPointLabelsFormat("@yPoint");
    //是否切割边缘点标签，默认为true
    lineSeries->setPointLabelsClipping(true);
    //设置点是否可视
    lineSeries->setPointsVisible(true);
    //设置笔
    lineSeries->setPen(QPen(QBrush(color),2));
    //使用opengl渲染
    lineSeries->setUseOpenGL(true);

    return lineSeries;
}


