#ifndef _PUB_CSS_H_
#define _PUB_CSS_H_

#include <QObject>
#include <QMap>

enum CSS
{
    SMALLWINDOW_LEFTBUTTONSTYLE,
    SMALLWINDOW_TITLELABEL,
    DEVICEMONITORING_BOTTOMLABEL,

};

class PubCss : public QObject
{
public:
    static PubCss* Get();
    QString GetStr(CSS) const;

private:
    PubCss(QObject* obj = nullptr);
    ~PubCss();

    QMap<CSS,QString> _mapList;
};


#endif //_PUB_CSS_H_
