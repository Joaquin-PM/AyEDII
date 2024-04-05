# Ejercicio 2)
##### a)
~~~
proc intercalar_cada_Alt(in/out a: array[1..2^n] of int, in i:nat)
    var k: nat
    k := 0
    while (k+1)*2*2^i <= 2^n do
        merge(a, k*2*2^i+1, (2*k+1)*2^i, (k+1)*2*2^i)
        k++
    od
end proc
~~~

##### b)
~~~
proc merge_sort_Alt(in/out a : array[1..2^n] of int)
    var i: nat
    while 2^i < 2^n do
        intercalar_cada_Alt(a, i)
        i++
    od
end proc
~~~
