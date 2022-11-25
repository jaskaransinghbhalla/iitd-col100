n=int(input())
i=1
while(i<=n):
    j=1
    while(j<=n):
        if((i==1) or (i==n)):
            print("*",end='')
        elif((j==1) or (j==n)):
            print("*",end='')
        else:
            print(" ",end='') 
        j=j+1
    print()
    i=i+1