//*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Joona Pellinen
 * Opiskelijanumero: 0612488
 * Päivämäärä: 28.3.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Altti Väätäinen
 */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
#define LEN 80

int valikko(void) {
    int valinta;
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Tulosta tulokset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);
    getchar();
    return valinta;
}

int main(void) {
    char tiedostonimi[LEN];
    LISTA *pAlku = NULL;
    ARRAY pTbl[70];
    int valinta = -1, luku = 0;

    while (valinta != 0){
        valinta = valikko();
        if (valinta == 1){
            tiedostonimi_ohjelma(tiedostonimi);
            pAlku = lue_ohjelma(tiedostonimi);
            continue;
        }
        if (valinta == 2){
            luku = analysoi_ohjelma(pAlku, pTbl);
            continue;
        }
        if (valinta == 3){             
            tulosta_tiedot(pTbl, luku);
            continue;
        }
        if (valinta == 0){
            vapauta(pAlku);
            printf("Kiitos ohjelman käytöstä.\n\n");
            break;
        }
        else{
            printf("Tuntematon valinta, yritä uudestaan.\n\n");
            continue;
        }
    }
}

/*******************************************************************/
/* eof */