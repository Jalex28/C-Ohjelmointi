#include <stdio.h>

int main(void) {
    int luku1;
    int luku2;
    int valinta;

    printf("Anna kaksi kokonaislukua: ");
    scanf("%d %d", &luku1, &luku2);

    printf("\nValikko\n1) Summaa luvut yhteen.\n2) Kerro luvut keskenään.\n");
    printf("Valitse: ");
    scanf("%d", &valinta);

    switch (valinta) {
        case 1:
            printf("\nLuvut laskettiin yhteen. Tulos = %d.\n", (luku1+luku2));
            break;
        case 2:
            printf("\nLuvut kerrottiin keskenään. Tulos = %d.\n", (luku1*luku2));
            break;
        default:
            printf("\nTuntematon valinta.\n");
            break;
    }
    return 0;
}