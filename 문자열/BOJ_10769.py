s1 = input()
s2 = s1
count_h = count_s = 0
while 1:
    num = s1.find(":-)")
    if num == -1:
        break
    s1 = s1[num + 3 :]
    count_h += 1
while 1:
    num = s2.find(":-(")
    if num == -1:
        break
    s2 = s2[num + 3 :]
    count_s += 1
if count_h > count_s:
    print("happy")
elif count_h < count_s:
    print("sad")
elif count_h == 0 and count_s == 0:
    print("none")
else:
    print("unsure")
