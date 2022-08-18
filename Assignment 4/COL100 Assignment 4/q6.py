import math
x=int(input())
n=int(input())
i=1

while(i<=n):
    k=(math.pow(-1,i))/math.pow(x,(2*i))
    print('%.2f' %k)
    i=i+1
    
