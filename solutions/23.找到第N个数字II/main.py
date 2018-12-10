import math
def nth(n):
    if n<=9:return n
    tmp_sum = 9
    num = 9
    num2 = 1
    while n>=tmp_sum:
        if n==tmp_sum:return 9
        num*=10
        num2+=1
        tmp_sum+=(num*num2)
    tmp_sum -= (num*num2)
    n = n-tmp_sum
    c1 = n/num2
    c2 = n%num2
    if c2==0:return (num/9+c1-1)%10
    return int(str(num/9+c1)[c2-1])

def solution(line):
    x = int(line.strip())
    start = 1
    end = 10
    k = 1
    sums = 0
    while True:
        sums += k * (start + 1 + end) * (end - start) / 2 - (pow(10, k) - 1) / 9 * (end - start)
        if sums >= x:
            break
        start *= 10
        end *= 10
        k += 1
    if sums == x:
        target = end
    else:
        sums -= k * (start + 1 + end) * (end - start) / 2 - (pow(10, k) - 1) / 9 * (end - start)
        n = start
        while True:
            sums += k * (n+1) - (pow(10, k) - 1) / 9
            if sums >= x:
                break
            n += 1
        sums -= k * (n+1) - (pow(10, k) - 1) / 9
        target = x - sums

    return str(nth(target))