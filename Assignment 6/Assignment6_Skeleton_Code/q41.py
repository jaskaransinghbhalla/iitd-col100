matrixA = [[1.00,2.00,3.00],[2.00,3.00,4.00],[4.00,5.00,6.00]]
matrixB = [[1.00,0.00,2.00],[9.00,8.00,5.00],[5.00,8.00,0.00]]
matrixC = [["Hello"]]
matrixD = [[1.00,2.00],[5.00,7.00],[3.00,8.00]]
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
def Multiplication(A:list,B:list) -> list:
    
    # Return the multiplication of matrices A and B if it exists
	# WRITE YOUR CODE HERE
    if len(A[0])==len(B) and CheckMatrix(A)==True and CheckMatrix(B)==True :
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
A=[[1.00,2.00,3.00],[2.00,1.00,7.00]]
print(Symmetric(matrixA))
