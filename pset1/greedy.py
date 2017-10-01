i,c,q,z = 0,0,0,0

c = float(input("Please enter your number: "))

z = int(c * 100) # it seems that there is no need to round here ?
print(z)

i = z // 25
q = z % 25
z = q

i = i + (z // 10)
q = z % 10
z = q

i = i + (z // 5)
q = z % 5

i = i + q

print(int(i))   