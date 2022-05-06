#include <QHBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QDebug>

#include "MoldProTableView.h"
#include "MoldProModelDelegate.h"

MoldProTableView::MoldProTableView(QWidget* parent/* = nullptr*/)
    :QTableView(parent)
{
    this->setMouseTracking(true);
    const QStringList horHeadList = (QStringList() << "序号" << "模具编号" << "版本号" << "类型"<< "状态" << "产品名称" << "计划交期" << "当前进度");
    MoldProTableModel* tableModel = new MoldProTableModel(this);
    tableModel->setObjectName("Model");
    MoldProModelDelegate* tableDelegate = new MoldProModelDelegate(this);
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
    this->setColumnWidth(2,55);
    this->setColumnWidth(3,55);
    this->setColumnWidth(4,60);
    this->setColumnWidth(5,60);
    this->setColumnWidth(6,90);
    this->setColumnWidth(7,130);

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


//    this->connect(this->verticalScrollBar(),&QScrollBar::valueChanged,this,[=](int value){
//        if(value + 13 < _max)
//        {
//            if(value == this->verticalScrollBar()->maximum())
//            {
//                _row += 1;
//                emit RefrushData(_row);
//            }
//        }
//    });

    //设置行列表头无法点击
    this->setCornerButtonEnabled(false);
    this->horizontalHeader()->setSectionsClickable(false);

}

MoldProTableView::~MoldProTableView()
{

}

void MoldProTableView::Set_Model_Data(QList<QStringList> data,QList<QVariantList> list)
{
    MoldProTableModel* tableModel = this->findChild<MoldProTableModel*>("Model");
    tableModel->PushBackData(data,list);
}



#if 0
QString MoldProTableView::Get_ModelData(const int row, const int Col) const
{
    MoldProTableModel* tableModel = this->findChild<MoldProTableModel*>("Model");
    const QModelIndex index = tableModel->index(row,Col);
    const QString value = this->model()->data(index).toString();

    return value;
}
void MoldProTableView::Pop_Model_Data()
{
    this->verticalScrollBar()->setValue(0);
    MoldProTableModel* tableModel = this->findChild<MoldProTableModel*>("Model");
    tableModel->PopBackData();
    _row = 0;
}
void MoldProTableView::mousePressEvent(QMouseEvent *event)
{
    MoldProModelDelegate* tableDelegate = this->findChild<MoldProModelDelegate*>("Delegate");
    MoldProTableModel* tableModel = this->findChild<MoldProTableModel*>("Model");
    int row = indexAt(event->pos()).row();
    if(row >= 0)
    {
        tableDelegate->Set_ClickedRow(row);
    }
    else
    {
        tableDelegate->Set_ClickedRow(-1);
    }
    tableModel->RefrushModelData();


    return QTableView::mousePressEvent(event);
}
#endif

#if 0
void ClickedRow(int Row);
void MoldProTableView::ClickedRow(int Row)
{
    const QModelIndex index = this->model()->index(Row,0);
    this->clicked(index);
}

#if 0
void ChangePaint(QString,QString,QString);
bool Get_RowInfo(QStringList&);
bool MoldProTableView::Get_RowInfo(QStringList& value)
{
    DBDataModelDelegate* tableDelegate = this->findChild<DBDataModelDelegate*>("Delegate");
    MoldProTableModel* tableModel = this->findChild<MoldProTableModel*>("Model");
    const int ClickedRow = tableDelegate->Get_ClickedRow();
    if(ClickedRow == -1)
    {
        return false;
    }
#if 0
    const QModelIndex nameIndex = tableModel->index(ClickedRow,7);
    const QModelIndex codeIndex = tableModel->index(ClickedRow,9);
    const QModelIndex TypeIndex = tableModel->index(ClickedRow,8);
    //层位
    const QModelIndex DiskIndex = tableModel->index(ClickedRow,2);
    const QModelIndex WorkIndex = tableModel->index(ClickedRow,3);
    const QModelIndex ResultIndex = tableModel->index(ClickedRow,10);
    const QModelIndex ActionIndex = tableModel->index(ClickedRow,6);
    const QModelIndex TimeIndex = tableModel->index(ClickedRow,14);

    const QString nameValue = this->model()->data(nameIndex).toString();
    const QString codeValue = this->model()->data(codeIndex).toString();
    const QString typeValue = this->model()->data(TypeIndex).toString();
    const QString diskValue = this->model()->data(DiskIndex).toString();
    const QString workValue = this->model()->data(WorkIndex).toString();
    const QString resultValue = this->model()->data(ResultIndex).toString();
    const QString actionValue = this->model()->data(ActionIndex).toString();
    const QString timeValue = this->model()->data(TimeIndex).toString();
#endif

    const QString nameValue = Get_ModelData(ClickedRow,7);
    const QString codeValue = Get_ModelData(ClickedRow,9);
    const QString typeValue = Get_ModelData(ClickedRow,8);
    const QString frameValue = Get_ModelData(ClickedRow,1);
    const QString diskValue = Get_ModelData(ClickedRow,2);
    const QString workValue = Get_ModelData(ClickedRow,3);
    const QString resultValue = Get_ModelData(ClickedRow,10);
    const QString actionValue = Get_ModelData(ClickedRow,6);
    const QString timeValue = Get_ModelData(ClickedRow,14);

    value << nameValue << codeValue << typeValue << frameValue << diskValue << workValue << resultValue << actionValue << timeValue;

    return true;
}
#endif

#endif
