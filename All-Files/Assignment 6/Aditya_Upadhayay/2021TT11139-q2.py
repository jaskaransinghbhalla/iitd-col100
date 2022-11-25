# This is the starter code for COL100 Assignment 6 question 2
# There are different functions in this question that you have to fill 
# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.

# You can only use arrays or lists to store your data and are not allowed to import anything
l=list()
def Issue():
    if len(l)==0:
        print('Invalid')
    else:
        del(l[0])

def Join(AadharID: int):
    l.append(str(AadharID))

def Check():
    if len(l)==0:
        print('Invalid')
    else:
        print(l[0])

def GetLine():
    if len(l)==0:
        print('Invalid')
    else:
        print(" ".join(l))

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    Join(5) # Join 5
    # Note that you have to parse the input and then send values in the function like done here
    Check() # Check
    Join(4) # Join 4
    Check() # Check
    GetLine() # GetLine
    Join(3) # Join 3
    GetLine() # GetLine
    Issue() # Issue
    Check() # Check
    GetLine() # GetLine
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code

def inp():
    n=int(input())
    for x in range(0,n):
        a=input()
        lis=a.split(" ")
        if lis[0]=="Join":
            Join(lis[1])
        elif lis[0]=="Issue":
            Issue()    
        elif lis[0]=="Check":
            Check()
        elif lis[0]=="GetLine":
            GetLine()
#testcase()
inp()
#testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder