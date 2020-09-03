s = input()
f = input()
new_s = ""
for i in s:
    if i < "0" or i > "9":
        new_s += i
if new_s.find(f) != -1:
    print(1)
else:
    print(0)
