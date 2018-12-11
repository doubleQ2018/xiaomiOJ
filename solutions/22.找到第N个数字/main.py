# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块
import math
"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    x = int(line.strip())
    s = int(math.sqrt(2*x))
    target = 0
    for n in range(s-1, s+2):
        if n*(n-1)/2 < x and (n+1)*n/2 >= x:
            target = n
            break
    target = x - target*(target-1)/2
    k = (target - 1) % 16
    if k < 9:
        return str(k+1)
    else:
        return str(17-k)