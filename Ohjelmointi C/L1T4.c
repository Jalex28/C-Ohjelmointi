#include <stdio.h>
#include <string.h>

int main(void) {
    char c;
    char merkkijono[22];

    printf("Anna merkki: ");
    scanf("%c", &c);
    getchar();
    printf("Annoit merkin '%c'.\n", c);
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    fgets(merkkijono, 22, stdin);
/*scanf("%s", merkkijono);*/
    merkkijono[strlen(merkkijono)-1] = '\0';
    printf("Annoit merkkijonon '%s'.\n", merkkijono);
    return 0;
}