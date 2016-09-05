
import random

def fill_array(array,length):
    for i in range(0,length):
        array[i] = random.randint(0,length)
    return

def print_array(array,length):
    print("[ ", end="")
    for i in range(0,length):
        print(array[i], end="")
        if (i!=length-1):
            print(", ", end="")
    print(" ]\n")

def quick_sort_helper(array,first,last):
    if (last<first):
        return

    mid = int(first + int((last-first)/2))
    pivot = array[mid]

    i = first
    j = last
    while (i<j):
        while (array[i] < pivot):
            i+=1
        while (array[j] > pivot):
            j-=1
        if (i<j):
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
            i+=1
            j-=1

    if (first < j):
        quick_sort_helper(array,first,j)
    if (i < last):
         quick_sort_helper(array,i,last)

    return

def quick_sort(array,length):
    if (length<2):
        return
    start_position = 0
    quick_sort_helper(array,start_position,length-1)

def get_size():
    while (True):
        length = input("Enter an integer size for the array: ")
        if (type(i) is int):
            return i
    return


def main():
    print("hello world")
    #length = get_size()
    length = 10
    array = [0] * length

    fill_array(array,length)
    print_array(array,length)

    quick_sort(array,length)
    print("array has been sorted")

    print_array(aray,length)


if __name__ == "__main__":
    main()
