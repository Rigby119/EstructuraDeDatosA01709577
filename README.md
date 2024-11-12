# Proyecto: Pokedex Viewer
Una herramienta para visualizar una base de datos tipo pokedex en la que puedes acceder y organizar la información sobre distintos pokemones.

El objetivo principal del proyecto es almacenar y organizar datos clave de cada pokémon, permitiendo ordenar esta información de acuerdo con diferentes criterios y preferencias del usuario. También se permite al usuario buscar la entrada específica de un pokémon y de varios pokemons del mismo tipo.

## Descripción del avance 1
El primer avance incluye la posibilidad de usar los datos almacenados en un archivo txt (que después podríamos cambiar a otro tipo de archivo) y guardarlos en los vectores correspondientes.

## Descripción del avance 2
El segundo avance incluye la posibilidad de usar los vectores creados en el avance anterior para poder ordenar la información usando diferentes indicadores, una vez ordenada la información, también permite mostrarla de diferentes maneras y buscar un pokemon específico para mostrar sus datos.

### Cambios sobre el primer avance
1. Al principio el programa usaría solamente las estructuras de datos tipo Vector, sin embargo para una mejor demostración de los temas vistos en clase y mayor eficacia en las busquedas de multiples datos, decidí usar también Stack

## Descripción del avance 3
Este tercer avance incluye la funcionalidad completa del programa, permitiendo al usuario acceder a todas las funciones de la herramienta y al final de cada sesión, guardar los cambios hechos en la pokedex en su respectiva base de datos.

### Cambios sobre el segundo avance
Más que nada terminé de implementar las funciones que tenía en el segundo avance
1. El programa solo iba a ordenar la base de datos y luego la iba a guardar, pero para que tuviera mayor utilidad, ahora puede ser utilizado para buscar y filtrar información de la base de datos. Para esto añadí un menu con el que el usuario puede interactuar.

## Instrucciones para compilar el avance de proyecto
### Main.cpp
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 dataOrganizer.h pokemon.h main.cpp`

## Instrucciones para ejecutar el avance de proyecto
### Main.cpp
Ejecuta el siguiente comando en la terminal:

Windows:
`.\a.exe`
Linux o Mac:
`.\a.out`

## Descripción de las entradas del avance de proyecto
El sistema puede leer un archivo de texto (databaseKanto.txt o databaseNational.txt) que contiene la información de los pokémon, y luego almacenar estos datos en un vector de objetos Pokemon. Este archivo se estructura de la siguiente manera:

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
Durante la ejecución, el programa muestra las salidas que el usuario va pidiendo y al final de este, el archivo de database, será actualizado según el ultimo acomodo del usuario

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
MergeSort es el método que ocupé para ordenar los datos, ya que maneja mejor los datos repetidos y mantiene una complejidad de O(n log n) en todos los casos.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Este proyecto almacena la información en un vector para acceder a datos en posiciones aleatorias en tiempo constante O(1).

Y también usa Stack para busquedas en las que queremos obtener los datos en el orden que los fuimos añadiendo, igual con complejidad O(1) para este caso.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El resto de funciones incluye su análisis de complejidad en el código en dónde está implementada en forma de comentario.

El programa en sí tendrá una complejidad de al menos O(n) debido a que esta es la complejidad de la lectura de archivo este sería el mejor caso, en el caso promedio, el programa tendrá una complejidad de O(n) también o O(nlogn) dependiendo qué funciones ejecute el usuario debido a que las funciones de todos() y tipos() pasan por todos los datos de la base de datos. Cómo peor caso podríamos decir que la complejidad es O(i) dónde i es la cantidad de veces que el usuario se mantiene dentro del ciclo, pudiendo hacer multiples operaciones.

### SICT0302: Toma decisiones
#### Selecciona y usa una estructura de datos adecuada al problema
Este proyecto almacena la información en un vector, principalmente porque con este podemos acceder a datos en posiciones aleatorias en tiempo constante O(1) y tienen una buena flexibilidad para ajustar automáticamente su tamaño por si queremos agregar más pokémon a la base de datos.

También es muy útil porque nuestro algoritmo de MergeSort son más fácil de programar usando vectores, ya que permiten un fácil acceso y manipulación de los elementos.

Por otro lado, la función de busqueda por tipos usa la estructura de Stack para almacenar temporalmente los Pokemones que vaya encontrando, una vez terminada la busqueda podemos acceder facilmente al total de elementos gracias a .size, y dependiendo de si el usuario quiere o no ver los datos, podemos llamar .top() y .pop() o solo .pop(), esta estructura facilita mucho la retención temporal de elementos ya que el método .pop() elimina los datos del stack para que podamos después añadir nuevos elementos al mismo en otra busqueda.

Escogí esta estructura debido a la necesidad de mostrar al usuario los datos encontrados en el mismo orden en el que fueron encontrados, al mismo tiempo, esta estructura permite mantener nuestra complejidad de O(1) 

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se ha realizado un análisis de la complejidad para cada algoritmo de ordenamiento revisado en clase. El QuickSort podría ser más rápido en la mayoría de los casos al ordenar por ID, pero nuestro programa puede ordenar por otros dos parámetros que sí se repiten y son muy variables. Es por esto que se eligió el MergeSort para ordenar los datos, ya que maneja mejor los datos repetidos y mantiene una complejidad de O(n log n) en todos los casos.

### SICT0303B: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de buscar pokemones por nombre así como mostrar la información de todos los pokemones ordenados por el atributo seleccionado.

Para esto se hace uso principalmente de el llamado a un elemento de nuestro vector de apuntadores usando el índice del elemento dentro de corchetes y por otro lado, en el caso del Stack se usa el método .top() para conocer el siguiente valor accedible del Stack.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La función principal del programa para leer datos, almacena cada dato temporalmente hasta tener todos los atributos del pokemon y en ese momento crea el objeto Pokemon con dichos atributos, posteriormente se une su apuntador al vector principal y se pasa al siguiente Pokemon. En el caso del Stack, simplemente se añaden los apuntadores ya creados a la pila, para ir sacandolos de uno por uno.

#### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
Los pokemones están registrados en el archivo databaseUnsorted.txt de donde se leen al iniciar el programa. En este mismo archivo se guardan los datos al terminar y siempre se usa la misma estructura para guardar y leer la información almacenada.