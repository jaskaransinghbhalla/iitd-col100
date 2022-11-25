from re import I


n=int(input())
i=1

count=1
while(i<=n):
    j=1
    while(j<=i):
        print(count,end=" ")
        count=count+1
        j=j+1
    i=i+1
    print()
    