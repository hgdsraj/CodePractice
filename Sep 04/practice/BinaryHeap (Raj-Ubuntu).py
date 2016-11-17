import random
import math

class BinaryHeap(object):
    """ This class is a BinaryHeap.
        Includes a sort function, implemented as heapsort
        insert, etc.
    """
    #variables:
    MAX_SIZE = 100
    heap_size = 0;
    array_size = 0;
    heap = [0] * MAX_SIZE

    def fill_heap_random(self,length):
        self.array_size = length
        for i in range(0,length):
            self.heap[i] = random.randint(0,length)
        return

    def __init__(self,length = 0):
        self.fill_heap_random(length)
        return

    def print_heap(self):
        print("[ ", end="")
        for i in range(0,self.array_size):
            print(self.heap[i], end="")

            if (i!=self.array_size-1):
                print(", ", end="")

        print(" ]\n")

    #helper functions:
    def get_left_child(self,index):
        left_child = index*2 + 1
        return left_child

    def get_right_child(self,index):
        right_child = index*2 + 2
        return right_child

    def is_sorted(self):
        for i in range(0,self.array_size-1):
            if(self.heap[i] > self.heap[i+1]):
                return False
        return True

    #swaps heap[index_one] with heap[index_two]
    def swap(self,index_one,index_two):
        temp = self.heap[index_one]
        self.heap[index_one] = self.heap[index_two]
        self.heap[index_two] = temp

    #puts largest element at top of heap starting at index
    def max_heapify(self,index):
        left = self.get_left_child(index)
        right = self.get_right_child(index)
        if index < 0 or index > self.heap_size:
            print("INDEX ERRRO!")
            return
        largest = index

        if left < self.heap_size and self.heap[left] > self.heap[index]:
            largest = left

        if right < self.heap_size and self.heap[right] > self.heap[largest]:
            largest = right

        if largest != index:
            self.swap(index,largest)
            self.max_heapify(largest)

    #builds a heap, with all children smaller than their parents
    def build_max_heap(self):
        self.heap_size = self.array_size
        floor_length = int(math.floor(self.heap_size/2))
        for i in range(floor_length, -1, -1):
            self.max_heapify(i)

    #sorts the array nlogn time.
    def heap_sort(self):
        self.build_max_heap()
        for i in range(self.array_size-1,0,-1):
            self.swap(0,i)
            self.heap_size-=1
            self.max_heapify(0)
