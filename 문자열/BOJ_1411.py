n = int(input())
ans = []
for _ in range(n):
    eng = [-1 for _ in range(30)]
    s = input()
    counter = 1
    re_s = ""
    for i in s:
        if eng[ord(i) - ord("a") + 1] == -1:
            eng[ord(i) - ord("a") + 1] = counter
            counter += 1
        re_s += str(eng[ord(i) - ord("a") + 1])
    # print(re_s)
    ans.append(re_s)

counter = 0
for i in range(len(ans)):
    for j in range(i + 1, len(ans)):
        if ans[i] == ans[j]:
            counter += 1

print(counter)