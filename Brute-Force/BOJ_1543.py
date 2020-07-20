answer = 0
s = input()
a = input()

while True:
    fl = s.find(a)
    if fl == -1:
        break
    else:
        answer += 1
        s = s[fl + len(a) :]

print(answer)
