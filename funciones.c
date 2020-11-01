#include "funciones.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char * _strdup (const char *s) {
    size_t len = strlen (s) + 1;
    void *new = malloc (len);

    if (new == NULL)
    	return NULL;

    return (char *) memcpy (new, s, len);
}

char *get_txt_field (char * tmp, int k) {

    char * tmpDup = _strdup(tmp);

    const char character[2] = " ";
    char *token = (char *) malloc (50 * sizeof (char));

    int i = 0;

    token = strtok(tmpDup, character);

    while(i < k && token != NULL){

        token = strtok(NULL, character);
        i++;
    }

    return token;
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


void agregaInfo (HashMap* Ciudades, char* ciudad1, char* ciudad2, int distancia){

Ciudad * city1;
 Ciudad * city2;

      if (searchMap(Ciudades,ciudad1)== NULL){
       city1 = crearCiudad(ciudad1);
       insertMap(Ciudades,ciudad1,city1);}
      else {
       city1 = searchMap(Ciudades,ciudad1);
      }

     if (searchMap(Ciudades,ciudad2)== NULL){
        city2 = crearCiudad(ciudad2);
        insertMap(Ciudades, ciudad2,city2);}
      else {
       city2 = searchMap(Ciudades,ciudad2);
      }

     if(searchMap(city1->distancias, ciudad2) == NULL){
        insertMap(city1->distancias,ciudad2,distancia);
     }

     if(searchMap(city2->distancias, ciudad1) == NULL){
        insertMap(city2->distancias,ciudad1,distancia);
     }

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


void ImportarCiudades( HashMap * Ciudades){
    system("cls");
    printf("Please enter the file name (n_n) ");
    char name[50]; //the name of the file that has the games
    FILE * fp;
    Pair * check;

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


    printf("All the Cities were imported correctly (^_^) "); //message that pops out on the window if all the games were imported correctly
    system("pause");
    system("cls");



}


void  ciudadMasCercana (HashMap * Ciudades, char * nombreCiudad){

Ciudad * ciudad;
ciudad = searchMap(Ciudades,nombreCiudad);
//long Capacidad = mapcapactity(ciudad->distancias);
if (ciudad == NULL) return;
Pair* compare = firstMap(ciudad->distancias);
int menor = 900;
char * name;
int i;
while(compare != NULL){
   if  (menor > (compare->value) && (strcmp(compare->key,nombreCiudad)!= 0) ){
    menor = compare->value;
    name = compare->key;
   }
compare = nextMap(ciudad->distancias);
}
printf("%d %s \n",menor,name);
    system("pause");
    system("cls");
}

void crearRuta(HashMap* ciudades, char * nombreCiudad){


    Ciudad * ciudad = searchMap(ciudades, nombreCiudad);
    if (ciudad == NULL){
        return;
    }

    int i = 0;
    int distanciaTotal = 0;
    int cont;

    mostrarCiudadesAdyacentes(ciudad);
    Ciudad ** CiudadyDistancia = (Ciudad **)malloc (30*sizeof(Ciudad *));
    CiudadyDistancia[0] = ciudad;

    char nombreCiudadAdyacente[30];



    do{

        printf("\nIngrese otra ciudad: "); // se iran ingresando ciudades hasta que el usuario digite 0, si es asi, se sale del ciclo y termina
        fflush(stdin);

        do{
                   cont = 1;
                   scanf("%s",nombreCiudadAdyacente);

          if (strcmp(nombreCiudadAdyacente, "0") == 0){
            break;
        }else if  (searchMap(ciudades,nombreCiudadAdyacente)== NULL){
                     printf("Please enter a valid City\n");
                   }
                   else cont = 0;
                }while(cont==1);



        if (strcmp(nombreCiudadAdyacente, "0") == 0){
            break;
        }

        if( searchMap(ciudad->distancias, nombreCiudadAdyacente) == NULL){
            return;
        }

        //si nos movemos a la ciudad, entonces sumamos la distancia recorrida
        distanciaTotal += searchMap(ciudad->distancias, nombreCiudadAdyacente); //el mapa de distancias guarda como valor la distancia entre las dos ciudades

        Ciudad * ciudadAdyacente = searchMap(ciudades, nombreCiudadAdyacente);

        mostrarCiudadesAdyacentes(ciudadAdyacente);

        i++;

        CiudadyDistancia[i] = ciudadAdyacente;

        ciudad = ciudadAdyacente;

    }while (strcmp(nombreCiudadAdyacente, "0") != 0);



    printf("\nRecorrido: \n\n");

    printf("Comienzo: %s -> ", CiudadyDistancia[0]->nombre);

    for( i = 1 ; CiudadyDistancia[i] != NULL ; i++){

        if(CiudadyDistancia[i + 1] != NULL){

            printf("%s -> ", CiudadyDistancia[i]->nombre);

        }
        else{

            printf("Fin de la ruta: %s", CiudadyDistancia[i]->nombre);

        }

    }

    printf("\nDistancia total recorrida: %d KM", distanciaTotal);

    printf("\n");
    system("pause");
    system("cls");

}

 void mostrarCiudadesAdyacentes(Ciudad * ciudad ){

    Pair * adyacente= firstMap(ciudad->distancias);
    printf("\n");
    while(adyacente){
        printf("%s\n",adyacente->key);
        adyacente=nextMap(ciudad->distancias);
    }

}



