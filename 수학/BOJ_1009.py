num = int(input())

for n in range(num):
    a, b = map(int, input().split())
    if a % 10 == 0:
        print(10, end="\n")
        continue
    temp = b % 4 + 4
    ans = str(a ** temp)
    print(ans[-1], end="\n")