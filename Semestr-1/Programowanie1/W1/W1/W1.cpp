// W1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void zad1() {
    unsigned int n, m, k;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);
    printf("Podaj k: ");
    scanf_s("%d", &k);
    unsigned int cn = n;
    while (cn > m && cn < k) {
        cn += n;
        printf("%d\n", cn);
    }

}

void zad2() {
    unsigned int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    unsigned int sum = 0;

    for (int i = 0; i <= n; i++)
        sum += i * i;

    printf("Suma: %d\n", sum);

}

int main()
{
    //zad1
    zad1();

    //zad2
    zad2();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
