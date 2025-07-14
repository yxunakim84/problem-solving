def solution(name, yearning, photo):
    answer = []
    # d = {}
    # for i in range(len(name)):
    #     d[name[i]] = yearning[i] 
    d = dict(zip(name, yearning))
    for item in photo:
        val = 0
        for _name in item:
            if _name in d:
                val += d[_name]
        answer.append(val)
    return answer