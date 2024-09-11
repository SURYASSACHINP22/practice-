name= input("enter the name")
if "surya"  not in name:
    print("is not there")

b=len(name)
print("len of your name",b)

type(name) 
a= (int)(input("enter the no"))
type(a)
if type(a)==int:
    print("it is of int tupe")
else:
    print("it of oter type rather than int ")


n=int(input("enter the value of key"))
count=0
i=1
div=n
while(i<=n or div>=1):
    if i%3==0:
        if div==1:
            break
        div=div/3
        count+=1
    i+=1
print("outside count==",count)
