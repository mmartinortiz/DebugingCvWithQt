#include "cvdebugsystem.h"
#include <QImage>

CVDebugSystem* CVDebugSystem::pInstance_ = NULL;

CVDebugSystem::CVDebugSystem()
{
    mWindows.clear();
}

CVDebugSystem::~CVDebugSystem()
{
    QHash<QString, CVDebugWindow* >::const_iterator i = mWindows.constBegin();
     while (i != mWindows.constEnd()) {
         delete i.value();
         ++i;
     }
}

void CVDebugSystem::showimg(QString window, cv::Mat *img)
{
    if (!mWindows.contains(window))
    {
        CVDebugWindow *win = new CVDebugWindow();
        mWindows.insert(window, win);
    }
    mWindows[window]->setImage(img);
    mWindows[window]->setWindowTitle(window);
    mWindows[window]->show();
}

void CVDebugSystem::showimg(QString window, cv::Mat img)
{
    this->showimg(window, &img);
}
