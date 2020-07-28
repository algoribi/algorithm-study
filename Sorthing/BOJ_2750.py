n = int(input())
num = []
for i in range(n):
    temp = int(input())
    num.append(temp)

sort_num = sorted(num)

for i in range(n):
    print(sort_num[i], end="\n")

