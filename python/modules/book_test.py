from book import Book
from book import EconomyBook

def book_test():
    b1 = Book("A history of AI", "Jason", "Technology")
    b2 = EconomyBook("How Economy Works", "John")

    book_shelf = [b1, b2]

    for book in book_shelf:
        print(book.description())


book_test()
