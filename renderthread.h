#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QSize>
#include <QImage>

class RenderThread : public QThread
{
    Q_OBJECT
public:
    explicit RenderThread(QObject *parent = 0);
    ~RenderThread();

    void render(void);

signals:
    void renderedImage(const QImage &image, double scaleFactor);

protected:
    void run();

private:
    QMutex mutex;
    QWaitCondition condition;
    bool restart;
    bool abort;
};

#endif // RENDERTHREAD_H
