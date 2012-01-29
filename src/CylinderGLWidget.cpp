#include <QMutexLocker>

#include "CylinderGLWidget.h"

CylinderGLWidget::CylinderGLWidget( QWidget *parent, double height, double radius ) : QGLWidget( parent ), Cylinder( height, radius ) {

}

CylinderGLWidget::~CylinderGLWidget() {

}

/*
void CylinderGLWidget::setHeight( double height ) {
    Cylinder::setHeight( height );
}

void CylinderGLWidget::setRadius( double radius ) {
    Cylinder::setRadius( radius );
}
*/

void CylinderGLWidget::updateProperties() {
    Cylinder::updateProperties();

    QMutexLocker locker( &cylinderMutex );

    emit gotNewSurfaceArea( surfaceArea );
    emit gotNewVolume( volume );
}

void CylinderGLWidget::initializeGL() {

}

void CylinderGLWidget::resizeGL() {

}

void CylinderGLWidget::paintGL() {

}

void CylinderGLWidget::mousePressEvent( QMouseEvent *event ) {

}

void CylinderGLWidget::mouseMoveEvent( QMouseEvent *event ) {

}

void CylinderGLWidget::mouseDoubleClickEvent( QMouseEvent *event ) {

}

void CylinderGLWidget::draw() {

}
