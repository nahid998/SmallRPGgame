#include "enemy.h"
#include "player.h"
#include <iostream>

Enemy::Enemy(const std::string& enemyName, int enemyHealth, int enemyDamage)
    : name(enemyName), health(enemyHealth), damage(enemyDamage) {}

std::string Enemy::getName() const {
    return name;
}

bool Enemy::isAlive() const {
    return health > 0;
}

void Enemy::attack(Player& player) {
    std::cout << name << " attacca e infligge " << damage << " danni.\n";
    player.takeDamage(damage);
}

void Enemy::takeDamage(int amount) {
    health -= amount;
    std::cout << name << " subisce " << amount << " danni.\n";
    if (health <= 0) {
        std::cout << name << " è stato sconfitto!\n";
    }
}
