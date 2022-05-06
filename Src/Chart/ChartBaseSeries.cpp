#include "ChartBaseSeries.h"

ChartBaseSeries::ChartBaseSeries(QWidget *parent)
{

}

ChartBaseSeries::~ChartBaseSeries()
{

}

AxisPar ChartBaseSeries::GetPar(AParModel model)
{
    AxisPar aPar;
    switch(model)
    {
        case APRODUCTIONSUM1:
        {
            AxisPar par;
            par.xMax = 5;
            par.xCount = 1;
            par.yNameList = QStringList() << "设变" << "修膜" << "新模";
            aPar = par;
            break;
        }
        case APRODUCTIONSUM2:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xNameList = QStringList() << "1月" << "2月" << "3月" << "4月" << "5月" << "6月" << "7月" << "8月";
            aPar = par;
            break;
        }
        case APRODUCTIONSUM3:
        {
            AxisPar par;
            par.xCount = 1;
            par.xMax = 12000;
            par.yNameList = QStringList() << "设变" << "修膜" << "新模";
            aPar = par;
            break;
        }
        case APRODUCTIONSUM4:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xNameList = QStringList() << "1月" << "2月" << "3月" << "4月" << "5月" << "6月" << "7月" << "8月";
            aPar = par;
            break;
        }
        case APLANFORTHEMONTH1:
        {
            AxisPar par;
            par.yMax = 700;
            par.xCount = 8;
            par.xNameList = QStringList() << "摸仁" << "不会" << "辅件" << "电极";
            aPar = par;
            break;
        }
        case APLANFORTHEMONTH2:
        {
            AxisPar par;
            par.yMax = 100;
            par.xMax = 32;
            par.yCount = 6;
            par.xCount = 33;
            aPar = par;
            break;
        }
        case ALOADDISTRIBUTION1:
        {
            AxisPar par;
            par.yMax = 90;
            par.yCount = 10;
            par.xNameList = QStringList() << "CNC组" << "CNC精" << "EDM" << "WEDM" << "锐床" << "磨末";
            aPar = par;
            break;
        }
        case ALOADDISTRIBUTION2:
        {
            AxisPar par;
            par.yMax = 200;
            par.yCount = 9;
            par.xMax = 8;
            par.xCount = 9;
            aPar = par;
            break;
        }
        case APASSEDTHEINSPECTION1:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 7;
            par.xMax = 11;
            par.xCount = 12;
            aPar = par;
            break;
        }
        case APASSEDTHEINSPECTION2:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 7;
            par.xMax = 11;
            par.xCount = 12;
            aPar = par;
            break;
        }
        case APASSEDTHEINSPECTION3:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xNameList = QStringList() << "CNC组" << "CNC精" << "EDM" << "WEDM" << "铣床" << "磨床";
            par.xCount = 0;
            aPar = par;
            break;
        }
        case AQUALITYMANAGEMENT1:
        {
            break;
        }
        case AQUALITYMANAGEMENT2:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xNameList = QStringList() << "CNC" << "EDM" << "线割" << "磨床" << "铣床" << "外协";
            aPar = par;
            break;
        }
        case AQUALITYMANAGEMENT3:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 7;
            par.xMax = 32;
            par.xCount = 33;
            aPar = par;
            break;
        }
        case ACHARTLINE:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 13;
//            par.xMax = 12;
//            par.xCount = 13;
            par.xNameList = QStringList() << "1月" << "2月" << "3月" << "4月" << "5月" << "6月"
                                          << "7月" << "8月" << "9月" << "10月" << "11月" << "12月";
            aPar = par;
            break;
        }
        case ACHARTCURVE1:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 5;
            par.xMax = 16;
            par.xCount = 17;
            aPar = par;
            break;
        }
        case ACHARTCURVE2:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 5;
            par.xMax = 16;
            par.xCount = 17;
            aPar = par;
            break;
        }
        case ACHARTCURVE3:
        {
            AxisPar par;
            par.yMax = 120;
            par.yCount = 5;
            par.xMax = 16;
            par.xCount = 17;
            aPar = par;
            break;
        }
        case ACHARTBAR1:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.yformat = "%.0f%";
            par.xNameList = QStringList() << "项目1" << "项目2" << "项目3" << "项目4" << "项目5" << "项目6";
            aPar = par;
            break;
        }
        case ACHARTBAR2:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.yformat = "%.0f%";
            par.xNameList = QStringList() << "小组1" << "小组2" << "小组3" << "小组4" << "小组5" << "小组6";
            aPar = par;
            break;
        }
        case ACHARTBAR3:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xMax = 32;
            par.xCount = 17;
            aPar = par;
            break;
        }
        case ACHARTBAR4:
        {
            AxisPar par;
            par.yMax = 100;
            par.yCount = 6;
            par.xMax = 32;
            par.xCount = 17;
            aPar = par;
            break;
        }
        case ACHARTBAR5:
        {
            AxisPar par;
            par.yMax = 600;
            par.yCount = 7;
            par.xNameList = QStringList() << "模仁" << "揽件" << "辅件" << "电极";
            aPar = par;
            break;
        }
        case ACHARTBAR6:
        {
            AxisPar par;
            par.yMax = 600;
            par.yCount = 7;
            par.xNameList = QStringList() << "模仁" << "揽件" << "辅件" << "电极";
            aPar = par;
            break;
        }
        case ACHARTBAR7:
        {
            AxisPar par;
            par.xMax = 100;
            par.xCount = 6;
            par.yNameList = QStringList() << "项目1" << "项目2" << "项目3" << "项目4" << "项目5" << "项目6";
            aPar = par;
            break;
        }
        case ACHARTBAR8:
        {
            AxisPar par;
            par.xMax = 100;
            par.xCount = 6;
            par.yMax = 32;
            par.yCount = 17;
            aPar = par;
            break;
        }
        case ACHARTBAR9:
        {
            AxisPar par;
            par.xMax = 100;
            par.xCount = 6;
            par.yMax = 32;
            par.yCount = 17;
            aPar = par;
            break;
        }
        case ACHARTBAR10:
        {
            AxisPar par;
            par.xMax = 100;
            par.xCount = 1;
            par.yNameList = QStringList() << "设变" << "修膜" << "新模";
            aPar = par;
            break;
        }
    }
    return aPar;
}

ChartPar ChartBaseSeries::GetPar(CParModel index)
{
    ChartPar _cPar;
    switch (index)
    {
        case CPRODUCTIONSUM1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPRODUCTIONSUM2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPRODUCTIONSUM3:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPRODUCTIONSUM4:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPLANFORTHEMONTH1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPLANFORTHEMONTH2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CLOADDISTRIBUTION1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CLOADDISTRIBUTION2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPASSEDTHEINSPECTION1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPASSEDTHEINSPECTION2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CPASSEDTHEINSPECTION3:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CQUALITYMANAGEMENT1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CQUALITYMANAGEMENT2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CQUALITYMANAGEMENT3:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CCHARTLINE:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTCURVE1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CCHARTCURVE2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CCHARTCURVE3:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(40,42,76));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR1:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR2:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR3:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR4:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR5:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR6:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR7:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR8:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR9:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
        case CCHARTBAR10:
        {
            ChartPar cPar;
            cPar._backBrush = QBrush(QColor(18,60,120));
            _cPar = cPar;
            break;
        }
    }
    return _cPar;
}

void ChartBaseSeries::Set(ChartPar par)
{
    _cPar = par;
}

void ChartBaseSeries::Set(AxisPar par)
{
    _aPar = par;
}
