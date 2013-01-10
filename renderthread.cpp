#include <QDebug>

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
    qDebug() << "render";
}

void RenderThread::run(void){
    forever {
        mutex.lock();
        mutex.unlock();

        mutex.lock();
        if (!restart)
            condition.wait(&mutex);
        restart = false;
        mutex.unlock();
    }
}
