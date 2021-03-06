import time

def isEven(value): #Первый вариант. Изначальный
    return( value%2==0)
def isEvenNew(value): #Улучшенный вариант
    return( not value&1)

start=time.time()
for i in range(10000):
    isEven(i)
    
end1=time.time()

for i in range(10000):
    isEvenNew(i)
end2=time.time()-end1

print("Time isEven - "+str(end1-start))
print("Time isEvenNew - "+str(end2))
