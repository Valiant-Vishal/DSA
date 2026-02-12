import random

numbers = [random.randint(1, 10000) for _ in range(10000)]


lines = []
for i in range(0, len(numbers), 10):
    chunk = numbers[i:i+10]
    
    line = ", ".join(map(str, chunk)) + ","
    lines.append(line)

content = "\n".join(lines)


filename = "random_numbers.txt"
with open(filename, "w") as f:
    f.write(content)


preview = "\n".join(lines[:5])
print(preview)