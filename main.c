#include <stdio.h>

int assignTable(int guestCount) {
    if(0 < guestCount && guestCount <= 2) return 1; // If the number of guest is between 0 and 2 assign them to table 1
    if(2 < guestCount && guestCount <= 4) return 2; // If the number of guest is between 2 and 4 assign them to table 2
    if(4 < guestCount && guestCount <= 8) return 3; // If the number of guest is between 4 and 8 assign them to table 3
    return 0;                                       // Else return error
}

int menuPrice(char dish,int drink,int dessert) {
    int total = 0;
    
    switch (dish) {
        case 'c': total += 15; break; // If guest requested some 'couscous' then add 15$ to total
        case 't': total += 8; break;  // If guest requested some 'tomates'  then add  8$ to total
        case 'r': total += 23; break; // If guest requested some 'risotto'  then add 23$ to total
        default: return 0;            // Else return an error
    }

    switch (drink) {
        case 's': total += 5; break;   // If guest requested some 'soda'     then add  5$ to total
        case 'e': total += 2; break;   // If guest requested some 'eau'      then add  2$ to total
        case 'l': total += 12; break;  // If guest requested some 'lomonade' then add 12$ to total
        default: return 0;             // Else return an error
    }

    switch (dessert) {
        case 't': total += 62; break; // If guest requested some 'tiramisu' then add 62$ to total
        case 'g': total += 3; break;  // If guest requested some 'glace'    then add  3$ to total
        case 'm': total += 8; break;  // If guest requested some 'macaron'  then add  8$ to total
        default: return 0;            // Else return an error
    }

    return total;
}

int main() {
    int guestCount;
    char dish, drink, dessert;

    // Getting guest count
    printf("Bonjour, combien êtes vous ?");
    scanf("%d", &guestCount);

    // Assigning them to a table
    int assignedTable = assignTable(guestCount);
    if(assignedTable == 0)
        printf("Désoler vous êtes trop nombreux, je doit vous refuser.");
    else
        printf("Très bien veuiller prendre la table n°%d\n", assignedTable);

    // Getting selected menu
    printf("Que voulez vous en plats ?('c' pour couscous(15$), 't' pour tomates(8$) et 'r' pour risotto(23$))");
    scanf("%c\n", &dish);

    printf("Que voulez vous en boissons ?('s' pour soda(5$), 'e' pour eau(2$) et 'l' pour limonade(12$))");
    scanf("%c\n", &drink);

    printf("Que voulez vous en desserts ?('t' pour tiramisu(62$), 'g' pour glace(3$) et 'm' pour macaron(8$))");
    scanf("%c\n", &dessert);

    // Making the total price of menu
    int price = menuPrice(dish, drink, dessert);
    if(price == 0) {
        printf("Désoler votre commande est invalide.");
        return 1;
    }

    // Making the total for all guest
    int totalPrice = price * guestCount;
    scanf("Très bien cela vous fera un total de %d $", totalPrice);



    return 0;
}
