// Petle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void zad1() {
	int n, m;
	printf("Podaj n i m: \n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int cn = n;
	while (n < m) {
		printf("%d\n", n);
		n *= cn;
	}

}

void zad2() {
	int n, m;
	printf("Podaj n i m: \n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int cn = n;

	for (int i = 1; i <= m; i++) {
		printf("%d\n", n);
		n *= cn;
	}


}

void zad3() {
	int n, m, k;
	printf("Podaj n, m i k: \n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	scanf_s("%d", &k);
	int cn = n;
	while (n > m && n < k) {
		printf("%d\n", n);
		n *= cn;
	}

}

//zad4 silnia
void fact() {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}
	printf("Silnia: %d", factorial);

}

void zad5() {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += pow(i, 2);
	}
	printf("%d", sum);

}

void zad6() {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int iloczyn = 1;
	if (n > 2) {
		if (n % 2 == 0) {
			for (int i = 2; i <= n; i *= 2)
				iloczyn *= i;
		}
		else {
			for (int i = 2; i < n; i *= 2)
				iloczyn *= i;
		}
		printf("Iloczyn: %d", iloczyn);
	}
	else
		printf("Podaj liczbe wieksza od 2!\n");

}

void zad7() {
	int n, m;
	printf("Podaj n < m: \n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int iloczyn = 1;
	for (int i = n; i <= m; i++)
		iloczyn *= i;
	printf("Iloczyn: %d", iloczyn);

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

void zad8() {
	int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);
	printf("%d", Fib(n));

}

void zad9() {
	int n, m;
	printf("Podaj n i m: \n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	while (m > 0) {
		int tmp = m;
		m = n % m;
		n = tmp;
	}
	printf("%d", n);

}

void zad10() {
	unsigned int n;
	printf("Podaj n: ");
	scanf_s("%d", &n);

	unsigned int square_root = 0;

	while ((square_root + 1) * (square_root + 1) <= n)
		square_root++;

	printf("Pierwiastek zaokraglony w dol: %u\n", square_root);
}

void zad11() {
	int a, b, c, d;
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj b: ");
	scanf_s("%d", &b);
	printf("Podaj c: ");
	scanf_s("%d", &c);
	printf("Podaj d: ");
	scanf_s("%d", &d);

	// Najmniejszy x dla |a| * x^2 + b * x + c <= d
	int modul_a = (a < 0) ? -a : a;
	int x = 0;
	while (modul_a * x * x + b * x + c <= d)
		x++;
	printf("Najmniejszy x: %d\n", x);

	// Najwiêkszy x dla 5 * x^2 + a * x + b < c
	int x_max = 0;
	while (5 * x_max * x_max + a * x_max + b < c)
		x_max++;
	x_max--;
	printf("Najwiekszy x: %d\n", x_max);

	// Najwiêkszy x dla 5 * x^2 + a * x + b <+ c
	int max_x = 0;
	while (5 * max_x * max_x + a * max_x + b < c)
		max_x++;
	max_x--;
	printf("Najwiekszy x(<=): %d\n", max_x);


}

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void zad12() {
	int n;
	printf("Podaj dodatnie n: ");
	scanf_s("%d", &n);

	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			sum += i;
		}
	}
	printf("Suma liczb pierwszych mniejszych od n: %d\n", sum);
}

void zad13() {
	int n;
	printf("Podaj dodatnie n: ");
	scanf_s("%d", &n);

	long long sum = 0;
	long long factorial = 1;

	for (int i = 0; i <= n; i++) {
		if (i > 0)factorial *= i;
		sum += factorial;
	}

	printf("Suma silni od 0! do n!: %lld\n", sum);
}

void zad14() {
	int n;
	printf("Podaj dodatnie n: ");
	scanf_s("%d", &n);

	printf("Trojki pitagorejskie mniejsze od n: \n");
	for (int a = 1; a < n; a++)
		for (int b = a; b < n; b++)
			for (int c = b; c < n; c++)
				if (a * a + b * b == c * c)
					printf("(%d, %d, %d)\n", a, b, c);

}

int main()
{
	//zad1();
	//zad2();
	//zad3();
	//fact();
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


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


