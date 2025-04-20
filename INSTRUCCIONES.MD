# Proyecto de Algoritmos de Búsqueda

Este proyecto implementa varios algoritmos de búsqueda y ordenamiento en C, utilizando un archivo CSV como fuente de datos. Los algoritmos incluyen Bubble Sort, Insertion Sort, Selection Sort, Búsqueda Binaria y Búsqueda Secuencial.

## 📋 Requisitos
- Tener instalado `make` para gestionar la compilación.

## 🚀 Instrucciones para Compilar y Ejecutar

### 1️⃣ Compilación
1. Abre una terminal en la raíz del proyecto.
2. Ejecuta el siguiente comando para compilar el proyecto:
   make

Esto generará un archivo ejecutable en la carpeta build/ con el nombre program.out.

2️⃣ Ejecución
Para ejecutar el programa, utiliza el siguiente comando:
./do <opciones>

3️⃣ Opciones Disponibles
El programa soporta los siguientes comandos:

--help: Muestra la ayuda del programa.
--generate <cantidad>: Genera un archivo CSV con productos aleatorios.
--bubble-sort <campo>: Ordena los datos usando Bubble Sort.
--insertion-sort <campo>: Ordena los datos usando Insertion Sort.
--selection-sort <campo>: Ordena los datos usando Selection Sort.
--binary-search <campo> <valor>: Realiza una búsqueda binaria en el campo especificado.
--sequential-search <campo> <valor>: Realiza una búsqueda secuencial en el campo especificado.
--stats: Muestra estadísticas del inventario

4️⃣ Ejemplos de Uso
Generar un archivo CSV con 100 productos:
./do --generate 100

Ordenar los productos por precio usando Bubble Sort:
./do --bubble-sort Precio

5️⃣ Limpieza
Para limpiar los archivos generados durante la compilación, ejecuta:
make clean