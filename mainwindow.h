#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_capturingButton_clicked();
    void onTimerEvent();
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    VideoCapture* capture;
};

#endif // MAINWINDOW_H
