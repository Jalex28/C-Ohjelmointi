#include <string.h>
#include <stdio.h>

#define KOKO 50
typedef struct Kirja {
    char nimi[KOKO];
    int vuosi;
    int hyllypaikka;

};

int main (void) {
    struct Kirja kirja;

    printf("Anna kirjan nimi: ");
    fgets(kirja.nimi, 50, stdin);
    kirja.nimi[strlen(kirja.nimi)-1] = '\0';
    printf("Anna kirjan painovuosi: ");
    scanf("%d", &kirja.vuosi);
    getchar();
    printf("Anna kirjan hyllypaikka: ");
    scanf("%d", &kirja.hyllypaikka);
    getchar();
    printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n",kirja.nimi, kirja.vuosi, kirja.hyllypaikka);
    return 0;
}