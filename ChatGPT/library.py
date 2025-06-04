import sys

class Book:
    def __init__(self, title, author, isbn, available=True):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.available = available

    def __str__(self):
        return f"{self.title} written by {self.author}, with ISBN #{self.isbn}"
    
class Member:
    id_counter = 1

    def __init__(self, name):
        self.name = name
        self.member_id = Member.id_counter
        Member.id_counter += 1
        self.borrowed_books = []

    def borrow_book(self, book):
        if len(self.borrowed_books) < 3:
            if book.available == True:
                book.available = False
                self.borrowed_books.append(book)
            else:
                raise ValueError("Book not available")
        else:
            print("Too many books borrowed")
        
    def return_book(self, book):
        if book in self.borrowed_books:
            self.borrowed_books.remove(book)
            book.available = True
        else:
            print("Book never borrowed by the user")

    def list_books(self):
        print("Books borrowed:")
        for book in self.borrowed_books:
            print(book)

class Library:
    def __init__(self):    
        self.books = []
        self.members = []

    def add_book(self, title, author, isbn, available=True):
        if title not in self.books:
            new_book = Book(title, author, isbn, available=True)
            self.books.append(new_book)
        else:
            print(f"{title} already in the library")

    def register_member(self, name):
        new_member = Member(name)
        self.members.append(new_member)

    def find_book_by_title(self,title):
        for book in self.books:
            if book.title == title:
                return book
        print(f"{title} is not in the library")
        
    def list_available_books(self):
        print("List of available books:")
        for book in self.books:
            if book.available:
                print(book)

