set terminal png size 800,600
set output 'comparacion_algoritmos.png'
set title "Comparación de Algoritmos de Ordenamiento"
set xlabel "Tamaño de Entrada (n)"
set ylabel "Tiempo de Ejecución (s)"
set grid
set key left top
set yrange [0:*]  # Ajusta automáticamente hasta el máximo valor
plot \
    "bubble.txt" using 1:2 with linespoints title "Bubble Sort", \
    "selection.txt" using 1:2 with linespoints title "Selection Sort", \
    "insertion.txt" using 1:2 with linespoints title "Insertion Sort", 
