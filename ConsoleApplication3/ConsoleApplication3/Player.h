#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Enemy;
class Potion;

class Player {
private:
    std::string name;
    int health;
    int damage;
    int defense;
    int maxHealth;

public:
    Player(const std::string& playerName, int playerHealth, int playerDamage, int playerDefense);

    std::string getName() const;
    bool isAlive() const;  // Aggiunta del metodo isAlive()

    void attack(Enemy& enemy);
    void defend();
    void usePotion(Potion& potion);
    void takeDamage(int amount);
};

#endif  // PLAYER_H
