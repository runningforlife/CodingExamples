
class Book():
    """a class to describe a book"""

    def __init__(self, name, author, category):
        self.name = name
        self.author = author
        self.category = category

    def description(self):
        return self.name + " " + self.author + " " + self.category


    def getName(self):
        return self.name

    def getAuthor(self):
        return self.author

    def getCategory(self):
        return self.category


class EconomyBook(Book):
    """economic book"""

    def __init__(self, name, author):
        super().__init__(name, author, "Economy")
