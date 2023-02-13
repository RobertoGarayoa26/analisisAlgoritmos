def cuenta(monedas, n, sum):

    #table[i] almacenará el número de soluciones para el valor i.
    #Necesitamos filas de suma + 1 ya que la tabla se construye de manera ascendente utilizando
    #el caso base (suma = 0) Inicialice todos los valores de la tabla como 0
    tabla = [0 for k in range(sum+1)]                       #O(1)

    #Caso base: Si el valor dado es 0
    tabla[0] = 1                                            #O(1)

    #Elija todas las monedas una por una y actualice los valores de la tabla[]
    #después del índice mayor o igual que el valor de la moneda elegida
    for i in range(0, n):                                   #O(1)
        for j in range(monedas[i], sum+1):                  #O(n)
            tabla[j] += tabla[j-monedas[i]]                 #T(n-1)+O(1)

    return tabla[sum]                                       #T(n-1)

monedas = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000]        #O(1)
n = len(monedas)                                            #O
sum = 250                                              #O(1)
x = cuenta(monedas, n , sum)
print(x)