# Given an array of integers, return an array where each element is the product
# of every element in the array except for its corresponding element in the
# first. Make the solution in O(n) time.

import random
import time

# Brute force method: calculate every element of the corresponding array
# manually.
def brute(a):
    soln = []
    for x in range(len(a)):
        soln.append(1)
        for y in range(len(a)):
            if y != x:
                soln[x] *= arr[y]
    return soln

# Speed up the process by reducing repeat operations. Steps are explained with
# the example array: [1,3,5,2,4]. The solution is [120,40,24,60,30].
def clever(a):
    soln = []
    for x in range(len(a)):
        soln.append(1)

    #   1   3   5   2   4
    #   1--------------->
    #           3------->
    #              15--->
    #                  30

    # Since 1x3 is added to every element after 3, we only need
    # to calculate it once and this will be the first factor for
    # every other element. The second factor for every element
    # (except the 3rd) will be 3*5, so 15 is now applicable to
    # the rest of the elements.
    for x in range(1, len(a)):
        soln[x] *= soln[x-1] * a[x-1]

    # We now have this.
    #   1   3   5   2   4
    #   1   1   3  15  30
    # The 2nd to last element is only missing *4, so we do that.
    # Since every element remaining is also missing *4, we save this
    # as our "multiplication value," the variable I've named "mv".
    
    #   1   1   3  60  30
    # 3rd element is missing *4 and *2, new mv=8. Each time, mv
    # is updated to the previous mv * the element we just finished.
    #   1   1  24  60  30           mv=8*5=40
    #   1  40  24  60  30           mv=40*3=120
    # 120  40  24  60  30
    mv = a[len(a)-1]
    for x in range(len(a)-2, -1, -1):
        soln[x] *= mv
        mv *= a[x]

    # We've reduced operations from O(n^2) to ~O(2n).
    return soln

if __name__ == '__main__':
    n = int(input('Enter number of items: '))

    arr = []
    for x in range(n):
        arr.append(random.randint(0,50))

    p1 = time.time_ns()
    sc = clever(arr)
    p2 = time.time_ns()
    print('Clever solved in {} s'.format((p2-p1)/10**9))

    p1 = time.time_ns()
    sb = brute(arr)
    p2 = time.time_ns()
    print('Brute solved in {} s'.format((p2-p1)/10**9))

    for x in range(len(sb)):
        if sb[x] != sc[x]:
            print('Error: solutions do not match')

    print('Checked: solutions match')
