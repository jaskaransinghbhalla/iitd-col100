l = []
n = int(input())
def Join(l,id):
    l.append(id)
    return

def Issue(l):
    if(len(l)==0):
        print("Invalid")
    else:
        del[l[0]]
    return

def GetLine(l):
    if(len(l)==0):
        print("Invalid")
    else:
        for i in l:
            print(i, end = " " )
        print(end="\n")
    return

def Check(l):
    if(len(l)==0):
        print("Invalid")
    else:
        print(l[0])
    return 

for i in range (n):
    query = input()
    if(query=="Check"):
        Check(l)
    elif(query=="GetLine"):
        GetLine(l)
    elif(query=="Issue"):
        Issue(l)
    else:
        Join(l,query[len(query)-1])
        