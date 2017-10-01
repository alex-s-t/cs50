height = None

while height < 0 or height > 23 or height == None:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    
for i in range(1, height + 1):
    string = "{}{}  {}".format(" " * (height - i),"#" * i, "#" * i)
    print(string)