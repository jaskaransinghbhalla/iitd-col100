# This is the starter code for COL100 Assignment 6 question 1
# There are different functions in this question that you have to fill 


# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code

#inputforcode


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.

# You can only use arrays or lists to store your data and are not allowed to import anything
plate=[]
def PickPlate():
    if len(plate)==0:
        print("Invalid")
    else:
        k=plate.pop()
    # This is the PickPlate function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    return

def AddPlate(PlateID: int):
    plate.append(PlateID)
    # This is the AddPlate operation as mentioned in the pdf
    # This takes in one value the PlateID and adds it to the arrangement
    # You will have to parse the input and call this function wherever needed.
    # It doesn't need to return anything,
    # you could return a value if it helps your implementaton
    return


def Check():
    if len(plate)==0:
        return "Invalid"
    else:
        k=plate[len(plate)-1]
        return k
    # This is the Check function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    AddPlate(5) # AddPlate 5
    # Note that you have to parse the input and then send values in the function like done here
    Check() # Check
    AddPlate(4) # AddPlate 4
    Check() # Check
    AddPlate(3) # AddPlate 3
    PickPlate() # PickPlate
    Check() # Check
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code
n=int(input())
for x in range(0,n):
    a=input()
    lis=a.split(" ")
    if lis[0]=="AddPlate":
        AddPlate(lis[1])
    elif lis[0]=="PickPlate":
        PickPlate()    
    elif lis[0]=="Check":
        print(Check())
#testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder