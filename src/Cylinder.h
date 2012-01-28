#ifndef CYLINDER_H
#define CYLINDER_H

#include <QObject>
#include <QMutex>

class Cylinder : public QObject {
    Q_OBJECT

public:
    Cylinder( QObject *parent, double height = 0, double radius = 0 );
    ~Cylinder();

    double getSurfaceArea();
    double getVolume();

signals:
    void gotNewSurfaceArea( double surfaceArea );
    void gotNewVolume( double volume );

public slots:
    void setHeight( double height );
    void setRadius( double radius );

private:
    void updateProperties();

    QMutex cylinderMutex;

    double height;
    double radius;

    double volume;
    double surfaceArea;
};

#endif
