n=int(input())
def pattern(a):
    if a==1:
        return "111"
    else:
        return str(a)+pattern(a-1)+str(a)+pattern(a-1)+str(a)
print(pattern(n))