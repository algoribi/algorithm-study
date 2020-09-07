eng = [0 for _ in range(30)]
text = input().upper()

for i in text:
    eng[ord(i) - 65] += 1

num = max(eng)
if eng.count(num) >= 2:
    print("?")
else:
    print(chr(eng.index(num) + 65))