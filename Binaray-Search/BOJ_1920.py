n = int(input())
num = list(map(int, input().split(" ")))
num.sort()
m = int(input())
arr = list(map(int, input().split(" ")))

for i in arr:
    left = 0
    right = len(num) - 1

    while right >= left:
        mid = (right + left) // 2
        if num[mid] < i:
            left = mid + 1
        elif num[mid] > i:
            right = mid - 1
        elif num[mid] == i:
            print(1)
            break
        else:
            print(0)
            break
        if left > right:
            print(0)
            break
