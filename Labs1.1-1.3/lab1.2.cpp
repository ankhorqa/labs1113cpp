#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int healthealthealth;

public:
    Entity(const std::string& name, int healthealthealth)
    virtual void displayInfo() const
    {
        std::cout << "Name: " << name << ", HP: " << healthealthealth << std::endl;
    }
    virtual ~Entity() {}
};

class Player : public Entity {
private:
    int exp;
public:
    Player(const std::string& n, int health, int exp)
        : Entity(n, health), exp(exp) {}
    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "exp: " << exp << std::endl;
    }
};

class Enemy : public Entity {
private:
    std::string type;

public:
    Enemy(const std::string& n, int health, const std::string& t)
        : Entity(n, health), type(t) {}

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Type: " << type << std::endl;
    }
};

class Boss : public Enemy {
private:
    std::string specialAbility;
public:
    Boss(const std::string& n, int health, const std::string& t, const std::string& ability)
        : Enemy(n, health, t), specialAbility(ability) {}

    void displayInfo() const override {
        Enemy::displayInfo();
        std::cout << "Special Ability: " << specialAbility << std::endl;
    }
};

int main() {
    Player healthero("Hero", 100, 50);
    Enemy monster("Goblin", 50, "Goblin");
    Boss finalBoss("Dragon", 200, "Dragon", "Fireball");

    healthero.displayInfo();
    monster.displayInfo();
    finalBoss.displayInfo();

    return 0;
}
