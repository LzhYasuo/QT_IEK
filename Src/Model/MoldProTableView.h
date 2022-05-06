#ifndef MOLD_PRO_TABLE_VIEW
#define MOLD_PRO_TABLE_VIEW

#include <QWidget>
#include <QTableView>

class QTableView;
class MoldProTableView : public QTableView
{
    Q_OBJECT
public:
    //SettingFourValTableView(QStringList HorList,int TableMaxNum,int NameWidth,int TableWidth,int DefaultHeight,int TableHeight,QWidget* parent = nullptr);
    MoldProTableView(QWidget* parent = nullptr);
    ~MoldProTableView();

    void Set_Model_Data(QList<QStringList> data,QList<QVariantList> list);
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


#endif //MOLD_PRO_TABLE_VIEW
