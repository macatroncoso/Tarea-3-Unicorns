#include "funciones.h"
#include <stdbool.h>


const char *get_txt_field (char * tmp, int k) {
int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){


        if(open_mark || tmp[i]!= ' '){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ' '){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }

    return NULL;

}

int lower_than_string(void* key1, void* key2){
    char* k1=(char*) key1;
    char* k2=(char*) key2;
    if(strcmp(k1,k2)<0) return 1;
    return 0;
}

int lower_than_int(void* key1, void* key2){ //This function compare 2 keys *int
    int k1 = *((int*) (key1));
    int k2 = *((int*) (key2));
    return k1<k2;
}


void agregaInfo (TreeMap* ciudades, char* ciudad1, char* ciudad2, int distancia){

Ciudad* c1;
 Ciudad* c2;

      if (searchMap(ciudades,ciudad1)== NULL){
         c1 = crearCiudad(ciudad1);
         insertMap(ciudades, ciudad1, c1);}
      else {
       c1 = searchMap(ciudades,ciudad1);
      }
      if (searchMap(ciudades,ciudad2)==NULL){
        c2= crearCiudad(ciudad2);
         insertMap(ciudades,ciudad2,c2);}
       else {
       c2 = searchMap(ciudades,ciudad2);
      }

     insertMap(c1->distancias,ciudad2,distancia);
     insertMap(c2->distancias,ciudad1,distancia);

}

Ciudad * crearCiudad(char * name ) {
   Ciudad* nuevaCiudad= (Ciudad *) malloc (sizeof(Ciudad));
   strcpy( nuevaCiudad->nombre,name);
  nuevaCiudad->distancias = createMap(200);
 return nuevaCiudad;
}

char * toString(int id){

 //function that convert a string to a int
    int digitos = 0;
    int aux = id;
    int numAlreves = 0;
    int auxDigitos;

    while(aux != 0){

        aux = aux / 10;
        digitos++;

    }

    aux = id;
    auxDigitos = digitos;
    digitos--;

    char * idString = (char *) malloc ( (auxDigitos + 1) * sizeof(char));

    while(aux != 0){

        numAlreves = numAlreves + ( (aux % 10) * pow(10, digitos) );
        aux = aux / 10;
        digitos--;

    }

    aux = id;
    digitos = auxDigitos;
    int i = 0;

    while(numAlreves > 0){

        idString[i] = (numAlreves%10) + 48;
        i++;
        numAlreves = numAlreves / 10;

    }

    idString[i] = '\0';

    return idString;

}

void ImportarCiudades( TreeMap * Ciudades){
  printf("awa");
    system("cls");
    printf("Please enter the file name (n_n) ");
    char name[50]; //the name of the file that has the games
    FILE * fp;

    do{

        fflush(stdin);
        scanf("%[^\n]s", name);
        fp = fopen( name , "r"); //opens the file in read
        if (fp == NULL){
            printf("Invalid file :( Please enter a valid file! "); //if the file isn't valid this message will pop on the screen
        }
        fflush(stdin);

    }while(fp == NULL);

    char line [1024];

    while( fgets(line, 1023, fp) != NULL ){  //read and get every field of the csv file

        char * ciudad1 = get_txt_field(line, 0);
        char * ciudad2 = get_txt_field(line, 1);
        int distancia =  atoi(get_txt_field(line, 2));
        agregaInfo(Ciudades,ciudad1,ciudad2,distancia);


    }

    printf("All the Distances were imported correctly (^_^) "); //message that pops out on the window if all the games were imported correctly
    system("pause");
    system("cls");

}

Ciudad * ciudadMasCercana (TreeMap * Ciudades, char * nombreCiudad){
Ciudad * ciudad;
ciudad = searchMap(Ciudades,nombreCiudad);
int Capacidad = mapcapacity(ciudad->distancias);
int i;
int mayor = 0;
 for (i = 0; i < Capacidad ; i++){
 if (mayor < (searchTreeMap(ciudad->distancias,))){
    mayor = searchTreeMap(ciudad->distancias,);
    }
 }
printf("%s",mayor);
return mayor;
}

// Ciudad más cercana (char* nombreCiudad): La aplicación imprime por pantalla la ciudad más cercana a la ciudad ingresada.
