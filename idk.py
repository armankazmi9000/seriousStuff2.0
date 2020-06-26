from ppretty import ppretty


class Animal(object):
    def __init__(self):
        self.legs = 2
        self.name = 'Dog'
        self.color= 'Spotted'
        self.smell= 'Alot'
        self.age  = 10
        self.kids = 0


print ppretty(Animal(), seq_length=10)