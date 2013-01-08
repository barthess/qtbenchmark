#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QSize>

class RenderThread : public QTread
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
    uint rgbFromWaveLength(double wave);

    QMutex mutex;
    QWaitCondition condition;
    double centerX;
    double centerY;
    double scaleFactor;
    QSize resultSize;
    bool restart;
    bool abort;

    enum { ColormapSize = 512 };
    uint colormap[ColormapSize];
};

#endif // RENDERTHREAD_H
