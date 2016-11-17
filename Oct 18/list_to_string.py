import copy

def list_to_string(string):
    temp_string = copy.copy(string)
    temp_string[len(string)-1] = 'and ' + temp_string[len(string)-1]
    return ", ".join(temp_string)

def main():
    spam = ['apples', 'bananas', 'tofu', 'cats']
    print(list_to_string(spam))
    return

if __name__ == '__main__':
    main()
