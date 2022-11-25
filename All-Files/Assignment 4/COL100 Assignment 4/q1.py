a=int(input())
x=int(input())
k=1    
while(a>0):
    if(a%x==0):
        k=k*a
    a=a-1
print(k)