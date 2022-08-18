from cmath import sqrt
a=int(input())
b=int(input())
c=int(input())
D=b**2-4*a*c
q1=(-b+sqrt(D))/(2*a)
q2=(-b-sqrt(D))/(2*a)
QR1=q1.real
QI1=q1.imag
QR2=q2.real
QI2=q2.imag    
print('%.2f' %QR1,'%.2f' %QI1,sep=" ")
print('%.2f' %QR2,'%.2f' %QI2,sep=" ")