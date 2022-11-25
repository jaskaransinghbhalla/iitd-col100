


def sortings(inpt : str) -> str: # it takes string as input and return string
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
            
            
    
    
    

    # return your's string result
    # your's code end here 
    

if __name__=="__main__": # calling main (run automtically)
    inpt = input()       # taking input from user (string type)
    out = sortings(inpt) # calling function sortings in which you have to write code
    print (out)          # printing the output of your's function

    
            
    
            
            