n = int(input())
for t in range(n):
    num, s = input().split()
    ans = ""
    for c in s:
        ans += int(num) * c
    print(ans)
