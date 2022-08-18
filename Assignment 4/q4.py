n=int(input())
i=0
a=65
while(i<=n):
    j=1
    k=1
    while(j<=i):
        print(" ",end=" ")
        j=j+1
    while(k<=(n-i)):
        print(chr(a),end=" ")
        k=k+1
    a=a+1
    i=i+1
    print()