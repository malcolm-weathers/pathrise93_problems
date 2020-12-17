def power(x, a):
    if a == 0:
        return 1
    return x * power(x, a - 1)

if __name__ == '__main__':
    print(power(2, 2))
    print(power(2, 3))
    print(power(3, 5))
