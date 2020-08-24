n = int(input())
ans = 0
if n % 5 == 0:
    ans = n // 5
else:
    for num in reversed(range(n // 5 + 1)):
        if (n - (5 * num)) % 3 == 0:
            ans = num + (n - (5 * num)) // 3
            break
    if ans == 0 and n % 3 == 0:
        ans = n // 3
    elif ans == 0:
        ans = -1

print(ans)
