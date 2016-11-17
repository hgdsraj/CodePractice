
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

def confirm_sorted(array,length):
    for i in range(0,length-1):
        if(array[i] > array[i+1]):
            return False
    return True


def quick_sort_helper(array,first,last):
    if (last<first):
        return

    mid = int(first + int((last-first)/2))
    pivot = array[mid]

    i = first
    j = last
    while (i < j):
        while (array[i] < pivot):
            i+=1
        while (array[j] > pivot):
            j-=1
        if (i<=j):
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

def merge(array,first,mid,last):

    temp_array = [0] * (last-first+1)
    temp_iterator = 0;
    first_iterator = first
    last_iterator = mid+1

    while (first_iterator <= mid and last_iterator <= last):
        if (array[first_iterator] < array[last_iterator]):
            temp_array[temp_iterator] = array[first_iterator]
            first_iterator+=1
        else:
            temp_array[temp_iterator] = array[last_iterator]
            last_iterator+=1
        temp_iterator+=1

    while (first_iterator <= mid):
        temp_array[temp_iterator] = array[first_iterator]
        temp_iterator+=1
        first_iterator+=1

    while (last_iterator <= last):
        temp_array[temp_iterator] = array[last_iterator]
        temp_iterator+=1
        last_iterator+=1

    temp_iterator = 0
    for i in range(first,last+1):
        array[i] = temp_array[temp_iterator]
        temp_iterator+=1

def merge_sort_helper(array,first,last):
    if(last<=first):
        return

    mid = int(first + int( (last-first)/2 ) )

    merge_sort_helper(array,first,mid)
    merge_sort_helper(array,mid+1,last)
    merge(array,first,mid,last)


def merge_sort(array,length):
    if (length<2):
        return
    first = 0
    merge_sort_helper(array,first,length-1)

def get_size():
    while (True):
        try:
            length = int(input("Enter an integer size for the array: "))
            return length
        except:
            print("please input int")
    return


def main():
    print("hello world")
    #length = get_size()
    length = get_size()
    array = [0] * length

    fill_array(array,length)
    print_array(array,length)

    #quick_sort(array,length)
    merge_sort(array,length)
    print("array has been sorted")

    if (confirm_sorted(array,length)):
        print("array was sorted successfuly.")
    print_array(array,length)


if __name__ == "__main__":
    main()
