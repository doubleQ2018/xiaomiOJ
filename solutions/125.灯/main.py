# Author : Qi Zhang
# Date   : 2019-02-19

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    n, l = map(int, line.split())
    if n % 2 == 0:
        if l % 2 == 0:
            return n-l
        else:
            return l
    else:
        if l % 2 == 0:
            return "Impossible"
        else:
            return min(n-l, l)