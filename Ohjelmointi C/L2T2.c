#include <stdio.h>

int main(void) {
    int luku;
    int alaraja = 10;
    int ylaraja = 200;
    int i = 0;
    int summa = 0;

    printf("Anna jokin luku väliltä 10 - 200: ");
    scanf("%d", &luku);

    if (luku < alaraja || luku > ylaraja) {
        printf("Antamasi luku ei ole annetulla välillä.\n");
        return 0;
    }
    for (i = 0; i <= luku; i++) {
        summa += i;
    }
    printf("Lukujen 0 - %d summa on %d.\n", luku, summa);
    return 0;
}