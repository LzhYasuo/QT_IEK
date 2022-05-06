#ifndef PARTS_INVENTORY_MODEL_DELEGATE_H_
#define PARTS_INVENTORY_MODEL_DELEGATE_H_

#include <QObject>
#include <QAbstractTableModel>
#include <QItemDelegate>

class PartsInventoryModelItem
{
public:
    PartsInventoryModelItem();
    ~PartsInventoryModelItem();

    QString GetId() const
    {
        return _id;
    }
    void SetId(QString id)
    {
        _id = id;
    }

    QString GetNumNo() const
    {
        return _numNo;
    }
    void SetNumNo(const QString numNo)
    {
        _numNo = numNo;
    }

    QString GetName() const
    {
        return _name;
    }
    void SetName(QString name)
    {
        _name = name;
    }

    QString GetSpecification() const
    {
        return _specification;
    }
    void SetSpecification(QString specification)
    {
        _specification = specification;
    }

    QString GetMaterial() const
    {
        return _material;
    }
    void SetMaterial(QString Material)
    {
        _material = Material;
    }

    QString GetSize() const
    {
        return _size;
    }
    void SetSize(QString size)
    {
        _size = size;
    }

    QString GetRepositories() const
    {
        return _repositories;
    }
    void SetRepositories(QString Repositories)
    {
        _repositories = Repositories;
    }

    QString GetRemainder() const
    {
        return _repositories;
    }
    void SetRemainder(QString Remainder)
    {
        _remainder = Remainder;
    }

    QString GetPercentage() const
    {
        return _percentage;
    }
    void SetPercentage(QString Percentage)
    {
        _percentage = Percentage;
    }

    QVariantList GetList() const
    {
        return _progressList;
    }
    void SetList(QVariantList list)
    {
        _progressList = list;
    }

private:
    QString _id;
    QString _numNo;
    QString _name;
    QString _specification;
    QString _material;
    QString _size;
    QString _repositories;
    QString _remainder;
    QString _percentage;
    QVariantList _progressList;
};

class PartsInventoryTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    PartsInventoryTableModel(QObject* parent = nullptr);
    ~PartsInventoryTableModel();

//    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
    void RefrushModel(PartsInventoryModelItem);
    void setHorizontalHeaderList(QStringList hHeadList);
    void setVerticalHeaderList(QStringList VHeadList);
    void RefrushModelData();
    void PushBackData(QList<QStringList>,QList<QVariantList>);
    void PopBackData();

signals:
    void ModityData(int,int,QVariant);
private:
    QStringList horizontal_header_list;
    QStringList vertical_header_list;
    QList<PartsInventoryModelItem> Ary_row_List;
};

class PartsInventoryModelDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit PartsInventoryModelDelegate(QObject *parent = nullptr);
    virtual ~PartsInventoryModelDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:
};


#endif //PARTS_INVENTORY_MODEL_DELEGATE_H_
