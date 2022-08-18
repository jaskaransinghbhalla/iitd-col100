def addition(a,b):
    k=a+b
    print(int(k))
def subtraction(a,b):
    k=a-b
    print(int(k))
def multiplication(a,b):
    k=a*b
    print(int(k))
def division(a,b):
    k=a/b
    print(int(k))
def modulus(a,b):
    k=a%b
    print(int(k))

a=int(input())
b=int(input())
c=int(input())

if(c==1):
    addition(a,b)
elif(c==2):
    subtraction(a,b)
elif(c==3):
    multiplication(a,b)
elif(c==4):
    division(a,b)
elif(c==5):
    modulus(a,b)