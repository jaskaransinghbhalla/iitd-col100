a=int(input())
b=int(input())
c=int(input())

if (c==1):
	print(a+b)
else:
	if(c==2):
		print(a-b)
	else:
		if(c==3):
			print(a*b)
		else:
			if(c==4):
				if(a/b == int(a/b)):
					k=int(a/b)
				else:
					k=a/b
					k=round(k,2)
				print(k)
			else:
				if(a%b == int(a%b)):
					k1=int(a%b)
				else:
					k1=(a%b)
					k1=round(k1,2)
				print(k1)
