# Proyecto: Pokedex Viewer
Una base de datos tipo pokedex que pueda acceder y organizar información sobre distintos pokemones, lo ideal sería usar los 1025
(aproximadamente) pokemones que hay, sin embargo, para fines practicos empezaremos usando los primeros 151.

Guardaremos distintos datos de cada pokemon en dos vectores (todavía no está implementado de tal manera), uno de datos tipo int y otro de datos tipo string.

En el vector de int guardaremos cosas cómo el ID y los stats del pokemón, estos mismos datos nos servirán para ordenar de distintas maneras y de acuerdo a la preferencia del usuario los datos de cada pokemon. Este vector será ordenado pero el de string no, se planea que una vez ordenado el vector de int, se mostrará la información de cada pokemon de la siguiente manera:

int index = 0; // primer dato que en este caso es el ID
for (int attribute : vectorPokemonsInt) {
    if (index == 0) {
        std::cout << "#" << vectorPokemonsInt[index] << ": ";
        showPokemonsString(vectorPokemonsInt[index]); // Función que mostrará cada valor del vector de strings usando el ID cómo referencia
    } else if (index == vectorPokemonsInt.size - 1) {
        std::cout << vectorPokemonsInt[index] << std::endl;
    }
    else {
        std::cout << vectorPokemonsInt[index] << ", ";
    }
}

Basicamente mostrará el ID, luego todos los datos tipo string y luego los tipo int, si no también podríamos imprimir cada dato en el orden que queramos, pero haríamos un cout para cada valor (lo cuál visualmente podría verse mejor).

Para la organización de los vectores, usaremos diferentes algoritmos de ordenamiento.

Para ordenar por ID usaremos un quickSort, preferimos esta opción por su velocidad y como en este caso los datos son irrepetibles y son consecutivos por lo que dificilmente encontraremos un peor caso para el quicksort.

Para ordenar por statsPromedio y la suma de stats usaremos mergesort ya que al haber datos repetidos será un poco más eficiente al momento de comparar las separaciones que hace.

## Descripción del avance 1
Este primer avance incluye la posibilidad de usar los datos almacenados en un archivo txt (que después podríamos cambiar a otro tipo de archivo) y guardarlos en los vectores correspondientes.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance_PokedexViewer` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance_PokedexViewer.exe` 

## Descripción de las entradas del avance de proyecto
Por el momento la base de datos se encuentra en un archivo llamado database.txt el formato evidentemente es txt y los datos estan separados por línea, cada línea es un pokemon diferente y los datos están almacenados de la siguiente manera:

0001,Bulbasaur,Pla,Ven,310,051,sta

Dónde:

1° dato; 0001 es el ID del pokemon, los 0's serán eliminados posteriormente para ser guardados cómo ints
2° dato; Bulbasaur es el nombre del pokemon
3° dato; Pla es el tipo primario del pokemon, Pla es tipo Planta por ejemplo.
4° dato; Ven es el tipo secundario del pokemon, Ven es tipo Veneno por ejemplo.
5° dato; 310 es la suma de las estadisticas del pokemon
6° dato; 051 es el promedio de estadisticas del pokemon
7° dato; sta es la categoria del pokemon, sta es por starter, las demás opciones son fos (fosil), pse (pseudo-legendario) y leg (legendario)

## Descripción de las salidas del avance de proyecto
En este momento la salida es cada dato de la base de datos ordenado por ID

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
"Para la organización de los vectores, usaremos diferentes algoritmos de ordenamiento.

Para ordenar por ID usaremos un quickSort, preferimos esta opción por su velocidad y como en este caso los datos son irrepetibles y son consecutivos por lo que dificilmente encontraremos un peor caso para el quicksort.

Para ordenar por statsPromedio y la suma de stats usaremos mergesort ya que al haber datos repetidos será un poco más eficiente al momento de comparar las separaciones que hace."

Aquí resalto el porque de la elección de algoritmos para el proyecto y distingo entre los dos posibles casos que tengo (números repetidos y no repetidos) tomando en cuenta que el peor caso no es el mismo en ambas situaciones.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
La implementación del algoritmo es la misma que trabajamos en clase pero necesita de ciertos cambios para este proyecto, principalmente porque mi vector base es un vector que contiene vectores y no ints
