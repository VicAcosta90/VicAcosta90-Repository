class Book:
    def __init__(self, title, author, pages, available=True):
        self.title = title
        self.author = author
        self.pages = pages
        self.available = True

    def borrow(self):
        if self.available:
            self.available = False
            print(f"You have borrowed {self.title}")
        else:
            print(f"Sorry, {self.title} is not available.")

    def return_book(self):
        self.available = True
        print(f"You have returned {self.title}")


class Library:
    def __init__(self):
        self.books = []

    def add_book(self, title, author, pages):
        new_book = Book(title, author, pages)
        self.books.append(new_book)

    def borrow_book(self, title):
        for book in self.books:
            if book.title == title:
                if book.available:
                    book.available = False
                    print(f"You have borrowed {book.title}")
                else:
                    print("Book is currently borrowed")
                return
        print("Book not found")

    def return_book(self, title):
        for book in self.books:
            if book.title == title:
                if book.available == False:
                    book.available = True
                    print(f"You have returned {book.title}")
                else:
                    print("Book is already returned")
                return
        print("Book not found")

    def list_books(self):
        for book in self.books:
            status = "Available" if book.available else "Borrowed"
            print(f"{book.title} by {book.author} ({book.pages} pages) - {status}")
