#include <string.h>
#include <stdio.h>
#define KOKO 200

int main(void) {
    int valinta;
    int true = 1;
    char c;
    char merkkijono[KOKO] = "\0";

    while(true) {
        printf("\nValikko\n1) Lisää uusi merkki\n2) Tyhjennä merkkijono\n3) Tulosta merkkijono\n0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &valinta);
        getchar();

        if (valinta >= 0 && valinta <= 3){
            if (strlen(merkkijono) == 200) {
                printf("\nMerkkijonoon ei mahdu enempää merkkejä.\n");
                continue;
            } else if (valinta == 3 & merkkijono[0] == 0) {
                printf("\nMerkkijono on tyhjä.\n");
                continue;
            } else {
                switch (valinta) {
                    case 1:
                        printf("\nAnna jokin merkki: ");
                        scanf("%c", &c);
                        getchar();
                        strncat(merkkijono, &c, 1);
                        break;
                    case 2:
                        merkkijono[0] = 0;
                        printf("\nMerkkijono on tyhjennetty.\n");
                        break;
                    case 3:
                        printf("\nMerkkijono: %s\n", merkkijono);
                        break;
                    case 0:
                        printf("\nOhjelman lopetus.\n");
                        true = 0;
                        return 0;    
                }
            }
        } else {
            printf("\nTuntematon valinta.\n");
            continue;
        }
    }
}