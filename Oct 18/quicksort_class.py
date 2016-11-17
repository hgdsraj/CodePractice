from random import randint as rand

class smart_array(object):
    array = [None]
    length = 0

    def __init__(self, given_length = 0):
        self.array = self.array*int(given_length)
        self.length = given_length

    def randomize(self):
        for i in range(self.length):
            self.array[i] = rand(0,self.length)

    def quicksort_helper(self, first, last):
        if first >= last:
            return

        mid = first + (last - first) // 2
        pivot = self.array[mid]
        i = first
        j = last

        while i < j:
            while self.array[i] < pivot:
                i += 1
            while self.array[j] > pivot:
                j -= 1
            if i <= j:
                temp = self.array[j]
                self.array[j] = self.array[i]
                self.array[i] = temp
                i += 1
                j -= 1

        if first < j:
            self.quicksort_helper(first, j)
        if i < last:
            self.quicksort_helper(i, last)
        return

    def quicksort(self):
        if self.length > 1:
            self.quicksort_helper(0, (self.length - 1) )
        return


def main():
    j = smart_array(10)
    j.randomize()
    print(j.array)
    j.quicksort()
    print(j.array)

    return

if __name__ == '__main__':
    main()
