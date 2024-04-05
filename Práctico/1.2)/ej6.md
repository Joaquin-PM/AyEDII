# Ejercicio 6)
~~~
proc partition_Alt(in/out a: array[1..n] of T, in lft,rgt: nat, out pivot_lft,pivot_rgt: nat)
    var pivot_val: T
    var i, j, k: nat
    j := rgt
    i := lft
    k := lft + 1
    pivot_val := a[lft]
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
    pivot_lft := i + 1 
    pivot_rgt := k
end proc
~~~
~~~
proc quick_sort_rec_Alt(in/out a: array[1..n] of T, in lft,rgt: nat)
    if rgt > lft then
        partition_Alt(a, lft, rgt)
        quick_sort_rec_Alt(a, lft, pivot_lft)
        quick_sort_rec_Alt(a, pivot_rgt, rgt)
    fi
end proc
~~~









