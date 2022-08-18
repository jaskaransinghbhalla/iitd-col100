n=int(input())
a=[0]*n
for i in range(0,n):
    a[i]=input()
def numwords(a):
    b=[0]*len(a)
    for i in range(0,len(a)):
        a[i]=a[i].replace(","," ")
        a[i]=a[i].replace("."," ")
        b[i]=len(a[i].split())
    k=min(b)
    return k
print('%.2f'%numwords(a))
