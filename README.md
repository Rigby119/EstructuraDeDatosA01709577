# Proyecto: Pokedex Viewer
Una base de datos tipo pokedex que pueda acceder y organizar información sobre distintos pokemones. Aunque la pokédex oficial incluye más de 1025 pokémon, para fines prácticos, este proyecto maneja inicialmente los primeros 151 pokémon de la primera generación.

El objetivo principal del proyecto es almacenar y organizar datos clave de cada pokémon, permitiendo ordenar esta información de acuerdo con diferentes criterios y preferencias del usuario. Se implementan diferentes algoritmos de ordenamiento para lograr esto.

## Descripción del avance 1
El primer avance incluye la posibilidad de usar los datos almacenados en un archivo txt (que después podríamos cambiar a otro tipo de archivo) y guardarlos en los vectores correspondientes.

## Descripción del avance 2
El segundo avance incluye la posibilidad de usar los vectores creados en el avance anterior para poder ordenar la información usando diferentes indicadores, una vez ordenada la información, también permite mostrarla de diferentes maneras y buscar un pokemon específico para mostrar sus datos.

## Instrucciones para compilar el avance de proyecto
### Main.cpp
Ejecuta el siguiente comando en la terminal:

`g++ dataOrganizer.h pokemon.h main.cpp -o pokedexViewer`

### Pruebas.cpp
Ejecuta el siguiente comando en la terminal:

`g++ dataOrganizer.h pokemon.h pruebas.cpp -o pruebasPokedex` 

## Instrucciones para ejecutar el avance de proyecto
### Main.cpp
Ejecuta el siguiente comando en la terminal:

`.\pokedexViewer.exe`

### Pruebas.cpp
Ejecuta el siguiente comando en la terminal:

`.\pruebasPokedex.exe`

## Descripción de las entradas del avance de proyecto
El sistema puede leer un archivo de texto (databaseUnsorted.txt) que contiene la información de los pokémon, y luego almacenar estos datos en un vector de objetos Pokemon. Este archivo se estructura de la siguiente manera:

0001,Bulbasaur,Pla,Ven,310,051,sta

Dónde:

1° dato; 0001 es el ID del pokemon.
2° dato; Bulbasaur es el nombre del pokemon.
3° dato; Pla es el tipo primario del pokemon, Pla es tipo Planta por ejemplo.
4° dato; Ven es el tipo secundario del pokemon, Ven es tipo Veneno por ejemplo.
5° dato; 310 es la suma de las estadisticas del pokemon.
6° dato; 051 es el promedio de estadisticas del pokemon.
7° dato; sta es la categoria del pokemon, sta es por starter, las demás opciones son fos (fosil), pse (pseudo-legendario) y leg (legendario).

## Descripción de las salidas del avance de proyecto
El programa mostrará la lista de pokémon ordenada según la preferencia del usuario (por ID, suma de estadísticas o promedio de estadísticas). Además, puede mostrar todos los detalles de un pokémon específico seleccionado.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa.

En el archivo pruebas.cpp se prueban las funciones de:

findPokemon
clear
showSortData
showAllData
mergeSort y sus derivadas

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

Complejidad O(n)
    función de busqueda
    función de eliminado
    función de lectura de datos

complejidad O(1)
    función de imprimir información de un pokemon

complejidad O(n log n)
    función de ordenamiento (MergeSort)

Por implementar
    Eliminar una entrada al final O(1)
    Eliminar una entrada O(n) - O(log n)
    Agregar o insertar una entrada O(n)

### SICT0302: Toma decisiones
#### Selecciona y usa una estructura lineal adecuada al problema
Este proyecto almacena la información en un vector, principalmente porque con este podemos acceder a datos en posiciones aleatorias en tiempo constante O(1) y tienen una buena flexibilidad para ajustar automáticamente su tamaño por si queremos agregar más pokémon a la base de datos.

También es muy útil porque nuestro algoritmo de MergeSort son más fácil de programar usando vectores, ya que permiten un fácil acceso y manipulación de los elementos.

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se ha realizado un análisis de la complejidad para cada algoritmo de ordenamiento revisado en clase. El QuickSort podría ser más rápido en la mayoría de los casos al ordenar por ID, pero nuestro programa puede ordenar por otros dos parámetros que sí se repiten y son muy variables. Es por esto que se eligió el MergeSort para ordenar los datos, ya que maneja mejor los datos repetidos y mantiene una complejidad de O(n log n) en todos los casos.

### SICT0303B: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de buscar pokemones por nombre así como mostrar la información de todos los pokemones ordenados por el atributo seleccionado.

#### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
Los pokemones están registrados en el archivo databaseUnsorted.txt de donde se leen al iniciar el programa.