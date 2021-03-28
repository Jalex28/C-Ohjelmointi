/*Tekijä: Joona Pellinen
OP NRO: 0612488*/

#include <stdio.h>

int lasku (int luku, int potenssi);

int main(void) {
    int luku;
    int potenssi;
    int tulos;

    printf("Ohjelma laskee luvun potenssiin.\n");
    printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
    scanf("%d", &luku);
    getchar();
    printf("Anna potenssi, jonka haluat laskea: ");
    scanf("%d", &potenssi);
    getchar();
    tulos = lasku(luku, potenssi);
    printf("%d ^ %d = %d.\n",luku,potenssi,tulos);
    return 0;
}

int lasku (int luku, int potenssi) {
    int tulos = 1;
    int i = 1;
    while(i <= potenssi) {
        tulos *= luku;
        i++;
    }

    return tulos;
}