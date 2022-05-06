#ifndef PARTS_INVENTORY_TABLE_VIEW_H_
#define PARTS_INVENTORY_TABLE_VIEW_H_

#include <QWidget>
#include <QTableView>

class QTableView;
class PartsInventoryTableView : public QTableView
{
    Q_OBJECT
public:
    PartsInventoryTableView(QWidget* parent = nullptr);
    ~PartsInventoryTableView();

    void Set_Model_Data(QList<QStringList> data,QList<QVariantList> list);

    int Get_Row() const
    {
        return _row;
    }
    void Set_Max(int max)
    {
        _max = max;
    }
signals:
    void TableModityData(int,int,QVariant);
    void RefrushData(int Row);

private:
    int _row = 0;
    int _max = 0;
};


#endif //PARTS_INVENTORY_TABLE_VIEW_H_
