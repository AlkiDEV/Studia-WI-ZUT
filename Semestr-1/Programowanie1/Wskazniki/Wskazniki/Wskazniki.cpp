#include <iostream>

void wypiszTablice(int* tab, int n) {
    for (int i = 0; i < n; i++)
        printf("%d, ", tab[i]);
    printf("\n");
}
void wypiszTab2D(int* tab, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("%d ", tab[i * m + j]);
    printf("\n");
}

int zad1(int* a, int* b) {
    return *a < *b ? *a : *b;
}
int* zad2(int* a, int* b){
    return *a < *b ? a : b;
}
void zad3(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* zad4(){
    int a;
    return &a;
}
double* zad5(){
    double a;
    return &a;
}
int* zad6(unsigned int n){
    int* num = (int*)malloc(n * sizeof(int));
    return num;
}
double* zad7(unsigned int n){
    double* num = (double*)malloc(n * sizeof(int));
    return num;
}
int** zad8(unsigned int n) {
    int** num = (int**)malloc(n * sizeof(int*));
    return num;
}
void zad9(int* tab1, int* tab2, int n){
    wypiszTablice(tab1, n);
    wypiszTablice(tab2, n);
    for (int i = 0; i < n; ++i) {
        int tmp = tab1[i];
        tab1[i] = tab2[i];
        tab2[i] = tmp;
    }
    wypiszTablice(tab1, n);
    wypiszTablice(tab2, n);
}
void zad10(int* tab1, int* tab2, int n1, int n2) {
    wypiszTablice(tab1, n1);
    wypiszTablice(tab2, n2);

    int m = (n1 < n2) ? n1 : n2;
    for (int i = 0; i < m; ++i) {
        int tmp = tab1[i];
        tab1[i] = tab2[i];
        tab2[i] = tmp;
    }
    wypiszTablice(tab1, n1);
    wypiszTablice(tab2, n2);
}
int* zad11(int n, int m){
    int* tab = (int*)malloc(n * m * sizeof(int));

    return tab;
}
void zad12(int* tab, int n, int m){
    free(tab);
    tab = NULL;
}
int* zad13(int n, int m, int o){
    int* tab = (int*)malloc(n * m * o * sizeof(int));

    return tab;
}
void zad14(int* tab, int n, int m, int o){
    free(tab);
    tab = NULL;
}
int zad15(int* tab2D, int n, int m){
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += tab2D[i * m + j];

    return sum;
}
int zad16(int* tab2D, int n, int m){
    int index = 0;
    double avg = -DBL_MAX;

    for (int i = 0; i < n; i++) {
        long sum = 0;
        for (int j = 0; j < m; ++j)
            sum += tab2D[i * m + j];
        double avg2 = (double(sum / (double)m));

        if (avg2 > avg) {
            avg = avg2;
            index = i;
        }
    }

    return index;
}

int main()
{
    int a = 7, b = 11;
    int tab1[5] = { 1, 9, 5, 3, 8 };
    int tab2[5] = { 2, 1, 3, 7, 0 };
    int tab3[10] = { 0, 6, 9, 2, 1, 3, 7, 4, 2, 0 };
    //printf("%d\n", zad1(&a, &b));
    //printf("%d\n", zad2(&a, &b));
    //zad3(&a, &b);
    //zad4();
    //zad5();
    //printf("%d", zad6(a));
    //printf("%d", zad7(a));
    //printf("%d", zad8(a));
    //zad9(tab1, tab2, 5);
    //zad10(tab1, tab3, 5, 10);
    //zad11(5, 5);
    //zad12(zad11(5, 5), 5, 5);
    //zad13(5, 5, 5);
    //zad14(zad13(5, 5, 5), 5, 5, 5);
    //zad15(zad11(5, 5), 5, 5);
    //zad16(zad11(5, 5), 5, 5);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
