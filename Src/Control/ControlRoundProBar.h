#ifndef _CONTROL_ROUND_PRO_BAR_H_
#define _CONTROL_ROUND_PRO_BAR_H_

#include <QWidget>

class ContorlRoundProBar : public QWidget
{
    Q_OBJECT
public:
    ContorlRoundProBar(QWidget* parent = nullptr);
    ~ContorlRoundProBar();

    Q_PROPERTY( double  oldproprortion  READ  GetOldproprortion  WRITE  SetOldproprortion);
    void ChangeValue();

    void SetOldproprortion(double d);
    double GetOldproprortion();
private:
    void paintEvent(QPaintEvent *event);

    void DrawOotRound(QPainter*);
    void DrawInRound(QPainter*);
    void DrawOutRound1(QPainter*);
    void DrawText(QPainter*);

private:
    double oldproprortion = 0.0;
    double proportion = 0.0;
    QString str = "";
};


#endif //_CONTROL_ROUND_PRO_BAR_H_
