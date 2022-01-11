#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadPushButton_clicked();

    void on_resetPushButton_clicked();

    void on_savePushButton_clicked();

    void on_exitPushButton_clicked();

    void on_actionDescription_triggered();

    void on_edge_detection_button_clicked();

    void on_contrast_enhancement_button_clicked();

    void on_contrast_spinbox_valueChanged(double arg1);

    void on_load_xml_button_clicked();

    void on_run_detection_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
