#include <stdio.h>

int main(void) {
    float liukuluku;
    int valinta;
    float pii = 3.141;

    printf("Anna liukuluku: ");
    scanf("%f", &liukuluku);

    printf("\nValikko\n1) Kerro piin arvo luvulla %.3f.\n2) Jaa piin arvo luvulla %.3f.\n", liukuluku, liukuluku);
    printf("Valitse: ");
    scanf("%d", &valinta);

    switch (valinta) {
        case 1:
            printf("\nPii * %.3f = %.3f.\n", liukuluku, (pii*liukuluku));
            break;
        case 2:
            printf("\nPii / %.3f = %.3f.\n", liukuluku, (pii/liukuluku));
            break;
        default:
            printf("\nTuntematon valinta.\n");
            break;
    }
    return 0;
}