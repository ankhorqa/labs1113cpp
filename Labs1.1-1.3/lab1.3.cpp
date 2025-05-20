#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Entity {
protected:
    std::string name;
    int health;
    int attack;
    int defense;

public:
    Entity(const std::string& n, int h, int a, int d)
            : name(n), health(h), attack(a), defense(d) {}

    virtual void attackTarget(Entity& target) {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            target.takeDamage(damage);
            std::cout << name << " атакует " << target.getName() << " на " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << " без урона!\n";
        }
    }

    virtual void displayInfo() const {
        std::cout << "Имя: " << name << ", ХП: " << health 
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }

    virtual void heal(int amount) {
        health += amount;
        if (health > 100) health = 100;
        std::cout << name << " восстанавливает " << amount << " ХП. Текущее ХП: " << health << std::endl;
    }

    virtual void takeDamage(int amount) {
        if (amount > 0) {
            health -= amount;
            if (health < 0) health = 0;
        }
    }

    const std::string& getName() const { return name; }
    int getDefense() const { return defense; }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }

    virtual ~Entity() {}
};

class Character : public Entity {
public:
    Character(const std::string& n, int h, int a, int d)
            : Entity(n, h, a, d) {}

    void attackTarget(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 20) {
                damage *= 2;
                std::cout << "Крит. Урон! ";
            }
            target.takeDamage(damage);
            std::cout << name << " атакует " << target.getName() << " на " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << " без урона!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Персонаж: " << name << ", ХП: " << health 
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }

    void heal(int amount) override {
        health += amount;
        if (health > 100) health = 100;
        std::cout << name << " восстанавливает " << amount << " ХП! Текущее ХП: "
                  << health << std::endl;
    }
};

class Monster : public Entity {
public:
    Monster(const std::string& n, int h, int a, int d)
            : Entity(n, h, a, d) {}

    void attackTarget(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 30) {
                damage += 5;
                std::cout << "Отравленная атака! ";
            }
            target.takeDamage(damage);
            std::cout << name << " атакует " << target.getName() << " на " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << " без урона!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Враг: " << name << ", ХП: " << health
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }
};

class Boss : public Monster {
public:
    Boss(const std::string& n, int h, int a, int d)
            : Monster(n, h, a, d) {}

    void attackTarget(Entity& target) override {
        int damage = attack - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 40) {
                damage += 10;
                std::cout << "Огненная атака! ";
            }
            target.takeDamage(damage);
            std::cout << name << " атакует " << target.getName() << " на " << damage << " урона!\n";
        } else {
            std::cout << name << " атакует " << target.getName() << " без урона!\n";
        }
    }

    void displayInfo() const override {
        std::cout << "Босс: " << name << ", ХП: " << health 
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Character hero("Герой", 100, 20, 10);
    Monster goblin("Скелет", 50, 15, 5);
    Boss finalBoss("Дракон", 150, 30, 15);

    Entity* entities[] = { &hero, &goblin, &finalBoss };

    std::cout << "Все существа" << std::endl;
    for (auto entity : entities) {
        entity->displayInfo();
    }

    for (int i = 1; i < 4; i++) {
        entities[0]->attackTarget(*entities[i]);
    }

    for (int i = 1; i < 4; i++) {
        entities[i]->attackTarget(*entities[0]);
    }

    std::cout << "\nЛечение" << std::endl;
    hero.heal(20);

    std::cout << "\nАтака босса" << std::endl;
    finalBoss.attackTarget(hero);


    return 0;
}
