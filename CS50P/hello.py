# A STR is a sequence of text
# An INT is an integer like a -1, 0 or 1
# A float is a number with a decimal
# Bools or booleans expresions are True or False
# List is a way of containing multiples values all in the same variable
# A diccionarie or dict is a data structure that allows to associate one value with another


def main():
    name = input("What's your name? ")
    hello(name)


def hello(to="world"):
    return f"Hello,", {to}


if __name__ == "__main__":
    main()