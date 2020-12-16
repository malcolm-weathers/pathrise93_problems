# Implement a hash map from scratch.

words = []
for x in range(117):
    words.append(set())

def hashs(s):
    n = 7
    for char in s:
        n *= 7+((ord(char)-50)*3)
    return n % 117

def adds(s):
    words[hashs(s)].add(s)

def finds(s):
    return s in words[hashs(s)]

if __name__ == '__main__':
    adds('test')
    adds('text')
    adds('benihana')
    print('text={} bipartite={}'.format(finds('text'),finds('bipartite')))
