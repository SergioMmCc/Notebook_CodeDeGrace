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

    # Metodos de sets
    # No tiene elementos repetidos, no esta ordenado
    s = {1, 2, 3} # Declarar
    s.add(4) # Agregar un elemento
    s.remove(4) # Eliminar un elemento. Si el elemento no esta lanza un error
    s.discard(4) # Tambien elimina un elemento pero si no esta no genera error
    x = s.pop() # Elimina y retorna un elemento arbitrario
    s.clear() # Vacía el conjunto
    s1 = {1, 2}
    s2 = {2, 3}
    s3 = {4, 5, 6}

    # Metodos de operaciones de conjuntos
    # Union de conjuntos
    s4 = s1.union(s2, s3)
    s4 = s1 | s2 | s3

    # Interseccion de conjuntos
    s4 = s1.instersection(s2, s3)
    s4 = s1 & s2 & s3

    # Retorna lo que esta en el primer conjunto pero no en los demas
    s4 = s1.difference(s2, s3)
    s4 = s1 - s2 - s3

    # Los elementos que solo estan en un conjunto
    # Se recomienda usarla solo para dos conjuntos
    s4 = s1.symmetric_difference(s2).symmetric_difference(s3)
    s4 = (s1 ^ s2) ^ s3

    
    # Metodos para relaciones de conjuntos

    s1.issubset(s2) # Devuelve True si s1 es subconjunto de s2
    s1.issuperset(s2) # Devuelve True si s1 es superconjunto de s2
    s1.isdisjoint(s2) # Devuelve True si no tienen elementos en comun


    # Metodos de actualizacion

    # Actualiza s1 con la union entre s1 y s2
    s1.update(s2) 
    s1 |= s2

    # Actualiza s1 con la interseccion entre s1 y s2
    s1.intersection_update(s2)
    s1 &= s2

    # Actualiza s1 eliminando los elementos que estan en s2
    s1.difference_update(s2)
    s1 -= s2

    # Actualiza s1 con la diferencia simetrica entre s1 y s2
    s1.symmetric_difference_update(s2)
    s1 ^= s2


    # SortedSet puede hacer todo eso, pero esta ordenado y tambien tiene:
    # pip install sortedcontainers -> Instalacion
    from sortedcontainers import SortedSet
    s = SortedSet([1, 2, 3, 4]) # Declarar
    mini = s.pop() # Retorna el elemento menor
    cond = 2 in s # Retorna True si s esta en s
    i = s.index(2) # Retorna la posicion de 2 (0-index)
    s.update([4, 5, 7]) # Agrega elementos
    s.bisect_left(6) # Retorna el indice en que se insertaria el 6
    s.bisect_right(3) # Lo mismo que bisect_left pero si el elemento ya 
                      # esta en s entonces devuelve su posicion + 1

main()