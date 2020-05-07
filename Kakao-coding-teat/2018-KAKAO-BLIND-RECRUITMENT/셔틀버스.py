def solution(n, t, m, timetable):
    answer = ""
    timetable = [int(time[:2]) * 60 + int(time[3:5]) for time in timetable]

    timetable.sort()

    last_bus_time = 540 + (n - 1) * t
    for i in range(n):
        if len(timetable) < m:
            answer = "%02d:%02d" % (last_bus_time // 60, last_bus_time % 60)
            break
        if i == n - 1:
            if timetable[0] > last_bus_time:
                answer = "%02d:%02d" % (
                    last_bus_time // 60, last_bus_time % 60)
                break
            time = timetable[m - 1] - 1
            answer = "%02d:%02d" % (time // 60, time % 60)
        arrive_bus_time = 540 + i * t
        for j in range(m - 1, -1, -1):
            if timetable[j] <= arrive_bus_time:
                del timetable[j]
    return answer
