# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    num, k = line.rstrip().split(",")
    k = int(k)
    if len(num) <= k:
            return '0'

    stack = []

    for digit in num:
        while k> 0 and stack and int(stack[-1]) > int(digit):
            stack.pop()
            k -= 1
        stack.append(digit)

    while k > 0: #corner case 112 remove 1
        stack.pop()
        k -= 1
    return ''.join(stack).lstrip('0') or '0'