from cmath import sqrt

a=int(input())
b=int(input())
c=int(input())
D=b**2-4*a*c
q1=(-b+sqrt(D))/(2*a)
q2=(-b-sqrt(D))/(2*a)

if(q1.real == int(q1.real)):
    QR1=int(q1.real)
else:
    QR1=q1.real
    QR1=round(QR1,2)
    
if(q1.imag == int(q1.imag)):
    QI1=int(q1.imag)
else:
    QI1=q1.imag
    QI1=round(QI1,2)

if(q2.real == int(q2.real)):
    QR2=int(q2.real)
else:
    QR2=q2.real
    QR2=round(QR2,2)
    
if(q2.imag == int(q2.imag)):
    QI2=int(q2.imag)
else:
    QI2=q2.imag
    QI2=round(QI2,2)
    
print(QR1,QI1,sep=" ")
print(QR2,QI2,sep=" ")