from math import factorial

A = tuple(factorial(i) for i in range(0, 101))
t = int(input())
for q in range(t):
    n = int(input())
    print(A[n])
