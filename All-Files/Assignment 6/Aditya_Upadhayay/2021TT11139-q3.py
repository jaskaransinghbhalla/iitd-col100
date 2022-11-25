# This is the starter code for COL100 Assignment 6 question 3
# There are different functions in this question that you have to fill 


# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.


# You can only use arrays or lists to store your data and are not allowed to import anything
line=[]
bill=[]
def maxlist(list_name):
    for x in range(0,len(list_name)):
            if max(list_name)==list_name[x]:
                k=[]
                k.append(x)
                return k
def Highest():
    if len(line)==0:
        return "Invalid"
        
    else:
        m1=maxlist(bill)
        m=line[m1[0]]
        return m
    # This is the highest function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    

def Order(orderID: int, BillValue:int):
    line.append(int(orderID))
    bill.append(int(BillValue))
    # This is the order operation as mentioned in the pdf
    # This takes in two values orderID and the bill value
    # You will have to parse the input and call this function wherever needed.
    # It doesn't need to return anything,
    # you could return a value if it helps your implementaton
    return

def Serve():
    if len(line)==0:
        print("Invalid")
        return
    else:
        m2=maxlist(bill)
        k1=bill.pop(m2[0])
        k2=line.pop(m2[0])
        return
    # This is the serve function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    Order(5,20) # Order 5 20
    # Note that you have to parse the input and then send values in the function like done here
    Highest() # Highest
    Order(4,100) # Order 4 100
    Highest() # Highest
    Order(3,100) # Order 3 100
    Highest() # Highest
    Serve() # Serve
    Highest() # Highest
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code

#testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder

n=int(input())
for x in range(0,n):
    a=input()
    lis=a.split(" ")
    if lis[0]=="Order":
        Order(lis[1],lis[2])
    elif lis[0]=="Serve":
        Serve()    
    elif lis[0]=="Highest":
        print(Highest())