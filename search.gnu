set terminal png size 800,600
set output 'busquedas.png'
set title "Comparación de Tiempos de Búsqueda"
set xlabel "Tamaño del arreglo"
set ylabel "Tiempo de Ejecución (s)"
set grid
plot "secuencial.txt" using 1:2 with linespoints title "Búsqueda Secuencial", \
     "binaria.txt" using 1:2 with linespoints title "Búsqueda Binaria"
