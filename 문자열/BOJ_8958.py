n = int(input())
for _ in range(n):
    s = input()
    ans = 0
    counter = 0
    for c in s:
        if c == "X":
            counter = 0
        else:
            counter += 1
        ans += counter
    print(ans, end="\n")
