# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.rstrip().split(",")]
    nums = sorted(nums)
    ans = nums[len(nums)/2]
    return str(ans)