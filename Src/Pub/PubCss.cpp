#include "PubCss.h"

#define GETSTR(x) #x

PubCss *PubCss::Get()
{
    static PubCss cx;
    return &cx;
}

QString PubCss::GetStr(CSS css) const
{
    auto it = _mapList.begin();
    for(; it != _mapList.end(); ++it)
    {
        if(it.key() == css)
        {
            return it.value();
        }
    }
    return "";
}

PubCss::PubCss(QObject *obj)
    :QObject (obj)
{
    _mapList[SMALLWINDOW_LEFTBUTTONSTYLE] = GETSTR
    (
        QPushButton
        {
            border:none;
            color:rgb(255,255,255);
        }
        QPushButton:hover
        {
            background-color:rgb(25,28,59);
        }
    );
    _mapList[SMALLWINDOW_TITLELABEL] = GETSTR
    (
        QLabel
        {
            border:none;
            color:rgb(255,255,255);
            font: "楷体" 13pt;
        }
    );
    _mapList[DEVICEMONITORING_BOTTOMLABEL] = GETSTR
    (
        QLabel
        {
            border:none;
            color:rgb(235,235,235);
            background-color:rgb(48,48,85);
        }
    );
}

PubCss::~PubCss()
{

}
