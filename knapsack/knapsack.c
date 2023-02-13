/*Problema de la mochila utilizando recursividad.

Descripción del problema:
    -Teniendo los "pesos" y "valores" (o se podría considerar como la "prioridad" del objeto) de N-artículos, coloque esos artículos en una mochila de capacidad "pesoMax" para obtener el máximo valor total en la mochila. En otras palabras, teniendo 2 arreglos de enteros "val[0..., N-1]" y "peso[0..., N-1]" los cuales representan los valores y pesos asociados con N artículos respectivamente. También teniendo un entero pesoMax el cual representa la capacidad de la mochila, encuentra el máximo valor dentro de val[], como la suma de pesos de los artículos ya sean pequeños o iguales a pesoMax. No puedes partir un objeto, se tiene que meter el objeto o no meterlo dentro de la mochila (0 ó 1)-

Propuesta para la resolución:
    "Una solución simple es considerar todos los subconjuntos de los objetos o artículos y,  calcular su peso y valor de todos los subconjuntos. Y se va a considerar sólamente los subconjuntos los cuales el peso total sea menor que pesoMax. Para cada uno de los subconjuntos, se tomará el máximo valos del subconjunto".
*/
#include <stdio.h>


//Función que retorna el objeto máximo de 2 objetos/enteros
int max(int objct1, int objct2) { return (objct1 > objct2) ? objct1 : objct2; }                 //O(1)

//Máximo valor que se puede poner en la mochila de capacitad pesoMax
//Necesitaremos el peso máximo de la mochila, el arreglo del peso y del valor (prioridad) y una constante Objcts para el número de artículos
int mochila(int pesoMax, int peso[], int val[], int objcts){
    /*Caso base:
        Si no hay objetos para ingresar o no hay un peso máximo, retorna un 0 la función y ahí termina.*/
    if (objcts == 0 || pesoMax == 0)                    //O(1)
        return 0;


    /*Siguiente caso:
        Si el N objeto es mayor a la capacidad de la mochila, entonces no será agregado a la mochila y regresará la mochila como está antes del objeto.*/
    if (peso[objcts - 1] > pesoMax)
        return mochila(pesoMax, peso, val, objcts - 1);

    /*Regresar alguno de los 2 casos...
        Caso 1: El N-artículo SÍ es agregado
        Caso 2: El N-artículo NO es agregado
    */
    else
       return max(val[objcts - 1] + mochila(pesoMax - peso[objcts - 1], peso, val, objcts - 1), mochila(pesoMax, peso, val, objcts - 1));
}

//Main
int main(){
    int val[] = {360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147, 78, 256, 63, 17, 120, 164, 432, 35, 92, 110, 22, 42,50, 323, 514, 28, 87, 73, 78, 15, 26, 78, 210, 36, 85, 189, 274, 43, 33, 10, 19, 389, 276, 312};                  //O(1)
    int peso[] = {7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8, 15, 42, 9, 0, 42, 47, 52, 32, 26, 48, 55, 6, 29, 84, 2, 4, 18, 56, 7, 29, 93, 44, 71, 3, 86, 66, 31, 65, 0, 79, 20, 65, 52, 13};                   //O(1)
    int pesoMax = 1;                   //O(1)
    int objcts = sizeof(val)/sizeof(val[0]);                    //O(1)
    printf("El valor maximo que se puede juntar en la mochila es de %d\n", mochila(pesoMax, peso, val, objcts));
    printf("\n");
    return 0;
}