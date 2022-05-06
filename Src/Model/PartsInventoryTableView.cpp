#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QDebug>

#include "PartsInventoryModelDelegate.h"
#include "PartsInventoryTableView.h"

PartsInventoryTableView::PartsInventoryTableView(QWidget* parent/* = nullptr*/)
    :QTableView(parent)
{
    this->setMouseTracking(true);
    const QStringList horHeadList = (QStringList() << "序号" << "模具编号" << "品名" << "规格"<< "材料" << "尺寸" << "目标存库" << "当前库存" << "库存百分比" << "预警");
    PartsInventoryTableModel* tableModel = new PartsInventoryTableModel(this);
    tableModel->setObjectName("Model");
    PartsInventoryModelDelegate* tableDelegate = new PartsInventoryModelDelegate(this);
    tableDelegate->setObjectName("Delegate");
    this->setModel(tableModel);
    this->setItemDelegate(tableDelegate);

    tableModel->setHorizontalHeaderList(horHeadList);
    this->setSelectionBehavior( QAbstractItemView::SelectRows);


    //显示子网格
    this->setShowGrid(true);
    //取消进度条
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //设置默认高度
    this->verticalHeader()->setDefaultSectionSize(23);
    //设置表头高度
    this->horizontalHeader()->setFixedHeight(25);

    this->setColumnWidth(0,40);
    this->setColumnWidth(1,70);
    this->setColumnWidth(2,70);
    this->setColumnWidth(3,70);
    this->setColumnWidth(4,70);
    this->setColumnWidth(5,75);
    this->setColumnWidth(6,75);
    this->setColumnWidth(7,75);
    this->setColumnWidth(8,75);
    this->setColumnWidth(9,200);

    this->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    this->verticalHeader()->hide();

    this->horizontalHeader()->setStyleSheet("QHeaderView::section "
                                            "{"
                                            "color:rgb(0,170,190);"
                                            "background-color:rgb(48,48,88);"
                                            "border-left:none;"
                                            "border-bottom:1px solid rgb(40,40,40,150);"
                                            "border-top:1px solid rgb(40,40,40,150);"
                                            "border-right:1px solid rgb(40,40,40,150);}");
    this->setStyleSheet("background-color:rgb(48,48,88);"
                        "border:none;");
    this->setCornerButtonEnabled(false);
    this->horizontalHeader()->setSectionsClickable(false);

}

PartsInventoryTableView::~PartsInventoryTableView()
{

}

void PartsInventoryTableView::Set_Model_Data(QList<QStringList> data,QList<QVariantList> list)
{
    PartsInventoryTableModel* tableModel = this->findChild<PartsInventoryTableModel*>("Model");
    tableModel->PushBackData(data,list);
}

