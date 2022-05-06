#include "ChartBar.h"
#include <QHBoxLayout>
#include <QChartView>
#include <QDebug>
#include <QTime>

ChartBar::ChartBar(int index,QWidget *parent)
    :ChartBaseSeries (parent)
{
    _index = index;
}

ChartBar::~ChartBar()
{

}

void ChartBar::Init(QList<BarPer> bar)
{
    QHBoxLayout* mLayout = new QHBoxLayout();
    mLayout->setSpacing(0);
    mLayout->setContentsMargins(0,0,0,0);

    QBarSeries* barSeries = nullptr;
    QStackedBarSeries* stackedBarSeries = nullptr;
    QHorizontalBarSeries* hBarSeries = nullptr;
    QHorizontalStackedBarSeries* hstackedBarSeries = nullptr;
    if(_index == 1)
    {
        barSeries = InitBarSeries(bar);
    }
    else if(_index == 2)
    {
        stackedBarSeries = InitStackedBarSeries(bar);
    }
    else if(_index == 3)
    {
        barSeries = InitBarSeries(bar);
    }
    else if(_index == 4)
    {
        hBarSeries = InitHBarSeries(bar);
    }
    else if(_index == 5)
    {
        hstackedBarSeries = InithStackedBarSeries(bar);
    }
    else if(_index == 6)
    {
        hBarSeries = InitHBarSeries(bar);
    }

    Chart* chart = new Chart();
    chart->Set(_cPar);
    chart->Set(_aPar);
    chart->InitChart();
    chart->InitAxis();
    if(_index == 1 || _index == 3)
    {
        chart->addSeries(barSeries);
        if(chart->axisX() != nullptr)
            chart->setAxisX(chart->axisX(),barSeries);
        if(chart->axisY() != nullptr)
            chart->setAxisY(chart->axisY(),barSeries);
    }
    else if(_index == 2)
    {
        chart->addSeries(stackedBarSeries);
        if(chart->axisX() != nullptr)
            chart->setAxisX(chart->axisX(),stackedBarSeries);
        if(chart->axisY() != nullptr)
            chart->setAxisY(chart->axisY(),stackedBarSeries);
    }
    else if(_index == 4 || _index == 6)
    {
        chart->addSeries(hBarSeries);
        if(chart->axisX() != nullptr)
            chart->setAxisX(chart->axisX(),hBarSeries);
        if(chart->axisY() != nullptr)
            chart->setAxisY(chart->axisY(),hBarSeries);
    }
    else if(_index == 5)
    {
        chart->addSeries(hstackedBarSeries);
        if(chart->axisX() != nullptr)
            chart->setAxisX(chart->axisX(),hstackedBarSeries);
        if(chart->axisY() != nullptr)
            chart->setAxisY(chart->axisY(),hstackedBarSeries);
    }
    chart->InitLegend();
    if(_index == 1)
    {
        if(bar.size() == 1)
        {
            if(_max > 0)
            {
                SetMoreColor(barSeries,bar);
            }
        }
    }
    QChartView* view = new QChartView(chart);
    mLayout->addWidget(view);
    this->setLayout(mLayout);

}

QList<BarPer> ChartBar::GetBPar(BParListModel index)
{
    QList<BarPer> _valueList;
    switch (index)
    {
        case BPRODUCTIONSUMVALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> List1;
            List1 << 2 << 4 << 4;
            QList<qreal> List2;
            List2 << 2 << 2 << 3;
            valueList.push_back(BarPer{"",List1,QColor(255,255,255),QColor(0,175,179)});
            valueList.push_back(BarPer{"",List2,QColor(255,255,255),QColor(32,158,222)});
            _valueList = valueList;
            break;
        }
        case BPRODUCTIONSUMVALUE2:
        {
            QList<BarPer> valueList;
            QList<qreal> List3;
            List3 << 9814 << 9952 << 5000;
            QList<qreal> List4;
            List4 << 6867 << 5000 << 7927;
            valueList.push_back(BarPer{"",List3,QColor(255,255,255),QColor(0,175,179),});
            valueList.push_back(BarPer{"",List4,QColor(255,255,255),QColor(32,158,222)});
            _valueList = valueList;
            break;
        }
        case BPLANFORTHEMONTHVALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 452 << 332 << 232 << 380;
            QList<qreal> valueList2 = QList<qreal>() << 227 << 412 << 295 << 549;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(0,176,180)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(32,158,222)});
            _valueList = valueList;
            break;
        }
        case BPLANFORTHEMONTHVALUE2:
        {
            QList<BarPer> valueList;
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            QList<qreal> valueList2 = QList<qreal>() << 0;
            QList<qreal> valueList3 = QList<qreal>() << 0;
            QList<qreal> valueList4 = QList<qreal>() << 0;
            for(int var =0; var < 31;++var)
            {
                valueList2.append(qrand()%(20));
            }
            for(int var =0; var < 31;++var)
            {
                valueList3.append(qrand()%(20));
            }
            for(int var =0; var < 31;++var)
            {
                valueList4.append(qrand()%(20));
            }
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(0,176,180)});
            valueList.push_back(BarPer{"",valueList3,QColor(255,255,255),QColor(255,192,0)});
            valueList.push_back(BarPer{"",valueList4,QColor(255,255,255),QColor(32,158,222)});
            _valueList = valueList;
            break;
        }
        case BLOADDISTRIBUTIONVALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>();
            QList<qreal> valueList2 = QList<qreal>();
            for(int var = 0; var < 6;++var)
            {
                valueList1.append(qrand()%(40));
            }
            for(int var =0; var < 6;++var)
            {
                valueList2.append(qrand()%(40));
            }
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(0,176,180)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(255,42,45)});
            _valueList = valueList;
            break;
        }
        case BPASSEDTHEINSPECTIONVALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 77 << 68 << 43 << 30 << 47 << 30;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(255,42,45)});
            _valueList = valueList;
            break;
        }
        case BQUALITYMANAGEMENTVALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 46 << 39 << 30 << 81 << 43 << 30;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(255,42,45)});
            _valueList = valueList;
            break;
        }
        case BCHARTBAR1VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 57 << 72 << 88 << 41 << 88 << 55;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(255,42,45)});
            _valueList = valueList;
            break;
        }
        case BCHARTBAR1VALUE2:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 72 << 74 << 87 << 64 << 43 << 43;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(255,42,45)});
            _valueList = valueList;
            break;
        }
        case BCHARTBAR2VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1;
            QList<qreal> valueList2;
            QList<qreal> valueList3;

            valueList1.push_back(0);
            valueList2.push_back(0);
            valueList3.push_back(0);
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int var =0; var < 31;++var)
            {
                valueList1.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList2.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList3.append(qrand()%(33));
            }
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(1,178,179)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(1,133,189)});
            valueList.push_back(BarPer{"",valueList3,QColor(255,255,255),QColor(253,191,1)});
            _valueList = valueList;
            break;

        }
        case BCHARTBAR2VALUE2:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1;
            QList<qreal> valueList2;
            QList<qreal> valueList3;

            valueList1.push_back(0);
            valueList2.push_back(0);
            valueList3.push_back(0);
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int var =0; var < 31;++var)
            {
                valueList1.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList2.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList3.append(qrand()%(33));
            }
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(52,182,214)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(254,183,41)});
            valueList.push_back(BarPer{"",valueList3,QColor(255,255,255),QColor(234,81,45)});
            _valueList = valueList;
            break;
        }
        case BCHARTBAR3VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 281 << 461 << 299 << 131;
            QList<qreal> valueList2 = QList<qreal>() << 453 << 336 << 428 << 398;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(1,176,181)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(0,113,193)});
            _valueList = valueList;
            break;
        }
        case BCHARTBAR3VALUE2:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 210 << 213 << 259 << 245;
            QList<qreal> valueList2 = QList<qreal>() << 177 << 473 << 177 << 512;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(253,139,40)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(117,55,118)});
            _valueList = valueList;
            break;
        }
        case BCAHRTBAR4VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 88 << 45 << 42 << 75 << 71 << 83;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(253,139,40)});
            _valueList = valueList;
            break;
        }
        case BCAHRTBAR5VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1;
            QList<qreal> valueList2;
            QList<qreal> valueList3;

            valueList1.push_back(0);
            valueList2.push_back(0);
            valueList3.push_back(0);
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int var =0; var < 31;++var)
            {
                valueList1.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList2.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList3.append(qrand()%(33));
            }
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(1,178,179)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(1,133,189)});
            valueList.push_back(BarPer{"",valueList3,QColor(255,255,255),QColor(253,191,1)});
            _valueList = valueList;
            break;
        }
        case BCAHRTBAR5VALUE2:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1;
            QList<qreal> valueList2;
            QList<qreal> valueList3;

            valueList1.push_back(0);
            valueList2.push_back(0);
            valueList3.push_back(0);
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //不能放在循环里，否则容易出现很多相同随机数
            for(int var =0; var < 31;++var)
            {
                valueList1.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList2.append(qrand()%(33));
            }
            for(int var =0; var < 31;++var)
            {
                valueList3.append(qrand()%(33));
            }
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(52,182,214)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(254,183,41)});
            valueList.push_back(BarPer{"",valueList3,QColor(255,255,255),QColor(234,81,45)});
            _valueList = valueList;
            break;
        }
        case BCAHRTBAR6VALUE1:
        {
            QList<BarPer> valueList;
            QList<qreal> valueList1 = QList<qreal>() << 40 << 53 << 90;
            QList<qreal> valueList2 = QList<qreal>() << 68 << 64 << 58;
            valueList.push_back(BarPer{"",valueList1,QColor(255,255,255),QColor(0,113,194)});
            valueList.push_back(BarPer{"",valueList2,QColor(255,255,255),QColor(1,176,181)});
            _valueList = valueList;
            break;
        }
    }

    return _valueList;
}

void ChartBar::SetMax(int max)
{
    _max = max;
}

void ChartBar::SetMaxColor(QColor color)
{
    _maxColor = color;
}

void ChartBar::SetMoreColor(QBarSeries* barSeries, QList<BarPer> List)
{
    QList<QBarSet*> barSetList = barSeries->barSets();

    qDebug() << barSetList.at(0)->at(1);
    if(barSetList.size() == List.size())
        return;
    for(int i = 0 ; i < barSetList.size(); i++)
    {
        if(List.at(0)._value.at(i) > _max)
        {
            barSetList.at(i)->setColor(_maxColor);
        }
    }
}


QBarSeries *ChartBar::InitBarSeries(QList<BarPer> list)
{
    QFont fontText("SimHei");
    fontText.setPixelSize(12);

    QBarSeries* barSet = new QBarSeries();
    //设置文字可视化
    barSet->setLabelsVisible(true);
    //设置文字格式 高
    barSet->setLabelsFormat("@value");
    //设置文字所处位置
    barSet->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    for(auto &i : list)
    {
        //创建柱
        QBarSet* set = new QBarSet(i._name);
        //设置字体
        set->setLabelFont(fontText);
        //设置背景色
        set->setBrush(i._brushColor);
        //设置边框色
        set->setBorderColor(i._borderColor);
        //设置值
        set->append(i._value);
        //添加
        barSet->append(set);

    }

    return barSet;
}

QStackedBarSeries *ChartBar::InitStackedBarSeries(QList<BarPer> list)
{
    QFont fontText("SimHei");
    fontText.setPixelSize(12);
    QStackedBarSeries* barSet = new QStackedBarSeries();
    //设置文字可视化
    barSet->setLabelsVisible(true);
    //设置文字格式 高
    barSet->setLabelsFormat("@value");
    //设置文字所处位置
    barSet->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    for(auto &i : list)
    {
        //创建柱
        QBarSet* set = new QBarSet(i._name);
        //设置字体
        set->setLabelFont(fontText);
        //设置背景色
        set->setBrush(i._brushColor);
        //设置边框色
        set->setBorderColor(i._borderColor);
        //设置值
        set->append(i._value);
        //添加
        barSet->append(set);
    }
    return barSet;

}

QHorizontalBarSeries *ChartBar::InitHBarSeries(QList<BarPer> list)
{
    QFont fontText("SimHei");
    fontText.setPixelSize(12);
    QHorizontalBarSeries* barSet = new QHorizontalBarSeries();
    //设置文字可视化
    barSet->setLabelsVisible(true);
    //设置文字格式 高
    barSet->setLabelsFormat("@value");
    //设置文字所处位置
    barSet->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    for(auto &i : list)
    {
        //创建柱
        QBarSet* set = new QBarSet(i._name);
        //设置字体
        set->setLabelFont(fontText);
        //设置背景色
        set->setBrush(i._brushColor);
        //设置边框色
        set->setBorderColor(i._borderColor);
        //设置值
        set->append(i._value);
        //添加
        barSet->append(set);
    }
    return barSet;
}

QHorizontalStackedBarSeries* ChartBar::InithStackedBarSeries(QList<BarPer> list)
{
    QFont fontText("SimHei");
    fontText.setPixelSize(12);
    QHorizontalStackedBarSeries* barSet = new QHorizontalStackedBarSeries();
    //设置文字可视化
    barSet->setLabelsVisible(true);
    //设置文字格式 高
    barSet->setLabelsFormat("@value");
    //设置文字所处位置
    barSet->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    for(auto &i : list)
    {
        //创建柱
        QBarSet* set = new QBarSet(i._name);
        //设置字体
        set->setLabelFont(fontText);
        //设置背景色
        set->setBrush(i._brushColor);
        //设置边框色
        set->setBorderColor(i._borderColor);
        //设置值
        set->append(i._value);
        //添加
        barSet->append(set);
    }
    return barSet;
}
