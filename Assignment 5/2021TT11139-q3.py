def pandovan(a):
    if a==0 or a==1 or a==2:
        return 1
    else:
        return (pandovan(a-2)+pandovan(a-3))
num=int(input())
print('%.2f' %pandovan(num))