#ifndef _CHART_H_
#define _CHART_H_

#include <QChart>

QT_CHARTS_USE_NAMESPACE

//图表参数
struct ChartPar
{
    QBrush _backBrush;
    QPen _pen;
};

//标签参数
struct LegendPar
{
    //后续要什么加什么
};

//XY参数
struct AxisPar
{
    QString xTitle = "";
    QStringList xNameList = QStringList();
    int xMin = 0;
    int xMax = 0;
    int xCount = 0;
    bool xIsShow = false;
    QString xformat = "";

    QString yTitle = "";
    QStringList yNameList = QStringList();
    int yMin = 0;
    int yMax = 0;
    int yCount = 0;
    QString yformat = "";
};

class Chart : public QChart
{
public:
    Chart();
    ~Chart();

    void InitChart();
    void InitLegend();
    void InitAxis();

    void Set(AxisPar axisPar);
    void Set(ChartPar);

private:
    ChartPar _chartPar;
    AxisPar _axisPar;
};

#endif //_CHART_H_
