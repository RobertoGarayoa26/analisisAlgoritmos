/*
Randomize Binary Search utilizando la estrategia de Divide-and-conquer con recursividad.

Descripción del problema:
    "Nos dan una matriz ordenada de A[] de n elementos. Necesitamos encontrar si x está presente en A o no. En la búsqueda binaria siempre se usa el elemento medio, en este problema se deberá de elegir al azar un elemento en el rango dado."

    En Binary Search se tiene:
        medio = (inicio + final)/2

    En Randomize Binary Search se tiene:
        Generación de un número aleatorio "randomNum"
        Dado que el rango de números en el que queremos un numero aleatorio es [inicio, final]
        Por lo tanto, hacemos:
            randomNum = randomNum%(final-inicio+1)
        Entonces
            randomNum = inicio + randomNum
        Por lo tanto, randomNum es un número aleatorio entre el inicio y el final

Propuesta para la resolución:
*/

#include <iostream>
#include <ctime>
using namespace std;

//Función que generará un número aleatorio entre inicio y final y lo retornará
int getRandom(int inicio, int final){                   //O(1)
    srand(time(NULL));                  //O(1)
    return (inicio + rand() % (final - inicio + 1));                //O(1)
}

/*
Una función de un Radomize Binary Search
regresa la ubicación de "inicio" en un arreglo dado arr[izq..der] si está presente el número, sino retorna un "-1"
*/
int randomBinSearch(int arr[], int izq, int der, int inicio){

    if(der >= izq){                 //O(1)
        //Aquí se define el "medio" como un índice random entre izq y der
        int medio = getRandom(izq, der);                    //O(1)

        //Si el elemento se encuentra presente en el medio entonces..
        if(arr[medio] == inicio)                        //O(1)
            return medio;

        //Si el elemento es menor que el medio, entonces sólo puede estar presente en el subarreglo de la izquierda
        if(arr[medio] > inicio)                 //O(1)
            return randomBinSearch(arr, izq, medio-1, inicio);                  //T(n-1)+O(1)

        //Si no sucede lo anterior, entonces el elemento se encuentra en el subarreglo de la derecha
        return randomBinSearch(arr, medio+1, der, inicio);                  //T(n-1)+O(1)

    }

    //En caso de que no se encuentra el elemento en medio del arreglo
    return -1;

}

//Main
int main(void){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};                 //O(1)
    int number = sizeof(arr)/sizeof(arr[0]);
    int inicio = 5;
    int result = randomBinSearch(arr, 0, number-1, inicio);
    (result == -1) ? printf("El elemento no esta presente en el arreglo") : printf("El elemento esta presente en el index %d", result);
    return 0;
}