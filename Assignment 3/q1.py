


a=float(input())
b=float(input())
c=float(input())

if(a==int(a)):
    a=int(a)
else:
    a=round(a,2)
if(b==int(b)):
    b=int(b)
else:
    b=round(b,2)
    
if(c==int(c)):
    c=int(c) 
else:
    c=round(c,2) 
    
if(a>b):
    if(a>c):
        print(a)
    else:
        print(c)
else:
    if(b>c):
        print(b)
    else:
        print(c)
