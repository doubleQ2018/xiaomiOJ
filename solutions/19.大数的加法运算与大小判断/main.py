# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    if '<' in line:
        a, b = line.rstrip().split('<')
        a.lstrip('0')
        b.lstrip('0')
        if len(a) < len(b):
            return "Y"
        elif len(a) > len(b):
            return "N"
        else:
            return "Y" if a < b else "N"
    if '>' in line:
        a, b = line.rstrip().split('>')
        a.lstrip('0')
        b.lstrip('0')
        if len(a) > len(b):
            return "Y"
        elif len(a) < len(b):
            return "N"
        else:
            return "Y" if a > b else "N"
    a, b = line.rstrip().split('+')
    if len(a) < len(b):
        a, b = b, a
    i = len(a) - 1
    j = len(b) - 1
    r = 0
    ans = ""
    while (i >= 0 and j >= 0):
        val = int(a[i]) + int(b[j]) + r
        if val >= 10:
            ans += str(val % 10)
            r = 1
        else:
            ans += str(val)
            r = 0
        i -= 1
        j -= 1

    while (i >= 0):
        val = int(a[i]) + r
        if val >= 10:
            ans += str(val % 10)
            r = 1
        else:
            ans += str(val)
            r = 0
        i -= 1
    if r == 1:
        ans += "1"
    
    ans = ans[::-1].lstrip("0")
    if ans == "":
        return "0"
    else:
        return ans