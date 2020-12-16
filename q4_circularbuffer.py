# Implement a circular buffer.

class circle_buffer():
    def __init__(self):
        self.data = []
        self.read = 0
        self.write = 0

    def bwrite(self, item):
        if self.write >= len(self.data):
            self.data.append(item)
            self.write += 1
        else:
            if self.write == self.read:
                self.read += 1
            
            self.data[self.write] = item
            self.write += 1

        if self.write == 8:
            self.write = 0
        if self.read == 8:
            self.read = 0      

    def bread(self):
        item = self.data[self.read]
        self.read += 1
        if self.read == 8:
            self.read = 0
        return item

    def print(self):
        print(self.data)

if __name__ == '__main__':
    b = circle_buffer()
    for x in range(0,10):
        b.bwrite(x)
    b.print()
    b.bwrite(55)
    b.bwrite(55)
    b.print()
    print(b.bread())
    print(b.bread())
    b.bwrite(67)
    b.bwrite(68)
    b.bwrite(75)
    b.bwrite(77)
    b.print()
    print(b.bread())
    print(b.bread())
