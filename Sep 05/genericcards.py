# Design the data structure for a generic deck of cards
# n different suits
# m values per suit: similar to typical playing cards, a range from 1 - m

'''

# Reference classes

class Pet(object):

    def __init__(self, name, species):
        self.name = name
        self.species = species

    def getName(self):
        return self.name

    def getSpecies(self):
        return self.species

    def __str__(self):
        return "%s is a %s" % (self.name, self.species)

class Dog(Pet):

    def __init__(self, name, chases_cats):
        Pet.__init__(self, name, "Dog")
        self.chases_cats = chases_cats

    def chasesCats(self):
        return self.chases_cats

    binHeap = BinaryHeap(length)
    binHeap.print_heap()
    binHeap.heap_sort()
    if binHeap.is_sorted():
        print("Successful Sort.")
        binHeap.print_heap()


    def __init__(self,length = 0):
        self.fill_heap_random(length)
        return


'''

'''
Data: list based, list of card objects which have suit and value attributes
(card and deck classes are sorted abstract factories)
Operations: shuffle, remove, add, etc
'''

from random import shuffle as s

# Interfaces:

class Deck(object):

    def __init__(self, num_suits, num_values):
        self.list = [0] * (num_suits * num_values)
        deck_pos = 0
        for i in range(num_suits):
            for j in range(num_values):
                a_card = Card(i, j)
                self.list[deck_pos] = a_card
                deck_pos += 1


    def shuffle(self):
        s(self.list)

    '''
    def remove(self, Card):
        self.list.remove()

    def add(self, Card):
        self.list.append(Card)
    '''

class Card(object):

    def __init__(self, suit, value):
        self.suit = suit
        self.value = value
