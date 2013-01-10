#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&thread, SIGNAL(renderedImage(QImage,double)),
            this, SLOT(updatePixmap(QImage,double)));

    setWindowTitle(tr("Mandelbrot"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatePixmap(const QImage &image, double scaleFactor){

}
