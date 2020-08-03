n = int(input())
t = []
for i in range(n):
    num = int(input())
    t.append(num)

counter_l = counter_r = l_max = r_max = 0

for i in range(n):
    if i == 0:
        counter_l += 1
        l_max = t[i]
    else:
        if l_max < t[i]:
            counter_l += 1
            l_max = t[i]
for i in reversed(range(n)):
    if i == n - 1:
        counter_r += 1
        r_max = t[i]
    else:
        if r_max < t[i]:
            counter_r += 1
            r_max = t[i]
print(counter_l, counter_r, sep="\n")
