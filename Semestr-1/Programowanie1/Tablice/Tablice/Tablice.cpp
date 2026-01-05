#include <iostream>
// Funkcje ogolne
void printArray(int n, int* tab) {
    for (int i = 0; i < n; i++)
        printf("%d, ", tab[i]);
    printf("\n");
}
void printArrayD(int n, double* tab) {
    for (int i = 0; i < n; i++)
        printf("%.1f, ", tab[i]);
    printf("\n");
}
float avg(int n, int* tab) {
    float av = 0;
    for (int i = 0; i < n; i++)
        av += tab[i];
    av /= n;
    return av;
}
int suma(int n, int* tab) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += tab[i];

    return sum;
}
int sumaKw(int n, int* tab) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += tab[i] * tab[i];

    return sum;
}

// Funkcje zdan
void zad1(int n, int *tab){
    for (int i = 0; i < n; i++)
        tab[i] = 0;
    printArray(n, tab);
    for (int i = 0; i < n; i++)
        tab[i] = i;
    printArray(n, tab);
    for (int i = 0; i < n; i++)
        tab[i] *= 2;
    printArray(n, tab);
    for (int i = 0; i < n; i++)
        if (tab[i] == 0)
            tab[i] = -tab[i];
    printArray(n, tab);
}
void zad2(int n, int *tab){
    printf("Srednia: %.1f\n", avg(n, tab));
    printf("Suma: %d\n", suma(n, tab));
    printf("Suma kwadratow: %d\n", sumaKw(n, tab));
}
void zad3(int n, int *tab){
    printf("Srednia: %.2f", avg(n, tab));
}
void zad4a(int n, int* tab1, int* tab2) {
    printArray(n, tab2);
    for (int i = 0; i < n; i++)
        tab2[i] = tab1[i];
    printArray(n, tab2);
}
void zad4b(int n, int* tab1, int* tab2) {
    printArray(n, tab2);
    for(int i = 0; i < n; i++)
        tab2[i] = tab1[n - 1 - i];
    printArray(n, tab2);
}
void zad5(int n, int* tab1, int* tab2, int* tab3){
    printArray(n, tab1);
    printArray(n, tab2);
    printArray(n, tab3);
    for (int i = 0; i < n; i++)
        tab3[i] = tab1[i] + tab2[i];
    printArray(n, tab3);
    for (int i = 0; i < n; i++)
        tab3[i] = (tab1[i] > tab2[i]) ? tab1[i] : tab2[i];
    printArray(n, tab3);
    for (int i = 0; i < n; i++) {
        int temp = tab1[i];
        tab1[i] = tab3[i];
        tab3[i] = tab2[i];
        tab2[i] = temp;
    }
    printArray(n, tab1);
    printArray(n, tab2);
    printArray(n, tab3);
}
void zad6(int n, int* tab1, int* tab2, double* tab3){
    for (int i = 0; i < n; i++)
        tab3[i] = tab1[i];
    for (int i = 0; i < n; i++)
        tab3[n + i] = tab2[i];
    printArrayD(20, tab3);

    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == 0)
            tab3[i] = tab2[i / 2];
        else
            tab3[i] = tab1[i / 2];
    }
    printArrayD(20, tab3);
}
void zad7(int n, int* tab1, int* tab2, int* tab3){
    int maxVal = tab1[0];
    int minVal = tab1[0];

    for (int i = 0; i < n; i++) {
        if (tab1[i] > maxVal) maxVal = tab1[i];
        if (tab1[i] < minVal) minVal = tab1[i];
        if (tab2[i] > maxVal) maxVal = tab2[i];
        if (tab2[i] < minVal) minVal = tab2[i];
        if (tab3[i] > maxVal) maxVal = tab3[i];
        if (tab3[i] < minVal) minVal = tab3[i];
    }

    printf("Max: %d\n", maxVal);
    printf("Min: %d\n", minVal);

}
void zad8(int n, int* tab){

    int minVal = tab[0], maxVal = tab[0], minIndex = 0, maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (tab[i] < minVal) minVal = tab[i]; minIndex = i;
        if (tab[i] > maxVal) maxVal = tab[i]; maxIndex = i;
    }

    printf("Min: %d index %d\n", minVal, minIndex);
    printf("Max: %d index %d\n", maxVal, maxIndex);

    int temp = tab[minIndex];
    tab[minIndex] = tab[maxIndex];
    tab[maxIndex] = temp;
    printf("%d\n", tab[maxIndex]);

    for (int i = 0; i < n; i++)
        if (tab[i] < 0) tab[i] = -tab[i];

}
void zad9(int n, int* tab1, int* tab2){
    int scalar = 0;
    for (int i = 0; i < n; i++) {
        scalar += tab1[i] * tab2[i];
    }
    printf("%d", scalar);
}

int main()
{
    int tab[10] = { 4, 6, 7, 3, 8, 2, 6, 4, 7, 5 };
    int tab2[10] = { 3, 47, 17, 13, 3, 11, 9, 2, 3, 15 };
    int tab3[10] = { 6, 8, 64, 35, 75, 34, 56, 67, 86, 45 };
    double tab4[20];
    //printArray(10, tab);

    //zad1(10, tab);
    //zad2(10, tab2);
    //zad3(10, tab);
    //zad4a(10, tab, tab2);
    //zad4b(10, tab, tab2);
    //zad5(10, tab, tab2, tab3);
    //zad6(10, tab, tab2, tab4);
    //zad7(10, tab, tab2, tab3);
    //zad8(10, tab);
    //zad9(10, tab, tab2);


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

