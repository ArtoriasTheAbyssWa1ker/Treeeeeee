#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Human
{
private:
    string name;
    float hight;
    float weight;

public:
    void set_base_data()
    {
        cout << "Enter name, hight, weiht of eldian: " << endl;
        cin >> name; // подкорректировать
        cin >> hight;
        cin >> weight;
    }
    void get_base_data()
    {
        cout << "Eldian: " << name << ", " << hight << ", " << weight;
    }
};

class Eldians : public Human
{
private:
    bool abBecTitan = true; // способность становиться титаном
};

class Shifters : public Eldians
{
private:
    bool abBecSaneTitan = true; // способность становиться разумным титаном
    bool isTitan = false;       // состояние Титана

public:
    void onOffTitan()
    {
        if (isTitan == false)
        {
            isTitan = true;
        }
        else
        {
            isTitan = false;
        }
    }
};

class AttackTitan : public Shifters
{
private:
    bool strByFreedom = true; // стремление к свободе
};

class ColossalTitan : public Shifters
{
private:
    bool contBySteam = true; // контроль пара
    std::string height = "very hight";
};

class ArmoredTitan : public Shifters
{
private:
    bool armorPlates = true;   // броневые пластины
    bool contArmPlates = true; // контроль броневыми пластинами
};

int main()
{
    ArmoredTitan At;
    At.set_base_data();
    At.get_base_data();
}