import matplotlib.pyplot as plt
import random
import numpy as np


def linear_search(arr, key):
    comparisons = 0
    for x in arr:
        comparisons += 1
        if x == key:
            break
    return comparisons

def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    comparisons = 0
    while low <= high:
        comparisons += 1
        mid = (low + high) // 2
        if arr[mid] == key:
            break
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return comparisons

def fibonacci_search(arr, key):
    n = len(arr)
    comparisons = 0
    fib2, fib1 = 0, 1
    fib = fib1 + fib2

    while fib < n:
        fib2, fib1 = fib1, fib
        fib = fib1 + fib2

    offset = -1
    while fib > 1:
        i = min(offset + fib2, n - 1)
        comparisons += 1
        if arr[i] < key:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > key:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return comparisons

    if fib1 and offset + 1 < n:
        comparisons += 1
    return comparisons

# ---------------- Array Sizes ----------------

sizes = [10, 20, 30]
linear_comp = []
binary_comp = []
fibonacci_comp = []

for n in sizes:
    # Generate random sorted array
    arr = sorted(random.sample(range(1, 1000), n))
    print(f"\nArray of size {n}: {arr}")

    # User input key
    key = int(input(f"Enter key to search in array of size {n}: "))

    # Count comparisons
    linear_comp.append(linear_search(arr, key))
    binary_comp.append(binary_search(arr, key))
    fibonacci_comp.append(fibonacci_search(arr, key))

# ---------------- Bar Graph ----------------

x = np.arange(len(sizes))
width = 0.25

plt.bar(x - width, linear_comp, width, color='red', label='Linear')
plt.bar(x, binary_comp, width, color='green', label='Binary')
plt.bar(x + width, fibonacci_comp, width, color='blue', label='Fibonacci')

plt.xlabel('Array Size (n)')
plt.ylabel('Number of Comparisons')
plt.title('Comparisons of Search Algorithms for User Key')
plt.xticks(x, sizes)
plt.legend()
plt.grid(axis='y')
plt.show()