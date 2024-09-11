# x="24"
# y=float(x)
# print(x)

# x=100
# print(type(x))
# y=bin(x)
# print(type(bin(x)))
# print(type(y))
# print(y)

# x=0b10101110
# print(type(x))
# print(x)

# x=0x2f
# print(x)
# print(oct(x))

# x=0o1255
# print(x)
# print(bin(x))

# a=int(input("enter the no to find the squre"))
# print("squre of %d"%(a))
# print("is",(a**2))

# Tamo=int(input("enter the total amount\nrate of intrest\nand time period for simple rate of intrest"))
# itest,time=7,2
# si=(Tamo*itest*time)/100
# print('''"the simple rate of intrest is"''',si)

# print("single line if else statement")
# X=int(input("enter the valve"))
# print("+ve"if X>0 else "-ve")

# i=1
# while i<=3:
#     a=int(input("enter the no"))
#     if a%2==0:
#         print("even number you won")
#         break
#     i+=1
# else:
#     print("you lost")

# r=range(0,100,2*2)
# for e in r:
#     print(e,sep="\t",end=" ")
# print()
# r=range(100)
# for e in r:
#     print(e,sep="\t",end=" ")

# for e in range(0,int(input("enter the upper bound of the range which starting form the "))):
#     print(e,sep="\t",end=" ")

# word1=input("enter 1st word")
# word2=input("enter 2nd word")
# if word1<word2:
#     print("the dictionary order is",word1,word2,sep="\n")
# else:
#     print("the dictionary order is",word2,word1,sep="\n")

# x=int(input("enter the no for check it is 3 digit or not\n"))
# print("it is 3 digit\n"if 999>=x>=100 else "it is not 3 digite no\n")

# print("enter the value of the a ,b, c")
# a,b,c=int(input()),int(input()),int(input())
# if b*b-4*a*c==0:
#     print("root are equal and real")
# elif b*b-4*a*c>0:
#     print("root are real and distint")
# else :
#     print("root are imagenary")

# year=int(input("enter the year to check it is leao year or not"))
# if year%100==0:
#     if year%400==0:
#         print("it is the leap year")
#     else:
#         print("it is not a leap year")
# else:
#     if year%4==0:
#         print("it is the leap year")
#     else:
#         print("it is not a leap year")

# print("enter the value of the a ,b, c")
# a,b,c=int(input()),int(input()),int(input())
# if a>b:
#     print("a is greter"if a>c else "c is greter ")
# else:
#     print("b is greter"if b>c else "c is greter ")

# x=int(input("enter the no"))
# match x:
#     case x if x>0:
#         print("value is +ve")
#     case x if x<0:
#         print("value is +ve")
#     case _:
#         print("value is 0")

# string=input("enter a string\n\n")
# vowels="aeiouAEIOU"
# count=0
# cound=0
# for e in string:
#     if e in vowels:
#         print(e,sep=" ",end="\t")
#     if e == " ":
#         count +=1
#     if e is " ":
#         cound+=1
# print("count=",count,"cound=",cound)

# n=int(input("enter the no for multipliction table"))
# range=range(11)
# for e in range:
#     print("{}*{}={}".format(n,e,n*e))

# for e in range(0,int(input("enter the upper bound "))+1,2):
#     print(e)

# start=int(input("input start value"))
# end=int(input("enter the ending value"))
# for x in range (start,end):
#     for i in range(2,x):
#         if x%i==0:
#             break
#     else:
#         print(x,end=" ")

# n=eval(input("enter the nunber to find the factorial of a no"))
# fa=1
# for e in range(1,n+1):
#         print("e=",e,end="\n")
#         fa=fa*e
#         print("fa=",fa,end="\n")
# print("is",fa,end="\n")     
     
# n=int(input("enter the digit for digit sum\n"))
# s=0
# count=0
# while n:
#     s=s+n%10
#     n=n//10
#     count+=1
# print("sum of",count,"digit = ",s)

# d=n=int(input("enter the digit tocinvert in binary without inbilt bin methods\n"))
# s=''
# while n:
#     s=str(n%2)+s
#     n=n//2
# print("the binary for ",d,"is",s,"\n")
# print("binary using bin inbuilt method",bin(d))

# i=0
# n=int(input("enter the n for while "))
# while (i<n):
#     print("i am clear not a doum")
#     i+=1
# # python dont have increment and decrement like i++ or i--
    
# i=0
# n=int(input("enter the n value \nwe will give you even value till upto n\n"))
# while(i<n):
#     i+=1
#     if (i%2!=0):
#         continue
#     print(i,end=" ")
    

# # we are performing for else with loop
# i=0 
# print("you have 10 chance in that give any even value")
# while(i<10):
#     n=int(input())
#     if(n%2==0):
#         print('you won the game')
#         break
#     i+=1
# else:
#     print ("you lost the game")

# name=input("enter your name we will print without s ")
# for e in name:
#     if e=="s":
#         break
#     print(e,end="")
# else:
#     print("no s is found")

# # range class using

# n=int(input("enter the no "))
# r=range(1,n+1)
# for e in r:
#     print(e,end=" ")
# print()

# # above code can be write as 

# for e in range(1,int(input("enter the no"))):
#     print(e,end=" ")
# print()

# x=int(input("enter what value of multipels you wants and we give additon for it"))
# n=int(input("how many"))
# s=0
# for e in range(1,n+1):
#     print(" now element index is ",e,"and sum upto",e,"is",s)
#     s+=x*e
# print("total sum is",s)

# l=[10,"sachin",1]
# print(l)
# l[0]=100
# l[1]="SACHIN"
# print(l)
# l.append("SURYAWANSHI")
# print(l)
# l.insert(0,"name")
# print(l)
# del(l[1])
# print(l)
# print(type(l))

# n=int(input("how many no you want to insert"))
# list=list()
# i=0
# while i<n:
#     list.append(int(input("enter the no")))
#     i+=1
# print(list)
# list.count(7)
# print(list)
# list.index(7)
# print(list)
# list.pop(-3)
# print(list)
# list.pop(2)
# print(list)
# list.remove(7)
# print(list)
# list.sort()
# print(list)
# print(sorted(list))
# print(list)
# list.reverse()
# print(list)
# print(len(list))
# print(max(list))
# print(min(list))
# print(sum(list))
# del(list[5])
# print(list)
# list.pop(7)
# print(list)
# list.insert(5,700)
# print(list)
# list.append(750)
# print(list)
# list.insert(100,100000)
# print(list)

# # import one
# # print(one.a)
# # print(one.b)
# # from one import a,b
# # a="sachin"
# # b="suryawanshi"
# # print(a)
# # print(b)

# import keyword
# print(keyword.keylist)

# x= 'a'
# type(x)
# ord(x)

# x=65
# chr(x)

# print("\nhello\nthis is my first code in the python \n")
# print("enter the two no for the addition")
# a=int(input())
# b=int(input())
# c=a+b
# print("the sum is for",a,"and",b,"is",c)
# print(a,b,c)
# print("\n\n\n\n")
# a=10
# b=100
# c=1000
# print(a,b,c,sep='----')
# print("sep will sepereate the print valve \nbut\nin above line we are taking it by manually\n\n\n")
# print(a,b,c,end=',,,')
# print("end will stop the print to change the line automatically")
# print(a,b,c,sep='___',end='####')
# print("\\n")
# print("the value of the a is %d and b is %d also c is %d"%(a,b,c),"\n\n\n\n")
# rand="ramesh randi"
# print(rand)

# s="sachin"
# print("{}".format(s))
# s="{},{},{}"
# x="sachin"
# y="prabhakar"
# z="suryawanshi"
# print(s.format(x,y,z))
# print("{2},{0},{1}".format(x,y,z))

# n=int(input("enter the user input for while function\n it is METHOD 1 FOR USER INPUT"))
# i=0
# l1=list()
# while i<n:
#     l1.append(int(input("enter the no")))
#     i+=1
# print(l1)

# print("2nd method using str")
# str=input("enter the integers for array with ,in it")
# l1=str.split(',')
# print(type(l1))
# sc=[int(e) for e in l1]
# print(sc)

# date=["20","12","2023"]
# print("-".join(date))

# s1="sachin prabhakar suryawanshi"
# print(s1.split(" "))
# l1=s1.split(" ")
# print(l1)
# scan=[str(e)for e in l1]
# print(scan)

# x=int(input("enter value for match block(switch block)"))
# match x:
#     case 1:
#         print("it is one")
#     case 2:
#         print("it is two")
# print("not matching the arguments ")


# ele=eval(input("enter the type "))
# # eval is the method which return the string value
# match ele:
#     case 1:
#         print("it is one ")
#     case 2:
#         print("it is one ")
#     case [1,2,3]:
#         print("it is array of 3 element")
#     case "sachin":
#         print("string name sachin")
#     case _:
#         print("it is default case")

# print("out of match ")        

# case=eval(input("enter the value of any type "))
# match case:
#     case case if type(case)==int:
#         print("int type valve")
#     case case if type(case)==float:
#         print("float type ")
#     case case if type(case)==chr:
#         print("type of char ")
#     case case if type(case)==str:
#         print("string value")
#     case _:
#         print("default")

# print("check to check the no is +ve or not ")
# a=int(input("enter the no "))
# if a>0 :
#     print("the no is positive")
# else:
#     print("not posithive")  

# a=int(input("enter the value for a b c respectivly"))
# b=int(input())
# c=int(input())

# if a>b or b>c:
#     print("biggest is a")
# elif b>c or c>a:
#     print("bigger valve is b")
# else:
#     print("c is bigger")

# x=int(input("enter a no"))
# print("positive "if x>0 else "non positive")

# t1=tuple([int(e) for e in input("enter the list element for tople input")])
# print(type(t1))
# print(t1)
# t1=([1,2,6,6,5,8,6],)
# print(type(t1))
# print(t1)
# t1=tuple([1,2,6,6,5,8,6])
# print(type(t1))
# print(t1)
# t1=tuple(range(1,10))
# print(type(t1))
# print(t1)
# t1=(range(1,10))
# print(type(t1))
# print(t1)

# set=set([10,20,20,30])
# print(set)
# set={1,5,6,8,2,7}
# print(set)
# set.add(40)
# print(set)
# set.update([5,16,4,31,6])
# print(set)
# set={1,515,True}
# print(set)
# set.remove(515)
# print(set)

# set1=set([10,20,20,30,55,9])
# print(set1)
# set1.discard(55)
# print(set1)

# s={e for e in input("enter a string") if e in "acious"}
# print(s)

# s=input("enter a no seperated by coama")
# s1={eval(e) for e in s.split(',') }
# print(s1)

# print("enter the list element")
# l1=[eval(e) for e in input().split(',')]
# print(l1)
# l2=list(eval(e) for e in input().split(','))
# print(l2)
# print(len(l1))
# print(sum(l1))
# avg=sum(l1)/len(l1)
# print(avg)
# i,l2=0,[]
# for e in l1:
#     if i%2==0:
#         l2.append(e)
#     i+=1
# print(l2)     

# n=int(input("enter the up to what no you want"))
# l1=[]
# i=0
# pfabo=-1
# fabci=1
# while i<=n:
#     if n==0:
#         print(pfabo+1)
#     elif n==1:
#         print(fabci)
#     else:
#         fabcisum=pfabo+fabci
#         l1.append(fabcisum)
#         pfabo=fabci
#         fabci=fabcisum
#     i+=1    
# print(l1)    

# n=int(input("enter the up to what no you want"))
# l1=[]
# for e in range(2,n+1):
#     for i in range(2,e):
#         if e%i==0:
#             break
#     else :
#         l1.append(e)
# print(l1)

# print("enter the element of matrix A {row wise}")
# a=[
# [eval(e) for e in input().split(',')],
# [eval(e) for e in input().split(',')],
# [eval(e) for e in input().split(',')]
# ]
# print("enter the element of matrix B {row wise}")
# b=[
# [eval(e) for e in input().split(',')],
# [eval(e) for e in input().split(',')],
# [eval(e) for e in input().split(',')]
# ]
# c=[[0,0,0],[0,0,0],[0,0,0]]
# for i in range(0,3):
#     for j in range(0,3):
#         c[i][j]=a[i][j]+b[i][j]
#         print(c[i][j],end="\t")
#     print()
# print()

# s1=input("enter the string\n")
# for e in s1:
#     if e>='a' and e<='z' or e>='A' and e<='Z':
#         pass
#     else:
#         print("entered string is contain non string char also")
#         break
# else:
#     print("string contain charector only")
# print()

# s1=input("enter the string\n")
# print(s1)
# s1.strip()
# print(s1.strip())
# s2=s1.split(' ')
# print(s2)
# i=0
# wordcount=0
# while i<len(s2):
#     if s2[i]!='':
#         wordcount+=1
#     i+=1
# print("word count:",wordcount)
# print()

# s1=input("enter the string\n")
# print(s1[::-1])
# print(s1,reversed==True)














