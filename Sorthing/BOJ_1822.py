n = list(map(int, input().split()))
numa = list(map(int, input().split()))
numb = list(map(int, input().split()))
numa.sort()
numb.sort()
ans = []
ai = bi = 0
if len(numa) == 0:
    print(0)
else:
    while 1:
        if ai >= len(numa):
            break
        elif bi >= len(numb):
            while ai < len(numa):
                ans.append(numa[ai])
                ai += 1
            break

        if numa[ai] == numb[bi]:
            ai += 1
            bi += 1
        elif numa[ai] > numb[bi]:
            bi += 1
        else:
            ans.append(numa[ai])
            ai += 1
    print(len(ans), end="\n")
    for i in ans:
        print(i, end=" ")
