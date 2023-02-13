#include<stdio.h>
#include<string.h>

// Función para obtener el número mayor entre 2 números
int max (int x, int y) { return (x > y)? x : y; }

// Retorna en la variable "sequence" la longitud de la subsecuencia palindrómica más grande
int longestPalindromic(char *sequence, int i, int j){
	//Caso base 1: Si sólo existe 1 elemento en la palabra
	if (i == j)
		return 1;

	//Caso base 2: Si hay 2 caracteres en la palabra y además ambos son iguales
	if (sequence[i] == sequence[j] && i + 1 == j)
		return 2;

	// Si el primero y el último caracter coinciden
	if (sequence[i] == sequence[j])
		return longestPalindromic(sequence, i+1, j-1) + 2;

	//Si el primer y el ultimo caracter NO coinciden
	return max( longestPalindromic(sequence, i, j-1), longestPalindromic(sequence, i+1, j) );
}

//Main
int main(){
	char sequence[] = "BB";
	int n = strlen(sequence);
	printf ("The length of the LPS is %d\n", longestPalindromic(sequence, 0, n-1));
	getchar();
	return 0;
}
