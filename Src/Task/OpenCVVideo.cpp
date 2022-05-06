#include "OpenCVVideo.h"
#include <QDebug>
#include <windows.h>
#include <QElapsedTimer>

static cv::VideoCapture cap2;
static cv::Mat MatCamear;

OpenCV_PV_Thread::OpenCV_PV_Thread()
{

}

OpenCV_PV_Thread::~OpenCV_PV_Thread()
{
    isClose = true;
    this->quit();
    this->wait();
}


bool OpenCV_PV_Thread::Open()
{
    mux.lock();
    bool isOpen = cap2.open(0);
    mux.unlock();
    if(!isOpen)
    {
        return false;
    }
    isCamear = true;
    return true;
}

void OpenCV_PV_Thread::run()
{
    while(1)
    {
        mux.lock();
        if(isClose)
        {
            mux.unlock();
            break;
        }
        if(!isCamear)
        {
            mux.unlock();
            continue;
        }
        if(isCamear && cap2.isOpened())
        {
            bool isRead = cap2.read(MatCamear);
            if(isRead)
                emit ShowCamera(MatCamear);
        }
        else
        {
            Sleep(30);
        }

        mux.unlock();
    }
}
