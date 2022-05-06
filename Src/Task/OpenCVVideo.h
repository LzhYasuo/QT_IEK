#ifndef _OPENCV_PV_THREAD_H_
#define _OPENCV_PV_THREAD_H_

#include <QThread>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <QMutex>
#include <string.h>

enum SavePaintModel
{
    pSavePaint,
    vSavePaint,
    cSavePaint,
};

class OpenCV_PV_Thread : public QThread
{
    Q_OBJECT
public:
    OpenCV_PV_Thread();
    ~OpenCV_PV_Thread();
    bool Open();

    void run();

signals:
    void ShowCamera(cv::Mat);

private:
    //摄像头是否被打开
    bool isCamear = false;
    QMutex mux;
    bool isClose = false;
};

#endif //_OPENCV_PV_THREAD_H_
