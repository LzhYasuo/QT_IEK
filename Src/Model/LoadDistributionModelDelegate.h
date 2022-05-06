#ifndef _LOAD_DISTRIBUTION_MODEL_DELEGATE_H_
#define _LOAD_DISTRIBUTION_MODEL_DELEGATE_H_

#include <QObject>
#include <QAbstractTableModel>
#include <QItemDelegate>

class LoadDistributionProModelItem
{
public:
    LoadDistributionProModelItem();
    ~LoadDistributionProModelItem();

    QString GetNumNo() const
    {
        return _numNo;
    }
    void SetNumNo(const QString numNo)
    {
        _numNo = numNo;
    }

    QString GetTime1() const
    {
        return _time1;
    }
    void SetTime1(const QString time)
    {
        _time1 = time;
    }

    QString GetTime2() const
    {
        return _time2;
    }
    void SetTime2(const QString time)
    {
        _time2 = time;
    }

    QString GetTime3() const
    {
        return _time3;
    }
    void SetTime3(const QString time)
    {
        _time3 = time;
    }

    QString GetTime4() const
    {
        return _time4;
    }
    void SetTime4(const QString time)
    {
        _time4 = time;
    }

    QString GetTime5() const
    {
        return _time1;
    }
    void SetTime5(const QString time)
    {
        _time1 = time;
    }

    QString GetTime6() const
    {
        return _time1;
    }
    void SetTime6(const QString time)
    {
        _time1 = time;
    }

    QString GetTime7() const
    {
        return _time1;
    }
    void SetTime7(const QString time)
    {
        _time1 = time;
    }

private:
    QString _numNo;
    QString _time1;
    QString _time2;
    QString _time3;
    QString _time4;
    QString _time5;
    QString _time6;
    QString _time7;
};

class LoadDistributionTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    LoadDistributionTableModel(QObject* parent = nullptr);
    ~LoadDistributionTableModel();

//    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);
    void RefrushModel(LoadDistributionProModelItem);
    void setHorizontalHeaderList(QStringList hHeadList);
    void setVerticalHeaderList(QStringList VHeadList);
    void RefrushModelData();
    void PushBackData(QList<QStringList>);
//    void PopBackData();

signals:
    void ModityData(int,int,QVariant);
private:
    QStringList horizontal_header_list;
    QStringList vertical_header_list;
    QList<LoadDistributionProModelItem> Ary_row_List;
};

class LoadDistributionModelDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit LoadDistributionModelDelegate(QObject *parent = nullptr);
    virtual ~LoadDistributionModelDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:
};


#endif //_LOAD_DISTRIBUTION_MODEL_DELEGATE_H_
