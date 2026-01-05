// Funkcje.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Funkcje mog¹ce byæ wykorzystywane w ca³ym zestawie zadañ
// Modulo
int mod(int a) {
    return (a < 0) ? -a : a;
}
// Silnia
int fact(int a) {
    int factorial = 1;
    for (int i = 1; i <= a; i++)
        factorial *= i;

    return factorial;
}
int factRec(int a) {
    if (a == 1) return 1;
    else return a * fact(a - 1);
}
// Najwiêkszy dzielnik mniejszy od n
int ND(unsigned int n) {
    for (int k = n / 2; k >= 1; k--)
        if (n % k == 0)
            return k;
    return 1;
}
// 2^n
float pow2n(int n) {
    float a = 1.0;
    if (n > 0)
        for (int i = 0; i < n; i++)
            a *= 2;
    else {
        for (int i = 0; i <= -n; i++)
            a *= 2;
        a = 1 / a;
    }
    return a;
}
// n^m
float powNm(int n, int m) {
    float a = 1.0;
    if (m > 0)
        for (int i = 0; i <= m; i++)
            a *= n;
    else {
        for (int i = 0; i <= -n; i++)
            a *= n;
        a = 1 / a;
    }
    return a;
}
// n^(1/2)
int sqrtN(unsigned int n){
    unsigned int a = 0;
    while ((a + 1) * (a + 1) <= n)
        a++;
    return a;
}
// n^(1/m)
int rootMN(int n, int m) {
    if (n == 0)return 0;
    if (m <= 1)return -1;
    int l = 1, h = n, r = 0;
    while (l <= h) {
        int mid = (l + h) / 2;

        long long power = 1;
        for (int i = 0; i < m; i++) {
            power *= mid;
            if (power > n)break;
        }
        if (power <= n) {
            r = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return r;

}
//GCD(a, b) - Euklides
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
int NWD(int a, int b) {
    if (b == 0) return a;
    return NWD(b, a % b);
}
// Funkcja do znajdywania rozkladow kwadratowych
void znajdzRozklady(int n, int start, int* rozk³ad, int poziom, int przypadekB, int m = 2) {
    if (n == 0) {
        // Wypisz rozk³ad
        for (int i = 0; i < poziom; i++) {
            printf("%d^%d", rozk³ad[i], m);
            if (i < poziom - 1) printf(" + ");
        }
        printf("\n");
        return;
    }

    for (int i = start; i * i <= n; i++) {
        rozk³ad[poziom] = i;
        znajdzRozklady(n - powNm(i, m), przypadekB ? i : 1, rozk³ad, poziom + 1, przypadekB, m);
    }
}
// Wczytywanie liczb
int readNumber() {
    int num;
    printf("Podaj liczbe calkowita: ");
    scanf_s("%d", &num);
    return num;
}
// Ciagi rekurencyjne
// an = 2 an-1 + 5
int an1(int n) {
    if (n == 0) return 1;
    return 2 * an1(n - 1) + 5;
}
// an = an-1 + 2 + 3n - 3
int an2(int n) {
    if (n == 0) return 1;
    return an2(n - 1) + 2 + 3 * n - 3;
}
//Fibonacci
int Fib(int n, int f1 = 1, int f2 = 1) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return f2;
    else
        return Fib(n - 1, f2, f1 + f2);
}
// an = an-1 + an-2
int an3(int n) {
    if (n == 0) return 1;
    else if (n == 1) return 0;
    else return an3(n - 1) + an3(n - 2);
}
// an = an-1 + n + an-2 + n
int an4(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return an4(n - 1) + n + an4(n - 2) + n;
}
// an = an-1 + an-2 + an-3
int an5(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return an5(n - 1) + an5(n - 2) + an5(n - 3);
}
// F(n,m) = ...
int F1(int n, int m) {
    if (n == 0 || m == 0) return 1;
    return F1(n - 1, m) + F1(n, m - 1) + 3 * F1(n - 1, m - 1);
}
int F2(int n, int m) {
    if (n == 0 || m == 0) return 1;
    return F2(n, m - 1) + F2(n - 1, m) + F2(n, m - 1);
}

// Funkcje zadañ
void zad1() {
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    printf("|%d| = %d\n", n, mod(n));
}
void zad2() {
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    printf("%d! = %d\n", n, fact(n));
}
void zad3() {
    unsigned int n;
    printf("Podaj n (n > 2): ");
    scanf_s("%d", &n);
    if (n < 2)
        return;
    
    printf("Najwiekszy dzielnik mniejszy od n: %d\n", ND(n));

}
void zad4(){
    unsigned int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    printf("2^%d = %f\n", n, pow2n(n));
}
void zad5(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    printf("2^%d = %.2f\n", n, pow2n(n));
}
void zad6(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    printf("%d^%d = %.2f\n", n, m, powNm(n, m));
}
void zad7(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    printf("%d^%d = %.2f\n", n, m, powNm(n, m));
}
void zad8(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    printf("Pierwiastek kwadratowy(zaokraglenie w dol) z %d = %d\n", n, sqrtN(n));
}
void zad9(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    printf("%d^(1/%d) = %d\n", n, m, rootMN(n, m));
}
void zad10(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    int sum = 0;
    for (int i = 1; i < n; i++)
        if (gcd(n, i) == 1)
            sum += i;

    printf("Suma: %d\n", sum);
}
void zad11(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    int sum = 0;
    float sumC = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += sqrtN(i);
        sumC += sqrt(i);
    }

    printf("Suma: %d, Suma kontrolna: %f", sum, sumC);
}
void zad12(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += rootMN(i, m);
    }

    printf("Suma: %d", sum);
}
void zad13(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    if (n <= 0)
        printf("n musi byc dodatnie!\n");

    printf("Przypadek a):\n");
    for (int a = 1; a * a < n; a++)
        for (int b = 1; b * b < n; b++)
            if (a * a + b * b == n)
                printf("%d^2 + %d^2 = %d\n", a, b, n);

    printf("Przypadek b):\n");
    for (int a = 1; a * a < n; a++)
        for (int b = a; b * b < n; b++)
            if (a * a + b * b == n)
                printf("%d^2 + %d^2 = %d\n", a, b, n);

}
void zad14(){
    int n;
    printf("Podaj n: ");
    scanf_s("%d", &n);

    if (n <= 0)
        printf("n musi byc dodatnie!\n");


    int rozk³ad[100];
    printf("Przypadek a):\n");
    znajdzRozklady(n, 1, rozk³ad, 0, 0);
    printf("\nPrzypadek b):\n");
    znajdzRozklady(n, 1, rozk³ad, 0, 1);

}
void zad15(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    printf("Przypadek a)\n");
    for (int a = 1; pow(a, m) < n; a++) {
        for (int b = 1; pow(a, m) + pow(b, m) <= n; b++) {
            if (pow(a, m) + pow(b, m) == n) {
                printf("%d^%d + %d^%d = %d\n", a, m, b, m, n);
            }
        }
    }

    printf("\nPrzypadek b)\n");
    for (int a = 1; pow(a, m) < n; a++) {
        for (int b = a; pow(a, m) + pow(b, m) <= n; b++) {
            if (pow(a, m) + pow(b, m) == n) {
                printf("%d^%d + %d^%d = %d\n", a, m, b, m, n);
            }
        }
    }

}
void zad16(){
    int n, m;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    printf("Podaj m: ");
    scanf_s("%d", &m);

    if (n <= 0)
        printf("n musi byc dodatnie!\n");

    int rozk³ad[100];
    printf("Przypadek A:\n");
    znajdzRozklady(n, 1, rozk³ad, 0, 0, m);
    printf("\nPrzypadek B:\n");
    znajdzRozklady(n, 1, rozk³ad, 0, 1, m);
}
void zad17(){
    static int count = 0;
    count++;
    printf("Funkcja zostala wywolana %d razy.", count);
}
void zad18(){
    int n;
    printf("Ile wartosci wygenerowac?\n");
    scanf_s("%d", &n);
    srand(time(NULL));

    double x = (double)rand() / RAND_MAX;

    printf("Wygenerowane wartosci:\n");
    printf("x0 = %.6lf\n", x);

    for (int i = 1; i < n; i++) {
        x = 1 - x * x;
        printf("x%d = %.6lf\n", i, x);
    }

}
void zad19(){
    static int sum = 0;
    int value = readNumber();
    sum += value;
    printf("Aktualna suma wynosi: %d\n", sum);
}
void zad20(){
    int n = readNumber();
    printf("%d! = %d", n, factRec(n));
}
void zad21(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, an1(n));
}
void zad22(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, an2(n));
}
void zad23(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, Fib(n));
}
void zad24(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, an3(n));
}
void zad25(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, an4(n));
}
void zad26(){
    int n = readNumber();
    printf("Wartosc %d elementu ciagu wynosi: %d", n, an5(n));
}
void zad27(){
    int n = readNumber();
    int m = readNumber();
    printf("Wartosc F(%d, %d) wynosi: %d", n, m, F1(n, m));
}
void zad28(){
    int n = readNumber();
    int m = readNumber();
    printf("Wartosc F(%d, %d) wynosi: %d", n, m, F2(n, m));
}
void zad29(){
    int n = readNumber();
    int m = readNumber();
    printf("Wartosc NWD(%d, %d) wynosi: %d", n, m, NWD(n, m));
}

int main()
{
    //zad1();
    //zad2();
    //zad3();
    //zad4();
    //zad5();
    //zad6();
    //zad7();
    //zad8();
    //zad9();
    //zad10();
    //zad11();
    //zad12();
    //zad13();
    //zad14();
    //zad15();
    //zad16();
    //zad17();
    //zad18();
    //zad19();
    //zad20();
    //zad21();
    //zad22();
    //zad23();
    //zad24();
    //zad25();
    //zad26();
    //zad27();
    //zad28();
    //zad29();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
