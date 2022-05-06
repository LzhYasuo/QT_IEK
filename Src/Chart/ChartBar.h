#ifndef _CHART_BARSET_H_
#define _CHART_BARSET_H_

#include "ChartBaseSeries.h"
#include <QBarSeries>
#include <QBarSet>
#include <QPercentBarSeries>
#include <QStackedBarSeries>
#include <QHorizontalBarSeries>
#include <QHorizontalStackedBarSeries>
#include "Chart.h"

QT_CHARTS_USE_NAMESPACE//QtChart名空间

enum BParListModel
{
    BPRODUCTIONSUMVALUE1,
    BPRODUCTIONSUMVALUE2,
    BPLANFORTHEMONTHVALUE1,
    BPLANFORTHEMONTHVALUE2,
    BLOADDISTRIBUTIONVALUE1,
    BPASSEDTHEINSPECTIONVALUE1,
    BQUALITYMANAGEMENTVALUE1,
    BCHARTBAR1VALUE1,
    BCHARTBAR1VALUE2,
    BCHARTBAR2VALUE1,
    BCHARTBAR2VALUE2,
    BCHARTBAR3VALUE1,
    BCHARTBAR3VALUE2,
    BCAHRTBAR4VALUE1,
    BCAHRTBAR5VALUE1,
    BCAHRTBAR5VALUE2,
    BCAHRTBAR6VALUE1,
};


struct BarPer
{
    QString _name;
    QList<qreal> _value;
    QColor _borderColor;
    QColor _brushColor;
};

class ChartBar : public ChartBaseSeries
{
    Q_OBJECT
public:
    ChartBar(int index,QWidget* parent = nullptr);
    ~ChartBar();

    void Init(QList<BarPer> list);
    QList<BarPer> GetBPar(BParListModel);
    void SetMoreColor(QBarSeries*,QList<BarPer>);
    void SetMax(int max);
    void SetMaxColor(QColor);
private:
    QBarSeries* InitBarSeries(QList<BarPer> list);
    QStackedBarSeries* InitStackedBarSeries(QList<BarPer> list);
    QHorizontalBarSeries* InitHBarSeries(QList<BarPer> list);
    QHorizontalStackedBarSeries* InithStackedBarSeries(QList<BarPer> list);
    int _index = 0;
    int _max = 0;
    QColor _maxColor = QColor();
};


#endif //_CHART_BARSET_H_
