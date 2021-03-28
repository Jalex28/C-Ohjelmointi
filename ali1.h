/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Joona Pellinen
 * Opiskelijanumero: 0612488
 * Päivämäärä: 28.3.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Altti Väätäinen
 */
/*******************************************************************/
#ifndef ali1
#define ali1
#include <time.h>

typedef struct pLista {
	char Palautusaika[80];
	char TehtavaNimi[80];
	int TehtavaID;
	int KayttajaID;
	struct tm p7;
	struct tm p8;
	struct pLista *pSeuraava;
}LISTA;


typedef struct array {
	char TehtNimi[15];
	int palautusluku;
	struct array *pSeuraava1;
}ARRAY;

LISTA *lue_ohjelma (char *tiedostonimi);
void tulosta_tiedot(ARRAY *pTbl, int luku);

#endif
/*******************************************************************/
/* eof */

