from math import gcd

# Zadanie 1
def encrypt(text, a=5, b=8):
    text = text.replace(" ", "").upper()
    encrypted = ""
    for char in text:
        x = ord(char) - ord('A')
        y = (a * x + b) % 26
        encrypted += chr(y + ord('A'))

    return encrypted

tekst = input("Podaj tekst jawny: ").upper()
print(f"Tekst zaszyfrowany: {encrypt(tekst)}")

# Zadanie 2
def decrypt(cipher, a=5, b=8):
    a_inv = 0
    for i in range(1, 26):
        if(a * i) % 26 == 1:
            a_inv = i
            break
    decrypted = ""
    for char in cipher:
        y = ord(char) - ord('A')
        x = (a_inv * (y - b)) % 26
        decrypted += chr(x + ord('A'))

    return decrypted

print(f"Tekst odszyfrowany: {decrypt(encrypt(tekst))}")

# Zadanie 3
def check_key(key):
    if gcd(key, 26) != 1:
        return False
    else:
        return True

a = int(input("Podaj wartosc klucza a: "))
if check_key(a):
    print(f"Klucz {a} jest poprawny")
else:
    print(f"Klucz {a} nie jest poprawny")

