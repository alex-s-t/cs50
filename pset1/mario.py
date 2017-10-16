def pyramid_printer(height):
    """Simply prints out a mario end stage pyramid"""

    # sentinel values for sanity in terminal output
    if height < 0 or height > 23:
        return False

    for i in range(1, height + 1):
        string = "{}{}  {}".format(
                                    " " * (height - i),
                                    "#" * i,
                                    "#" * i)
        print(string)
    return True


if __name__ == "__main__":
    pyramid_printer(15)

