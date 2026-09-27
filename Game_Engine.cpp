#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Entity
{
protected:
    string name;
    int id;

public:
    Entity(string n, int i) : name(n), id(i) {}
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~Entity() {}
};

class player : public Entity
{
private:
    int health;
    int level;

public:
    player(string n, int i, int h, int l)
        : Entity(n, i), health(h), level(l) {}

    void update() override
    {
        health -= 10;
        level++;
    }

    void render() override
    {
        cout << "name=" << name << endl;
        cout << "id=" << id << endl;
        cout << "health=" << health << endl;
        cout << "level=" << level << endl;
    }
};

class enemy : public Entity
{
private:
    int attackpower;
    int enemyhealth;
    string type;

public:
    enemy(string n, int i, int a, int e, string t)
        : Entity(n, i), attackpower(a), enemyhealth(e), type(t) {}

    void update() override
    {
        attackpower += 5;
        enemyhealth -= 10;
    }

    void render() override
    {
        cout << "name=" << name << endl;
        cout << "id=" << id << endl;
        cout << "typeEnemy=" << type << endl;
        cout << "attackpower=" << attackpower << endl;
        cout << "enemyhealth=" << enemyhealth << endl;
    }
};

class GameEngine
{
private:
    vector<Entity*> entities;
    static int total;

public:
    void add(Entity* e)
    {
        entities.push_back(e);
        total++;
    }

    static void showtotal()
    {
        cout << total << endl;
    }

    void runGameLoop()
    {
        for (size_t i = 0; i < entities.size(); i++)
        {
            entities[i]->update();
            entities[i]->render();
        }
    }

    ~GameEngine()
    {
        for (size_t i = 0; i < entities.size(); i++)
        {
            delete entities[i];
        }
        entities.clear();
    }
};

int GameEngine::total = 0;

int main()
{
    GameEngine g;

    g.add(new player("yuri", 123, 100, 1));
    cout << "==============" << endl;

    g.add(new enemy("ppp", 123, 10, 100, "fire"));

    g.runGameLoop();

    cout << "==============" << endl;
    GameEngine::showtotal();
}
