import os
def writing(filename,text):
    f=open(filename, "w")
    f.write(text)
    f.close()
def append(filename,text):
    f=open(filename,"a")
    f.write(text)
    f.close()
def reading(filename):
    try:
        f=open(filename,"r")
        text=f.read()
        print(text)
        f.close()
    except FileNotFoundError:
        print("File Not Found Error")
def search(filename, word):
    try:
        f=open(filename,"r")
        line_count=0
        for line in f.readlines():
            line_count+=1
            strlist=line.split(' ')
            word_count=0
            for w in strlist:
                word_count+=1
                if word==w:
                    return (line_count,word_count)
        else:
            return None 
        f.close()
    except FileNotFoundError:
        print("File Not Found")
def modify(filename,oldword, newword):
    t=search(filename,oldword)
    if t!=None:
        mylist=[]
        try:
            f=open(filename,"r")
            for line in f.readlines():
                line=line.replace(oldword,newword)
                mylist.append(line)
            f.close()
            f=open(filename,"w")
            f.write(''.join(mylist))
            f.close()
        except FileNotFoundError:
            print("File Not Found")
    else:
        print("Search Failed")

def delete(filename,oldword, newword=''):
    t=search(filename,oldword)
    if t!=None:
        mylist=[]
        try:
            f=open(filename,"r")
            for line in f.readlines():
                line=line.replace(oldword,newword)
                mylist.append(line)
            f.close()
            f=open(filename,"w")
            f.write(''.join(mylist))
            f.close()
        except FileNotFoundError:
            print("File Not Found")
    else:
        print("Search Failed")

#os.rename("file1.txt","file2.txt")
os.remove("file2.txt")
print()

