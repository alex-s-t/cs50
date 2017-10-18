def caesar_encrypt(plaintext, key):
    """Encrypts with Caesar's Cipher a plain text."""

    ciphertext = ''

    for char in plaintext:

        if char.islower():
            ciphertext += chr((((ord(char) - 97) + key) % 26) + 97)

        elif char.isupper():
            ciphertext += chr((((ord(char) - 65) + key) % 26) + 65)

        else:
            ciphertext += char

    return ciphertext


if __name__ == "__main__":

    plaintext = input("Plaintext: ")
    key = int(input("Key: ")) % 26
    print(caesar_encrypt(plaintext, key))

