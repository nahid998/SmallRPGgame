#ifndef POTION_H
#define POTION_H

class Potion {
private:
    int healingPower;

public:
    Potion(int power);

    int getHealingPower() const;
};

#endif  // POTION_H
