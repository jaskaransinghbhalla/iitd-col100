from typing import List
def sortings(lst : List[str]) -> List[str]: # it takes list of strings as input and return list of strings
    # write your code in this function only
    # your's code start here 
    
    return lst 
    
    # return your's result (list of string) 
    # your's code end here 
    

if __name__=="__main__": # calling main (run automtically)
    lst = []             # list that stores the input strings
    num = int(input())   # taking input from user of number of strings of list
    for i in range(num): # take input of all strings of list
        inpt = input()
        lst.append(inpt) # append each string into the list
    lst = sortings(lst)  # calling function in which you have to write the code
    print (lst)          # printing the output (list of strings) of your's function
