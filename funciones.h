#ifndef funciones_h
#define funciones_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "hashmap.h"
#include "treemap.h"


typedef struct{
   char nombre[30];
   HashMap* distancias;

}Ciudad;



 char *get_txt_field (char * , int );

char * toString(int );

int lower_than_string(void* , void* );

int lower_than_int(void* , void* );

void agregaInfo (HashMap*, char* , char* , int );

Ciudad * crearCiudad(char *  );

 void ImportarCiudades(HashMap * );

 void  ciudadMasCercana (HashMap * , char * );

void crearRuta(HashMap*, char *);

#endif // funciones_h
