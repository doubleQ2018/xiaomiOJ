def best(num):
    if num[1] == num[0] + 1 and num[2] == num[1] + 1 and num[3] == num[2] + 1 and num[4] == num[3] + 1:
        return (1, num[4])
    maxcount = 1
    count = 1
    target = -1
    for i in range(1, len(num)):
        if num[i] == num[i-1]:
            count += 1
            if count >= maxcount:
                maxcount = count
                target = num[i]
        else:
            count = 1
            if count >= maxcount:
                maxcount = count
                target = num[i]

    if maxcount == 4:
        return (2, target)
    elif maxcount == 3:
        return (3, target)
    elif maxcount == 2:
        return (4, target)
    else:
        return (5, target)


def solution(line):
    x, y = line.split(",")
    hua = {"J": 11, "Q": 12, "K": 13, "A": 14}
    xnum = [hua[i] if hua.has_key(i) else int(i) for i in x.split()]
    ynum = [hua[i] if hua.has_key(i) else int(i) for i in y.split()]
    xnum = sorted(xnum)
    ynum = sorted(ynum)
    xx = best(xnum)
    yy = best(ynum)
    if xx[0] < yy[0]:
        return "win"
    elif xx[0] > yy[0]:
        return "lose"
    elif xx[0] == 1:
        if xx[1] > yy[1]:
            return "win"
        elif xx[1] < yy[1]:
            return "lose"
        else:
            return "draw"
    elif xx[0] == 2 or xx[1] == 3:
        if xx[1] > yy[1]:
            return "win"
        else:
            return "lose"

    elif xx[0] == 4:
        if xx[1] > yy[1]:
            return "win"
        elif xx[1] < yy[1]:
            return "lose"
        else:
            xrm = [i for i in xnum if i != xx[1]]
            yrm = [i for i in ynum if i != yy[1]]
            if xrm[0] == xrm[1] or xrm[1] == xrm[2]:
                xcount = 2
            else:
                xcount = 1
            if yrm[0] == yrm[1] or yrm[1] == yrm[2]:
                ycount = 2
            else:
                ycount = 1
            if xcount > ycount:
                return "win"
            elif xcount < ycount:
                return "lose"
            elif xcount == 1:
                for i in range(2, -1, -1):
                    if xrm[i] > yrm[i]:
                        return "win"
                    if xrm[i] < yrm[i]:
                        return "lose"
                return "draw"
            else:
                if xrm[1] > yrm[1]:
                    return "win"
                elif xrm[1] < yrm[1]:
                    return "lose"
                else:
                    xt = [i for i in xrm if i != xrm[1]]
                    yt = [i for i in yrm if i != yrm[1]]
                    if xt[0] > yt[0]:
                        return "win"
                    elif xt[0] < yt[0]:
                        return "lose"
                    else:
                        return "draw"
    else:
        for i in range(4, -1, -1):
            if xnum[i] > ynum[i]:
                return "win"
            if xnum[i] < ynum[i]:
                return "lose"
        return "draw"