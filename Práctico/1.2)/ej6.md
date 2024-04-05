# Ejercicio 6)
~~~
proc partition(in/out a: array[1..n] of T, in izq, der: nat, out pivot_izq, pivot_der: nat)
    var pivot_val: T
    var i, j, k: nat
    j := der
    i := izq
    k := izq + 1
    pivot_val := a[izq]
    while k <= j do
        if a[k] = pivot_val then
            k++
        if a[k] < pivot_val then
            swap(a, k, i)
            k++
            i++
        if a[k] > pivot_val then
            swap(a, k, j)
            j--
        fi
    od
    pivot_izq := i + 1 
    pivot_der := k
end proc
~~~
