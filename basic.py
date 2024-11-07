# Es importante tener en cuenta que python es aproximadamente 40 veces mas lento que C++

import array as arr # Para trabajar con arrays
import numpy as np

def main ():
    # Leer una linea completa, separar los elementos por los espacios y almacenarlos en una lista
    read = input()
    numbers = read.split()
    numbers = list(map(int, numbers)) # 'map' si permite repeticiones, en cambio 'set' no

    #Leer un entero
    n = int(input())

    # Leer un número flotante
    d = float(input())

    # Leer una cadena
    s = input()

    # Tamaño de una cadena
    x = len(s)

    # Agregar un caracter a una cadena
    s2 += s1[i]
    s2 += 'a'

    # Negar un bool
    cond = True
    not cond # Esto seria False

    # Potencia de un numero
    ans = base ** exp

    # Ciclo for
    for i in range (0, 5): # Esto iria hasta el 4
    for auto in autos: # autos seria una lista

    # Condicionales
    if(cond1):
    elif(cond2):
    else:

    # Minimo y maximo
    mina = min(mina, number)
    maxa = max(maxa, number)

    # Convertir un numero binario (guardado como cadena) en un entero base 10
    n10 = int(n2, 2)

    # Pasar un numero de base 10 a base 2 (se convierte a cadena)
    ans2 = bin(ans10)[2:]

    # Evaluar una string que es una expresion matematica (tambien puede tener parentesis)
    result = eval(expresion)

    # Metodos de listas (list)
    # Resaltar que una sola lista puede contener varios tipos de datos, incluida otra lista
    lista = [1, "dos", [3, "cuatro"], 5.0, True] # Declarar
    lista.append(6) # Agregar un elemento
    lista.remove('dos') # Eliminar un elemento
    lista.sort() # Ordenar
    print(lista) # Imprimir toda la lista
    lista.extend([7, 8])  # Agrega 7 y 8 a la lista
    lista.insert(1, 'a') # Inserto 'a' en la posicion 1, el resto de elementos corren un espacio a la derecha
    n = lista.pop() # Elimina el ultimo elemento de la lista y se lo asigna a 'n'
    n = lista.pop(3) # Elimina el ultimo en la posicion 3 de la lista y se lo asigna a 'n'
    lista.clear() # Elimina todos los elementos la lista, quedando: lista = []
    lista.reverse # Invierte los elementos de la lista
    indice = lista.index("cuatro") # Devuelve el indice de la primera aparicion de "cuatro"
    indice2 = lista.index(x, start) # Comienza a buscar desde el indice start
    indice3 = lista.index(x, start, end) # Devuelve la primera aparicion de x en el rango [start, end)
    conteo = lista.count(x) # Devuelve el numero de veces que aparece 'x' en la lista

main()