#ifndef MOLD_PRO_MODEL_DELEGATE_H_
#define MOLD_PRO_MODEL_DELEGATE_H_

#include <QObject>
#include <QAbstractTableModel>
#include <QItemDelegate>

class MoldProModelItem
{
public:
    MoldProModelItem();
    ~MoldProModelItem();

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

    QString GetVersion() const
    {
        return _version;
    }
    void SetVersion(QString version)
    {
        _version = version;
    }

    QString GetType() const
    {
        return _type;
    }
    void SetType(QString type)
    {
        _type = type;
    }

    QString GetState() const
    {
        return _state;
    }
    void SetState(QString state)
    {
        _state = state;
    }

    QString GetName() const
    {
        return _name;
    }
    void SetName(QString name)
    {
        _name = name;
    }

    QString GetTime() const
    {
        return _time;
    }
    void SetTime(QString time)
    {
        _time = time;
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
    QString _version;
    QString _type;
    QString _state;
    QString _name;
    QString _time;
    QVariantList _progressList;
};

class MoldProTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    MoldProTableModel(QObject* parent = nullptr);
    ~MoldProTableModel();

//    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
    void RefrushModel(MoldProModelItem);
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
    QList<MoldProModelItem> Ary_row_List;
};

class MoldProModelDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MoldProModelDelegate(QObject *parent = nullptr);
    virtual ~MoldProModelDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:
};


#endif //MOLD_PRO_MODEL_DELEGATE_H_
