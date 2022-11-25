a=float(input())
b=float(input())
c=float(input())
    
if(a>b):
    if(a>c):
        print('%.2f' %a)
    else:
        print('%.2f' %c)
else:
    if(b>c):
        print('%.2f' %b)
    else:
        print('%.2f' %c)
