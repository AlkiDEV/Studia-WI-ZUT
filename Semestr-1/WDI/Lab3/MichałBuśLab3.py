import numpy as np
import math

# Zadanie 3
def validate(k):
    det = int(round(np.linalg.det(k)))
    print(f"Wyznacznik macierzy: {det}")
    mod_det = det % 26
    print(f"Wyznacznik mod 26: {mod_det}")
    g = math.gcd(mod_det, 26)
    print(f"NWD(det(K), 26) = {g}")
    if g == 1:
        return True
    else:
        return False


# Zadanie 1
def letter_to_number(letter):
    return ord(letter) - ord('A')

def number_to_letter(number):
    return chr(number + ord('A'))

K = np.array([[3,3],
              [2,5]])
def encrypt(text, k):
    if(not validate(k)):
        return 0
    if len(text) % 2 != 0:
        text += "X"
    numbers = [letter_to_number(letter) for letter in text]
    blocks = [numbers[i:i+2] for i in range(0, len(numbers), 2)]
    cipher_nums = []

    for i in range(0, len(numbers), 2):
        a = numbers[i]
        b = numbers[i+1]

        c1 = (k[0][0] * a + k[0][1] * b) % 26
        c2 = (k[1][0] * a + k[1][1] * b) % 26

        cipher_nums.extend([c1, c2])

    cipher_text = "".join(number_to_letter(int(num)) for num in cipher_nums)
    return cipher_text

tekst = input("Podaj tekst jawny: ").replace(" ", "").upper()
print(f"Tekst zaszyfrowany: {encrypt(tekst, K)}")

# Zadanie 2
def decrypt(text, k):
    if (not validate(k)):
        return 0
    det = int(round(np.linalg.det(k))) % 26
    def mod_inverse(a, m):
        a = a % m
        for x in range(1, m):
            if (a * x) % m == 1:
                return x
        raise ValueError("Brak odwrotności modularnej")

    inv_det = mod_inverse(det, 26)
    adj = np.round(det * np.linalg.inv(k)).astype(int) % 26

    dk = (inv_det * adj) % 26
    if len(text) % 2 != 0:
        text += "X"
    numbers = [letter_to_number(letter) for letter in text]
    blocks = [numbers[i:i + 2] for i in range(0, len(numbers), 2)]
    decrypt_nums = []

    for i in range(0, len(numbers), 2):
        a = numbers[i]
        b = numbers[i + 1]

        c1 = (dk[0][0] * a + dk[0][1] * b) % 26
        c2 = (dk[1][0] * a + dk[1][1] * b) % 26

        decrypt_nums.extend([c1, c2])

    decrypted_text = "".join(number_to_letter(int(num)) for num in decrypt_nums)
    return decrypted_text

print(f"Tekst odszyfrowany: {decrypt(encrypt(tekst, K), K)}")

