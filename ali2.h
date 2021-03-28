/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Joona Pellinen
 * Opiskelijanumero: 0612488
 * Päivämäärä: 28.3.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Altti Väätäinen
 */
/*******************************************************************/
#ifndef ali2
#define ali2
#include <time.h>
#include "ali1.h"
#define LEN 80

LISTA *kasittely_ohjelma(char rivibufferi[]);
int analysoi_ohjelma(LISTA *pAlku, ARRAY *pTbl);
void vapauta(LISTA *pL);
void tiedostonimi_ohjelma(char *tiedostonimi);

#endif
/*******************************************************************/
/* eof */

