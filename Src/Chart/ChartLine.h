#ifndef _CHART_LINE_H_
#define _CHART_LINE_H_

#include "ChartBaseSeries.h"

#include <QChartView>//显示图表
#include <QLineSeries>
#include <QDoubleSpinBox>
#include <QList>
#include <QScatterSeries>

#include "Chart.h"

QT_CHARTS_USE_NAMESPACE//QtChart名空间

enum LParListModel
{
    LPRODUCTIONSUMVALUE1,
    LPRODUCTIONSUMVALUE2,
    LLOADDISTRIBUTIONVALUE1,
    LPASSEDTHEINSPECTIONVALUE1,
    LPASSEDTHEINSPECTIONVALUE2,
    LQUALITYMANAGEMENTVALUE1,
    LCHARTLINEVALUE,
};

struct LinePar
{
    QColor Color;
    QString name;
    QList<QPointF> list;
};

class ChartLine : public ChartBaseSeries
{
    Q_OBJECT
public:
    ChartLine(QWidget* parent = nullptr);
    ~ChartLine();

    void Init(QList<LinePar>);
    QList<LinePar> GetLPar(LParListModel);
private:
    QLineSeries* InitLine(QColor Color,QString name,QList<QPointF> list);
    QScatterSeries* InitInSeries(QColor,QList<QPointF> list);
    QScatterSeries* InitOutSeries(QList<QPointF> list);
};


#endif //_CHART_LINE_H_
