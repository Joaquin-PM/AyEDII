### ¿Qué relación implementa la función *goes_before()*?¿Cuál es el criterio que usa?
La función ***goes_before()*** recibe 2 enteros y te retorna un booleano que dice si el
primer elemento es menor que el segundo de acuerdo a su valor absoluto.

### Resultados del ejercicio 4
- UNSORTED-100000:
  - statistics for selection_sort ---> time elapsed = 27420.5 | comparisons: 704982704 | swaps: 100000
  - statistics for insertion_sort ---> time elapsed = 35798.1 | comparisons: 2498635594 | swaps: 2498535610
  - statistics for quick_sort ---> time elapsed = 32.365 | comparisons: 3547068 | swaps: 360595

- SORTED-DESC-10000:
  - statistics for selection_sort --> time elapsed = 357.913 | comparisons: 49995000 | swaps: 10000
  - statistics for insertion_sort --> time elapsed = 717.392 | comparisons: 49995000 | swaps: 49995000
  - statistics for quick_sort --> time elapsed = 411.248 | comparisons: 74990000 | swaps: 9999

- SORTED-ASC-10000:
  - statistics for selection_sort --> time elapsed = 287.392, comparisons: 49995000, swaps: 10000
  - statistics for insertion_sort --> time elapsed = 0.143, comparisons: 10398, swaps: 399
  - statistics for quick_sort --> time elapsed = 526.107, comparisons: 96110645, swaps: 9626

#### CONCLUSIÓN:
- Para listas desordenadas el quick_sort es ampliamente superior y a mas aumenta la cantidad a ordenar mas hace la diferencia en tiempo.
- Para listas ordenadas el insertion_sort fue mucho mejor.
- Para listas ordenadas al revés selection_sort y quick_sort tardaron parecido, al insertion_sort parece que le costo notoriamente mas. 
  Creo que si la lista fuera mas grande eventualmente el quick_sort le sacaria mucha ventaja al selection_sort.
