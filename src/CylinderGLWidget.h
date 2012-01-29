#ifndef CYLINDERGLWIDGET_H
#define CYLINDERGLWIDGET_H

#include <QGLWidget>

#include "Cylinder.h"

class CylinderGLWidget : public QGLWidget, public Cylinder {
    Q_OBJECT

public:
    CylinderGLWidget( QWidget *parent = 0, double height = 0, double radius = 0 );
    ~CylinderGLWidget();

signals:
    void gotNewSurfaceArea( double surfaceArea );
    void gotNewVolume( double volume );

/*
public slots:
    void setHeight( double height );
    void setRadius( double radius );
*/

protected:
    void updateProperties();

    void initializeGL();
    void resizeGL();
    void paintGL();
    void mousePressEvent( QMouseEvent *event );
    void mouseMoveEvent( QMouseEvent *event );
    void mouseDoubleClickEvent( QMouseEvent *event );

private:
    void draw();

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};
#endif
