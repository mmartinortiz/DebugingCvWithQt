#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QMessageBox>
#include "cvdebugsystem.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    capture = NULL;
}

MainWindow::~MainWindow()
{
    capture->release();
    delete ui;
    delete capture;
    delete timer;
}

void MainWindow::on_capturingButton_clicked()
{
    capture = new VideoCapture(CV_CAP_ANY);

    if ( !capture ) {
        QMessageBox::warning(this, tr("OpenCV Error"),
                             tr("ERROR: capture is NULL"),
                             QMessageBox::Ok);
        return;
    }

    // Disable the button
    ui->capturingButton->setEnabled(false);

    // Init the timer to grab images
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerEvent()));
    timer->start(1000/33);
}

/**
 * @brief MainWindow::onTimerEvent
 *
 * Draw image on main window
 */
void MainWindow::onTimerEvent()
{
    Mat image;
    capture->grab();
    capture->retrieve(image);

    if (image.empty()) return;

    QImage::Format format;
    if (image.channels() == 1) format = QImage::Format_Mono;
    else                       format = QImage::Format_RGB888;

    QImage  img = QImage((const unsigned char*)(image.data),
                         image.cols,
                         image.rows,
                         image.step,
                         format).rgbSwapped();

    ui->label->setPixmap(QPixmap::fromImage(img));

    // Two random debug window
    float x = image.cols/2;
    float y = image.rows/2;
    CVDebugSystem::getInstance().showimg("Debug Window 1", Mat(image(Rect(0,0,x,y))));
    CVDebugSystem::getInstance().showimg("Debug Window 2", Mat(image(Rect(0,0,x/2,y/2))));
}

void MainWindow::closeEvent(QCloseEvent *)
{
    exit(0);
}
