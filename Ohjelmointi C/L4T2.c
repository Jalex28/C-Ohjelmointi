#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define RIVI 2
#define SARAKE 2

int tulosta(int matriisi[RIVI][SARAKE], char name [50]) {
    int i, j;

    printf("\n%s:\n", name);
    for (i = 0; i < RIVI; i++) {
        for (j = 0; j < SARAKE; j++)
            printf("%4d ", matriisi[i][j]);
        printf("\n");
    }
    return 0;
}

int main() {
    int i, j;
    int matriisi1[RIVI][SARAKE];
    int matriisi2[RIVI][SARAKE];
    char nimi1[50] = "Matriisi 1";
    char nimi2[50] = "Matriisi 2";
    char nimisumma[50] = "Summamatriisi";

    printf("Anna arvot yhteenlaskettaville matriiseille:\n");

    printf("Matriisin 1 alkiot:\n");
    for (i = 0; i < RIVI; i++)
        for (j = 0; j < SARAKE; j++){
            printf("Rivi %d alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi1[i][j]);
        }

    tulosta(matriisi1, nimi1);

    printf("\nMatriisin 2 alkiot:\n");
    for (i = 0; i < RIVI; ++i)
        for (j = 0; j < SARAKE; ++j){
            printf("Rivi %d alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi2[i][j]);
        }

    tulosta(matriisi2, nimi2);
    printf("\n");
    int summamatriisi[RIVI][SARAKE];
    for (i = 0; i < RIVI; ++i)
        for (j = 0; j < SARAKE; ++j){
            summamatriisi[i][j] = matriisi1[i][j] + matriisi2[i][j];
        }

    tulosta(summamatriisi, nimisumma);
    printf("\n");

    return 0;
}