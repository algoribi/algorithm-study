n = int(input())
st = []
for i in range(n):
    temp = input().split()
    st.append([temp[0], int(temp[1]), int(temp[2]), int(temp[3])])

st_sort = sorted(st, key=lambda s: (-s[1], s[2], -s[3], s[0]))

for i in st_sort:
    print(i[0])
