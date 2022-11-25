'''
Write Your's Explaination for O(N) Time Complexity Here
As for loop is running N number of times, so order of time complexity this program is O(N).
Time Complexity = O(num)*(O(1)+O(1)) = O(num) = O(N)
'''

def heaven(num : int) -> int:  # write your code in this function only
    # your's code start here 
    # remove pass and write your code
    if num==1:      #Time Complexity = O(1)
        return(1)
    elif(num==2):   #Time Complexity = O(1)
        return(2)
    elif(num==3):   #Time Complexity = O(1)
        return(4)
    else:
        answer=0
        a=1
        b=2
        c=4
        #Time Complexity = O(num)*(O(1)+O(1))
        for i in range(4,num+1):    
            #Time Complexity = O(1)
            answer=a+b+c        
            #Time Complexity = O(1)   
            a,b,c=b,c,answer        
        return(answer)
    # return your's integer result
    # your's code end here 
    
    
if __name__=="__main__": # calling main (run automtically)
    num = int(input())   # taking input from user
    out = heaven(num)    # calling function in which you have written code
    print (out)          # printing the output of your's function


