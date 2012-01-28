#include <iostream>
#include <stdlib.h>
#include <QApplication>

#include "Cylinder.h"

void printUsage( ) {
    std::cout << "Usage: cylinder                  launch GUI" << "\n";
    std::cout << "   or: cylinder [arguments]      run in batch mode" << "\n\n";
    std::cout << "Arguments:\n";
    std::cout << "  -h, --height <integer>         Height of the cylinder\n";
    std::cout << "  -r, --radius <integer>         Radius of the cylinder\n";
}

int processBatch( int argc, char *argv[] ) {

    int radius = -1, height = -1;

    for ( int i = 1; i < argc; i++ ) {

        if ( strcmp( argv[i], "--help" ) == 0 ) {
            std::cout << "cylinder - A sample program for CDL Systems (compiled " << __DATE__ << " " << __TIME__ << ")\n\n";
            printUsage();

            return EXIT_SUCCESS;
        } else if ( strcmp( argv[i], "-h" ) == 0 ||
                    strcmp( argv[i], "--height" ) == 0 ) {

            height = atof( argv[++i] );
        } else if ( strcmp( argv[i], "-r" ) == 0 ||
                    strcmp( argv[i], "--radius" ) == 0 ) {

            radius = atof( argv[++i] );
        } else {
            std::cout << "cylinder: invalid parameter " << argv[i] << "\n\n";
            printUsage();

            return EXIT_FAILURE;
        }
    }

    /* Create the cylinder object */
    Cylinder cylinder( qApp, radius, height );

    /* Print the properties of the cylinder */
    std::cout << "Surface area: " << cylinder.getSurfaceArea() << "\n";
    std::cout << "Volume: " << cylinder.getVolume() << "\n";

    return EXIT_SUCCESS;
}

int main ( int argc, char *argv[] ) {
    //Cylinder cylinder = new Cylinder();

    if ( argc > 1 ) {
        // running in batch mode

        return processBatch( argc, argv );
    }
    
    //QApplication app( argc, argv );

    //return app.exec();
}
