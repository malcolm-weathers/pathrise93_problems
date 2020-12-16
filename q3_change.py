import time

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

def change_dyn_r(amt, coins, dyn):
    if amt == 0:
        return []
    elif amt == 1:
        return [1]
    if dyn[amt] != -1:
        return dyn[amt]

    possible = []
    for coin in coins:
        if coin > amt:
            continue
        possible.append([coin] + change_dyn_r(amt-coin, coins, dyn))

    best = possible[0]
    for p in possible[1:]:
        if len(p) < len(best):
            best = p
    dyn[amt] = best
    return best

def change_dyn(amt, coins):
    dyn = []
    for x in range(amt+1):
        dyn.append(-1)
    return change_dyn_r(amt, coins, dyn)
    

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
