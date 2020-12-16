# Find all the combinations of a string in lowercase and uppercase.

def combos(x):
    if len(x) == 0:
        return ['']
    rec = combos(x[1:])
    lc = [x[0].upper()+y for y in rec]
    lc2 = [x[0].lower()+y for y in rec]
    return lc+lc2

if __name__ == '__main__':
    print(combos('ab'))
