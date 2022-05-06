#include "LoadDistributionModelDelegate.h"
#include <QPainter>
#include <QDebug>

LoadDistributionProModelItem::LoadDistributionProModelItem()
{

}

LoadDistributionProModelItem::~LoadDistributionProModelItem()
{

}


LoadDistributionTableModel::LoadDistributionTableModel(QObject* parent)
    :QAbstractTableModel (parent)
{

}

LoadDistributionTableModel::~LoadDistributionTableModel()
{

}

#if 0
Qt::ItemFlags LoadDistributionTableModel::flags(const QModelIndex &index) const
{
    if(index.column() != 0)
        return Qt::ItemIsEditable | Qt::ItemIsSelectable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}
#endif

int LoadDistributionTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return Ary_row_List.size();
}
int LoadDistributionTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 8;
}
QVariant LoadDistributionTableModel::data(const QModelIndex &index, int role) const
{
    if(Ary_row_List.size() < 1 || !index.isValid())
        return QVariant();
    if  (role == Qt::TextAlignmentRole)
         {
             return  int (Qt::AlignHCenter | Qt::AlignVCenter);
         }
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if(index.column() == 0)
        {
            return Ary_row_List.at(index.row()).GetNumNo();
        }
        else if(index.column() == 1)
        {
            return Ary_row_List.at(index.row()).GetTime1();
        }
        else if(index.column() == 2)
        {
            return Ary_row_List.at(index.row()).GetTime2();
        }
        else if(index.column() == 3)
        {
            return Ary_row_List.at(index.row()).GetTime3();
        }
        else if(index.column() == 4)
        {
            return Ary_row_List.at(index.row()).GetTime4();
        }
        else if(index.column() == 5)
        {
            return Ary_row_List.at(index.row()).GetTime5();
        }
        else if(index.column() == 6)
        {
            return Ary_row_List.at(index.row()).GetTime6();
        }
        else if(index.column() == 7)
        {
            return Ary_row_List.at(index.row()).GetTime7();
        }
    }
    return QVariant();
}
QVariant LoadDistributionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if(orientation == Qt::Horizontal)
        {
            if(horizontal_header_list.size() > section)
                return horizontal_header_list[section];
            else
                return QVariant();
        }
        if(orientation == Qt::Vertical)
        {
            if(vertical_header_list.size() > section)
                return vertical_header_list[section];
            else
                return QVariant();
        }
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

void LoadDistributionTableModel::setHorizontalHeaderList(QStringList hHeadList)
{
    horizontal_header_list = hHeadList;
}

void LoadDistributionTableModel::setVerticalHeaderList(QStringList VHeadList)
{
    vertical_header_list = VHeadList;
}

void LoadDistributionTableModel::RefrushModel(LoadDistributionProModelItem item)
{
    const int count = Ary_row_List.size();
    beginInsertRows(QModelIndex(), count, count);
    Ary_row_List.push_back(item);
    endInsertRows();
}

bool LoadDistributionTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(value);
    if(Ary_row_List.size() < 1 || !index.isValid())
        return false;
    if  (role == Qt::TextAlignmentRole)
         {
             return int (Qt::AlignHCenter | Qt::AlignVCenter);
         }
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
#if 0
        if(index.column() == 0)
        {
            Ary_row_List->at(index.row())->Set_Name(value.toString());
        }
        if(index.column() == 1)
        {
            Ary_row_List->at(index.row())->Set_FirstVal(value.toString());
        }
        else if(index.column() == 2)
        {
            Ary_row_List->at(index.row())->Set_SecondVal(value.toString());
        }
        else if(index.column() == 3)
        {
            Ary_row_List->at(index.row())->Set_ThirdVal(value.toString());
        }
        else if(index.column() == 4)
        {
            Ary_row_List->at(index.row())->Set_FourVal(value.toString());
        }
        emit ModityData(index.row(),index.column(),value);
#endif

        return true;
    }
    return false;
}

void LoadDistributionTableModel::PushBackData(QList<QStringList> list)
{
    if(list.size() <= 0)
    {
        return;
    }
    if(list.at(0).size() < 7)
    {
        return;
    }
    for(int i = 0; i < list.size(); i++)
    {
        LoadDistributionProModelItem Item;
        const QString null = "";
        Item.SetNumNo(list.at(i).at(0).isEmpty() ? null : list.at(i).at(0));
        Item.SetTime1(list.at(i).at(1).isEmpty() ? null : list.at(i).at(1));
        Item.SetTime2(list.at(i).at(2).isEmpty() ? null : list.at(i).at(2));
        Item.SetTime3(list.at(i).at(3).isEmpty() ? null : list.at(i).at(3));
        Item.SetTime4(list.at(i).at(4).isEmpty() ? null : list.at(i).at(4));
        Item.SetTime5(list.at(i).at(5).isEmpty() ? null : list.at(i).at(5));
        Item.SetTime6(list.at(i).at(6).isEmpty() ? null : list.at(i).at(6));
        Item.SetTime7(list.at(i).at(7).isEmpty() ? null : list.at(i).at(7));
        Ary_row_List.push_back(Item);
    }

    RefrushModelData();
}

//void LoadDistributionTableModel::PopBackData()
//{
//    for(int i = 0; i < Ary_row_List.size(); i++)
//    {
//        Ary_row_List.removeAt(0);
//    }
//    Ary_row_List.clear();
//    RefrushModelData();
//}

void LoadDistributionTableModel::RefrushModelData()
{
    this->beginResetModel();

    this->endResetModel();
}

LoadDistributionModelDelegate::LoadDistributionModelDelegate(QObject *parent)
    :QItemDelegate (parent)
{

}

LoadDistributionModelDelegate::~LoadDistributionModelDelegate()
{

}

void LoadDistributionModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 0 || index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4
        || index.column() == 5 || index.column() == 6 || index.column() == 7)
    {
        painter->setPen(QPen(QColor(255,255,255)));
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
#if 0
    else if(index.column() == 1)
    {
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
    else if(index.column() == 2)
    {
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
    else if(index.column() == 3)
    {
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
    else if(index.column() == 4)
    {
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
#endif
    else
    {
        QItemDelegate::paint(painter,option,index);
    }
}

