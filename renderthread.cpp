#include "renderthread.h"

RenderThread::RenderThread(QObject *parent) :
    QThread(parent)
{
    restart = false;
    abort = false;
}

RenderThread::~RenderThread()
{
    mutex.lock();
    abort = true;
    condition.wakeOne();
    mutex.unlock();

    wait();
}

void RenderThread::render(void){

}
