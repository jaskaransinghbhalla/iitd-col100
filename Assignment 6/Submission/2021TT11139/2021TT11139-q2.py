# This is the starter code for COL100 Assignment 6 question 2
# There are different functions in this question that you have to fill 
# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code
# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.
# You can only use arrays or lists to store your data and are not allowed to import anything
# This is the Issue function as mentioned in the pdf
# It takes no parameters and doesn't need to return anything,
# you could return a value if it helps your implementaton
# This is the Join operation as mentioned in the pdf
# This takes in one value the AadharID and adds the person to the line
# You will have to parse the input and call this function wherever needed.
# It doesn't need to return anything,
# you could return a value if it helps your implementaton
# This is the Check function as mentioned in the pdf
# It takes no parameters and doesn't need to return anything,
# you could return a value if it helps your implementaton
# This is the GetLine function as mentioned in the pdf
# It takes no parameters and doesn't need to return anything,
# you could return a value if it helps your implementaton
# Here we have not called print statements and that is upto you to do
# You could return values and then print or print in the function itself
# You can do whatever you like as long as the functions are used in the code
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder
# The example in the pdf has the following operations
# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
# Note that you have to parse the input and then send values in the function like done here
line=[]
output=[]

def Issue():
    if len(line)==0:
        output.append("Invalid")
    else:
        line.pop(0)

def Join(AadharID: int):
    line.append(AadharID)

def Check():
    if len(line)==0:
        output.append("Invalid")
    else:
        k=line[0]
        output.append(k)

def GetLine():
    if len(line)==0:
        output.append("Invalid")
    else:
        k=""
        for x in range(0,len(line)):
            k=k+str(line[x])+" "
        output.append(k)
        #output.append(' '.join(line))

def testcase():
    Join(5) # Join 5
    Check() # Check
    Join(4) # Join 4
    Check() # Check
    GetLine() # GetLine
    Join(3) # Join 3
    GetLine() # GetLine
    Issue() # Issue
    Check() # Check
    GetLine() # GetLine

def inpu():
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
inpu()
print(*output, sep="\n")