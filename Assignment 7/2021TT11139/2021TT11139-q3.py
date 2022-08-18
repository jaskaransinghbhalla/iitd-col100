from typing import List

def sortings(lst : List[str]) -> List[str]: # it takes list of strings as input and return list of strings
    # write your code in this function only
    # your's code start here 

    #Function to Sort List
    def sortstr(inpt : str) -> str: 
        # it takes string as input and return string    
        # write your code in this function only
        # your's code start here
        
        def counter_func(list,c):
            a=0
            for x in range(len(list)):
                if (list[x]==c):
                    a+=1
            return(a)
        l=[]
        indexes=[]
        l1=[]
        for x in range(0,len(inpt)):
            l.append(inpt[x])  
        for x in range(0,len(l)):  
            if(counter_func(inpt,inpt[x])%2!=0):
                if(inpt[x].isnumeric()):
                    l1.append(inpt[x])
                    indexes.append(x)   
        for index in sorted(indexes, reverse=True):
            del l[index]
        l1.sort()
        final_list=l1+l
        final="".join(final_list)
        return(final) 
    
    #Sorting Individual strings in the list according to question 2
    lis=[]
    for x in range(0,len(lst)):
        a=sortstr(lst[x])
        lis.append(a)

    #Function to get the integer in the front
    def trimmer(lis):
        lis1=[]
        for j in range(0,len(lis)):
            temp=[]
            for i in range(0,len(lis[j])):
                if lis[j][i].isnumeric()==True:
                    temp.append(lis[j][i])
                else:
                    break
            temp1="".join(temp)
            lis1.append(temp1)
        return(lis1)
    lis1=trimmer(lis)
    
    #lis contains sorted list of strings according to question2
    #lis1 contains lis of numbers in front of list

    #Dealing with Empty Strings
    for x in range(len(lis1)-1,-1,-1):
        if lis1[x]=="":
            lis1[x]="9000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"

    #Converting List entries to numbers
    for k in range(0,len(lis1)):
        lis1[k]=int(lis1[k]) 

    lis2 = [[lis1[i], lis[i]] for i in range(len(lis))]
    lis2.sort()
    
    #Defining final list
    final=[lis2[i][1] for i in range(len(lis2))]    
    #returning the final result
    return(final)
    # return your's result (list of string) 
    # your's code end here 

if __name__=="__main__": # calling main (run automtically)
    lst = []             # list that stores the input strings
    num = int(input())   # taking input from user of number of strings of list
    for i in range(num): # take input of all strings of list
        inpt = input()
        lst.append(inpt) # append each string into the list
    lst = sortings(lst)  # calling function in which you have to write the code
    print(lst)          # printing the output (list of strings) of your's function