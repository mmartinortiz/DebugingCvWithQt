#include "cvdebugwindow.h"
#include "ui_cvdebugwindow.h"

CVDebugWindow::CVDebugWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CVDebugWindow)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
}

CVDebugWindow::~CVDebugWindow()
{
    delete ui;
}

void CVDebugWindow::setImage(cv::Mat *image)
{
    QImage::Format format;
    if (image->channels() == 1) format = QImage::Format_Mono;
    else                        format = QImage::Format_RGB888;

    QImage  img = QImage((const unsigned char*)(image->data),
                         image->cols,
                         image->rows,
                         image->step,
                         format).rgbSwapped();

    QImage aux;
    if (ui->fitButton->isChecked())
    {
        aux = img.scaled(ui->label->size());
    }
    else
    {
        if (ui->scaleFactor->value() != 1)
        {
            aux = img.scaled(img.size()*ui->scaleFactor->value());
        }
        else
            aux = img;
    }

    ui->label->setPixmap(QPixmap::fromImage(aux));
}

void CVDebugWindow::on_fitButton_toggled(bool checked)
{
    if (checked) ui->scaleFactor->setEnabled(false);
    else ui->scaleFactor->setEnabled(true);
}
