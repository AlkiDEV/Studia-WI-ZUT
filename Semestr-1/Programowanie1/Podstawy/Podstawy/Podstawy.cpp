// Podstawy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //Zad 1
    printf_s("Hello World!\n");
    //Zad 2
    printf_s("Bardzo\ndlugi\nnapis\n");
    //Zad 3
    printf_s("Napis zawierajacy rozne dziwne znaczki // \\\\ $ & %% \n");
    //Zad 4
    int a = 0;
    scanf_s("%d", &a);
    printf_s("%d\n", a);
    //Zad 5
    float b;
    scanf_s("%f", &b);
    printf_s("%.2f\n", b);
    //Zad 6
    int ta[3];
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &ta[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf_s("%d\n", ta[i]);
    }
    //Zad 7
    int c;
    scanf_s("%d", &c);
    printf_s("%d\n", c + 1);
    //Zad 8
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &ta[i]);
        sum += ta[i];
    }
    float sr = sum / 3;
    printf_s("%.2f\n", sr);
    //Zad 9
    float x = 0;
    scanf_s("%f", &x);
    printf("%.2f\n", sqrt(x));
    //Zad 10
    scanf_s("%f", &x);
    printf("%.2f\n", (x > 0 ? x : x *= -1));
    //Zad 11
    scanf_s("%f", &x);
    printf("%.2f\n", x);
    //Zad 12
    scanf_s("%f", &x);
    printf("%e", x);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
