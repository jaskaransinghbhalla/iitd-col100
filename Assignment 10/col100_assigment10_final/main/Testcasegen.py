#Test case generator for assignment 10

import random
t=int(input())
file1=open("Test.txt", "w")
file1.write(str(t)+"\n")

def append():
    s="append "+str(random.randint(0,1000))+"\n"
    return s

def insert():
    s="insert "+str(random.randint(0,100))+" "+str(random.randint(0,1000))+"\n"
    return s

def pop():
    s="pop"+"\n"
    return s

def clear():
    s="clear"+"\n"
    return s

def count():
    s="count "+str(random.randint(0,1000))+"\n"
    return s

def reverse():
    return "reverse"+"\n"

def leng():
    return "len"+"\n"

def setitem():
    return "setitem "+str(random.randint(0,100))+" "+str(random.randint(0,1000))+"\n"
def getitem():
    return "getitem "+str(random.randint(0,100))+"\n"

def erase():
    return "erase "+str(random.randint(0,100))+"\n"

def swap():
    return "swap "+str(random.randint(0,100))+"\n"

def index_into(n):
    s="index_into "+str(n)+" "
    for i in range(n):
        s+=str(random.randint(0,50))+" "

    return s+"\n"

def sort():
    return "sort "+"\n"

def print0():
    return "print\n"

for i in range(t):
    r=random.randint(1, 18)
    if (r==1):
        file1.write(append())

    elif r==2:
        file1.write(insert())

    elif r==3:
        file1.write(pop())

    elif r==4:
        file1.write(clear())

    elif r==5:
        file1.write(count())

    elif r==6:
        file1.write(reverse())

    elif r==7:
        file1.write(leng())

    elif r==8:
        file1.write(setitem())

    elif r==9:
        file1.write(getitem())

    elif r==10:
        file1.write(erase())

    elif r==11:
        file1.write(swap())

    elif r==12:
        r1=random.randint(1,20)
        file1.write(index_into(r1))

    elif r==13:
        file1.write(sort())

    else:
        file1.write(print0())

file1.close()

        


        

















    
        
    
    
