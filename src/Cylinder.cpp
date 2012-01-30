#include <QtGlobal>
#include <QMutexLocker>

#include "Cylinder.h"

#define PI 3.1415926535897932384626433832795

Cylinder::Cylinder( double height, double radius ) {

    this->height = qMax( 0.0, height );
    this->radius = qMax( 0.0, radius );

    updateProperties();
}

Cylinder::~Cylinder() {

}

double Cylinder::getSurfaceArea() {
    QMutexLocker locker( &cylinderMutex );

    return surfaceArea;
}

double Cylinder::getVolume() {
    QMutexLocker locker( &cylinderMutex );

    return volume;
}

void Cylinder::setHeight( double height ) {
    if ( height >= 0 ) {
        cylinderMutex.lock();
        this->height = height;
        cylinderMutex.unlock();

        updateProperties();
    } else {
        qWarning( "Ignoring negative height value" );
    }
}

void Cylinder::setRadius( double radius ) {
    if ( radius >= 0 ) {
        cylinderMutex.lock();
        this->radius = radius;
        cylinderMutex.unlock();

        updateProperties();
    } else {
        qWarning( "Ignoring negative radius value" );
    }
}

void Cylinder::updateProperties() {
    QMutexLocker locker( &cylinderMutex );

    surfaceArea = 2 * PI * radius * (radius + height);
    volume = PI * radius * radius * height;
}
