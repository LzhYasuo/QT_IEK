#ifndef LOAD_DISTRIBUTION_TABLE_VIEW_H_
#define LOAD_DISTRIBUTION_TABLE_VIEW_H_

#include <QWidget>
#include <QTableView>

class QTableView;
class LoadDistributionTableView : public QTableView
{
    Q_OBJECT
public:
    //SettingFourValTableView(QStringList HorList,int TableMaxNum,int NameWidth,int TableWidth,int DefaultHeight,int TableHeight,QWidget* parent = nullptr);
    LoadDistributionTableView(QWidget* parent = nullptr);
    ~LoadDistributionTableView();

    void Set_Model_Data(QList<QStringList> data);
//    void Pop_Model_Data();
//    QString Get_ModelData(const int row,const int Col) const;
//    void mousePressEvent(QMouseEvent *event);

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


#endif //LOAD_DISTRIBUTION_TABLE_VIEW_H_
