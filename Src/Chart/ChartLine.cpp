#include "ChartLine.h"
#include <QValueAxis>
#include <QHBoxLayout>
#include <QScatterSeries>
#include <QTime>

ChartLine::ChartLine(QWidget *parent)
    :ChartBaseSeries(parent)
{

}

ChartLine::~ChartLine()
{

}

void ChartLine::Init(QList<LinePar> linepar)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);

    QList<QAbstractSeries*> SeriesList;
    for(auto &i : linepar)
    {
        QLineSeries* lineSeries = InitLine(i.Color,i.name,i.list);
        QScatterSeries* sc1 = InitOutSeries(i.list);
        QScatterSeries* sc2 = InitInSeries(i.Color,i.list);
        SeriesList.push_back(lineSeries);
        SeriesList.push_back(sc1);
        SeriesList.push_back(sc2);
    }

    //生成图表
    Chart* chart = new Chart();
    chart->Set(_cPar);
    chart->Set(_aPar);
    chart->InitChart();
    chart->InitAxis();

    for(auto &j : SeriesList)
    {
        chart->addSeries(j);
        chart->setAxisX(chart->axisX(),j);
        chart->setAxisY(chart->axisY(),j);
    }
    chart->InitLegend();

    //生成View
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mLayout->addWidget(chartView);
    this->setLayout(mLayout);
}

QList<LinePar> ChartLine::GetLPar(LParListModel index)
{
    QList<LinePar> _valueList;
    switch(index)
    {
        case LPRODUCTIONSUMVALUE1:
        {
            QList<LinePar> valueList;
            QList<QPointF> point;
            point << QPointF(0,20) << QPointF(1,80) << QPointF(2,35) << QPointF(3,82) << QPointF(4,85) << QPointF(5,18) << QPointF(6,22) << QPointF(7,16);
            QList<QPointF> point1;
            point1 << QPointF(0,15) << QPointF(1,60) << QPointF(2,63) << QPointF(3,78) << QPointF(4,85) << QPointF(5,70) << QPointF(6,18) << QPointF(7,36);
            QList<QPointF> point2;
            point2 << QPointF(0,18) << QPointF(1,22) << QPointF(2,32) << QPointF(3,83) << QPointF(4,56) << QPointF(5,10) << QPointF(6,37) << QPointF(7,35);
            valueList.push_back(LinePar{QColor(255,200,0),"",point});
            valueList.push_back(LinePar{QColor(1,177,181),"",point1});
            valueList.push_back(LinePar{QColor(7,106,182),"",point2});
            _valueList = valueList;
            break;
        }
        case LPRODUCTIONSUMVALUE2:
        {
            QList<LinePar> valueList;
            QList<QPointF> point3;
            point3 << QPointF(0,20) << QPointF(1,80) << QPointF(2,35) << QPointF(3,82) << QPointF(4,85) << QPointF(5,18) << QPointF(6,22) << QPointF(7,16);
            QList<QPointF> point4;
            point4 << QPointF(0,15) << QPointF(1,60) << QPointF(2,63) << QPointF(3,78) << QPointF(4,85) << QPointF(5,70) << QPointF(6,18) << QPointF(7,36);
            QList<QPointF> point5;
            point5 << QPointF(0,18) << QPointF(1,22) << QPointF(2,32) << QPointF(3,83) << QPointF(4,56) << QPointF(5,10) << QPointF(6,37) << QPointF(7,35);
            valueList.push_back(LinePar{QColor(255,200,0),"",point3});
            valueList.push_back(LinePar{QColor(1,177,181),"",point4});
            valueList.push_back(LinePar{QColor(7,106,182),"",point5});
            _valueList = valueList;
            break;
        }
        case LLOADDISTRIBUTIONVALUE1:
        {
            QList<LinePar> valueList;
            QList<QPointF> point1 = QList<QPointF>() << QPointF(1,20) << QPointF(2,50) << QPointF(3,100) << QPointF(4,180) << QPointF(5,85) << QPointF(6,18) << QPointF(7,60);
            QList<QPointF> point2 = QList<QPointF>() << QPointF(1,25) << QPointF(2,70) << QPointF(3,60) << QPointF(4,160) << QPointF(5,85) << QPointF(6,70) << QPointF(7,18);
            QList<QPointF> point3 = QList<QPointF>() << QPointF(1,40) << QPointF(2,10) << QPointF(3,120) << QPointF(4,150) << QPointF(5,56) << QPointF(6,30) << QPointF(7,55);
            QList<QPointF> point4 = QList<QPointF>() << QPointF(1,60) << QPointF(2,150) << QPointF(3,125) << QPointF(4,165) << QPointF(5,85) << QPointF(6,60) << QPointF(7,120);
            QList<QPointF> point5 = QList<QPointF>() << QPointF(1,30) << QPointF(2,80) << QPointF(3,20) << QPointF(4,175) << QPointF(5,85) << QPointF(6,110) << QPointF(7,40);
            QList<QPointF> point6 = QList<QPointF>() << QPointF(1,75) << QPointF(2,50) << QPointF(3,10) << QPointF(4,100) << QPointF(5,180) << QPointF(6,50) << QPointF(7,80);
            valueList.push_back(LinePar{QColor(0,181,183),"",point1});
            valueList.push_back(LinePar{QColor(254,190,0),"",point2});
            valueList.push_back(LinePar{QColor(0,112,191),"",point3});
            valueList.push_back(LinePar{QColor(71,100,147),"",point4});
            valueList.push_back(LinePar{QColor(214,77,84),"",point5});
            valueList.push_back(LinePar{QColor(0,174,123),"",point6});
            _valueList = valueList;
            break;
        }
        case LPASSEDTHEINSPECTIONVALUE1:
        {
             QList<LinePar> valueList;
             QList<QPointF> point1 = QList<QPointF>() << QPointF(1,87) << QPointF(2,30) << QPointF(3,32) << QPointF(4,31) << QPointF(5,33)
                                                      << QPointF(6,36) << QPointF(7,37) << QPointF(8,30) << QPointF(9,80) << QPointF(10,75);
             valueList.push_back(LinePar{QColor(0,181,183),"",point1});
             _valueList = valueList;
             break;
        }
        case LPASSEDTHEINSPECTIONVALUE2:
        {
            QList<LinePar> valueList;
            QList<QPointF> point1 = QList<QPointF>() << QPointF(1,73) << QPointF(2,32) << QPointF(3,33) << QPointF(4,31) << QPointF(5,32)
                                                     << QPointF(6,60) << QPointF(7,76) << QPointF(8,80) << QPointF(9,35) << QPointF(10,43);
            valueList.push_back(LinePar{QColor(0,181,183),"",point1});
            _valueList = valueList;
            break;
        }
        case LQUALITYMANAGEMENTVALUE1:
        {
            QList<LinePar> valueList;
            QList<QPointF> point1 = QList<QPointF>();
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int i = 0; i < 31; i++)
            {
                point1.append(QPointF(i + 1,qrand() % 100));
            }
            valueList.push_back(LinePar{QColor(0,181,183),"",point1});
            _valueList = valueList;
            break;
        }
        case LCHARTLINEVALUE:
        {
            QList<LinePar> valueList;
            QList<QPointF> point1;
            QList<QPointF> point2;
            QList<QPointF> point3;
            QList<QPointF> point4;
            QList<QPointF> point5;
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int i = 0; i < 12; i++)
            {
                point1.append(QPointF(i,qrand() % 120));
            }
            for(int i = 0; i < 12; i++)
            {
                point2.append(QPointF(i,qrand() % 120));
            }
            for(int i = 0; i < 12; i++)
            {
                point3.append(QPointF(i,qrand() % 120));
            }
            for(int i = 0; i < 12; i++)
            {
                point4.append(QPointF(i,qrand() % 120));
            }
            for(int i = 0; i < 12; i++)
            {
                point5.append(QPointF(i,qrand() % 120));
            }
            valueList.push_back(LinePar{QColor(47,166,242),"",point1});
            valueList.push_back(LinePar{QColor(51,215,218),"",point2});
            valueList.push_back(LinePar{QColor(222,129,50),"",point3});
            valueList.push_back(LinePar{QColor(74,100,151),"",point4});
            valueList.push_back(LinePar{QColor(188,92,88),"",point5});
            _valueList = valueList;
            break;
        }
    }
    return _valueList;
}

QLineSeries *ChartLine::InitLine(QColor Color, QString name, QList<QPointF> list)
{
    QFont font;
    font.setItalic(!font.italic());
    font.setPointSizeF(12);
    font.setFamily("微软雅黑");

    QLineSeries* lineSeries = new QLineSeries();
    //添加数据
    lineSeries->append(list);
    //设置线段的名称
    lineSeries->setName(name);
    //设置线段的颜色
    lineSeries->setColor(QColor());
    //设置线段是否可视话
    lineSeries->setVisible(true);
    //点标签文字是否可见
    lineSeries->setPointLabelsVisible(false);
    //点标签字体
    lineSeries->setPointLabelsFont(font);
    //点标签格式
    lineSeries->setPointLabelsFormat("@xPoint,@yPoint");
    //是否切割边缘点标签，默认为true
    lineSeries->setPointLabelsClipping(true);
    //设置点是否可视
    lineSeries->setPointsVisible(true);
    //设置笔
    lineSeries->setPen(QPen(QBrush(Color),2));
    //使用opengl渲染
    lineSeries->setUseOpenGL(true);

    //离散点
    QScatterSeries *series1 = new QScatterSeries();
    //圆形的点
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    //离散点边框颜色
    series1->setBorderColor(QColor(21, 100, 255));
    //离散点背景色
    series1->setBrush(QBrush(QColor(21, 100, 255)));
     //离散点大小
    series1->setMarkerSize(12);
    //添加数据
    series1->append(list);

    return lineSeries;
}

QScatterSeries *ChartLine::InitOutSeries(QList<QPointF> list)
{
    QScatterSeries *series1 = new QScatterSeries();
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series1->setBorderColor(QColor(255, 255, 255));  //边框颜色
    series1->setBrush(QBrush(QColor(255, 255, 255)));//背景颜色
    series1->setMarkerSize(12);
    series1->append(list);
    series1->setUseOpenGL(true);

    return series1;
}

QScatterSeries *ChartLine::InitInSeries(QColor color,QList<QPointF> list)
{
    QScatterSeries *series1 = new QScatterSeries();
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);//圆形的点
    series1->setBorderColor(color);  //边框颜色
    series1->setBrush(QBrush(color));//背景颜色
    series1->setMarkerSize(6);
    series1->append(list);
    series1->setUseOpenGL(true);

    return series1;
}

