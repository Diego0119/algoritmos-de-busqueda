set terminal png size 800,600
set output 'grafico.png'
set title "Desempeño de Selection Sort"
set xlabel "Tamaño de Entrada (n)"
set ylabel "Tiempo de Ejecución (s)"
set grid
plot "resultados.txt" using 1:2 with linespoints title "Selection Sort"
