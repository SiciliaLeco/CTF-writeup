import sympy
p = 845529816183328832288826827978944092433
g = 419182772165909068703324756801961881648
A = 803331951724823196054726562340183173391
B = 382083902245594277300548430928765321436
a = sympy.discrete_log(p, A, g)
print(a)
s1 = pow(B, a, p)
print(s1)
