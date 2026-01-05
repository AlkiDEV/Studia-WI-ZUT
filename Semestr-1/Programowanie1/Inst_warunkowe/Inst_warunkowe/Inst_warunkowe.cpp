// Inst_warunkowe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //Zad 1
	int n = 0;
	scanf_s("%d", &n);
	printf("%d\n", (n > 0 ? n : n *= -1));
	//Zad 2
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("%d\n", (a > b ? a : b));
	//Zad 3
	int tab[3];
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &tab[i]);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (tab[j] > tab[j + 1]) {
				// zamiana miejscami
				int temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
	printf("%d\n", tab[2]);
	//Zad 4
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	a = (a >= 0 ? a : a *= -1);
	b = (b >= 0 ? b : b *= -1);
	printf("%d\n", (a > b ? a : b));
	//Zad 5
	float h, p;
	scanf_s("%f", &p);
	scanf_s("%f", &h);
	float pole = (p * h) / 2;
	printf("%.2f\n", pole);
	//Zad 6
	/*double a1, b1, c1, a2, b2, c2;
	printf("Podaj wspó³czynniki a1 b1 c1 a2 b2 c2:\n");
	scanf_s("%lf %lf %lf %lf %lf %lf", &a1, &b1, &c1, &a2, &b2, &c2);

	double D = a1 * b2 - a2 * b1;
	double Dx = c1 * b2 - c2 * b1;
	double Dy = a1 * c2 - a2 * c1;

	if (D != 0) {
		double x = Dx / D;
		double y = Dy / D;
		printf("Rozwi¹zanie: x = %.4lf, y = %.4lf\n", x, y);
	}
	else {
		if (Dx == 0 && Dy == 0) {
			printf("Uk³ad ma nieskoñczenie wiele rozwi¹zañ.\n");
		}
		else {
			printf("Uk³ad jest sprzeczny (brak rozwi¹zañ).\n");
		}
	}*/
	//Zad 7

	double aa, bb, cc;
	printf("Podaj wspolczynniki a, b, c:\n");
	scanf_s("%lf %lf %lf", &aa, &bb, &cc);

	if (aa == 0) {
		if (bb == 0) {
			printf("Brak rozwiazan (rownanie sprzeczne).\n");
		}
		else {
			double xx = -cc / bb;
			printf("Rownanie liniowe, rozwiazanie: x = %.4lf\n", xx);
		}
	}
	else {
		double delta = bb * bb - 4 * aa * cc;
		if (delta > 0) {
			double x1 = (-bb - sqrt(delta)) / (2 * aa);
			double x2 = (-bb + sqrt(delta)) / (2 * aa);
			printf("Dwa rozwiazania: x1 = %.4lf, x2 = %.4lf\n", x1, x2);
		}
		else if (delta == 0) {
			double xx = -bb / (2 * aa);
			printf("Jedno rozwiazanie: x = %.4lf\n", xx);
		}
		else {
			printf("Brak rozwiazan rzeczywistych.\n");
		}
	}

	//Zad 8
	printf("\nPodaj jaka figura:\n1. Kwadrat\n2. Prostokat\n3. Trojkat\n");
	int figura = 0;
	scanf_s("%d", &figura);
	switch (figura)
	{
	case 1:
		int kw;
		printf("Wybrales kwadrat. Podaj wymiary boku a: ");
		scanf_s("%d", &kw);
		printf("Pole tego kwadratu wynosi: %d\n", (kw*kw));
		break;
	case 2:
		int bokA, bokB;
		printf("Wybrales prostokat.\nPodaj wymiary boku a: ");
		scanf_s("%d", &bokA);
		printf("Podaj wymiary boku b: ");
		scanf_s("%d", &bokB);
		printf("Pole tego prostokata wynosi: %d\n", (bokA * bokB));
		break;
	case 3:
		int podst, wys;
		printf("Wybrales trojkat.\nPodaj wymiary podstawy: ");
		scanf_s("%d", &podst);
		printf("Podaj wysokosc: ");
		scanf_s("%d", &wys);
		printf("Pole tego trojkata wynosi: %d\n", ((podst * wys) / 2));
		break;
	default:
		printf("Nieprawidlowy wybor!\n");
		break;
	}
	//Zak 9

	double aa1, bb1, result;
	char op;

	printf("Liczba a: ");
	scanf_s("%lf", &aa1);

	printf("Liczba b: ");
	scanf_s("%lf", &bb1);

	printf("Wybierz rodzaj dzialania (+, -, *, /): ");
	scanf_s(" %c", &op);  // spacja przed %c usuwa biale znaki

	switch (op) {
	case '+':
		result = aa1 + bb1;
		printf("Wynik: %.4lf\n", result);
		break;
	case '-':
		result = aa1 - bb1;
		printf("Wynik: %.4lf\n", result);
		break;

	case '*':
		result = aa1 * bb1;
		printf("Wynik: %.4lf\n", result);
		break;
	case '/':
		if (bb1 != 0) {
			result = aa1 / bb1;
			printf("Wynik: %.4lf\n", result);
		}
		else {
			printf("Error: nie dziel przez 0!\n");
		}
		break;
	default:
		printf("Zla operacja!\n");
	}



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
