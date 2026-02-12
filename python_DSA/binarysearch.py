List = [1,2,3,4,5,6,7,8,9.10,11,13]
def binary(l,s):
    low = 0
    high = len(l)-1
    while low <= high:
        mid = (low + high)//2
        if l[mid] == s:
            return mid
        elif l[mid] < s:
            low = mid + 1
        else:
            high = mid - 1
    return -1

print(binary(List,7))


