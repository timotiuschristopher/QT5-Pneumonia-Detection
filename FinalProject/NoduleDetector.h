#ifndef NODULEDETECTOR_H
#define NODULEDETECTOR_H

#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QString>
#include <QResource>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

class NoduleDetector : public QObject
{
    Q_OBJECT
    QString nodulecascade_filename_;
    QBasicTimer timer_;
    cv::Mat frame_;
    bool processAll_;
    cv::CascadeClassifier nodule_cascade;

    void process(cv::Mat frame);
    void loadFiles(cv::String noduleCascadeFilename);
    void queue(const cv::Mat & frame);
    void timerEvent(QTimerEvent* ev);
    static void matDeleter(void* mat);

public:
    NoduleDetector(QObject *parent=0) : QObject(parent), processAll_(true)
    {
        nodulecascade_filename_ = "F:/SGU/S7/DSP/Rusman/FinalProject/python_pneumothorax/data/pneumothorax-cascade.xml";
        loadFiles(nodulecascade_filename_.toStdString().c_str());
    }
    void setProcessAll(bool all);
    ~NoduleDetector();

signals:
    void image_signal(const QImage&);

public slots:
    void processFrame(const cv::Mat& frame);
    void nodulecascade_filename(QString filename);
};

#endif // NODULEDETECTOR_H
