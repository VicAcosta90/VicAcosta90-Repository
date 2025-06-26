from datetime import datetime


class Transaction:
    def __init__(self, amount, trx, description=""):
        self.amount = amount
        if trx.lower() in ["deposit", "withdraw"]:
            self.trx = trx
        else:
            raise ValueError("Not a valid transaction")
        self.timestamp = datetime.now()
        self.description = description

    def __str__(self,):
        return f"Amount: {self.amount}, Type: {self.trx}, Timestamp: {self.timestamp}, Description: {self.description}"

class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance
        self.transactions = []

    def __str__(self):
        return f"{self.owner}'s account - Balance: {self.balance}"

    def deposit(self, amount):
        new_deposit = Transaction(amount, "deposit", description="")
        self.transactions.append(new_deposit)
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            raise ValueError("Not enough money in account")
        else:            
            new_withdraw = Transaction(amount, "withdraw", description="")
            self.transactions.append(new_withdraw)
            self.balance -= amount

    def get_balance(self):
        return self.balance

    def print_statement(self):
        for transaction in self.transactions:
            print(transaction)
        print(f"Current balance: {self.balance}")


class Customer:
    def __init__(self, name):
        self.name = name
        self.accounts = []

    def open_account(self, initial_balance=0):
        new_account = BankAccount(self.name, balance=initial_balance)
        self.accounts.append(new_account)
        

    def close_account(self, account):
        if account in self.accounts:
            self.accounts.remove(account)
        else:
            raise ValueError("Account does not exists")

    def get_total_balance(self):
        return sum(account.get_balance()for account in self.accounts)

    def list_accounts(self):
        for account in self.accounts:
            print(account)

    def transfer(self, from_account, to_account, amount):
        if from_account in self.accounts and to_account in self.accounts:
            from_account.withdraw(amount)
            to_account.deposit(amount)