#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "renderthread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void updatePixmap(const QImage &image, double scaleFactor);

private:
    Ui::Widget *ui;
    RenderThread thread;
};

#endif // WIDGET_H
