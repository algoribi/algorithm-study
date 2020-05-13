"""
algorithm study
SWEA_[D3]7732_시간 개념
"""
test_case = int(input())
for i in range(test_case):
    now_time = input()
    next_time = input()

    now_time = int(now_time[:2]) * 3600 + int(now_time[3:5]) * 60 + int(now_time[6:])
    next_time = int(next_time[:2]) * 3600 + int(next_time[3:5]) * 60 + int(next_time[6:])
    if now_time > next_time:
        next_time += 24 * 3600
    answer = "%02d:%02d:%02d" % (
        (next_time - now_time) / 3600,
        ((next_time - now_time) % 3600) / 60,
        ((next_time - now_time) % 3600) % 60,
    )
    print("#" + str(i + 1) + " " + answer + "\n")
