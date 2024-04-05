# Ejercicio 5)
~~~
proc position(in/out a: array[1..n] of int, in k: nat, out elem: int)
    var ppiv, lft, rgt: nat
    lft := 1
    rgt := n
    partition(a, lft, rgt, ppiv)
    while ppiv /= k do
        if ppiv > k then
            rgt := ppiv - 1
        if ppiv < k then
            lft := ppiv + 1
        fi
        partition(a, lft, rgt, ppiv)
    od
    elem := a[ppiv]
end proc
~~~
