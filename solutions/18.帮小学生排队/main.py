# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块
import json
"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    people = json.loads(line)

    if not people: return []
    peopledct, height, res = {}, [], []

    for i in range(len(people)):
        p = people[i]
        if p[0] in peopledct:
            peopledct[p[0]] += (p[1], i),
        else:
            peopledct[p[0]] = [(p[1], i)]
            height += p[0],

    height.sort()
    for h in height[::-1]:
        peopledct[h].sort()
        for p in peopledct[h]:
            res.insert(p[0], people[p[1]])

    return json.dumps(res, separators=(',', ':'))