#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Player;

class Enemy {
protected:
    std::string name;
    int health;
    int damage;

public:
    Enemy(const std::string& enemyName, int enemyHealth, int enemyDamage);

    std::string getName() const;
    bool isAlive() const;  // Aggiunta del metodo isAlive()

    void attack(Player& player);
    void takeDamage(int amount);
};

#endif  // ENEMY_H
