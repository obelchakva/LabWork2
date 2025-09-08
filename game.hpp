#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <locale>

using namespace std;

struct Person
{
    string name;
    int damage;
    int health;
    string fraction;
    int distance;
    virtual void attack(Person& a) = 0; 
    virtual void attack(Person&a, Person&b) = 0;
    virtual void attack(Person&a, Person&b, Person&c) = 0;
    virtual ~Person() = default; 
};

struct Voin : public Person
{
    int attack_distance;
};

struct Luchnik : public Person
{
    int attack_distance;
};

struct Mag : public Person
{
    int attack_distance;
};

struct Pehota : public Voin
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
    
    Pehota();
};

struct Vor : public Voin
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    Vor();
};

struct Berserk : public Voin
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    Berserk()
    {
        attack_distance = 1;
        damage = 5;
        health = 6;
        distance = 1;
        fraction = "Воин";
        name = "Берсерк";
    }
};

struct Paladin : public Voin
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    Paladin()
    {
        attack_distance = 1;
        damage = 4;
        health = 11;
        distance = 1;
        fraction = "Воин";
        name = "Паладин";
    }
};

struct Celitel : public Mag
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    int heal;

    Celitel()
    {
        attack_distance = 2;
        health = 10;
        distance = 2;
        fraction = "Маг";
        heal = 2;
        name = "Целитель";
    }
};

struct Zaclinatel : public Mag
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person& a) override;
    
    int damage;

    Zaclinatel()
    {
        attack_distance = 2;
        health = 10;
        distance = 2;
        fraction = "Маг";
        damage = 1;
        name = "Заклинатель";
    }
};

struct Arhimag:public Mag
{
	void attack(Person&a);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person& a, Person& b);
	
	int damage;

	Arhimag()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Маг";
        name = "Архимаг";
	}
};

struct Illuzionist:public Mag
{
	void attack(Person &a);
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
	int damage;
	
	Illuzionist()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Иллюзионист";
        name = "Иллюзионист";
	}
};

struct Strelok:public Luchnik
{	
	void attack(Person&a, Person&b);
	void attack(Person&a);
	void attack(Person &a, Person &b, Person &c);
	
	Strelok()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Лучник";
        name = "Стрелок";
	}
};

struct Eger:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Eger()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Лучник";
        name = "Егерь";
	}
};

struct Antimag:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Antimag()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Антимаг";
        name = "Антимаг";
	}
};

struct Assasin:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Assasin()
	{
		attack_distance = 2;
		damage = 3;
		health = 10;
		distance = 2;
		fraction = "Лучник";
        name = "Ассасин";
	}
};

struct Predmet
{
	string fraction;
	string name;
	virtual void use(Person& a) = 0;
};

struct Amulet : public Predmet
{
	void use(Person &a) override;
	
	Amulet()
	{
		fraction = "Предмет";
		name = "Амулет";
	}
};

struct Yad : public Predmet
{
	void use(Person &a) override;
	
	Yad()
	{
		fraction = "Предмет";
		name = "Яд";
	}
};

struct Eleksir : public Predmet
{
	void use(Person &a) override;
	
	Eleksir()
	{
		fraction = "Предмет";
		name = "Эликсир";
	}
};

struct Proklyatie : public Predmet
{
	void use(Person &a) override;
	
	Proklyatie()
	{
		fraction = "Предмет";
		name = "Проклятие";
	}
};

#endif // GAME_HPP
