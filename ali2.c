/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Joona Pellinen
 * Opiskelijanumero: 0612488
 * Päivämäärä: 28.3.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: Altti Väätäinen
 */
/*******************************************************************/
#include "ali1.h"
#include "ali2.h"
#include "paaohjelma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


LISTA *kasittely_ohjelma(char rivibufferi[]) {
	char *p1, *p2, *p3, *p4, *p5;
	int p6;
	int atoilk, lkm = 0;
	LISTA *pUusi;

	if ((pUusi = (LISTA*)malloc(sizeof(LISTA))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			exit(0);
	}

	lkm += 1;
	p1 = strtok(rivibufferi, ";");
	strcpy(pUusi->Palautusaika, p1);
	p2 = strtok(NULL, ";");
	strcpy(pUusi->TehtavaNimi, p2);
	p3 = strtok(NULL, ";");
	atoilk = atoi(p3);
	pUusi->TehtavaID = atoilk;
	p4 = strtok(NULL, "\n");
	atoilk = atoi(p4);
	pUusi->KayttajaID = atoilk;
	p5 = strtok(p1, "/");
	p6 = atoi(p5);
	pUusi->p8.tm_mday = p6;
	p5 = strtok(NULL, "/");
	p6 = atoi(p5);
	pUusi->p8.tm_mon = p6-1;
	p5 = strtok(NULL, ",");
	p6 = atoi(p5);
	pUusi->p8.tm_year = p6+100;
	p5 = strtok(NULL, ":");
	p6 = atoi(p5);
	pUusi->p8.tm_hour = p6;
	p5 = strtok(NULL, "");
	p6 = atoi(p5);
	pUusi->p8.tm_min = p6;

	return pUusi;
}

int analysoi_ohjelma(LISTA *pAlku, ARRAY *pTbl){
	LISTA *ptr;
	int i, lkm = 0, teht = 0;
	if(pAlku == NULL){
		printf("Ei analysoitavaa, lue ensin palautustiedosto.\n\n");
		return 0;
	}
	for(i = 0; i<60; i++){
		strcpy(pTbl[i].TehtNimi,"Tyhjä");
		pTbl[i].palautusluku=0;
	}
	ptr = pAlku;
	while(ptr != NULL){
		if(strcmp(pTbl[ptr->TehtavaID-1].TehtNimi, "Tyhjä") == 0){
			strcpy(pTbl[ptr->TehtavaID-1].TehtNimi,ptr->TehtavaNimi);
			teht++;
		}
		pTbl[ptr->TehtavaID-1].palautusluku++;
		lkm++;
		ptr = ptr->pSeuraava;
	}
	printf("Palautuksia oli yhteensä %d, %d eri tehtävässä, keskimäärin %d per tehtävä.\n\n",lkm,teht,lkm/teht);
	return 1;
}

void vapauta(LISTA *pL) {
	LISTA *ptr;
	while(ptr != NULL){
		ptr = pL->pSeuraava;
		free(pL);
		pL = ptr;
	}
}

void tiedostonimi_ohjelma(char *tiedostonimi) {
    printf("Anna tiedoston nimi: ");
    fgets(tiedostonimi, LEN, stdin);
	tiedostonimi[strlen(tiedostonimi)-1] = '\0';
}

/*******************************************************************/
/* eof */

