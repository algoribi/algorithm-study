a, b = map(int, input().split())
m = int(input())
arr = list(map(int, input().split()))
num = 0
multi = 1
for i in reversed(arr):
    num += i * multi
    multi *= a
ans = []
while True:
    if int(num) == 0:
        break
    ans.append(int(num % b))
    num /= b
    print(num, end="\n")
for i in reversed(ans):
    print(i, end=" ")
