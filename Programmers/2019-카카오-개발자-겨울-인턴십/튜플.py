def solution(s):
    sps = s.split("},{")
    sps[0] = sps[0][2:]
    sps[-1] = sps[-1][:-2]
    sps.sort(key=len)
    chk = [0 for i in range(100010)]
    answer = []
    for i in sps:
        temp = i.split(",")
        for j in temp:
            if chk[int(j)] == 0:
                chk[int(j)] = 1
                answer.append(int(j))
    return answer