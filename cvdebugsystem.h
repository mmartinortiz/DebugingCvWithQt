#ifndef CVDEBUGSYSTEM_H
#define CVDEBUGSYSTEM_H

#include <QHash>
#include "cvdebugwindow.h"

class CVDebugSystem
{
public:
    static CVDebugSystem &getInstance()
    {
        if(pInstance_ == NULL)
        {
            pInstance_ = new CVDebugSystem();
            atexit(&DestroySingleton);    // At exit, destroy the singleton
        }
        return *pInstance_;
    }
    ~CVDebugSystem();
    
private:
    // Singleton
    static CVDebugSystem* pInstance_;

    // Delete the singleton instance
    static void DestroySingleton(){
        if(pInstance_ != NULL) delete pInstance_;
    }

    // Private to ensure single instance
    CVDebugSystem();
    QHash<QString, CVDebugWindow* > mWindows;

public:
    void showimg(QString window, cv::Mat *img);
    void showimg(QString window, cv::Mat img);
};

#endif // CVDEBUGSYSTEM_H
