#include <iostream>
#include <vector>
#include <map>
using namespace std;
// pattern Prototype

// Иерархия классов игровых персонажей
// Полиморфный базовый класс
class Zombie
{
public:
  virtual Zombie *clone() = 0;
  virtual void info() = 0;
  virtual ~Zombie() {}
};

// Производные классы различных зомби
class Walker : public Zombie
{
  friend class PrototypeFactory;

public:
  Zombie *clone()
  {
    return new Walker(*this);
  }
  void info()
  {
    cout << "Walker" << endl;
  }

private:
  Walker() {}
};

class Spitter : public Zombie
{
  friend class PrototypeFactory;

public:
  Zombie *clone()
  {
    return new Spitter(*this);
  }
  void info()
  {
    cout << "Spitter" << endl;
  }

private:
  Spitter() {}
};

class Crawler : public Zombie
{
  friend class PrototypeFactory;

public:
  Zombie *clone()
  {
    return new Crawler(*this);
  }
  void info()
  {
    cout << "Crawler" << endl;
  }

private:
  Crawler() {}
};

// Фабрика для создания зомби всех типов
class PrototypeFactory
{
public:
  Zombie *createWalker()
  {
    static Walker prototype;
    return prototype.clone();
  }
  Zombie *createSpitter()
  {
    static Spitter prototype;
    return prototype.clone();
  }
  Zombie *createCrawler()
  {
    static Crawler prototype;
    return prototype.clone();
  }
};

int main()
{
  PrototypeFactory factory;
  vector<Zombie *> v;
  v.push_back(factory.createWalker());
  v.push_back(factory.createSpitter());
  v.push_back(factory.createCrawler());

  for (int i = 0; i < v.size(); i++)
    v[i]->info();
}