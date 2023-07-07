#include "potion.h"

Potion::Potion(int power) : healingPower(power) {}

int Potion::getHealingPower() const {
    return healingPower;
}
