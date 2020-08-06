n = list(map(int, input().split()))
counter = [0, 0, 0, 0, 0]
c = 0
for i in range(n[0] * 5):
    w = input()
    if i % 5 == 0:
        c = 0
        continue
    if c == n[1]:
        continue
    wd = n[1] - w.count("*") / 4 - c
    if i % 5 == 1:
        counter[0] += wd
        c += wd
    elif i % 5 == 2:
        counter[1] += wd
        c += wd
    elif i % 5 == 3:
        counter[2] += wd
        c += wd
    elif i % 5 == 4:
        counter[3] += wd
        c += wd
        counter[4] += n[1] - c
w = input()
for i in counter:
    print(int(i), end=" ")
