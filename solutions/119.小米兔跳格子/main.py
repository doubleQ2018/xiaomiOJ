# Author : Qi Zhang
# Date   : 2019-01-16

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.strip().split()]
    stepsLeft = nums[0]

    if not stepsLeft and len(nums) > 1:
        return "false"

    for num in nums[1:-1]:
        stepsLeft = max(stepsLeft - 1, num)
        if not stepsLeft:
            return "false"

    return "true"