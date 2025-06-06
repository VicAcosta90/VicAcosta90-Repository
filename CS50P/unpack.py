#def total(galleons, sickles, knuts):
    #return (galleons * 17 + sickles) * 29 + knuts

#coins = {"galleons": 100, "sickles": 50, "knuts": 25}

#print(total(**coins), "Knuts")


#unpack "*" for lists and "**" for dicts

#----------


def f(*args, **kwargs):
    print("Named:", kwargs)


f(galleons=100, sickles=50, knuts=25)