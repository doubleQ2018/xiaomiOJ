# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    line = line.rstrip().split()
    nums = [int(i) for i in line[0].split(",")]
    target = int(line[1])
    if not nums:
            return -1

    low, high = 0, len(nums) - 1

    while low <= high:
        mid = (low + high) / 2
        if target == nums[mid]:
            return str(mid)

        if nums[low] <= nums[mid]:
            if nums[low] <= target <= nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        else:
            if nums[mid] <= target <= nums[high]:
                low = mid + 1
            else:
                high = mid - 1
    return "-1"