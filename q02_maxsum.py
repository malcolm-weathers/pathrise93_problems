# Given a list of integers, find the maximum sum with no two consecutive
# integers being added.

def maxsum(x):
    if x == []:
        return []
    if len(x) == 1:
        return [x[0]]
    o1 = [x[0]] + maxsum(x[2:])
    o2 = [x[1]] + maxsum(x[3:])
    if sum(o1) > sum(o2):
        return o1
    return o2

if __name__ == '__main__':
    print(maxsum([1,2,3]))
    print(maxsum([5,1,2,6]))
    print(maxsum([5,1,2,6,20,2]))
