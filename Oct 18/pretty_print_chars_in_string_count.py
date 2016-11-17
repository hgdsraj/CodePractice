import copy
import pprint

def get_count(string):
    count = {}

    for i in string:
        count.setdefault(i, 0)
        count[i] += 1
    return count

def main():
    spam = 'there is a lot of spam in most areas of the world but far less in kentucky'
    print(spam)

    print('The count of each char in spam is :')
    count = get_count(spam)
    pprint.pprint(count)

    spam_as_list = spam.split(' ')
    print('spam as a list is\n', spam_as_list)
    spam_as_tuple = tuple(spam_as_list)
    print('spam as a dtupleict is \n', spam_as_tuple)

    for i,j in count.items():
        print(i, ' is key')
        print(j, ' is value')

    lel = {'gg': '16', 'lel': 15}
    print('16' in lel)
    print('16' in lel.keys())
    print('there are ' + str(count.get('z', 0)) + ' z chars in our string')
    return

if __name__ == '__main__':
    main()
