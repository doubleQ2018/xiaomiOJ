# Author : Qi Zhang
# Date   : 2018-12-11

# 此处可 import 模块

"""
@param string line 为单行测试数据
@return string 处理后的结果
"""
def solution(line):
    nums = [int(i) for i in line.rstrip().split(",")]
    def divide(start, end):
        if start >= end:
            return 0
        m = (start + end) / 2
        ans = 0
        ans += divide(start, m)
        ans += divide(m+1, end)
        i = start
        j = m+1
        tmp = []
        while(i <= m and j <= end):
            if nums[i] <= nums[j]:
                tmp.append(nums[i])
                i += 1
            else:
                ans += m - i + 1
                tmp.append(nums[j])
                j += 1
        while(i <= m):
            tmp.append(nums[i])
            i += 1
        while(j <= end):
            tmp.append(nums[j])
            j += 1
        for k in range(start, end+1):
            nums[k] = tmp[k-start]
        return ans
    ans = divide(0, len(nums)-1)
    return str(ans)