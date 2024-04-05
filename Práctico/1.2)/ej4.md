# Ejercicio 4)
~~~
proc partition(in/out a:array[1..n] of T, in lft, rgt:nat, out ppiv:nat)
    var i, j, mid: nat
    ppiv := lft
    mid := (lft + rgt)/2
    i := lft + 1
    j := rgt
    if (a[lft] < a[mid] < a[rgt]) | (a[lft] > a[mid] > a[rgt]) then  
        swap(a, lft, mid)
    if (a[lft] < a[rgt] < a[mid]) | (a[lft] > a[rgt] > a[mid]) then  
        swap(a, lft, rgt)
    while i <= j do
        if a[i] <= a[ppiv] then
            i++
        if a[j] >= a[ppiv] then
            j--
        if a[i] > a[ppiv] & a[j] < a[ppiv] then     
            swap(a, i, j)
            i++
            j--
        fi
    od
end proc
~~~
