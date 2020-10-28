#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include "funciones.h"
int main()
{
    HashMap * Ciudades = createMap(200);

     ImportarCiudades(Ciudades);

    return 0;
}
