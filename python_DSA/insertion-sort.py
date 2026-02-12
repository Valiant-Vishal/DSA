test = [2,4,3,5,2,5,36,35,334,3,55]

def insertionSort(List) -> list:
    for i in range(1,len(List),1):
        j = i-1
        while(j>=0 and List[j] > List[j+1]):
            List[j],List[j+1] = List[j+1], List[j]
            j = j-1
    return List

print("Sorted list",insertionSort(test))