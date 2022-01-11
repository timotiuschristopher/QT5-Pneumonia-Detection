/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDescription;
    QAction *actionmedaimane_github_io;
    QAction *actionskhairimedaimane_gmail_com;
    QAction *actionTimotius_Christopher_Tantokusumo;
    QAction *actionTimotius_Christopher_Tantokusumo_2;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *exitPushButton;
    QLabel *ori_img;
    QPushButton *savePushButton;
    QPushButton *resetPushButton;
    QPushButton *loadPushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTextBrowser *description;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_contrast_img;
    QLabel *final_contrast_img;
    QLabel *histo_contrast;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *contrast_enhancement_button;
    QLabel *label;
    QDoubleSpinBox *contrast_spinbox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_morph_img;
    QLabel *final_morph_img;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *edge_detection_button;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_lung_nodule;
    QLabel *final_lung_nodule;
    QPushButton *load_xml_button;
    QPushButton *run_detection_button;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QMenu *menuAuthor;
    QMenu *menuContact;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1179, 602);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1179, 602));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setStyleSheet(QString::fromUtf8("background-image : url('assets/img/back.png')"));
        actionDescription = new QAction(MainWindow);
        actionDescription->setObjectName(QString::fromUtf8("actionDescription"));
        actionmedaimane_github_io = new QAction(MainWindow);
        actionmedaimane_github_io->setObjectName(QString::fromUtf8("actionmedaimane_github_io"));
        actionskhairimedaimane_gmail_com = new QAction(MainWindow);
        actionskhairimedaimane_gmail_com->setObjectName(QString::fromUtf8("actionskhairimedaimane_gmail_com"));
        actionTimotius_Christopher_Tantokusumo = new QAction(MainWindow);
        actionTimotius_Christopher_Tantokusumo->setObjectName(QString::fromUtf8("actionTimotius_Christopher_Tantokusumo"));
        actionTimotius_Christopher_Tantokusumo_2 = new QAction(MainWindow);
        actionTimotius_Christopher_Tantokusumo_2->setObjectName(QString::fromUtf8("actionTimotius_Christopher_Tantokusumo_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(6);
        sizePolicy1.setVerticalStretch(6);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setBaseSize(QSize(0, -1));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 301, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(100, 20, 100, 20);
        exitPushButton = new QPushButton(gridLayoutWidget);
        exitPushButton->setObjectName(QString::fromUtf8("exitPushButton"));

        gridLayout->addWidget(exitPushButton, 4, 0, 1, 1);

        ori_img = new QLabel(gridLayoutWidget);
        ori_img->setObjectName(QString::fromUtf8("ori_img"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(ori_img->sizePolicy().hasHeightForWidth());
        ori_img->setSizePolicy(sizePolicy2);
        ori_img->setMinimumSize(QSize(20, 20));
        ori_img->setBaseSize(QSize(5, 5));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        ori_img->setFont(font);
        ori_img->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(ori_img, 0, 0, 1, 1);

        savePushButton = new QPushButton(gridLayoutWidget);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));
        savePushButton->setEnabled(false);

        gridLayout->addWidget(savePushButton, 3, 0, 1, 1);

        resetPushButton = new QPushButton(gridLayoutWidget);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setEnabled(false);

        gridLayout->addWidget(resetPushButton, 2, 0, 1, 1);

        loadPushButton = new QPushButton(gridLayoutWidget);
        loadPushButton->setObjectName(QString::fromUtf8("loadPushButton"));

        gridLayout->addWidget(loadPushButton, 1, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 380, 1141, 141));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        description = new QTextBrowser(gridLayoutWidget_2);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout_2->addWidget(description, 0, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(320, 10, 291, 361));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_contrast_img = new QLabel(gridLayoutWidget_3);
        label_contrast_img->setObjectName(QString::fromUtf8("label_contrast_img"));
        label_contrast_img->setMaximumSize(QSize(1000, 20));
        label_contrast_img->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_contrast_img->setFont(font1);
        label_contrast_img->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_contrast_img);

        final_contrast_img = new QLabel(gridLayoutWidget_3);
        final_contrast_img->setObjectName(QString::fromUtf8("final_contrast_img"));
        final_contrast_img->setEnabled(true);
        final_contrast_img->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(final_contrast_img);

        histo_contrast = new QLabel(gridLayoutWidget_3);
        histo_contrast->setObjectName(QString::fromUtf8("histo_contrast"));
        histo_contrast->setMouseTracking(true);
        histo_contrast->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(histo_contrast);

        horizontalWidget1 = new QWidget(gridLayoutWidget_3);
        horizontalWidget1->setObjectName(QString::fromUtf8("horizontalWidget1"));
        horizontalWidget1->setMaximumSize(QSize(16777215, 45));
        horizontalLayout = new QHBoxLayout(horizontalWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        contrast_enhancement_button = new QPushButton(horizontalWidget1);
        contrast_enhancement_button->setObjectName(QString::fromUtf8("contrast_enhancement_button"));
        contrast_enhancement_button->setMaximumSize(QSize(150, 20));
        contrast_enhancement_button->setBaseSize(QSize(0, 20));

        horizontalLayout->addWidget(contrast_enhancement_button);

        label = new QLabel(horizontalWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(50, 25));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        contrast_spinbox = new QDoubleSpinBox(horizontalWidget1);
        contrast_spinbox->setObjectName(QString::fromUtf8("contrast_spinbox"));
        contrast_spinbox->setMaximumSize(QSize(50, 20));
        contrast_spinbox->setDecimals(1);
        contrast_spinbox->setMaximum(10.000000000000000);
        contrast_spinbox->setSingleStep(0.500000000000000);

        horizontalLayout->addWidget(contrast_spinbox);


        verticalLayout->addWidget(horizontalWidget1);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(620, 10, 261, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_morph_img = new QLabel(layoutWidget);
        label_morph_img->setObjectName(QString::fromUtf8("label_morph_img"));
        label_morph_img->setMaximumSize(QSize(16777215, 20));
        label_morph_img->setFont(font1);
        label_morph_img->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_morph_img);

        final_morph_img = new QLabel(layoutWidget);
        final_morph_img->setObjectName(QString::fromUtf8("final_morph_img"));
        final_morph_img->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(final_morph_img);

        horizontalWidget = new QWidget(layoutWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 45));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edge_detection_button = new QPushButton(horizontalWidget);
        edge_detection_button->setObjectName(QString::fromUtf8("edge_detection_button"));
        edge_detection_button->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(edge_detection_button);


        verticalLayout_2->addWidget(horizontalWidget);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(890, 10, 261, 361));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_lung_nodule = new QLabel(gridLayoutWidget_4);
        label_lung_nodule->setObjectName(QString::fromUtf8("label_lung_nodule"));
        label_lung_nodule->setMaximumSize(QSize(16777215, 20));
        label_lung_nodule->setFont(font1);
        label_lung_nodule->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_lung_nodule);

        final_lung_nodule = new QLabel(gridLayoutWidget_4);
        final_lung_nodule->setObjectName(QString::fromUtf8("final_lung_nodule"));
        final_lung_nodule->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(final_lung_nodule);

        load_xml_button = new QPushButton(gridLayoutWidget_4);
        load_xml_button->setObjectName(QString::fromUtf8("load_xml_button"));

        verticalLayout_3->addWidget(load_xml_button);

        run_detection_button = new QPushButton(gridLayoutWidget_4);
        run_detection_button->setObjectName(QString::fromUtf8("run_detection_button"));

        verticalLayout_3->addWidget(run_detection_button);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1179, 20));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuAuthor = new QMenu(menuAbout);
        menuAuthor->setObjectName(QString::fromUtf8("menuAuthor"));
        menuContact = new QMenu(menuAbout);
        menuContact->setObjectName(QString::fromUtf8("menuContact"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionDescription);
        menuAbout->addSeparator();
        menuAbout->addAction(menuAuthor->menuAction());
        menuAbout->addSeparator();
        menuAbout->addAction(menuContact->menuAction());
        menuAbout->addSeparator();
        menuAuthor->addSeparator();
        menuAuthor->addSeparator();
        menuAuthor->addAction(actionTimotius_Christopher_Tantokusumo_2);
        menuContact->addSeparator();
        menuContact->addSeparator();
        menuContact->addAction(actionmedaimane_github_io);
        menuContact->addSeparator();
        menuContact->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Segmentation", nullptr));
        actionDescription->setText(QApplication::translate("MainWindow", "Description", nullptr));
        actionmedaimane_github_io->setText(QApplication::translate("MainWindow", "timotius.tantokusumo@student.sgu.ac.id", nullptr));
        actionskhairimedaimane_gmail_com->setText(QApplication::translate("MainWindow", "skhairimedaimane@gmail.com", nullptr));
        actionTimotius_Christopher_Tantokusumo->setText(QApplication::translate("MainWindow", "Timotius Christopher Tantokusumo", nullptr));
        actionTimotius_Christopher_Tantokusumo_2->setText(QApplication::translate("MainWindow", "Timotius Christopher Tantokusumo", nullptr));
        exitPushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        ori_img->setText(QApplication::translate("MainWindow", "Menu", nullptr));
        savePushButton->setText(QApplication::translate("MainWindow", "Save Image", nullptr));
        resetPushButton->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        loadPushButton->setText(QApplication::translate("MainWindow", "Load Image", nullptr));
        description->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Timotius Christopher Tantokusumo - 11806001</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">DSP Final Project - OpenCV and Cascade</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Pneumonia Detection Algorithm </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Image Processings:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Contrast Enchancement</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Morphological Edg"
                        "e detection</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">- Histogram</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">the cascade file:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">pneumonia-cascade.xml</span></p></body></html>", nullptr));
        label_contrast_img->setText(QApplication::translate("MainWindow", "Contrast Enchancement", nullptr));
        final_contrast_img->setText(QString());
        histo_contrast->setText(QApplication::translate("MainWindow", "Histogram", nullptr));
        contrast_enhancement_button->setText(QApplication::translate("MainWindow", "Contrast Enchancement", nullptr));
        label->setText(QApplication::translate("MainWindow", "Alpha", nullptr));
        label_morph_img->setText(QApplication::translate("MainWindow", "Morphological Edge Detection", nullptr));
        final_morph_img->setText(QString());
        edge_detection_button->setText(QApplication::translate("MainWindow", "Morphological Edge Detection", nullptr));
        label_lung_nodule->setText(QApplication::translate("MainWindow", "Pneumonia Detection", nullptr));
        final_lung_nodule->setText(QString());
        load_xml_button->setText(QApplication::translate("MainWindow", "Load XML", nullptr));
        run_detection_button->setText(QApplication::translate("MainWindow", "Run Detection", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
        menuAuthor->setTitle(QApplication::translate("MainWindow", "Author", nullptr));
        menuContact->setTitle(QApplication::translate("MainWindow", "Contact", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
