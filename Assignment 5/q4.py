n=int(input())
import numpy as np
a=np.full(n,'a',dtype=str)
for i in range(0,n):
    a[i]=input()
    print(a[i])
print(a)

def numwords(a):
    b=[0]*len(a)
    for i in range(0,len(a)):
        a[i]=a[i].replace(","," ")
        a[i]=a[i].replace("."," ")
        b[i]=len(a[i].split())
    k=min(b)
    return k
print('%.2f'%numwords(a))