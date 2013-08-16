#ifndef CVDEBUGWINDOW_H
#define CVDEBUGWINDOW_H

#include <QDialog>
#include <opencv2/core/core.hpp>

namespace Ui {
class CVDebugWindow;
}

class CVDebugWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit CVDebugWindow(QWidget *parent = 0);
    void setImage(cv::Mat *image);
    ~CVDebugWindow();
    
private Q_SLOTS:
    void on_fitButton_toggled(bool checked);

private:
    Ui::CVDebugWindow *ui;
};

#endif // CVDEBUGWINDOW_H
