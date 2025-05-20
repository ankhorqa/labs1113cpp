#include <iostream>
#include <string>


class Character {
private:
    std::string name;  
    int health;        
    int attack;        
    int defense;      

public:
    Character(std::string n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    int getHealth() {
        return health;
    }

    void displayInfo() const {
        std::cout << "Имя: " << name << ", ХП: " << health
                  << ", Атака: " << attack << ", Защита: " << defense << std::endl;
    }

    void heal(int amount) {
        health += amount;
        if (health > 100) {
            health = 100;
        }
        std::cout << name << " восстанавливает " << amount << " ХП. Текущее ХП: " << health << std::endl;
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) {
            health = 0;
        }
        std::cout << name << " получает " << amount << " урона. Текущее ХП: " << health << std::endl;
    }

    
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " атакует " << enemy.name << " на " << damage << " урона!" << std::endl;
        } else {
            std::cout << name << " атакует " << enemy.name << " без урона!" << std::endl;
        }
    }
};


int main() {
    Character hero("Герой", 100, 20, 10);
    Character monster("Гоблин", 100, 50, 5);

    hero.displayInfo();
    monster.displayInfo();

    hero.attackEnemy(monster);
    monster.displayInfo();

    monster.attackEnemy(hero);
    hero.displayInfo();

    hero.heal(20);
    hero.displayInfo();

    monster.takeDamage(20);
    monster.displayInfo();

    return 0;
}

