/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Joona Pellinen
 * Opiskelijanumero: 0612488
 * Päivämäärä: 28.3.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Altti Väätäinen
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ali1.h"
#include "ali2.h"
#include "paaohjelma.h"
#define LEN 80
 
LISTA *lue_ohjelma (char *tiedostonimi) {
    FILE *tiedosto;
	LISTA *pUusi, *ptr; 
	LISTA *pAlku = NULL;
	char rivibufferi[LEN];
	char pvm_alku[50], pvm_loppu[30];
	int lkm = 0;

	ptr = pAlku;
	while (ptr != NULL) {
		pAlku = ptr->pSeuraava;
		free(ptr);
		ptr = pAlku;
	}

	if((tiedosto = fopen(tiedostonimi, "r")) == NULL){
		perror("Tiedoston avaus epäonnistui");
		exit(0);
	}

	fgets(rivibufferi, LEN, tiedosto);

	while(fgets(rivibufferi, LEN, tiedosto) != NULL){
		lkm++;
		pUusi = kasittely_ohjelma(rivibufferi);
		if(pAlku == NULL){
			pAlku = pUusi;
			ptr = pAlku;
		} else {
			ptr->pSeuraava = pUusi;
			ptr = pUusi;
		}
	}

	strftime(pvm_alku, 50, "%d.%m.%Y", &pAlku->p8);
	strftime(pvm_loppu, 50, "%d.%m.%Y", &pUusi->p8);

	printf("Yhteensä %d palautusta %s - %s väliseltä ajalta.\n\n",lkm,pvm_alku,pvm_loppu);

	fclose(tiedosto);
	return pAlku;
}

void tulosta_tiedot(ARRAY *pTbl, int luku) {
	FILE *tiedosto;
	char tiedostonimi[50];
    char sel;
	int i;
	if(luku == 0){
		printf("Ei tulostettavaa, analysoi ensin palautustiedosto.\n\n");
		return;
	}
    
	printf("Tulosta tiedostoon (k/e): ");
	scanf("%c", &sel);
	getchar();
	if(sel == 'k'){
		tiedostonimi_ohjelma(tiedostonimi);
		tiedosto = fopen(tiedostonimi, "w");
		if(tiedosto == NULL){
			printf("Tiedostoon tallennus epäonnistui.\n");
			exit(0);
		}
		fprintf(tiedosto,"Tehtävä;Lkm\n");
		for(i = 0; i<60; i++){
			fprintf(tiedosto,"%s;%d\n",pTbl[i].TehtNimi,pTbl[i].palautusluku);
		}
		fclose(tiedosto);
		printf("\n");
	} else if(sel == 'e'){
		printf("Tehtävä;Lkm\n");
		for(i = 0; i<60; i++){
			printf("%s;%d\n",pTbl[i].TehtNimi,pTbl[i].palautusluku);
		}
		printf("\n");
	}
	return;
}
/*******************************************************************/
/* eof */

