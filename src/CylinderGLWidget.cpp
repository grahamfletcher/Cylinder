#include <QDebug>

#include <math.h>
#include <QMouseEvent>
#include <QMutexLocker>

#include "CylinderGLWidget.h"

CylinderGLWidget::CylinderGLWidget( QWidget *parent, double height, double radius ) : QGLWidget( parent ), Cylinder( height, radius ) {
    setFormat( QGLFormat( QGL::DoubleBuffer | QGL::DepthBuffer ) );

    rotationX = -60.0;
    rotationY = 0.0;
    rotationZ = 0.0;
}

CylinderGLWidget::~CylinderGLWidget() {
    gluDeleteQuadric( quadric );
}

void CylinderGLWidget::updateProperties() {
    Cylinder::updateProperties();

    QMutexLocker locker( &cylinderMutex );

    emit gotNewSurfaceArea( surfaceArea );
    emit gotNewVolume( volume );

    updateGL();
}

void CylinderGLWidget::initializeGL() {
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glShadeModel( GL_FLAT );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_CULL_FACE );

    glClearDepth(1.0f);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);
    GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glEnable(GL_LIGHT1);


    quadric = gluNewQuadric();
}

void CylinderGLWidget::resizeGL( int viewportWidth, int viewportHeight ) {
    glViewport( 0, 0, viewportWidth, viewportHeight );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum( -1.0, 1.0, -1.0, 1.0, -100.0, 1000.0 );
    glMatrixMode( GL_MODELVIEW );
}

void CylinderGLWidget::paintGL() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    draw();
}

void CylinderGLWidget::mousePressEvent( QMouseEvent *event ) {
    lastPosition = event->pos();
}

void CylinderGLWidget::mouseMoveEvent( QMouseEvent *event ) {
    GLfloat dx = GLfloat( event->x() - lastPosition.x() ) / QWidget::width();
    GLfloat dy = GLfloat( event->y() - lastPosition.y() ) / QWidget::height();

    if ( event->buttons() & Qt::LeftButton ) {
        rotationX += 180 * dy;
        rotationY += 180 * dx;
        updateGL();
    } else if ( event->buttons() & Qt::RightButton ) {
        rotationX += 180 * dy;
        rotationZ += 180 * dx;
        updateGL();
    }
    lastPosition = event->pos();
}

void CylinderGLWidget::mouseDoubleClickEvent( QMouseEvent *event ) {

}

void CylinderGLWidget::draw() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    float r = (float) 3 * Cylinder::radius / QWidget::width();
    float h = (float) 3 * Cylinder::height / QWidget::height();
    int subdivisions = 32;


    glPushMatrix();

    glTranslatef( 0, -(h / 2), -0.12 );
    glRotatef( rotationX, 1.0, 0.0, 0.0 );
    glRotatef( rotationY, 0.0, 1.0, 0.0 );
    glRotatef( rotationZ, 0.0, 0.0, 1.0 );
 
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    gluCylinder(quadric, r, r, h, subdivisions, 1);

    //draw the first cap
    gluQuadricOrientation(quadric, GLU_INSIDE);
    gluDisk( quadric, 0.0, r, subdivisions, 1);
    glTranslatef( 0,0,h );

    //draw the second cap
    gluQuadricOrientation(quadric,GLU_OUTSIDE);
    gluDisk( quadric, 0.0, r, subdivisions, 1);
    
    glPopMatrix();
}
