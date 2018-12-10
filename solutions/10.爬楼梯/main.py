# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    n = int(line.rstrip())
    if n == 1:
        return "1"
    if n == 2:
        return "2"
    a = 1
    b = 2
    for i in range(3, n+1):
        c = a+b
        a = b
        b = c
    return str(b)