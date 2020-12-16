# Determine whether a string is a palindrome.

import math

def palindrome(s):
    for x in range(0,math.ceil(len(s)/2)):
        if s[x] != s[len(s)-x-1]:
            return False
    return True

if __name__ == '__main__':
    print(palindrome('racecar'))
    print(palindrome('saas'))
    print(palindrome('arthur c fitzgerald'))
