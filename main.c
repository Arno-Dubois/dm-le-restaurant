#include <stdio.h>

int assignTable(int guestCount) {
    if(0 < guestCount && guestCount <= 2) return 1;
    if(2 < guestCount && guestCount <= 4) return 2;
    if(4 < guestCount && guestCount <= 8) return 3;
    else return 0;
}

int menuPrice(char dish,int drink,int dessert) {
    int total = 0;
    
    switch (dish) {
        case 'c': total += 15;
        case 't': total += 8;
        case 'r': total += 23;
        default: return 0;
    }

    switch (drink) {
        case 's': total += 5;
        case 'e': total += 2;
        case 'l': total += 12;
        default: return 0;
    }
    printf("%d", total);
}

int main() {
    int guestCount;
    char dish, drink, dessert;

    printf("Bonjour, combien êtes vous ?");
    scanf("%d", &guestCount);
    int assignedTable = assignTable(guestCount);
    if(assignedTable == 0) printf("Désoler vous êtes trop nombreux, je doit vous refuser.");
    else printf("Très bien veuiller prendre la table %d", assignedTable);

    printf("Que voulez vous en plats ?('c' pour couscous(15$), 't' pour tomates(8$) et 'r' pour risotto(23$))");
    scanf("%c", &dish);
    printf("Que voulez vous en boissons ?('s' pour soda(5$), 'e' pour eau(2$) et 'l' pour limonade(12$))");
    scanf("%c", &drink);
    printf("Que voulez vous en desserts ?('t' pour tiramisu(62$), 'g' pour glace(3$) et 'm' pour macaron(8$))");
    scanf("%c", &dessert);


    return 0;
}
