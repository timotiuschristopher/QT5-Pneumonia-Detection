#include "Image_Processing.hpp"
#include "NoduleDetector.h"
#include <vector>
#include <cstdint>
#include <chrono>
#include <random>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QMessageBox>

#include <iostream>
#include <cstdio>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace std;
using namespace cv;


Mat static markerMask, img0, img, imgGray, result;
Point static prevPt(-1, -1);
int static c;
QString static fileName;
QImage img_show;

//Morphological Variables
Mat static pre_morph_img, morph_img;
uint8_t morph_kernel_size = 0;
QImage morph_edge;

//Contrast Enhancement Variables
Mat static pre_contrast_img, contrast_img;
QImage contrast_enhancement;
double alpha;

//Histogram contrast Variables
Mat static hist_contrast;
QImage Qhist_contrast;

PIXEL_TYPE pixel_type = UINT8;

//Nodule detection Cascade Variables
cv::Mat preframe, frame, grey_image;
QImage frame_nodule;
cv::String nodule_cascade_name="F:/SGU/S7/DSP/Rusman/FinalProject/python_pneumothorax/data/pneumothorax-cascade.xml";
cv::CascadeClassifier nodule_cascade;

static void onMouse( int event, int x, int y, int flags, void* )
{
    if( x < 0 || x >= img.cols || y < 0 || y >= img.rows )
        return;
    if( event == cv::EVENT_LBUTTONUP || !(flags & cv::EVENT_FLAG_LBUTTON) )
        prevPt = Point(-1,-1);
    else if( event == cv::EVENT_LBUTTONDOWN )
        prevPt = Point(x,y);
    else if( event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_LBUTTON) )
    {
        Point pt(x, y);
        if( prevPt.x < 0 )
            prevPt = pt;
        line( markerMask, prevPt, pt, Scalar::all(255), 5, 8, 0 );
        line( img, prevPt, pt, Scalar::all(255), 5, 8, 0 );
        prevPt = pt;
        imshow("image", img);
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::connect(ui->exitPushButton,SIGNAL(clicked()), qApp,SLOT(quit()));
    c = waitKey(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadPushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, ("Open File"),QDir::homePath(),("Images (*.png *.jpeg *.jpg)"));
    if(!fileName.isNull()) {
        img0 = imread(fileName.toStdString(), 1);
        if( img0.empty() )
        {
            QMessageBox::information(this, tr("Couldn'g open image"),tr("Sorry !"));
        }
        namedWindow( "image", WINDOW_AUTOSIZE );
        img0.copyTo(img);
        cvtColor(img, markerMask, COLOR_BGR2GRAY);
        cvtColor(markerMask, imgGray, COLOR_GRAY2BGR);
        markerMask = Scalar::all(0);
        imshow( "image", img );
        setMouseCallback( "image", onMouse, 0 );

        img_show = QImage((const unsigned char*)img0.data, img0.cols, img0.rows, QImage::Format_RGB888);
                int w = ui-> ori_img ->width();
                int h = ui-> ori_img ->height();
                // if size exceeds the label, rescale while keeping aspect ratio
                        if (img0.cols > w || img0.rows > h) // if width and height exceeds
                            {
                               img_show = img_show.scaled(w, h, Qt::KeepAspectRatio);
                            }
        ui->ori_img ->setPixmap(QPixmap::fromImage(img_show));
        ui->ori_img -> resize(ui->ori_img->pixmap()->size());
        ui->resetPushButton->setEnabled(true);
        ui->contrast_enhancement_button->setEnabled(true);
        ui->edge_detection_button->setEnabled(true);
        ui->load_xml_button->setEnabled(true);
        ui->run_detection_button->setEnabled(true);

    } else {
        QMessageBox::information(this, tr("Unable to save file"), tr("Sorry !"));
    }
}


void MainWindow::on_resetPushButton_clicked()
{
    ui->savePushButton->setEnabled(false);
    ui->loadPushButton->setEnabled(true);
    ui->ori_img->clear();
    ui->final_morph_img->clear();
    ui->final_contrast_img->clear();
    ui->histo_contrast->clear();
    ui->contrast_spinbox->clear();
    ui->final_lung_nodule->clear();

    destroyWindow("Original Image");
    morph_img.release();
    contrast_img.release();
    preframe.release();
    grey_image.release();

    markerMask = Scalar::all(0);
    img0.copyTo(img);
    imshow( "image", img );

    ui->final_morph_img->setEnabled(true);
    ui->final_contrast_img->setEnabled(true);
    ui->final_lung_nodule->setEnabled(true);
}


void MainWindow::on_savePushButton_clicked()
{
    if(!morph_img.empty()) {
        QString s = QFileDialog::getSaveFileName( this,tr("Save Image"),QDir::homePath(),tr("Images (*.png *.xpm *.jpeg *.jpg)") );

        if(!s.isNull()) {
            imwrite(s.toStdString(), morph_img);
            QMessageBox::information(this, tr("Result saved"), tr("Good job"));
            ui->loadPushButton->setEnabled(true);
            ui->savePushButton->setEnabled(false);
            ui->resetPushButton->setEnabled(true);
            ui->contrast_enhancement_button->setEnabled(true);
            ui->edge_detection_button->setEnabled(true);
        }    

        else {
            QMessageBox::information(this, tr("Unable to save file"), tr("Sorry !"));

        }
    }

    if(!preframe.empty()) {
        QString s = QFileDialog::getSaveFileName( this,tr("Save Image"),QDir::homePath(),tr("Images (*.png *.xpm *.jpeg *.jpg)") );

        if(!s.isNull()) {
            imwrite(s.toStdString(), preframe);
            QMessageBox::information(this, tr("Result saved"), tr("Good job"));
            ui->loadPushButton->setEnabled(true);
            ui->savePushButton->setEnabled(false);
            ui->resetPushButton->setEnabled(true);
            ui->contrast_enhancement_button->setEnabled(true);
            ui->edge_detection_button->setEnabled(true);
        }

        else {
            QMessageBox::information(this, tr("Unable to save file"), tr("Sorry !"));

        }
    }
}

void MainWindow::on_exitPushButton_clicked(){
    QMessageBox msgBox;

    int ret = msgBox.information(this, tr("Exit"), tr("Are you sure to quit the app?"), QMessageBox::Yes | QMessageBox::No);

    switch (ret) {
      case QMessageBox::No :
        break;
      case QMessageBox::Yes :
            MainWindow::connect(ui->exitPushButton,SIGNAL(clicked()), qApp,SLOT(quit()));
        break;
      default:
          break;
    }
}

void MainWindow::on_actionDescription_triggered()
{
    QMessageBox::information(this, tr("Description"), tr("Qt C++ with OpenCV desktop application (version 1.0.0)\nImages segmentation by implementing the watershed algorithm.\nLicense : GNU GPL v3.0."));
}


void MainWindow::on_contrast_enhancement_button_clicked()
{
    pre_contrast_img = img0;
    pre_contrast_img.convertTo(contrast_img,-1,alpha,0);

    //  getting dimensions (w x h) of label
    int w = ui->final_contrast_img->width();
    int h = ui->final_contrast_img->height();

    contrast_enhancement = QImage((const unsigned char*)(contrast_img.data),contrast_img.cols,contrast_img.rows,QImage::Format_RGB888);

    if (contrast_img.cols > w || contrast_img.rows > h) // if width and height exceeds
        {
             contrast_enhancement = contrast_enhancement.scaled(w,h,Qt::KeepAspectRatio);
        }
    ui->final_contrast_img->setPixmap(QPixmap::fromImage(contrast_enhancement));
    ui->final_contrast_img->resize(ui->final_contrast_img->pixmap()->size());
    ui->savePushButton->setEnabled(true);

    //histogram
    hist_contrast = Histogram_Plot(contrast_img);

    int w1 = ui->histo_contrast->width();
    int h1 = ui->histo_contrast->height();

    Qhist_contrast = QImage((const unsigned char*)(hist_contrast.data),hist_contrast.cols,hist_contrast.rows,QImage::Format_RGB888);

    if (hist_contrast.cols > w1 || hist_contrast.rows > h1) // if image is too big, either we cant see the whole image in label, or the label gets too big causing a bad view
    {
        Qhist_contrast = Qhist_contrast.scaled(w,h,Qt::KeepAspectRatio);
    }
    ui->histo_contrast->setPixmap(QPixmap::fromImage(Qhist_contrast));
    //resize the label to fit the image
    ui->histo_contrast->resize(ui->final_contrast_img->pixmap()->size());
}

void MainWindow::on_edge_detection_button_clicked()
{
    pre_morph_img=contrast_img;
    cv::morphologyEx(pre_morph_img, morph_img,cv::MORPH_GRADIENT,cv::Mat());
    cv::threshold(morph_img, morph_img, 50, 255, cv::THRESH_BINARY);

    //  getting dimensions (w x h) of label
    int w = ui->final_morph_img->width();
    int h = ui->final_morph_img->height();

    morph_edge = QImage((const unsigned char*)(morph_img.data),morph_img.cols,morph_img.rows,QImage::Format_RGB888);

    if (morph_img.cols > w || morph_img.rows > h) // if width and height exceeds
        {
             morph_edge = morph_edge.scaled(w,h,Qt::KeepAspectRatio);
        }
    ui->final_morph_img->setPixmap(QPixmap::fromImage(morph_edge));
    ui->final_morph_img->resize(ui->final_morph_img->pixmap()->size());
    ui->savePushButton->setEnabled(true);
}


void MainWindow::on_contrast_spinbox_valueChanged(double arg1)
{
    alpha = arg1;
}

std::vector<float> Get_Histogram_Info(cv::Mat image)
{
    std::vector<float> info; // [range1, range2] and histogram bin size

    switch(image.depth())
    {
        case 0: // CV_8U
            info.push_back(0.0);
            info.push_back(255.0);
            info.push_back(256.0);
            pixel_type = UINT8;
            break;
        case 1: // CV_8S
            info.push_back(-128);
            info.push_back(127);
            info.push_back(256);
            pixel_type = INT8;
            break;
        case 2: // CV_16U
            info.push_back(0);
            info.push_back(65535);
            info.push_back(65536);
            pixel_type = UINT16;
            break;
        case 3: // CV_16S
            info.push_back(-32768);
            info.push_back(32767);
            info.push_back(65536);
            pixel_type = INT16;
            break;
        default:
            std::cout << "OTHER";
            break;
    }

    return info;
}

//defining RGB/GRAYSCALE
IMAGE_TYPE Check_Image_Type(cv::Mat image)
{
    IMAGE_TYPE im_type = NOT_DETECTED;

    switch(image.channels())
    {
        case 1:
        {
            im_type = GRAYSCALE;
            std::cout << "This image is:" << im_type << std::endl;
            break;
        }
        case 3:
        {
            std::vector<cv::Mat> bgr_planes;
            split(image, bgr_planes);
            cv::Size size = bgr_planes[0].size();
            int row_size = size.height;
            int column_size = size.width;

            switch(pixel_type)
            {
                case UINT8:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                      for (int k = 0; k < column_size; k++)
                      {
                          if (bgr_planes[0].at<uint8_t>(i,k) !=  bgr_planes[1].at<uint8_t>(i,k) or bgr_planes[0].at<uint8_t>(i,k) != bgr_planes[2].at<uint8_t>(i,k))
                          {
                                im_type = RGB;
                                std::cout << "This image is:" << im_type << std::endl;
                                return im_type;
                         }
                      }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case UINT16:
                {
                     for (int i = 0; i < row_size; i++)
                     {
                        for (int k = 0; k < column_size; k++)
                        {
                            if (bgr_planes[0].at<uint16_t>(i,k) !=  bgr_planes[1].at<uint16_t>(i,k) or bgr_planes[0].at<uint16_t>(i,k) != bgr_planes[2].at<uint16_t>(i,k))
                            {
                                 im_type = RGB;
                                 std::cout << "This image is:" << im_type << std::endl;
                                 return im_type;
                            }
                         }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case INT8:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                       for (int k = 0; k < column_size; k++)
                       {
                            if (bgr_planes[0].at<int8_t>(i,k) !=  bgr_planes[1].at<int8_t>(i,k) or bgr_planes[0].at<int8_t>(i,k) != bgr_planes[2].at<int8_t>(i,k))
                            {
                               im_type = RGB;
                               std::cout << "This image is:" << im_type << std::endl;
                               return im_type;
                            }
                       }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                case INT16:
                {
                    for (int i = 0; i < row_size; i++)
                    {
                         for (int k = 0; k < column_size; k++)
                         {
                              if (bgr_planes[0].at<int16_t>(i,k) !=  bgr_planes[1].at<int16_t>(i,k) or bgr_planes[0].at<int16_t>(i,k) != bgr_planes[2].at<int16_t>(i,k))
                              {
                                  im_type = RGB;
                                  std::cout << "This image is:" << im_type << std::endl;
                                  return im_type;
                              }
                          }
                    }
                    im_type = GRAYSCALE;
                    std::cout << "This image is:" << im_type << std::endl;
                    break;
                }
                default:
                {
                    std::cout << "Image pixel type could not be detected!";
                    break;
                }
            }
            break;
        }
        default:
        {
            std::cout << "Image Channel could not be detected!";
            break;
        }
    }
    return im_type;
}

cv::Mat Histogram_Plot(cv::Mat image)
{

     std::vector<float> histogram_info = Get_Histogram_Info(image);

     float histRange[2] = {histogram_info.at(0), histogram_info.at(1)};
     int histSize = histogram_info.at(2);
     const float* range = { histRange };

     std::cout << "Histogram Info : " << histRange[0] << " " << histRange[1] << " " << histSize << std::endl;

     std::vector<cv::Mat> planes;
     split(image, planes);
     bool uniform = true, accumulate = false;

     switch(Check_Image_Type(image))
     {
        case RGB:
        {
             cv::Mat b_hist, g_hist, r_hist;
             calcHist(&planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &range, uniform, accumulate );
             calcHist(&planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &range, uniform, accumulate );
             calcHist(&planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &range, uniform, accumulate );


             int hist_w = 512, hist_h = 400;
             int bin_w = cvRound( (double) hist_w/histSize );
             cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255));
             normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
             for( int i = 1; i < histSize; i++ )
             {
                  line(histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ),
                         cv::Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                         cv::Scalar( 255, 0, 0), 2, 8, 0  );
                  line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ),
                        cv::Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                        cv::Scalar( 0, 255, 0), 2, 8, 0  );
                  line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ),
                        cv::Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                        cv::Scalar( 0, 0, 255), 2, 8, 0  );
             }
             return histImage;
        }
        case GRAYSCALE:
        {
             cv::Mat hist;
             calcHist(&planes[0], 1, 0, cv::Mat(), hist, 1, &histSize, &range, uniform, accumulate );

             int hist_w = 512, hist_h = 400;
             int bin_w = cvRound( (double) hist_w/histSize );
             cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 255,255,255) );
             normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

             for( int i = 1; i < histSize; i++ )
             {
                 line( histImage, cv::Point( bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1)) ),
                       cv::Point( bin_w*(i), hist_h - cvRound(hist.at<float>(i)) ),
                       cv::Scalar(0, 0, 0), 2, 8, 0);
             }
             return histImage;
        }
        default:
        {
            cv::Mat tmp;
            std::cout << "Undefined Image Type!" << std::endl;
            return tmp;
        }
      }
}


void MainWindow::on_load_xml_button_clicked()
{
   if(!nodule_cascade.load(nodule_cascade_name)){
       QMessageBox::information(this, tr("Error Loading the .xml file or Cascade"),tr("Sorry !"));
   }
}

void MainWindow::on_run_detection_button_clicked()
{
    preframe = img0;

    cv::cvtColor(preframe, grey_image, COLOR_BGR2GRAY);
    cv::equalizeHist(grey_image, grey_image);

    std::vector<cv::Rect> nodules;

    //  getting dimensions (w x h) of label
    int w = ui->final_lung_nodule->width();
    int h = ui->final_lung_nodule->height();

    nodule_cascade.detectMultiScale(grey_image, nodules, 2, 1, 0|CASCADE_SCALE_IMAGE,cv::Size(10,10)); // Minimum size of obj

    for( size_t i = 0; i < nodules.size(); i++)
    {
        cv::rectangle(preframe, nodules[i], cv::Scalar(255, 0, 255 ));
        cv::putText(preframe,"Pneumonia",cv::Point(20,20),cv::FONT_HERSHEY_DUPLEX,1,cv::Scalar(225,225,0),2,cv::LINE_AA);
    }

    frame_nodule = QImage((const unsigned char*)(preframe.data),preframe.cols,preframe.rows, QImage::Format_RGB888);

    if (preframe.cols > w || preframe.rows > h) // if width and height exceeds
        {
             frame_nodule = frame_nodule.scaled(w,h,Qt::KeepAspectRatio);
        }

    ui->final_lung_nodule->setPixmap(QPixmap::fromImage(frame_nodule));
    ui->final_lung_nodule->resize(ui->final_lung_nodule->pixmap()->size());
    ui->savePushButton->setEnabled(true);
}
