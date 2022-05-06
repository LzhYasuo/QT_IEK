#include "MoldProModelDelegate.h"
#include <QPainter>
#include <QDebug>

MoldProModelItem::MoldProModelItem()
{

}

MoldProModelItem::~MoldProModelItem()
{

}

MoldProTableModel::MoldProTableModel(QObject* parent)
    :QAbstractTableModel (parent)
{

}

MoldProTableModel::~MoldProTableModel()
{

}

#if 0
Qt::ItemFlags MoldProTableModel::flags(const QModelIndex &index) const
{
    if(index.column() != 0)
        return Qt::ItemIsEditable | Qt::ItemIsSelectable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}
#endif

int MoldProTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return Ary_row_List.size();
}
int MoldProTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 8;
}
QVariant MoldProTableModel::data(const QModelIndex &index, int role) const
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
            return Ary_row_List.at(index.row()).GetId();
        }
        else if(index.column() == 1)
        {
            return Ary_row_List.at(index.row()).GetNumNo();
        }
        else if(index.column() == 2)
        {
            return Ary_row_List.at(index.row()).GetVersion();
        }
        else if(index.column() == 3)
        {
            return Ary_row_List.at(index.row()).GetType();
        }
        else if(index.column() == 4)
        {
            return Ary_row_List.at(index.row()).GetState();
        }
        else if(index.column() == 5)
        {
            return Ary_row_List.at(index.row()).GetName();
        }
        else if(index.column() == 6)
        {
            return Ary_row_List.at(index.row()).GetTime();
        }
        else if(index.column() == 7)
        {
            return Ary_row_List.at(index.row()).GetList();
        }
    }
    return QVariant();
}
QVariant MoldProTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

void MoldProTableModel::setHorizontalHeaderList(QStringList hHeadList)
{
    horizontal_header_list = hHeadList;
}

void MoldProTableModel::setVerticalHeaderList(QStringList VHeadList)
{
    vertical_header_list = VHeadList;
}

void MoldProTableModel::RefrushModel(MoldProModelItem item)
{
    const int count = Ary_row_List.size();
    beginInsertRows(QModelIndex(), count, count);
    Ary_row_List.push_back(item);
    endInsertRows();
}

bool MoldProTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

void MoldProTableModel::PushBackData(QList<QStringList> list,QList<QVariantList> valueList)
{
    if(list.size() <= 0 || valueList.size() <= 0)
    {
        return;
    }
    if(list.at(0).size() < 7)
    {
        return;
    }
    if(list.size() != valueList.size())
    {
        return;
    }
    for(int i = 0; i < list.size(); i++)
    {
        MoldProModelItem Item;
        const QString null = "";
        Item.SetId(list.at(i).at(0).isEmpty() ? null : list.at(i).at(0));
        Item.SetNumNo(list.at(i).at(1).isEmpty() ? null : list.at(i).at(1));
        Item.SetVersion(list.at(i).at(2).isEmpty() ? null : list.at(i).at(2));
        Item.SetType(list.at(i).at(3).isEmpty() ? null : list.at(i).at(3));
        Item.SetState(list.at(i).at(4).isEmpty() ? null : list.at(i).at(4));
        Item.SetName(list.at(i).at(5).isEmpty() ? null : list.at(i).at(5));
        Item.SetTime(list.at(i).at(6).isEmpty() ? null : list.at(i).at(6));
        Item.SetList(valueList.at(i));
        Ary_row_List.push_back(Item);
    }

    RefrushModelData();
}

//void MoldProTableModel::PopBackData()
//{
//    for(int i = 0; i < Ary_row_List.size(); i++)
//    {
//        Ary_row_List.removeAt(0);
//    }
//    Ary_row_List.clear();
//    RefrushModelData();
//}

void MoldProTableModel::RefrushModelData()
{
    this->beginResetModel();

    this->endResetModel();
}

MoldProModelDelegate::MoldProModelDelegate(QObject *parent)
    :QItemDelegate (parent)
{

}

MoldProModelDelegate::~MoldProModelDelegate()
{

}

void MoldProModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 0 || index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4
        || index.column() == 5 || index.column() == 6)
    {
//        painter->setPen(QPen(QColor(0,0,0)));
//        if(index.row() == ClickedRow)
//        {
//            painter->setBrush(QColor(0,0,50));
//            painter->setPen(QPen(QColor(255,255,255)));
//            painter->drawRect(option.rect);
//        }
        painter->setPen(QPen(QColor(255,255,255)));
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
    else if(index.column() == 7)
    {
        QVariantList list = index.model()->data(index,Qt::DisplayRole).toList();
        int total = 0;
        for(auto& i : list)
        {
            total += i.toInt();
        }
        float pro = (float)option.rect.width() / float(total);
        QList<float> proList;
        for(int i = 0; i < list.size(); i++)
        {
            const float Pro = list.at(i).toFloat() * pro;
            proList.push_back(Pro);
        }
        QList<QColor> colorList = QList<QColor>() << QColor(0,176,180) << QColor(255,192,0) << QColor(214,77,84);
        float proX = 0.0f;
        for(int i = 0; i <proList.size(); i++)
        {
            painter->setPen(QPen(colorList.at(i)));
            painter->setBrush(QBrush(colorList.at(i)));
            const int height = 10;
            int y = option.rect.y() +  (option.rect.height() / 2)  - (height / 2);
            painter->drawRect(option.rect.x() + proX,y,proList.at(i),height);
            proX += proList.at(i);
        }
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

