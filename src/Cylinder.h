#ifndef CYLINDER_H
#define CYLINDER_H

#include <QMutex>

class Cylinder {

public:
    Cylinder( double height = 0, double radius = 0 );
    ~Cylinder();

    double getSurfaceArea();
    double getVolume();

    void setHeight( double height );
    void setRadius( double radius );

protected:
    virtual void updateProperties();

    QMutex cylinderMutex;

    double height;
    double radius;

    double volume;
    double surfaceArea;
};

#endif
