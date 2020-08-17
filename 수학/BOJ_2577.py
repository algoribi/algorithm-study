a = int(input())
b = int(input())
c = int(input())

num = a * b * c
count = [0 for _ in range(10)]

while True:
    if num < 10:
        count[num] += 1
        break
    count[num % 10] += 1
    num //= 10

for i in count:
    print(i, end="\n")

