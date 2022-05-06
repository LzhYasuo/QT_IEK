#ifndef _CHART_CURVE_H_
#define _CHART_CURVE_H_

#include <QWidget>
#include "ChartBaseSeries.h"

#include <QChartView>//显示图表
#include <QSplineSeries>
#include <QDoubleSpinBox>
#include <QList>
#include <QPointF>

QT_CHARTS_USE_NAMESPACE//QtChart名空间

enum CuParListModel
{
    CUCHARTCURVE1,
    CUCHARTCURVE2,
    CUCHARTCURVE3
};

struct CurvePar
{
    QColor Color;
    QString name;
    QList<QPointF> list;
};

class ChartCurve : public ChartBaseSeries
{
    Q_OBJECT
public:
    ChartCurve(QWidget* parent = nullptr);
    ~ChartCurve();

    QList<CurvePar> GetCuPar(CuParListModel);
    void Init(QList<CurvePar>);
    void SetPointShow(bool);
private:
    QSplineSeries* InitLine(QColor,QString,QList<QPointF> list);
    bool isPointLabelShow = false;
};


#endif //_CHART_CURVE_H_
