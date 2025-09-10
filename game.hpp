/* Obel'chak Vyacheslav st129564@student.spbu.ru
 * LabWork2 */

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
	
    Berserk();
};

struct Paladin : public Voin
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    Paladin();
};

struct Celitel : public Mag
{
	void attack(Person& a) override;
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
    int heal;

    Celitel();
};

struct Zaclinatel : public Mag
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person& a) override;
    
    int damage;

    Zaclinatel();
};

struct Arhimag:public Mag
{
	void attack(Person&a);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person& a, Person& b);
	
	int damage;

	Arhimag();
};

struct Illuzionist:public Mag
{
	void attack(Person &a);
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	
	int damage;
	
	Illuzionist();
};

struct Strelok:public Luchnik
{	
	void attack(Person&a, Person&b);
	void attack(Person&a);
	void attack(Person &a, Person &b, Person &c);
	
	Strelok();
};

struct Eger:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Eger();
};

struct Antimag:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Antimag();
};

struct Assasin:public Luchnik
{
	void attack(Person&a, Person&b);
	void attack(Person&a, Person&b, Person&c);
	void attack(Person &a);
	
	Assasin();
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
	
	Amulet();
};

struct Yad : public Predmet
{
	void use(Person &a) override;
	
	Yad();
};

struct Eleksir : public Predmet
{
	void use(Person &a) override;
	
	Eleksir();
};

struct Proklyatie : public Predmet
{
	void use(Person &a) override;
	
	Proklyatie();
};

#endif // GAME_HPP
