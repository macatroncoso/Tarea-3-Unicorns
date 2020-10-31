 #include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include "funciones.h"
int main()
{
    HashMap* Ciudades = createMap(200);
    int option;
    char nombreCiudad[30];

    while(1){


    //our menu to print all our options :D

        printf("Welcome to the Unicorn's GPS App (n _ n) What would you like to do?  \n\n");
        printf("Option 1 <3 : Import Distances from a file \n");
        printf("Option 2 <3 : Show the nearest city\n");
        printf("Option 3 <3 : Add game \n");
        printf("Option 4 <3 : Search game by Name \n");
        printf("Option 5 <3 : Search game by type/s \n");
        printf("Option 6 <3 : Exit \n");

        do{
            scanf("%d", &option);
            if ((option > 6) || (option < 1))
               printf("Invalid option (> n <) please enter a valid menu option <3 \n");

        }while ((option > 6) || (option < 1));  //this "While" validates that the option entered is valid!

        switch(option){
            case 1: ImportarCiudades(Ciudades);
            break;
              case 2 : printf("Please enter the City you're searching ");
                fflush(stdin);
                 scanf("%s",nombreCiudad);
                   fflush(stdin);
                ciudadMasCercana(Ciudades, nombreCiudad);
                break;
        }

        if(option == 6){

            break;  //breaks the program

        }

    }


    return 0;
}
