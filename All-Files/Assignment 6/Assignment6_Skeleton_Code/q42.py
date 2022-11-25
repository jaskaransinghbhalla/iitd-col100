a=[[1,2,3,4,5],[5,7,8,9,10]]
b=[[1,1],[1,1],[1,1],[1,1],[1,1]]

for x in range(0,5):
    for y in range(0,2):
        b[x][y]=a[y][x]
print(b)