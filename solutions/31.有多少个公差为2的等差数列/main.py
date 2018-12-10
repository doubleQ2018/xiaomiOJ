# 此处可 import 模块
import math
"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    n = int(line.strip())
    ans = 0
    for l in range(1, int(math.sqrt(n))+2):
        if n % l == 0 and n/l > l-1:
            ans += 1
    return str(ans)