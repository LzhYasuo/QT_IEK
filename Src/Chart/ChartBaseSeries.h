#ifndef _CHART_BASE_SERIES_H_
#define _CHART_BASE_SERIES_H_

#include <QWidget>
#include "Chart.h"

enum AParModel
{
    APRODUCTIONSUM1,
    APRODUCTIONSUM2,
    APRODUCTIONSUM3,
    APRODUCTIONSUM4,
    APLANFORTHEMONTH1,
    APLANFORTHEMONTH2,
    ALOADDISTRIBUTION1,
    ALOADDISTRIBUTION2,
    APASSEDTHEINSPECTION1,
    APASSEDTHEINSPECTION2,
    APASSEDTHEINSPECTION3,
    AQUALITYMANAGEMENT1,
    AQUALITYMANAGEMENT2,
    AQUALITYMANAGEMENT3,
    ACHARTLINE,
    ACHARTCURVE1,
    ACHARTCURVE2,
    ACHARTCURVE3,
    ACHARTBAR1,
    ACHARTBAR2,
    ACHARTBAR3,
    ACHARTBAR4,
    ACHARTBAR5,
    ACHARTBAR6,
    ACHARTBAR7,
    ACHARTBAR8,
    ACHARTBAR9,
    ACHARTBAR10,
};

enum CParModel
{
    CPRODUCTIONSUM1,
    CPRODUCTIONSUM2,
    CPRODUCTIONSUM3,
    CPRODUCTIONSUM4,
    CPLANFORTHEMONTH1,
    CPLANFORTHEMONTH2,
    CLOADDISTRIBUTION1,
    CLOADDISTRIBUTION2,
    CPASSEDTHEINSPECTION1,
    CPASSEDTHEINSPECTION2,
    CPASSEDTHEINSPECTION3,
    CQUALITYMANAGEMENT1,
    CQUALITYMANAGEMENT2,
    CQUALITYMANAGEMENT3,
    CCHARTLINE,
    CCHARTCURVE1,
    CCHARTCURVE2,
    CCHARTCURVE3,
    CCHARTBAR1,
    CCHARTBAR2,
    CCHARTBAR3,
    CCHARTBAR4,
    CCHARTBAR5,
    CCHARTBAR6,
    CCHARTBAR7,
    CCHARTBAR8,
    CCHARTBAR9,
    CCHARTBAR10,

};

class ChartBaseSeries : public QWidget
{
    Q_OBJECT
public:
    ChartBaseSeries(QWidget* parent = nullptr);
    ~ChartBaseSeries();

    AxisPar GetPar(AParModel);
    ChartPar GetPar(CParModel);
    void Set(ChartPar par);
    void Set(AxisPar par);
protected:
    ChartPar _cPar;
    AxisPar _aPar;

    QMap<AParModel,AParModel> _aMapList;
    QMap<CParModel,CParModel> _cMapList;

};

#endif //_CHART_BASE_SERIES_H_
