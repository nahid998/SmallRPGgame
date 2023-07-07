#include "player.h"
#include "enemy.h"
#include "potion.h"
#include <iostream>

Player::Player(const std::string& playerName, int playerHealth, int playerDamage, int playerDefense)
    : name(playerName), health(playerHealth), damage(playerDamage), defense(playerDefense), maxHealth(playerHealth) {}

std::string Player::getName() const {
    return name;
}

bool Player::isAlive() const {
    return health > 0;
}

void Player::attack(Enemy& enemy) {
    std::cout << name << " attacca!\n";
    enemy.takeDamage(damage);
}

void Player::defend() {
    std::cout << name << " si difende e riduce i danni subiti.\n";
    defense += 5;
}

void Player::usePotion(Potion& potion) {
    int healingPower = potion.getHealingPower();
    std::cout << name << " usa una pozione e recupera " << healingPower << " punti vita.\n";
    health += healingPower;
    if (health > maxHealth) {
        health = maxHealth;
    }
}

void Player::takeDamage(int amount) {
    int damageTaken = amount - defense;
    if (damageTaken < 0) {
        damageTaken = 0;
    }
    health -= damageTaken;
    std::cout << name << " subisce " << damageTaken << " danni.\n";
    if (health <= 0) {
        std::cout << name << " è stato sconfitto!\n";
    }
}
