#include "OpenCVGLWidget.h"
#include <QPainter>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <QResizeEvent>
#include <QDebug>
#include <QShowEvent>

OpenCVGLWidget::OpenCVGLWidget(QWidget *parent)
    :QOpenGLWidget (parent)
{

}

OpenCVGLWidget::~OpenCVGLWidget()
{

}


void OpenCVGLWidget::ShowImg(cv::Mat mat)
{
    if(this->width() == 0 || this->height() == 0)
        return;
    cv::resize(mat,mat,cv::Size(this->width(),this->height()));
    img = MatToQImage(mat);
    update();
}

QImage OpenCVGLWidget::MatToQImage(const cv::Mat& mat)
{
    switch (mat.type())
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image(mat.data,
                     mat.cols, mat.rows,
                     static_cast<int>(mat.step),
                     QImage::Format_ARGB32);

        return image;
    }

    // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image(mat.data,
                     mat.cols, mat.rows,
                     static_cast<int>(mat.step),
                     QImage::Format_RGB888);

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image(mat.data,
                     mat.cols, mat.rows,
                     static_cast<int>(mat.step),
                     QImage::Format_Grayscale8);
#else
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if (sColorTable.isEmpty())
        {
            sColorTable.resize( 256 );

            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image(mat.data,
                     mat.cols, mat.rows,
                     static_cast<int>(mat.step),
                     QImage::Format_Indexed8 );

        image.setColorTable(sColorTable);
#endif

        return image;
    }

    // wrong
    default:
        break;
    }
    return QImage();
}


void OpenCVGLWidget::paintEvent(QPaintEvent *e)
{
    QPainter p;
    p.begin(this);
    p.drawImage(QPointF(0, 0), img);
    p.end();
}
