a=int(input())
b=int(input())
c=int(input())
sum=a+b
sub=a-b
mul=a*b
div=a/b
rem=a%b


if (c==1):
	print('%.2f' %sum)
else:
	if(c==2):
		print('%.2f' %sub)
	else:
		if(c==3):
			print('%.2f' %mul)
		else:
			if(c==4):
				print('%.2f' %div)
			else:
				print('%.2f' %rem)
