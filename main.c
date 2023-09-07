#include <stdio.h>

int assignTable(int guestCount) {
    if(0 < guestCount && guestCount <= 2) return 1;
    if(2 < guestCount && guestCount <= 4) return 2;
    if(4 < guestCount && guestCount <= 8) return 3;
    else return 0;
}

int main() {
    int guestCount;

    printf("Bonjour, combien êtes vous ?");
    scanf("%d", &guestCount);
    int tableNumber = assignTable(guestCount);
    if(tableNumber == 0) printf("Désoler vous êtes trop nombreux, je doit vous refuser.");
    else printf("Très bien veuiller prendre la table %d", tableNumber);

    return 0;
}
