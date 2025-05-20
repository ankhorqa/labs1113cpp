#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
    int health;

public:
    Entity(const std::string& n, int h) : name(n), health(h) {}

    virtual void displayInfo() const {
        std::cout << "Имя: " << name << ", ХП: " << health << std::endl;
    }

    virtual ~Entity() {}
};

class Player : public Entity {
private:
    int experience;

public:
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {}

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Опыт: " << experience << std::endl;
    }
};

class Enemy : public Entity {
private:
    std::string type;

public:
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {}

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Тип: " << type << std::endl;
    }
};

class Boss : public Enemy {
private:
    std::string Ultimate;

public:
    Boss(const std::string& n, int h, const std::string& t, const std::string& ability)
        : Enemy(n, h, t), Ultimate(ability) {}

    void displayInfo() const override {
        Enemy::displayInfo();
        std::cout << "Спецспособность: " << Ultimate << std::endl;
    }
};

int main() {
    Player hero("Герой", 100, 50);
    Enemy monster("Гоблин", 50, "Гоблин");
    Boss dragon("Дракон", 200, "Дракон", "Огненный шар");

    std::cout << "Информация об игроке:" << std::endl;
    hero.displayInfo();

    std::cout << "\nИнформация о враге:" << std::endl;
    monster.displayInfo();

    std::cout << "\nИнформация о боссе:" << std::endl;
    dragon.displayInfo();
    return 0;
}
