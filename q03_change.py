# Find the least number of coins you can make a specific amount of change with.

import time

# Brute-force, slow.
def change(amt, coins):
    if amt == 0:
        return []
    x = []
    
    for c in coins:
        if c > amt:
            continue
        x.append([c] + change(amt-c, coins))

    best = x[0]
    for y in x[1:]:
        if len(y) < len(best):
            best = y
    return best

# Dynamic should be much faster.
def change_dyn(amt, coins):
    dyn = []
    for x in range(amt+1):
        dyn.append([])

    dyn[1] = [1]
    for x in range(2, amt+1):
        possible = []
        for coin in coins:
            if coin > x:
                continue
            possible.append(dyn[x-coin] + [coin])
        best = possible[0]
        for p in possible[1:]:
            if len(p) < len(best):
                best = p
        dyn[x] = best
    return dyn[amt]

if __name__ == '__main__':
    n = int(input('Enter a number: '))

    p1 = time.time_ns()
    print(change_dyn(n, [1,5,10,25]))
    p2 = time.time_ns()
    print('Dynamic found solution in {} s'.format((p1-p1)/10**9))
    
    p1 = time.time_ns()
    print(change(n, [1,5,10,25]))
    p2 = time.time_ns()
    print('Recursive found solution in {} s'.format((p2-p1)/10**9))
