#include <stdio.h>



int assignTable(int guestCount) {
    if(0 < guestCount && guestCount <= 2) return 1; // If the number of guest is between 0 and 2 assign them to table 1
    if(2 < guestCount && guestCount <= 4) return 2; // If the number of guest is between 2 and 4 assign them to table 2
    if(4 < guestCount && guestCount <= 8) return 3; // If the number of guest is between 4 and 8 assign them to table 3
    return 0;                                       // Else return error
}



int generateMenuPrice(char dish,char drink,char dessert) {
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
        case 'l': total += 12; break;  // If guest requested some 'limonade' then add 12$ to total
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
    // Getting guest count
    int guestCount;
    printf("\nBonjour, combien êtes vous ?\n");
    scanf(" %d", &guestCount);

    // Assigning them to a table if an error is returned, end program
    int assignedTable = assignTable(guestCount);
    if(assignedTable == 0) {
        printf("\nDésoler vous êtes trop nombreux, je doit vous refuser.");
        return 1;
    }
    else
        printf("\nTrès bien veuiller prendre la table n°%d\n", assignedTable);

    // Getting selected menu
    char dish, drink, dessert;
    printf("\nQue voulez vous en plats ?\n('c' pour couscous(15$),\n 't' pour tomates(8$) ou\n 'r' pour risotto(23$))\n");
    scanf(" %c", &dish);

    printf("\nQue voulez vous en boissons ?\n('s' pour soda(5$),\n 'e' pour eau(2$) ou\n 'l' pour limonade(12$))\n");
    scanf(" %c", &drink);

    printf("\nQue voulez vous en desserts ?\n('t' pour tiramisu(62$),\n 'g' pour glace(3$) ou\n 'm' pour macaron(8$))\n");
    scanf(" %c", &dessert);

    // Making the total price of menu if an error is returned, end program
    int menuPrice = generateMenuPrice(dish, drink, dessert);
    if(menuPrice == 0) {
        printf("\nDésoler votre commande est invalide.");
        return 1;
    }

    // Making the total for all guest
    int totalPrice = menuPrice * guestCount;
    printf("\nTrès bien cela vous fera un total de %d$\n", totalPrice);




    return 0;
}
