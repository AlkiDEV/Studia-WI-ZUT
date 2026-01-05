// ####################################################################
// #                                                                  #
// #                  Mnozenie macierzy - Zadanie 1                   #
// #                     Autor: Michał Buś 60037                      #
// #                         Programowanie 1                          #
// #                                                                  #
// ####################################################################

#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

FILE *openFile(const char *path, const char *mode)
{
    FILE *plik;

    if (fopen_s(&plik, path, mode) != 0)
    {
        printf("Nie mozna otworzyc pliku %s!\n", path);
        return NULL;
    }

    return plik;
}

int **readMatrix(FILE *file, unsigned int n, unsigned int m)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (unsigned int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(m * sizeof(int));
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            fscanf(file, "%d", &matrix[i][j]);

    return matrix;
}

void generateMatrix(unsigned int n, unsigned int m, const char *path)
{
    FILE *plik = openFile(path, "w");
    fprintf_s(plik, "%d %d\n", n, m);

    int **mac;
    mac = (int **)malloc(n * sizeof(int *)); // wiersze
    for (int i = 0; i < n; i++)
        mac[i] = (int *)malloc(m * sizeof(int)); // kolumny

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mac[i][j] = rand() % 101;
            fprintf_s(plik, "%d ", mac[i][j]);
        }
        fprintf_s(plik, "\n");
    }

    for (int i = 0; i < n; i++)
        free(mac[i]);
    free(mac);

    fclose(plik);
}

void multiply(const char *file1_path, const char *file2_path, const char *result_path)
{
    FILE *file1 = openFile(file1_path, "r");
    FILE *file2 = openFile(file2_path, "r");
    FILE *result = openFile(result_path, "w");

    // sprawdzenie wymiarow macierzy
    unsigned int n1, m1, n2, m2;
    fscanf(file1, "%u %u", &n1, &m1);
    fscanf(file2, "%u %u", &n2, &m2);

    if (n1 != m2)
    {
        printf("Niepoprawne wymiary macierzy do wykonania mnozenia.\n");
        fclose(file1);
        fclose(file2);
        fclose(result);
        return;
    }

    // wczytanie macierzy z plikow
    int **mat1 = readMatrix(file1, n1, m1);
    int **mat2 = readMatrix(file2, n2, m2);
    int **result_mat = (int **)malloc(n1 * sizeof(int *));
    for (unsigned int i = 0; i < n1; i++)
        result_mat[i] = (int *)malloc(m2 * sizeof(int));

    // mnozenie
    for (unsigned int i = 0; i < n1; i++)
        for (unsigned int j = 0; j < m2; j++)
        {
            result_mat[i][j] = 0;
            for (unsigned int k = 0; k < m1; k++)
                result_mat[i][j] += mat1[i][k] * mat2[k][j];
        }

    // zapis wyniku do pliku
    fprintf_s(result, "%u %u\n", n1, m2);
    for (unsigned int i = 0; i < n1; i++)
    {
        for (unsigned int j = 0; j < m2; j++)
            fprintf_s(result, "%d ", result_mat[i][j]);
        fprintf_s(result, "\n");
    }

    for(unsigned int i = 0; i < n1; i++)
        free(mat1[i]);
    free(mat1);
    for(unsigned int i = 0; i < n2; i++)
        free(mat2[i]);
    free(mat2);
    for(unsigned int i = 0; i < n1; i++)
        free(result_mat[i]);
    free(result_mat);
    fclose(file1);
    fclose(file2);
    fclose(result);

}

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("Zostaly uzyte domyslne pliki i rozmiary.\nAby wygenerowac swoj rozmiar macierzy uruchom program z parametrami:\n");
        printf("matrix.exe <n1> <m1> <n2> <m2>\n");
        generateMatrix(3, 2, "files/matrix1.txt");
        generateMatrix(2, 3, "files/matrix2.txt");
        multiply("files/matrix1.txt", "files/matrix2.txt", "files/result.txt");
    }else if(argc == 5){
        generateMatrix(atoi(argv[1]), atoi(argv[2]), "files/matrix1.txt");
        generateMatrix(atoi(argv[3]), atoi(argv[4]), "files/matrix2.txt");
        multiply("files/matrix1.txt", "files/matrix2.txt", "files/result.txt");
    }else{
        printf("Niepoprawna liczba argumentow!\n");
    }

    return 0;
}
