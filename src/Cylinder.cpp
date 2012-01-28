#include <QtGlobal>
#include <QMutexLocker>

#include "Cylinder.h"

#define PI 3.1415926535897932384626433832795

Cylinder::Cylinder( QObject *parent, double height, double radius ) : QObject( parent ), height( height ), radius( radius ) {
    if ( height > 0 && radius > 0 ) {
        updateProperties();
    }
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

void Cylinder::setHeight( double h ) {
    if ( h >= 0 ) {
        cylinderMutex.lock();
        height = h;
        cylinderMutex.unlock();

        updateProperties();
    } else {
        qWarning( "Ignoring negative height value" );
    }
}

void Cylinder::setRadius( double r ) {
    if ( r >= 0 ) {
        cylinderMutex.lock();
        radius = r;
        cylinderMutex.unlock();

        updateProperties();
    } else {
        qWarning( "Ignoring negative radius value" );
    }
}

void Cylinder::updateProperties() {
    QMutexLocker locker( &cylinderMutex );

    /* Surface area */
    surfaceArea = 2 * PI * radius * (radius + height);
    emit gotNewSurfaceArea( surfaceArea );

    /* Volume */
    volume = PI * radius * radius * height;
    emit gotNewVolume( volume );
}
