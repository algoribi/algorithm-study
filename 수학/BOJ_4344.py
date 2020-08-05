c = int(input())
for i in range(c):
    ll = list(map(int, input().split(" ")))
    avg = 0
    for j in ll[1:]:
        avg += j
    avg /= ll[0]

    counter = 0
    for j in ll[1:]:
        if j > avg:
            counter += 1
    ans = round((counter / ll[0]) * 100, 3)
    print("%.3f" % ans, end="%\n")