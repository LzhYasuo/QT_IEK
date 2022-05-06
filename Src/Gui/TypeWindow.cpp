#include "QVBoxLayout"
#include "QPushButton"
#include "QStackedWidget"

#include "TypeWindow.h"
#include "../Pub/PubCss.h"

#include "../Chart/ChartLine.h"
#include "../Chart/ChartCurve.h"
#include "../Chart/ChartBar.h"

TypeWindow::TypeWindow(QWidget *parent)
    :BaseWidget(parent)
{
    this->Init();
    this->setObjectName("TypeWindow");
    this->setStyleSheet("#TypeWindow{background-color:rgb(5,30,83);}");
}

TypeWindow::~TypeWindow()
{

}

QPushButton* TypeWindow::GetLeftButton(QString name)
{
    const QString css = PubCss::Get()->GetStr(SMALLWINDOW_LEFTBUTTONSTYLE);
    QPushButton* btn = InitButton(name,0,30,css);

    return btn;
}

void TypeWindow::Init()
{
    this->setFixedSize(980,610);
    QHBoxLayout* mLayout = InitHLayout();

    QWidget* leftWidget = new QWidget();
    leftWidget->setObjectName("leftWidget");
    leftWidget->setStyleSheet("#leftWidget{background-color:rgb(4,46,106);}");
    leftWidget->setFixedWidth(110);
    QVBoxLayout* leftLayout = InitVLayout(5);

    QPushButton* btn1 = GetLeftButton("标准折线");
    QPushButton* btn2 = GetLeftButton("标准曲线");
    QPushButton* btn3 = GetLeftButton("标准柱状");
    QPushButton* btn4 = GetLeftButton("柱状堆积");
    QPushButton* btn5 = GetLeftButton("柱状分组");
    QPushButton* btn6 = GetLeftButton("横状柱状");
    QPushButton* btn7 = GetLeftButton("横装堆积");
    QPushButton* btn8 = GetLeftButton("横装分组");
    QPushButton* btn9 = GetLeftButton("数据转换");
    QPushButton* btn10 = GetLeftButton("平滑曲线");
    QPushButton* btn11 = GetLeftButton("系统设置");

    leftLayout->addWidget(btn1);
    leftLayout->addWidget(btn2);
    leftLayout->addWidget(btn3);
    leftLayout->addWidget(btn4);
    leftLayout->addWidget(btn5);
    leftLayout->addWidget(btn6);
    leftLayout->addWidget(btn7);
    leftLayout->addWidget(btn8);
    leftLayout->addWidget(btn9);
    leftLayout->addWidget(btn10);
    leftLayout->addWidget(btn11);
    leftLayout->addStretch();
    leftWidget->setLayout(leftLayout);

    QWidget* rightWidget = new QWidget();
    QHBoxLayout* rightLayout = InitHLayout();
    QStackedWidget* mSWidget = new QStackedWidget();

    QWidget* ChartLine = InitWidget(CHARTLINE);
    QWidget* ChartCurve = InitWidget(CHARTCURVE);
    QWidget* ChartBar1 = InitWidget(CHARTBAR);
    QWidget* ChartBar2 = InitWidget(CHARTBAR1);
    QWidget* ChartBar3 = InitWidget(CHARTBAR2);
    QWidget* ChartBar4 = InitWidget(CHARTBAR3);
    QWidget* ChartBar5 = InitWidget(CHARTBAR4);
    QWidget* ChartBar6 = InitWidget(CHARTBAR5);

    mSWidget->addWidget(ChartLine);
    mSWidget->addWidget(ChartCurve);
    mSWidget->addWidget(ChartBar1);
    mSWidget->addWidget(ChartBar2);
    mSWidget->addWidget(ChartBar3);
    mSWidget->addWidget(ChartBar4);
    mSWidget->addWidget(ChartBar5);
    mSWidget->addWidget(ChartBar6);

    this->connect(btn1,&QPushButton::clicked,this,[=](){
        mSWidget->setCurrentIndex(0);
    });
    this->connect(btn2,&QPushButton::clicked,this,[=](){
        mSWidget->setCurrentIndex(1);
    });
    this->connect(btn3,&QPushButton::clicked,this,[=](){
        mSWidget->setCurrentIndex(2);
    });
    this->connect(btn4,&QPushButton::clicked,this,[=](){
        mSWidget->setCurrentIndex(3);
    });
    this->connect(btn5,&QPushButton::clicked,this,[=](){
       mSWidget->setCurrentIndex(4);
    });
    this->connect(btn6,&QPushButton::clicked,this,[=](){
       mSWidget->setCurrentIndex(5);
    });
    this->connect(btn7,&QPushButton::clicked,this,[=](){
       mSWidget->setCurrentIndex(6);
    });
    this->connect(btn8,&QPushButton::clicked,this,[=](){
        mSWidget->setCurrentIndex(7);
    });

    rightLayout->addWidget(mSWidget);
    rightWidget->setLayout(rightLayout);
    mLayout->addWidget(leftWidget);
    mLayout->addWidget(rightWidget);
    this->setLayout(mLayout);
}

QWidget *TypeWindow::InitWidget(TypeWindowModel index)
{
    QWidget* Widget = nullptr;
    switch (index)
    {
        case CHARTLINE:
        {
            QWidget* mWidget = new QWidget();
            QHBoxLayout* mLayout = InitHLayout();

            ChartLine* line = new ChartLine();
            ChartPar cPar = line->GetPar(CCHARTLINE);
            AxisPar aPar = line->GetPar(ACHARTLINE);
            QList<LinePar> lPar = line->GetLPar(LCHARTLINEVALUE);
            line->Set(cPar);
            line->Set(aPar);
            line->Init(lPar);

            mLayout->addWidget(line);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTCURVE:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout(7);

            ChartCurve* curve1 = new ChartCurve();
            ChartPar cPar1 = curve1->GetPar(CCHARTCURVE1);
            AxisPar aPar1 = curve1->GetPar(ACHARTCURVE1);
            QList<CurvePar> cuPar1 = curve1->GetCuPar(CUCHARTCURVE1);

            curve1->Set(cPar1);
            curve1->Set(aPar1);
            curve1->Init(cuPar1);

            ChartCurve* curve2 = new ChartCurve();
            ChartPar cPar2 = curve2->GetPar(CCHARTCURVE2);
            AxisPar aPar2 = curve2->GetPar(ACHARTCURVE2);
            QList<CurvePar> cuPar2 = curve2->GetCuPar(CUCHARTCURVE2);

            curve2->Set(cPar2);
            curve2->Set(aPar2);
            curve2->Init(cuPar2);

            ChartCurve* curve3 = new ChartCurve();
            ChartPar cPar3 = curve3->GetPar(CCHARTCURVE3);
            AxisPar aPar3 = curve3->GetPar(ACHARTCURVE3);
            QList<CurvePar> cuPar3 = curve3->GetCuPar(CUCHARTCURVE3);

            curve3->SetPointShow(true);
            curve3->Set(cPar3);
            curve3->Set(aPar3);
            curve3->Init(cuPar3);

            mLayout->addWidget(curve1);
            mLayout->addWidget(curve2);
            mLayout->addWidget(curve3);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = new QVBoxLayout();

            ChartBar* bar1 = new ChartBar(1);
            ChartPar cPar1 = bar1->GetPar(CCHARTBAR1);
            AxisPar aPar1 = bar1->GetPar(ACHARTBAR1);
            QList<BarPer> bPar1 = bar1->GetBPar(BCHARTBAR1VALUE1);

            bar1->Set(cPar1);
            bar1->Set(aPar1);
            bar1->Init(bPar1);

            ChartBar* bar2 = new ChartBar(1);
            ChartPar cPar2 = bar2->GetPar(CCHARTBAR1);
            AxisPar aPar2 = bar2->GetPar(ACHARTBAR1);
            QList<BarPer> bPar2 = bar2->GetBPar(BCHARTBAR1VALUE1);

            bar2->Set(cPar2);
            bar2->Set(aPar2);
            bar2->Init(bPar2);

            mLayout->addWidget(bar1);
            mLayout->addWidget(bar2);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR1:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout();

            ChartBar* bar3 = new ChartBar(2);
            ChartPar cPar3 = bar3->GetPar(CCHARTBAR3);
            AxisPar aPar3 = bar3->GetPar(ACHARTBAR3);
            QList<BarPer> bPar3 = bar3->GetBPar(BCHARTBAR2VALUE1);

            bar3->Set(cPar3);
            bar3->Set(aPar3);
            bar3->Init(bPar3);

            ChartBar* bar4 = new ChartBar(2);
            ChartPar cPar4 = bar4->GetPar(CCHARTBAR4);
            AxisPar aPar4 = bar4->GetPar(ACHARTBAR4);
            QList<BarPer> bPar4 = bar4->GetBPar(BCHARTBAR2VALUE2);

            bar4->Set(cPar4);
            bar4->Set(aPar4);
            bar4->Init(bPar4);

            mLayout->addWidget(bar3);
            mLayout->addWidget(bar4);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR2:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout();

            ChartBar* bar5 = new ChartBar(3);
            ChartPar cPar5 = bar5->GetPar(CCHARTBAR5);
            AxisPar aPar5 = bar5->GetPar(ACHARTBAR5);
            QList<BarPer> bPar5 = bar5->GetBPar(BCHARTBAR3VALUE1);

            bar5->Set(cPar5);
            bar5->Set(aPar5);
            bar5->Init(bPar5);

            ChartBar* bar6 = new ChartBar(3);
            ChartPar cPar6 = bar6->GetPar(CCHARTBAR6);
            AxisPar aPar6 = bar6->GetPar(ACHARTBAR6);
            QList<BarPer> bPar6 = bar6->GetBPar(BCHARTBAR3VALUE2);

            bar6->Set(cPar6);
            bar6->Set(aPar6);
            bar6->Init(bPar6);

            mLayout->addWidget(bar5);
            mLayout->addWidget(bar6);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR3:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout();

            ChartBar* bar7 = new ChartBar(4);
            ChartPar cPar7 = bar7->GetPar(CCHARTBAR7);
            AxisPar aPar7 = bar7->GetPar(ACHARTBAR7);
            QList<BarPer> bPar7 = bar7->GetBPar(BCAHRTBAR4VALUE1);

            bar7->Set(cPar7);
            bar7->Set(aPar7);
            bar7->Init(bPar7);

            mLayout->addWidget(bar7);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR4:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout();

            ChartBar* bar8 = new ChartBar(5);
            ChartPar cPar8 = bar8->GetPar(CCHARTBAR8);
            AxisPar aPar8 = bar8->GetPar(ACHARTBAR8);
            QList<BarPer> bPar8 = bar8->GetBPar(BCAHRTBAR5VALUE1);

            bar8->Set(cPar8);
            bar8->Set(aPar8);
            bar8->Init(bPar8);

            ChartBar* bar9 = new ChartBar(5);
            ChartPar cPar9 = bar9->GetPar(CCHARTBAR9);
            AxisPar aPar9 = bar9->GetPar(ACHARTBAR9);
            QList<BarPer> bPar9 = bar9->GetBPar(BCAHRTBAR5VALUE2);

            bar9->Set(cPar9);
            bar9->Set(aPar9);
            bar9->Init(bPar9);

            mLayout->addWidget(bar8);
            mLayout->addWidget(bar9);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
        case CHARTBAR5:
        {
            QWidget* mWidget = new QWidget();
            QVBoxLayout* mLayout = InitVLayout();

            ChartBar* bar10 = new ChartBar(6);
            ChartPar cPar10 = bar10->GetPar(CCHARTBAR10);
            AxisPar aPar10 = bar10->GetPar(ACHARTBAR10);
            QList<BarPer> bPar10 = bar10->GetBPar(BCAHRTBAR6VALUE1);

            bar10->Set(aPar10);
            bar10->Set(cPar10);
            bar10->Init(bPar10);

            mLayout->addWidget(bar10);
            mWidget->setLayout(mLayout);

            Widget = mWidget;
            break;
        }
    }
    return Widget;
}
