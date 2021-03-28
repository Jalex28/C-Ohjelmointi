/* un 20180213 L06Viope.c L06-T1 */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DYNAAMINEN MUISTINVARAUS ja LINKITETTY LISTA
struct Node {
	int iLuku;
	struct Node *pNext;
};
typedef struct Node Solmu;

int main(void) {
	Solmu *pAlku = NULL, *pLoppu = NULL, *ptr;
	int nLuku;
	
	printf("Anna listan luvut.\n");
    printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
    scanf("%d", &nLuku);
	while (nLuku != 0) {
		// muistin varaus
		if ((ptr = (Solmu*)malloc(sizeof(Solmu))) == NULL ){
			perror("Muistin varaus epäonnistui");
			exit(1);
		}
        
		// uuden alkion arvojen määrittäminen
		ptr->iLuku = nLuku;
		ptr->pNext = NULL;

		// uuden alkion lisääminen listaan viimeiseksi alkioksi
		if (pAlku == NULL) { // lista on tyhjä -> myös eka alkio
			pAlku = ptr;
			pLoppu = ptr;
		} else {             // lista ei tyhjä -> viimeinen alkio
			pLoppu->pNext = ptr;
			pLoppu = ptr;
		}
        printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
        scanf("%d", &nLuku);
    }
	
	// listan läpikäynti
	printf("Listassa on seuraavat luvut: ");
	ptr = pAlku;
	while (ptr != NULL) {
		printf("%d ", ptr->iLuku);
		ptr = ptr->pNext;
	}
	printf("\n");

	// muistin vapauttaminen	
	ptr = pAlku;
	while (ptr != NULL) {
		pAlku = ptr->pNext;
		free(ptr);
		ptr = pAlku;
	}

	printf("Kiitos ohjelman käytöstä.\n"); 
	return 0;
}
/*****************************************************************************/
/* eof */
