import time
from random import randint


minRun=0
length=0

def minRunLength():
    global lengh
    global minRun
    flag=0
    n=length
    while n>=64:
        flag|=n&1
        n>>=1
    minRun=n+flag

def sortMas(array):
    isSorted=False
    i=0
    sortedEl=0
    runSize=len(array)-1

    while not isSorted:
        if array[i]>array[i+1]:
            p=array[i+1]
            array[i+1]=array[i]
            array[i]=p
            sortedEl+=1
        i+=1
        if i==runSize:
            i=0
            if sortedEl==0:
                isSorted=True
            else:
                sortedEl=0
    
def merge(runs, array):
    global length
    runSize=len(runs)
    while runSize>0:
        if runSize>1:
            runSizeEl=len(runs[0])
            i=0
            while i<runSizeEl:
                if len(runs[1])>0:
                    if runs[1][0]<runs[0][i]:
                        runs[0].insert(i,runs[1].pop(0))
                        runSizeEl+=1
                else:
                    break
                i+=1
            if len(runs[1])>0:
                runs[0].extend(runs[1])
            runs.pop(1)
            runSize-=1
        else:
           
            for i in range(length):
                array[i]=runs[0][i]
            runSize=0
        
        
    
    
def Timsort(array):
    start=time.time()
    global minRun
    global length
    minRun_1=minRun-1
    length_1=length-1
    runs=[[]]
    sortedMas = 0
    
    isSorted=True
    for i in range(length):
        if len(runs[-1])==0:
            isSorted=True
            runs[-1].append(array[i])
            if i>0 and array[i-1]>array[i]:
               sortedMas-=1
        else:
            if len(runs[-1])==minRun_1 or i==length_1:
                if runs[-1][-1]>array[i]:
                    isSorted=False
                runs[-1].append(array[i])
                if not isSorted:
                    sortMas(runs[-1])
                else:
                    sortedMas+=1
                if i<length_1:
                    runs.append([])
            else:
                if runs[-1][-1]>array[i]:
                    isSorted=False
                runs[-1].append(array[i])
   
    if sortedMas!=len(runs):
        merge(runs,array)
    print("Duration "+str(time.time()-start))
        

#Начальный размер массива
length=int(input("Array length:"))
#Исходные массивы. не отсортированный и отсортированный
arrayRand=[]
arraySort=[]

for i in range(length):
    arrayRand.append(randint(0,9))
    arraySort.append(i)

#print(arrayRand)
#print(arraySort)
minRunLength()
print(minRun)

Timsort(arrayRand)
Timsort(arraySort)
#print(arrayRand)
#print(arraySort)
