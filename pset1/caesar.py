plaintext = input("Plaintext: ")
key = int(input("Key: ")) % 26

ciphertext = ''

for char in plaintext:
    
    if char.islower():
        
        ciphertext += chr((((ord(char) - 97) + key) % 26) + 97)
        
    elif char.isupper():
        ciphertext += chr((((ord(char) - 65) + key) % 26) + 65)
    
    else:
        ciphertext += char
        
print(ciphertext)