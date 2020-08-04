list_pe = []
for i in range(5):
    s = input()
    if s.find("FBI") != -1:
        list_pe.append(i + 1)

if len(list_pe) == 0:
    print("HE GOT AWAY!")
else:
    for i in list_pe:
        print(i, end=" ")
