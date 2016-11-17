from BinaryHeap import BinaryHeap



def main():
    length = 10
    binHeap = BinaryHeap(length)
    binHeap.print_heap()
    binHeap.heap_sort()
    if binHeap.is_sorted():
        print("Successful Sort.")
        binHeap.print_heap()

if __name__ == "__main__":
    main()
