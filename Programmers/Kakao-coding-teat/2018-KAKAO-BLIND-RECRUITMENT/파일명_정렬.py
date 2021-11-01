import re

def solution(files):

    file = [re.split(r"([0-9]+)", i) for i in files]
    print(file)
    s_file = sorted(file, key=lambda x: (x[0].lower(), int(x[1])))

    answer = []
    for i in s_file:
        answer.append("".join(i))
    return answer
