#ifndef _CHART_PIE_H_
#define _CHART_PIE_H_

#include "ChartBaseSeries.h"
#include "QWidget"
#include <QPieSeries>
#include <QPieSlice>

QT_CHARTS_USE_NAMESPACE //QtChart名空间

class ChartPie : public ChartBaseSeries
{
    Q_OBJECT
public:
    ChartPie(QWidget* parent = nullptr);
    ~ChartPie();

    void Init(QList<QColor>,QStringList,QList<int>,int total);
private:
    void CreatePieSlice(QPieSeries*,QColor color,QString name,int value,int index,bool isExploded = false);
private:
    int _total = 0;
};

#endif //_CHART_PIE_H_
