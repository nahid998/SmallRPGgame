#include "player.h"
#include "enemy.h"
#include "potion.h"
#include <iostream>

int main() {
    Player player("Giocatore", 100, 20, 5);
    Enemy enemy("Nemico", 50, 10);
    Potion healthPotion(20);

    std::cout << "Benvenuto in RPG Text Game!\n";
    std::cout << "Inserisci il tuo nome: ";
    std::string playerName;
    std::cin >> playerName;
    player = Player(playerName, 100, 20, 5);

    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "Ciao, " << player.getName() << "! Cosa vuoi fare?\n";
        std::cout << "1. Attacca\n";
        std::cout << "2. Difenditi\n";
        std::cout << "3. Usa una pozione\n";
        std::cout << "Fai la tua scelta: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            player.attack(enemy);
            break;
        case 2:
            player.defend();
            break;
        case 3:
            player.usePotion(healthPotion);
            break;
        default:
            std::cout << "Scelta non valida!\n";
            break;
        }

        if (enemy.isAlive()) {
            enemy.attack(player);
        }
    }

    if (!player.isAlive()) {
        std::cout << "Hai perso! Il nemico ha vinto.\n";
    }
    else {
        std::cout << "Congratulazioni! Hai sconfitto il nemico.\n";
    }

    return 0;
}
