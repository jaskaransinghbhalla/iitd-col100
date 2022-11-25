# This is the starter code for COL100 Assignment 6 question 4
# There are different functions in this question that you have to fill 
# These are some example matrices that you can use to check your code
matrixA = [[1.00,2.00,3.00],[2.00,3.00,4.00],[4.00,5.00,6.00]]
matrixB = [[1.00,0.00,2.00],[9.00,8.00,5.00],[5.00,8.00,0.00]]
matrixC = [["Hello"]]
matrixD = [[1.00,2.00],[5.00,7.00],[3.00,8.00]]
# This is a print matrix function that could help you debug your code, it prints the whole matrix
def PrintMatrix(A:list ):
	# Print function that can help you debug your solutions
	if A == None:
		print(A)
		return
	# It will print None if the input is None
	rows = len(A)
	cols = len(A[0])
	for i in range(rows):
		for j in range(cols):
			print(A[i][j], end = " ")
		print()
# The argument type is a list and the return type is a boolean
def CheckMatrix(A: list)->bool:
    # Check whether the list of list is a matrix
	# WRITE YOUR CODE HERE
    if len(A)==0:
        b=False
    else:
        for i in range(0,len(A)):
            if len(A[i])==0:
                b=False
            else:
                for x in range(0,len(A)):
                    for y in range(0,len(A[x])):
                        if (type(A[x][y])==float) and (len(A[x])==len(A[0])):
                            b=True 
                        else:
                            b=False
    return b
# IMPORTANT NOTE: Please make sure to use CheckMatrix in the further questions
# The argument type is a list and the return type is a list as well
def Transpose(A:list) -> list:
    if CheckMatrix(A)==True:
        b=[]
        for x in range(0,len(A[0])):
            temp=[]
            for y in range(0,len(A)):
                temp.append(A[y][x])
            b.append(temp)
    else:
        b=None
    return b
    # Find the transpose of the matrix given please make sure the dimensions of the list of list
	# the transpose of the matrix
	# WRITE YOUR CODE HERE
# There are two arguments whose type is list, it returns a list as output
def Multiplication(A:list,B:list) -> list:
    # Return the multiplication of matrices A and B if it exists
	# WRITE YOUR CODE HERE
	if CheckMatrix(A)==True and CheckMatrix(B)==True:
		if len(A[0])==len(B):
			b=[]
			for x in range(0,len(A)):
				temp=[]
				for y in range(0,len(B[0])):
					sum=0
					for i in range(0,len(B)):
						sum=sum+A[x][i]*B[i][y]
					temp.append(sum)
				b.append(temp)
			return b
		else:
			return None
# There are two arguments whose type is list, it returns a list as output
def Addition(A:list,B:list) -> list:
    # Return the addition of matrices A and B if it exists
    # WRITE YOUR CODE HERE
    C = []
    if CheckMatrix(A)==True and CheckMatrix(B)==True:
        if len(A)==len(B) and len(A[0])==len(B[0]):
            for x in range(0,len(A)):
                temp=[]
                for y in range(0,len(A[0])):
                    temp.append(A[x][y]+B[x][y])
                    C.append(temp)
            return C
        else:           
            return None
# The argument type is a list and the return type is a boolean
def Symmetric(A: list)->bool:
    # Write code to check whether matrix is symmetric or not return True if it is
	# Return False in all the other cases 
	# WRITE YOUR CODE HERE
    if CheckMatrix(A)==True:
        B=Transpose(A)
        if len(A)==len(B) and len(B[0])==len(A[0]):
            for x in range(0,len(A)) :
                for y in range(0,len(A[0])):
                    if A[x][y]==B[x][y]:
                        return True
                    else :
                        return False
        else:
            return False
    else:
        return False
# THESE ARE SOME SAMPLE TESTCASES THAT YOU CAN USE TO EVALUATE YOUR CODE
# WE WILL NOT BE CHECKING THE OUTPUT OF THE FOLLOWING AND WILL CHECK THE RETURNED VALUE USING OUR TESTCASES
# Printing Matrix A
PrintMatrix(matrixA)
print()
# Checking whether matrixC is a valid Matrix
print(CheckMatrix(matrixC))
print()
# Printing the multiplication of matrixA and matrixB
PrintMatrix(Multiplication(matrixA,matrixB))
print()
# Printing the addition of matrixA and matrixB
PrintMatrix(Addition(matrixA,matrixB))
print()
# Is matrixA a symmetric matrix
print(Symmetric(matrixA))
print()
# Printing the transpose of matrixA
PrintMatrix(Transpose(matrixA))
print()
# THE ABOVE ARE ONLY FOR YOUR REFERENCE AND WILL NOT BE INCLUDED IN EVALUATION