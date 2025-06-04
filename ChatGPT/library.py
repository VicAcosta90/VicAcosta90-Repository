import uuid

class Book:
    def __init__(self, title, author, isbn, available=True):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.available = True

    def __str__(self):
        return f"{self.title} written by {self.author}, with ISBN #{self.isbn}"
    
class Member:
    id_counter = 1

    def __init__(self, name, member_id):
        self.name = name
        self.member_id = Member.id_counter
        Member.id_counter += 1
        self.borrowed_books = []

    def borrow_book(self, book):
        

Methods:

borrow_book(book) → adds book to borrowed list and marks it unavailable

return_book(book) → removes from borrowed list and marks it available

list_books() → prints borrowed books

🔹 3. Library
Attributes:

books (list of all Book)

members (list of all Member)

Methods:

add_book(book)

register_member(member)

find_book_by_title(title) → returns the book object or None

list_available_books()

✅ Bonus Features (optional)
If you finish the basics, try adding:

Prevent a member from borrowing more than 3 books

Prevent borrowing if book is not available

Prevent returning books the member didn’t borrow

Auto-generate member_id using uuid or a counter