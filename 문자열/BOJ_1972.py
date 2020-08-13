while True:
    s = input()
    if s == "*":
        break
    fl = 0
    for i in range(len(s) - 2):
        save = set()
        for j in range(len(s)):
            if j + i + 1 >= len(s):
                break
            temp = s[j] + s[j + i + 1]
            if temp in save:
                fl = 1
                break
            save.add(temp)
        if fl == 1:
            print(s + " is NOT surprising.")
            break
    if fl == 0:
        print(s + " is surprising.")
