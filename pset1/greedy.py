def greedy_change(c):
    """Determines min. number of coins as change"""

    i,q,z = 0,0,0


    z = int(c * 100) # round to int

    i = z // 25
    q = z % 25
    z = q

    i = i + (z // 10)
    q = z % 10
    z = q

    i = i + (z // 5)
    q = z % 5

    i = i + q

    return i


if __name__ == "__main__":

    c = float(input("Please enter your number: "))
    print(greedy_change(c))