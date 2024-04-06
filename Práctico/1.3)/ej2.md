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

###### c)
~~~
fun cima_dondeBin(a: array[1..n] of T) ret k: nat
    k := cima_dondeBin_rec(a,1,n)
end fun
~~~
~~~
fun cima_dondeBin_rec(a: array[1..n] of T, izq,der: nat) ret k: nat
    var mid: nat
    var b: bool
    mid := (izq+der)/2
    if (mid = i | a[mid] > a[mid-1]) & (mid = n | a[mid] < a[mid+1]) then
        k := mid
    if a[mid-1] < a[mid] < a[mid+1] then
        k := cima_dondeBin_rec(a,mid+1,der)
    if a[mid-1] > a[mid] > a[mid+1] then
        k := cima_dondeBin_rec(a,lft,mid-1)
    fi
end fun
~~~

###### d)



        
        





      
