#include "PartsInventoryModelDelegate.h"
#include <QPainter>
#include <QDebug>

PartsInventoryModelItem::PartsInventoryModelItem()
{

}

PartsInventoryModelItem::~PartsInventoryModelItem()
{

}

PartsInventoryTableModel::PartsInventoryTableModel(QObject* parent)
    :QAbstractTableModel (parent)
{

}

PartsInventoryTableModel::~PartsInventoryTableModel()
{

}

#if 0
Qt::ItemFlags PartsInventoryTableModel::flags(const QModelIndex &index) const
{
    if(index.column() != 0)
        return Qt::ItemIsEditable | Qt::ItemIsSelectable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}
#endif

int PartsInventoryTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return Ary_row_List.size();
}
int PartsInventoryTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 10;
}
QVariant PartsInventoryTableModel::data(const QModelIndex &index, int role) const
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
            return Ary_row_List.at(index.row()).GetName();
        }
        else if(index.column() == 3)
        {
            return Ary_row_List.at(index.row()).GetSpecification();
        }
        else if(index.column() == 4)
        {
            return Ary_row_List.at(index.row()).GetMaterial();
        }
        else if(index.column() == 5)
        {
            return Ary_row_List.at(index.row()).GetSize();
        }
        else if(index.column() == 6)
        {
            return Ary_row_List.at(index.row()).GetRepositories();
        }
        else if(index.column() == 7)
        {
            return Ary_row_List.at(index.row()).GetRemainder();
        }
        else if(index.column() == 8)
        {
            return Ary_row_List.at(index.row()).GetPercentage();
        }
        else if(index.column() == 9)
        {
            return Ary_row_List.at(index.row()).GetList();
        }
    }
    return QVariant();
}
QVariant PartsInventoryTableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

void PartsInventoryTableModel::setHorizontalHeaderList(QStringList hHeadList)
{
    horizontal_header_list = hHeadList;
}

void PartsInventoryTableModel::setVerticalHeaderList(QStringList VHeadList)
{
    vertical_header_list = VHeadList;
}

void PartsInventoryTableModel::RefrushModel(PartsInventoryModelItem item)
{
    const int count = Ary_row_List.size();
    beginInsertRows(QModelIndex(), count, count);
    Ary_row_List.push_back(item);
    endInsertRows();
}

bool PartsInventoryTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
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
        return true;
    }
    return false;
}

void PartsInventoryTableModel::PushBackData(QList<QStringList> list,QList<QVariantList> valueList)
{
    if(list.size() <= 0 || valueList.size() <= 0)
    {
        return;
    }
    if(list.at(0).size() < 9)
    {
        return;
    }
    if(list.size() != valueList.size())
    {
        return;
    }
    for(int i = 0; i < list.size(); i++)
    {
        PartsInventoryModelItem Item;
        const QString null = "";
        Item.SetId(list.at(i).at(0).isEmpty() ? null : list.at(i).at(0));
        Item.SetNumNo(list.at(i).at(1).isEmpty() ? null : list.at(i).at(1));
        Item.SetName(list.at(i).at(2).isEmpty() ? null : list.at(i).at(2));
        Item.SetSpecification(list.at(i).at(3).isEmpty() ? null : list.at(i).at(3));
        Item.SetMaterial(list.at(i).at(4).isEmpty() ? null : list.at(i).at(4));
        Item.SetSize(list.at(i).at(5).isEmpty() ? null : list.at(i).at(5));
        Item.SetRepositories(list.at(i).at(6).isEmpty() ? null : list.at(i).at(6));
        Item.SetRemainder(list.at(i).at(7).isEmpty() ? null : list.at(i).at(7));
        Item.SetPercentage(list.at(i).at(8).isEmpty() ? null : list.at(i).at(8));
        Item.SetList(valueList.at(i));
        Ary_row_List.push_back(Item);
    }

    RefrushModelData();
}

//void PartsInventoryTableModel::PopBackData()
//{
//    for(int i = 0; i < Ary_row_List.size(); i++)
//    {
//        Ary_row_List.removeAt(0);
//    }
//    Ary_row_List.clear();
//    RefrushModelData();
//}

void PartsInventoryTableModel::RefrushModelData()
{
    this->beginResetModel();

    this->endResetModel();
}

PartsInventoryModelDelegate::PartsInventoryModelDelegate(QObject *parent)
    :QItemDelegate (parent)
{

}

PartsInventoryModelDelegate::~PartsInventoryModelDelegate()
{

}

void PartsInventoryModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 0 || index.column() == 1 || index.column() == 2 || index.column() == 3 || index.column() == 4
        || index.column() == 5 || index.column() == 6 || index.column() == 7 || index.column() == 8)
    {
        painter->setPen(QPen(QColor(255,255,255)));
        QString mos = index.model()->data(index,Qt::DisplayRole).toString();
        QTextOption o;
        o.setAlignment(Qt::AlignCenter);
        painter->drawText(option.rect,mos,o);
    }
    if(index.column() == 9)
    {
        painter->save();
        painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        QVariantList valueList = index.model()->data(index,Qt::DisplayRole).toList();
        int radius = option.rect.height() / 2;

//        QFont font;
//        font.setPixelSize(option.rect.height() * 0.9);
//        painter->setFont(font);
        const int value1 = valueList.at(0).toInt();
        const int value2 = valueList.at(1).toInt();
        const int sum = value1 + value2;
        const double percent1 = (double)value1 / (double)sum;
        const double percent2 = (double)value2 / (double)sum;
        const int width1 = option.rect.width() * percent1;
        const int width2 = option.rect.width() * percent2;
        const QString text1 = QString("%1%").arg(QString::number(percent1 * 100, 'f', 0));
        const QString text2 = QString("%1%").arg(QString::number(percent2 * 100, 'f', 0));

        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(0,255,0));

        //计算绘制的区域,需要裁剪圆角部分
        QPainterPath clipPath1;
        clipPath1.addRoundedRect(option.rect, radius, radius);
        painter->setClipPath(clipPath1);
        QRect rect1(option.rect.x(), option.rect.y(), width1,option.rect.height());
        painter->drawRect(rect1);
        painter->setPen(QColor(255,255,255));
        painter->drawText(rect1, Qt::AlignCenter, text1);

        painter->setPen(Qt::NoPen);
        painter->setBrush(QColor(255,0,0));

        QPainterPath clipPath2;
        clipPath2.addRoundedRect(option.rect, radius, radius);
        painter->setClipPath(clipPath2);
        QRect rect2(option.rect.x() + width1, option.rect.y(), width2,option.rect.height());
        painter->drawRect(rect2);
        painter->setPen(QColor(255,255,255));
        painter->drawText(rect2, Qt::AlignCenter, text2);
        painter->restore();
    }
//    else
//    {
//        QItemDelegate::paint(painter,option,index);
//    }
}

