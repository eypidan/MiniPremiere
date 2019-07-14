#ifndef MINIPREMIERE_MYSLIDER_H
#define MINIPREMIERE_MYSLIDER_H

#include <QSlider>
#include <QMouseEvent>

class MySlider : public QSlider
{
public:
    MySlider();

protected:
    void mousePressEvent(QMouseEvent *ev);
};


#endif //MINIPREMIERE_MYSLIDER_H
