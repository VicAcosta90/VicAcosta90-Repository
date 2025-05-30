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

