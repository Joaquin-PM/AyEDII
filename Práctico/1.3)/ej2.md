# Ejercicio 2)
###### a)
~~~
fun tiene_cima(a: array[1..n] of T) ret b: bool
    var j,i: nat
    b := true
    i := 1
    while(i < n & a[i] < a[i+1]) do
        i++
    od
    j := i
    while j < n & b do
        b := a[j] > a[j+1]
        j++
    od
end proc
~~~

###### b)
~~~
fun cima_donde(a: array[1..n] of T) ret k: nat
    k := 1
    while k < n & a[k] < a[k+1] do
        k++
    od
end proc
~~~


        
        





      
