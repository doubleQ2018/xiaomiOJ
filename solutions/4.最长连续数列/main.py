# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    num = [int(i) for i in line.rstrip().split(",")]
    dict = {x: False for x in num}
    maxLen = -1
    for i in dict:
        if dict[i] == False:
            curr = i+1; lenright = 0
            while curr in dict:
                lenright += 1; dict[curr] = True; curr += 1
            curr = i-1; lenleft = 0
            while curr in dict:
                lenleft += 1; dict[curr] = True; curr -= 1
            maxLen = max(maxLen, lenleft+1+lenright)

    return str(maxLen)