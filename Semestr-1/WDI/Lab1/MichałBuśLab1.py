
#Zadanie 1
def cezar(text, przesuniecie):
    szyfr = ""
    for znak in text:
        if znak.isalpha():
            if znak.islower():
                szyfr += chr((ord(znak) - ord('a') + przesuniecie) % 26 + ord('a'))
            else:
                szyfr += chr((ord(znak) - ord('A') + przesuniecie) % 26 + ord('A'))
        else:
            szyfr += znak

    return szyfr


tekst = input("Podaj tekst: ")
split = int(input("Podaj przesuniecie: "))

print(cezar(tekst, split))

#Zadanie 2
tryb = input("Wybierz tryb: S - szyfrowanie, D - deszyfrowanie: ")

if tryb == "S" or tryb == "s":
    tekst = input("Podaj tekst: ")
    split = int(input("Podaj przesuniecie: "))
    print("Tryb: S")
    print("Tekst: " + tekst)
    print("Przesuniecie: " + str(split))
    print("Wnik: " + cezar(tekst, split))
elif tryb == "D" or tryb == "d":
    tekst = input("Podaj tekst do odszyfrowania: ")
    split = int(input("Podaj przesuniecie: "))
    print("Tryb: D")
    print("Tekst: " + tekst)
    print("Przesuniecie: " + str(split))
    print("Wnik: " + cezar(tekst, -split))

#Zadanie 3
zaszyfrowany = input("Podaj zaszyfrowany tekst: ")

print("Możliwe odszyfrowania: ")

for i in range(1, 26):
    print("Przesunięcie " + str(i) + ": " + cezar(zaszyfrowany, -i))




