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
    void attack(Person& a) override {
        if (a.fraction == "Иллюзионист") {
            if (a.distance <= attack_distance) {
                int randomNum = rand() % 101;
                if (randomNum <= 70) {
                    a.health -= damage;
                    cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
                } else {
                    cout << "Неудачная атака" << endl;
                }
            } else {
                cout << "Неудачная атака" << endl;
            }
        } else {
            if (a.distance <= attack_distance) {
                a.health -= damage;
                cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
            } else {
                cout << "Неудачная атака" << endl;
            }
        }
    }
    
    void attack(Person&a, Person&b) {

    }
    void attack(Person&a, Person&b, Person&c) {

    }
    

    Pehota()
    {
        attack_distance = 1;
        damage = 3;
        health = 10;
        distance = 1;
        fraction = "Воин";
        name = "Пехота";
    }
};

struct Vor : public Voin
{
    void attack(Person& a) override {
        if (a.fraction == "Иллюзионист") {
            if (a.distance <= attack_distance) {
                int randomNum = rand() % 101;
                if (randomNum <= 70) {
                    a.health -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
					if(a.damage >= 2) {
						a.damage -= 1;
						cout << "Вы украли " << 1 << " урона" << " у " << a.name << endl;
					}
					else {
						cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
					}
                } else {
                    cout << "Неудачная атака" << endl;
                }
            } else {
                cout << "Неудачная атака" << endl;
            }
        } else {
            if (a.distance <= attack_distance) {
                a.health -= damage;
                cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
                if(a.damage >= 2) {
					a.damage -= 1;
					cout << "Вы украли " << 1 << " урона" << " у " << a.name << endl;
				}
				else {
					cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
				}
            } else {
                cout << "Неудачная атака" << endl;
            }
        }
    }
    void attack(Person&a, Person&b) {

    }
    void attack(Person&a, Person&b, Person&c) {

    }

    Vor()
    {
        attack_distance = 1;
        damage = 2;
        health = 10;
        distance = 1;
        fraction = "Воин";
        name = "Вор";
    }
};

struct Berserk : public Voin
{
    void attack(Person& a) override {
        if (a.fraction == "Иллюзионист") {
            if (a.distance <= attack_distance) {
                int randomNum = rand() % 101;
                if (randomNum <= 70) {
                    a.health -= damage;
                    cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
                } else {
                    cout << "Неудачная атака" << endl;
                }
            } else {
                cout << "Неудачная атака" << endl;
            }
        } else {
            if (a.distance <= attack_distance) {
                a.health -= damage;
                cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
            } else {
                cout << "Неудачная атака" << endl;
            }
        }
    }

    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

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
    void attack(Person& a) override {
        if (a.fraction == "Иллюзионист") {
            if (a.distance <= attack_distance) {
                int randomNum = rand() % 101;
                if (randomNum <= 70) {
                    a.health -= damage;
                    cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
                } else {
                    cout << "Неудачная атака" << endl;
                }
            } else {
                cout << "Неудачная атака" << endl;
            }
        } else {
            if (a.distance <= attack_distance) {
                a.health -= damage;
                cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
            } else {
                cout << "Неудачная атака" << endl;
            }
        }
    }

    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

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
    int heal;

    void attack(Person& a) override {
		if(a.health > 0) {
			a.health += heal;
			cout << "Вы восстановили " << heal << " здоровья" << " у " << a.name << endl;
		}
		else {
			cout << a.name << " мертв, ему нельзя восстановить здоровье!" << endl;
		}
    }

    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

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
    int damage;

    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

    void attack(Person& a) override {
        if (a.fraction != "Антимаг") {
            if (a.fraction == "Иллюзионист") {
                if (a.distance <= attack_distance) {
                    int randomNum = rand() % 101;
                    if (randomNum <= 70) {
						if(a.damage >= 2) {
							a.damage -= damage;
							cout << "Вы отняли " << damage << " урона" << " по " << a.name << endl;
						}
						else {
							cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
						}
                    } else {
                        cout << "Неудачная атака" << endl;
                    }
                } else {
                    cout << "Неудачная атака" << endl;
                }
            } else {
                if (a.distance <= attack_distance) {
					if(a.damage >= 2) {
						a.damage -= damage;
						cout << "Вы отняли " << damage << " урона" << " у " << a.name << endl;
					}
					else {
						cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
					}
                } else {
                    cout << "Неудачная атака" << endl;
                }
            }
        } else {
            cout << "Неудачная атака" << endl;
        }
    }

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
	int damage;

    void attack(Person&a) {}
    void attack(Person&a, Person&b, Person&c) {}
	
	void attack(Person& a, Person& b) {
		if (a.fraction != "Антимаг") {
			if (a.fraction == "Иллюзионист") {
				if (a.distance <= attack_distance) {
					srand(time(0));
					int randomNum = rand() % 101;
					if (randomNum <= 70) {
						a.health -= damage;
						cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
					} else {
						cout << "Неудачная атака" << endl;
					}
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
				if (a.distance <= attack_distance) {
					a.health -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			}
		} else {
			cout << "Неудачная атака" << endl;
		}
		
		if (b.fraction != "Антимаг") {
			if (b.fraction == "Иллюзионист") {
				if (b.distance <= attack_distance) {
					srand(time(0));
					int randomNum = rand() % 101;
					if (randomNum <= 70) {
						b.health -= damage;
						cout << "Вы нанесли " << damage << " урона" << " по " << b.name << endl;
					} else {
						cout << "Неудачная атака" << endl;
					}
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
				if (b.distance <= attack_distance) {
					b.health -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << b.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			}
		} else {
			cout << "Неудачная атака" << endl;
		}
	}
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
	int damage;
	
	void attack(Person &a) {
		if (a.fraction != "Антимаг") {
			if (a.fraction == "Иллюзионист") {
				if (a.distance <= attack_distance) {
					int randomNum = rand() % 101;
					if (randomNum <= 70) {
						a.health -= damage;
						cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
					} else {
						cout << "Неудачная атака" << endl;
					}
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
				if (a.distance <= attack_distance) {
					a.damage -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			}
		} else {
			cout << "Неудачная аттака" << endl;
	}
	}

    void attack(Person&a, Person&b) {

    }
    void attack(Person&a, Person&b, Person&c) {

    }
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

    void attack(Person&a, Person&b) {}
    void attack(Person&a) {}
	void attack(Person &a, Person &b, Person &c) {
		if (a.fraction == "Иллюзионист") {
			if (a.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					a.health -= damage / 2;
					cout << "Вы нанесли " << damage / 2 << " урона" << " по " << a.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
			cout << "Неудачная атака" << endl;
			}
		} else {
			if (a.distance <= attack_distance) {
				a.health -= damage / 2;
				cout << "Вы нанесли " << damage / 2 << " урона" << " по " << a.name << endl;
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
		if (b.fraction == "Иллюзионист") {
			if (b.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					b.health -= damage / 2;
					cout << "Вы нанесли " << damage / 2 << " урона" << " по " << b.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
			cout << "Неудачная атака" << endl;
			}
		} else {
			if (b.distance <= attack_distance) {
				b.health -= damage / 2;
				cout << "Вы нанесли " << damage / 2 << " урона" << " по " << b.name << endl;
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
		if (c.fraction == "Иллюзионист") {
			if (c.distance <= attack_distance) {
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					c.health -= damage / 2;
					cout << "Вы нанесли " << damage / 2 << " урона" << " по " << c.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
			cout << "Неудачная атака" << endl;
			}
		} else {
			if (c.distance <= attack_distance) {
				c.health -= damage / 2;
				cout << "Вы нанесли " << damage / 2 << " урона" << " по " << c.name << endl;
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
	}
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

    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

	void attack(Person &a) {
		if (a.fraction == "Иллюзионист") {
			if (a.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					a.health -= damage * 2;
					cout << "Вы нанесли " << damage * 2 << " урона" << " по " << a.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
			cout << "Неудачная атака" << endl;
			}
		} else {
			if (a.distance <= attack_distance) {
					if (a.fraction == "Маг" || a.fraction == "Лучник" || a.fraction == "Антимаг") {
						a.health -= damage * 2;
						cout << "Вы нанесли " << damage * 2 << " урона" << " по " << a.name << endl;
					} else {
						a.health -= damage;
						cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
					}
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
	}
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
    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}
	void attack(Person &a) {
		if (a.fraction == "Иллюзионист") {
			if (a.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					a.health -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
			cout << "Неудачная атака" << endl;
			}
		} else {
			if (a.distance <= attack_distance) {
				a.health -= damage;
				cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
	}
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
    void attack(Person&a, Person&b) {}
    void attack(Person&a, Person&b, Person&c) {}

	void attack(Person &a) {
		if (a.fraction == "Иллюзионист") {
			if (a.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 70) {
					srand(time(0));
					int randomNum1 = rand() % 101;
					if (randomNum1 <= 10) {
						a.health = 0;
						cout << "Вы убили " << a.name << endl;
					} else {
						a.health -= damage;
						cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
					}
				} else {
					cout << "Неудачная атака" << endl;
				}
			} else {
				cout << "Неудачная атака" << endl;
			}
		} else {
			if (a.distance <= attack_distance) {
				srand(time(0));
				int randomNum = rand() % 101;
				if (randomNum <= 10) {
					a.health = 0;
					cout << "Вы убили " << a.name << endl;
				} else {
					a.health -= damage;
					cout << "Вы нанесли " << damage << " урона" << " по " << a.name << endl;
				}
			} else {
				cout << "Неудачная атака" << endl;
			}
		}
	}
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
	void use(Person &a) override {
		if(a.health > 0) {
			a.health += 5;
			cout << "Вы увеличили здоровье " << a.name << " на 5 единиц" << endl;
		}
		else
		{
			cout << a.name << " мертв, ему нелзя восстановить здоровье!" << endl;
		}
	}
	Amulet()
	{
		fraction = "Предмет";
		name = "Амулет";
	}
};

struct Yad : public Predmet
{
	void use(Person &a) override {
		a.health -= 4;
		cout << "Вы уменьшили здоровье " << a.name << " на 4 единицы" << endl;
	}
	Yad()
	{
		fraction = "Предмет";
		name = "Яд";
	}
};

struct Eleksir : public Predmet
{
	void use(Person &a) override {
		a.damage +=1;
		cout << "Вы повысили урон " << a.name << " на 1 единицу" << endl;
	}
	Eleksir()
	{
		fraction = "Предмет";
		name = "Эликсир";
	}
};

struct Proklyatie : public Predmet
{
	void use(Person &a) override {
		if(a.damage >=2 ) {
			a.damage -= 1;
			cout << "Вы понизили урон " << a.name << " на 1 единицу" << endl;
		}
		else {
			cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
		}
	}
	Proklyatie()
	{
		fraction = "Предмет";
		name = "Проклятие";
	}
};



int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Pehota pehota_1;
    Vor vor_1;
    Berserk berserk_1;
    Paladin paladin_1;
    
    Celitel celitel_1;
    Zaclinatel zaclinatel_1;
    Arhimag arhimag_1;
    Illuzionist illu_1;

    Strelok strelok_1;
    Eger eger_1;
    Antimag antimage_1;
    Assasin assasin_1;    

    Amulet amulet_1;
    Yad yad_1;
    Eleksir eleksir_1;
    Proklyatie proklyatie_1;
    
    vector <Voin*> a1;
    int random_1 = 0;
    int random_2 = 0;

    while(random_1 == random_2) {
        random_1 = rand() % 4 + 1;
        random_2 = rand() % 4 + 1;
    }

    if(random_1 == 1) {
        a1.push_back(&pehota_1);
    }

    else if(random_1 == 2) {
        a1.push_back(&vor_1);
    }

    else if(random_1 == 3) {
        a1.push_back(&berserk_1);
    }

    else if(random_1 == 4) {
        a1.push_back(&paladin_1);
    }

    if(random_2 == 1) {
        a1.push_back(&pehota_1);
    }

    else if(random_2 == 2) {
        a1.push_back(&vor_1);
    }

    else if(random_2 == 3) {
        a1.push_back(&berserk_1);
    }

    else if(random_2 == 4) {
        a1.push_back(&paladin_1);
    }

    vector <Luchnik*> b1;

    while(random_1 == random_2) {
        random_1 = rand() % 4 + 1;
        random_2 = rand() % 4 + 1;
    }

    if(random_1 == 1) {
        b1.push_back(&strelok_1);
    }

    else if(random_1 == 2) {
        b1.push_back(&eger_1);
    }

    else if(random_1 == 3) {
        b1.push_back(&antimage_1);
    }

    else if(random_1 == 4) {
        b1.push_back(&assasin_1);
    }

    if(random_2 == 1) {
        b1.push_back(&strelok_1);
    }

    else if(random_2 == 2) {
        b1.push_back(&eger_1);
    }

    else if(random_2 == 4) {
        b1.push_back(&assasin_1);
    }

    else if(random_2 == 3) {
        b1.push_back(&antimage_1);
    }

    vector <Mag*> c1;

    while(random_1 == random_2) {
        random_1 = rand() % 4 + 1;
        random_2 = rand() % 4 + 1;
    }

    if(random_1 == 1) {
        c1.push_back(&celitel_1);
    }

    else if(random_1 == 2) {
        c1.push_back(&zaclinatel_1);
    }

    else if(random_1 == 3) {
        c1.push_back(&arhimag_1);
    }

    else if(random_1 == 4) {
        c1.push_back(&illu_1);
    }

    if(random_2 == 1) {
        c1.push_back(&celitel_1);
    }

    else if(random_2 == 2) {
        c1.push_back(&zaclinatel_1);
    }

    else if(random_2 == 3) {
        c1.push_back(&arhimag_1);
    }

    else if(random_2 == 4) {
        c1.push_back(&illu_1);
    }
    
    vector <Predmet*> d1;

    while(random_1 == random_2) {
        random_1 = rand() % 4 + 1;
        random_2 = rand() % 4 + 1;
    }

    if(random_1 == 1) {
        d1.push_back(&amulet_1);
    }

    else if(random_1 == 2) {
        d1.push_back(&yad_1);
    }

    else if(random_1 == 3) {
        d1.push_back(&eleksir_1);
    }

    else if(random_1 == 4) {
        d1.push_back(&proklyatie_1);
    }

    if(random_2 == 1) {
        d1.push_back(&amulet_1);
    }

    else if(random_2 == 2) {
        d1.push_back(&yad_1);
    }

    else if(random_2 == 3) {
        d1.push_back(&eleksir_1);
    }

    else if(random_2 == 4) {
        d1.push_back(&proklyatie_1);
    }
    
    Pehota pehota_2;
    Vor vor_2;
    Berserk berserk_2;
    Paladin paladin_2;
    
    Celitel celitel_2;
    Zaclinatel zaclinatel_2;
    Arhimag arhimag_2;
    Illuzionist illu_2;

    Strelok strelok_2;
    Eger eger_2;
    Antimag antimage_2;
    Assasin assasin_2;    
    
    vector <Voin*> a2;
    int random_3 = 0;
    int random_4 = 0;

    while(random_3 == random_4) {
        random_3 = rand() % 4 + 1;
        random_4 = rand() % 4 + 1;
    }

    if(random_3 == 1) {
        a2.push_back(&pehota_2);
    }

    else if(random_3 == 2) {
        a2.push_back(&vor_2);
    }

    else if(random_3 == 3) {
        a2.push_back(&berserk_2);
    }

    else if(random_3 == 4) {
        a2.push_back(&paladin_2);
    }

    if(random_4 == 1) {
        a2.push_back(&pehota_2);
    }

    else if(random_4 == 2) {
        a2.push_back(&vor_2);
    }

    else if(random_4 == 3) {
        a2.push_back(&berserk_2);
    }

    else if(random_4 == 4) {
        a2.push_back(&paladin_2);
    }

    vector <Luchnik*> b2;

    while(random_3 == random_4) {
        random_3 = rand() % 4 + 1;
        random_4 = rand() % 4 + 1;
    }

    if(random_3 == 1) {
        b2.push_back(&strelok_2);
    }

    else if(random_3 == 2) {
        b2.push_back(&eger_2);
    }

    else if(random_3 == 3) {
        b2.push_back(&antimage_2);
    }

    else if(random_3 == 4) {
        b2.push_back(&assasin_2);
    }

    if(random_4 == 1) {
        b2.push_back(&strelok_2);
    }

    else if(random_4 == 2) {
        b2.push_back(&eger_2);
    }

    else if(random_4 == 4) {
        b2.push_back(&assasin_2);
    }

    else if(random_4 == 3) {
        b2.push_back(&antimage_2);
    }


    vector <Mag*> c2;

    while(random_3 == random_4) {
        random_3 = rand() % 4 + 1;
        random_4 = rand() % 4 + 1;
    }

    if(random_3 == 1) {
        c2.push_back(&celitel_2);
    }

    else if(random_3 == 2) {
        c2.push_back(&zaclinatel_2);
    }

    else if(random_3 == 3) {
        c2.push_back(&arhimag_2);
    }

    else if(random_3 == 4) {
        c2.push_back(&illu_2);
    }

    if(random_4 == 1) {
        c2.push_back(&celitel_2);
    }

    else if(random_4 == 2) {
        c2.push_back(&zaclinatel_2);
    }

    else if(random_4 == 3) {
        c2.push_back(&arhimag_2);
    }

    else if(random_4 == 4) {
        c2.push_back(&illu_2);
    }

    cout << "Ваша колода:" << endl;
    int j = 1;
    for(auto warrior: a1) {
        cout << j++ << " - " << warrior -> name << "; ";
    }
    cout << endl;
    for(auto luchnik: b1) {
        cout << j++ << " - " << luchnik -> name << "; ";
    }
    cout << endl;
    for(auto mag: c1) {
        cout << j++ << " - " << mag -> name << "; ";
    }
    cout << endl;
    for(auto predmet: d1) {
        cout << j++ << " - " << predmet -> name << "; ";
    }
    cout << endl;
    cout << "Вражеская колода:" << endl;
    int i = 1; 
    for(auto warrior: a2) {
        cout << i++ << " - " << warrior -> name << "; ";
    }
    cout << endl;
    for(auto luchnik: b2) {
        cout << i++ << " - " << luchnik -> name << "; ";
    }
    cout << endl;
    for(auto mag: c2) {
        cout << i++ << " - "  << mag -> name << "; ";
    }
    cout << endl;

    int turn = 1;

    while(1) {
        if(turn == 1) { // ход пользователя
            cout << "Выберите номер карты, которую вы хотите использовать..." << endl;      
            int choice;
            cin >> choice;
            if(choice == 2 && a1.size() == 1) {
				choice = 1;
			}
			else if(choice == 4 && b1.size() == 1) {
				choice = 3;
			}
			else if(choice == 6 && c1.size() == 1) {
				choice = 5;
			}
			if((choice == 1 || choice ==2) && a1.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!" << endl;
			}
			else if((choice == 3 || choice ==4) && b1.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!" << endl;
			}
			else if((choice == 5 || choice ==6) && c1.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!" << endl;
			}
            else if(choice == 1) {
                cout << "Выбрана карта " << a1[0]->name << endl;
                cout << "Выберите вражескую цель (1-6)..." << endl;
                int choice_2;
                cin >> choice_2;
                if(choice_2 == 2 && a2.size() == 1) {
                    choice_2 = 1;
                }
                else if(choice_2 == 4 && b2.size() == 1) {
                    choice_2 = 3;
                }
                else if(choice_2 == 6 && c2.size() == 1) {
                    choice_2 = 5;
                }
                if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if(choice_2 == 1) {
                    a1[0]->attack(*a2[0]);
                    if(a2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a2.erase(a2.begin());
                    }
                }
                else if(choice_2 == 2) {
                    a1[0]->attack(*a2[1]);
                    if(a2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a2.erase(a2.begin() + 1);
                    }
                }
                else if(choice_2 == 3) {
                    a1[0]->attack(*b2[0]);
                    if(b2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b2.erase(b2.begin());
                    }
                }
                else if(choice_2 == 4) {
                    a1[0]->attack(*b2[1]);
                    if(b2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b2.erase(b2.begin() + 1);
                    }
                }
                else if(choice_2 == 5) {
                    a1[0]->attack(*c2[0]);
                    if(c2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c2.erase(c2.begin());
                    }
                }
                else if(choice_2 == 6) {
                    a1[0]->attack(*c2[1]);
                    if(c2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c2.erase(c2.begin() + 1);
                    }
                }
                else {
                    cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
                }
            }
            else if(choice == 2) {
                cout << "Выбрана карта " << a1[1]->name << endl;
                cout << "Выберите вражескую цель (1-6)..." << endl;
                int choice_2;
                cin >> choice_2;
                if(choice_2 == 2 && a2.size() == 1) {
                    choice_2 = 1;
                }
                else if(choice_2 == 4 && b2.size() == 1) {
                    choice_2 = 3;
                }
                else if(choice_2 == 6 && c2.size() == 1) {
                    choice_2 = 5;
                }
                if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if(choice_2 == 1) {
                    a1[1]->attack(*a2[0]);
                    if(a2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a2.erase(a2.begin());
                    }
                }
                else if(choice_2 == 2) {
                    a1[1]->attack(*a2[1]);
                    if(a2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a2.erase(a2.begin() + 1);
                    }
                }
                else if(choice_2 == 3) {
                    a1[1]->attack(*b2[0]);
                    if(b2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b2.erase(b2.begin());
                    }
                }
                else if(choice_2 == 4) {
                    a1[1]->attack(*b2[1]);
                    if(b2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b2.erase(b2.begin() + 1);
                    }
                }
                else if(choice_2 == 5) {
                    a1[1]->attack(*c2[0]);
                    if(c2[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c2.erase(c2.begin());
                    }
                }
                else if(choice_2 == 6) {
                    a1[1]->attack(*c2[1]);
                    if(c2[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c2.erase(c2.begin() + 1);
                    }
                }
                else {
                    cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
                }
            }
            else if(choice == 3) {
                cout << "Выбрана карта " << b1[0]->name << endl;
                if(b1[0]->name == "Стрелок") {
					cout << "Выберите три вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int choice_2_1;
					int choice_2_2;
					int choice_2_3;
					cin >> choice_2_1 >> choice_2_2 >> choice_2_3;
					if(choice_2_1 == choice_2_2 || choice_2_1 == choice_2_3 ||choice_2_2 == choice_2_3 || choice_2_1 >= choice_2_2 || choice_2_1 >= choice_2_3 || choice_2_2 >= choice_2_3) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(choice_2_1 == 2 && a2.size() == 1) {
							choice_2_1 = 1;
						}
						else if(choice_2_1 == 4 && b2.size() == 1) {
							choice_2_1 = 3;
						}
						else if(choice_2_1 == 6 && c2.size() == 1) {
							choice_2_1 = 5;
						}
						if((choice_2_1 == 1 || choice_2_1 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 3 || choice_2_1 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 5 || choice_2_1 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_2 == 2 && a2.size() == 1) {
							choice_2_2 = 1;
						}
						else if(choice_2_2 == 4 && b2.size() == 1) {
							choice_2_2 = 3;
						}
						else if(choice_2_2 == 6 && c2.size() == 1) {
							choice_2_2 = 5;
						}
						if((choice_2_2 == 1 || choice_2_2 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 3 || choice_2_2 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 5 || choice_2_2 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_3 == 2 && a2.size() == 1) {
							choice_2_3 = 1;
						}
						else if(choice_2_3 == 4 && b2.size() == 1) {
							choice_2_3 = 3;
						}
						else if(choice_2_3 == 6 && c2.size() == 1) {
							choice_2_3 = 5;
						}
						if((choice_2_3 == 1 || choice_2_3 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_3 == 3 || choice_2_3 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_3 == 5 || choice_2_3 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(choice_2_1 == 1) {
							if(choice_2_2 == 2) {
								if(choice_2_3 == 3) {
									b1[0]->attack(*a2[0],*a2[1],*b2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
								}
								else if(choice_2_3 == 4) {
									b1[0]->attack(*a2[0],*a2[1],*b2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[0]->attack(*a2[0],*a2[1],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*a2[0],*a2[1],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 3) {
								if(choice_2_3 == 4) {
									b1[0]->attack(*a2[0],*b2[0],*b2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[0]->attack(*a2[0],*b2[0],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*a2[0],*b2[0],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[0]->attack(*a2[0],*b2[1],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*a2[0],*b2[1],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[0]->attack(*a2[0],*c2[0],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 2) {
							if(choice_2_2 == 3) {
								if(choice_2_3 == 4) {
									b1[0]->attack(*a2[1],*b2[0],*b2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[0]->attack(*a2[1],*b2[0],*c2[0]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*a2[1],*b2[0],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[0]->attack(*a2[1],*b2[1],*c2[0]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*a2[1],*b2[1],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[0]->attack(*a2[1],*c2[0],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 3) {
							if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[0]->attack(*b2[0],*b2[1],*c2[0]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[0]->attack(*b2[0],*b2[1],*c2[1]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[0]->attack(*b2[0],*c2[0],*c2[1]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 4) {
							if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[0]->attack(*b2[1],*c2[0],*c2[1]);
									if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else {
							cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(choice_2 == 1) {
						b1[0]->attack(*a2[0]);
						if(a2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin());
						}
					}
					else if(choice_2 == 2) {
						b1[0]->attack(*a2[1]);
						if(a2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin() + 1);
						}
					}
					else if(choice_2 == 3) {
						b1[0]->attack(*b2[0]);
						if(b2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin());
						}
					}
					else if(choice_2 == 4) {
						b1[0]->attack(*b2[1]);
						if(b2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin() + 1);
						}
					}
					else if(choice_2 == 5) {
						b1[0]->attack(*c2[0]);
						if(c2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin());
						}
					}
					else if(choice_2 == 6) {
						b1[0]->attack(*c2[1]);
						if(c2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(choice == 4) {
                cout << "Выбрана карта " << b1[1]->name << endl;
                if(b1[1]->name == "Стрелок") {
					cout << "Выберите три вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int choice_2_1;
					int choice_2_2;
					int choice_2_3;
					cin >> choice_2_1 >> choice_2_2 >> choice_2_3;
					if(choice_2_1 == choice_2_2 || choice_2_1 == choice_2_3 ||choice_2_2 == choice_2_3 || choice_2_1 >= choice_2_2 || choice_2_1 >= choice_2_3 || choice_2_2 >= choice_2_3) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(choice_2_1 == 2 && a2.size() == 1) {
							choice_2_1 = 1;
						}
						else if(choice_2_1 == 4 && b2.size() == 1) {
							choice_2_1 = 3;
						}
						else if(choice_2_1 == 6 && c2.size() == 1) {
							choice_2_1 = 5;
						}
						if((choice_2_1 == 1 || choice_2_1 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 3 || choice_2_1 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 5 || choice_2_1 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_2 == 2 && a2.size() == 1) {
							choice_2_2 = 1;
						}
						else if(choice_2_2 == 4 && b2.size() == 1) {
							choice_2_2 = 3;
						}
						else if(choice_2_2 == 6 && c2.size() == 1) {
							choice_2_2 = 5;
						}
						if((choice_2_2 == 1 || choice_2_2 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 3 || choice_2_2 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 5 || choice_2_2 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_3 == 2 && a2.size() == 1) {
							choice_2_3 = 1;
						}
						else if(choice_2_3 == 4 && b2.size() == 1) {
							choice_2_3 = 3;
						}
						else if(choice_2_3 == 6 && c2.size() == 1) {
							choice_2_3 = 5;
						}
						if((choice_2_3 == 1 || choice_2_3 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_3 == 3 || choice_2_3 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_3 == 5 || choice_2_3 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(choice_2_1 == 1) {
							if(choice_2_2 == 2) {
								if(choice_2_3 == 3) {
									b1[1]->attack(*a2[0],*a2[1],*b2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
								}
								else if(choice_2_3 == 4) {
									b1[1]->attack(*a2[0],*a2[1],*b2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[1]->attack(*a2[0],*a2[1],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*a2[0],*a2[1],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 3) {
								if(choice_2_3 == 4) {
									b1[1]->attack(*a2[0],*b2[0],*b2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[1]->attack(*a2[0],*b2[0],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*a2[0],*b2[0],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[1]->attack(*a2[0],*b2[1],*c2[0]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*a2[0],*b2[1],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[1]->attack(*a2[0],*c2[0],*c2[1]);
									if(a2[0]->health <= 0) {
										cout << a2[0]->name << " убит!" << endl;
										a2.erase(a2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 2) {
							if(choice_2_2 == 3) {
								if(choice_2_3 == 4) {
									b1[1]->attack(*a2[1],*b2[0],*b2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
								}
								else if(choice_2_3 == 5) {
									b1[1]->attack(*a2[1],*b2[0],*c2[0]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*a2[1],*b2[0],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[1]->attack(*a2[1],*b2[1],*c2[0]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*a2[1],*b2[1],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[1]->attack(*a2[1],*c2[0],*c2[1]);
									if(a2[1]->health <= 0) {
										cout << a2[1]->name << " убит!" << endl;
										a2.erase(a2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 3) {
							if(choice_2_2 == 4) {
								if(choice_2_3 == 5) {
									b1[1]->attack(*b2[0],*b2[1],*c2[0]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
								}
								else if(choice_2_3 == 6) {
									b1[1]->attack(*b2[0],*b2[1],*c2[1]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
							else if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[1]->attack(*b2[0],*c2[0],*c2[1]);
									if(b2[0]->health <= 0) {
										cout << b2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										c2.erase(c2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else if(choice_2_1 == 4) {
							if(choice_2_2 == 5) {
								if(choice_2_3 == 6) {
									b1[1]->attack(*b2[1],*c2[0],*c2[1]);
									if(b2[1]->health <= 0) {
										cout << b2[1]->name << " убит!" << endl;
										b2.erase(b2.begin() + 1);
									}
									else if(c2[0]->health <= 0) {
										cout << c2[0]->name << " убит!" << endl;
										b2.erase(b2.begin());
									}
									else if(c2[1]->health <= 0) {
										cout << c2[1]->name << " убит!" << endl;
										c2.erase(c2.begin() + 1);
									}
								}
							}
						}
						else {
							cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(choice_2 == 1) {
						b1[1]->attack(*a2[0]);
						if(a2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin());
						}
					}
					else if(choice_2 == 2) {
						b1[1]->attack(*a2[1]);
						if(a2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin() + 1);
						}
					}
					else if(choice_2 == 3) {
						b1[1]->attack(*b2[0]);
						if(b2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin());
						}
					}
					else if(choice_2 == 4) {
						b1[1]->attack(*b2[1]);
						if(b2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin() + 1);
						}
					}
					else if(choice_2 == 5) {
						b1[1]->attack(*c2[0]);
						if(c2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin());
						}
					}
					else if(choice_2 == 6) {
						b1[1]->attack(*c2[1]);
						if(c2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(choice == 5) {
                cout << "Выбрана карта " << c1[0]->name << endl;
                if(c1[0]->name == "Целитель") {
					cout << "Выберите союзную цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if(choice_2 == 1) {
						c1[0]->attack(*a1[0]);
					}
					else if(choice_2 == 2) {
						c1[0]->attack(*a1[1]);
					}
					else if(choice_2 == 3) {
						c1[0]->attack(*b1[0]);
					}
					else if(choice_2 == 4) {
						c1[0]->attack(*b1[1]);
					}
					else if(choice_2 == 5) {
						c1[0]->attack(*c1[0]);
					}
					else if(choice_2 == 6) {
						c1[0]->attack(*c1[1]);
					}
					else {
						cout << "По неизвестным причинам целитель начал лечить несуществующих союзников и не восстановил никому здоровье!" << endl;
					}
				}
				else if(c1[0]->name == "Заклинатель") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if(choice_2 == 1) {
						c1[0]->attack(*a2[0]);
					}
					else if(choice_2 == 2) {
						c1[0]->attack(*a2[1]);
					}
					else if(choice_2 == 3) {
						c1[0]->attack(*b2[0]);
					}
					else if(choice_2 == 4) {
						c1[0]->attack(*b2[1]);
					}
					else if(choice_2 == 5) {
						c1[0]->attack(*c2[0]);
					}
					else if(choice_2 == 6) {
						c1[0]->attack(*c2[1]);
					}
					else {
						cout << "По неизвестным причинам заклинатель начал заклинать несуществующих противников и не отнял ни у кого урон!" << endl;
					}
				}
				else if (c1[0]->name == "Архимаг") {
					cout << "Выберите две вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int choice_2_1;
					int choice_2_2;
					cin >> choice_2_1 >> choice_2_2;
					if(choice_2_1 == choice_2_2 || choice_2_1 >= choice_2_2) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(choice_2_1 == 2 && a2.size() == 1) {
							choice_2_1 = 1;
						}
						else if(choice_2_1 == 4 && b2.size() == 1) {
							choice_2_1 = 3;
						}
						else if(choice_2_1 == 6 && c2.size() == 1) {
							choice_2_1 = 5;
						}
						if((choice_2_1 == 1 || choice_2_1 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 3 || choice_2_1 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 5 || choice_2_1 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_2 == 2 && a2.size() == 1) {
							choice_2_2 = 1;
						}
						else if(choice_2_2 == 4 && b2.size() == 1) {
							choice_2_2 = 3;
						}
						else if(choice_2_2 == 6 && c2.size() == 1) {
							choice_2_2 = 5;
						}
						if((choice_2_2 == 1 || choice_2_2 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 3 || choice_2_2 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 5 || choice_2_2 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(choice_2_1 == 1) {
							if(choice_2_2 == 2) {
								c1[0]->attack(*a2[0],*a2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
							}
							else if(choice_2_2 == 3) {
								c1[0]->attack(*a2[0],*b2[0]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
							}
							else if(choice_2_2 == 4) {
								c1[0]->attack(*a2[0],*b2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[0]->attack(*a2[0],*c2[0]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[0]->attack(*a2[0],*c2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 2) {
							if(choice_2_2 == 3) {
								c1[0]->attack(*a2[1],*b2[0]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
							}
							else if(choice_2_2 == 4) {
								c1[0]->attack(*a2[1],*b2[1]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[0]->attack(*a2[1],*c2[0]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 5) {
								c1[0]->attack(*a2[1],*c2[1]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 3) {
							if(choice_2_2 == 4) {
								c1[0]->attack(*b2[0],*b2[1]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[0]->attack(*b2[0],*c2[0]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[0]->attack(*b2[0],*c2[1]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 4) {
							if(choice_2_2 == 5) {
								c1[0]->attack(*b2[1],*c2[0]);
								if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[0]->attack(*b2[1],*c2[1]);
								if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 5) {
							if(choice_2_2 == 6) {
								c1[0]->attack(*c2[0],*c2[1]);
								if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else {
							cout << "По неизвестным причинам архимаг начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else if(c1[0]->name == "Иллюзионист") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(choice_2 == 1) {
						c1[0]->attack(*a2[0]);
						if(a2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin());
						}
					}
					else if(choice_2 == 2) {
						c1[0]->attack(*a2[1]);
						if(a2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin() + 1);
						}
					}
					else if(choice_2 == 3) {
						c1[0]->attack(*b2[0]);
						if(b2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin());
						}
					}
					else if(choice_2 == 4) {
						c1[0]->attack(*b2[1]);
						if(b2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin() + 1);
						}
					}
					else if(choice_2 == 5) {
						c1[0]->attack(*c2[0]);
						if(c2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin());
						}
					}
					else if(choice_2 == 6) {
						c1[0]->attack(*c2[1]);
						if(c2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам иллюзионист начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(choice == 6) {
                cout << "Выбрана карта " << c1[1]->name << endl;
                if(c1[1]->name == "Целитель") {
					cout << "Выберите союзную цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if(choice_2 == 1) {
						c1[1]->attack(*a1[0]);
					}
					else if(choice_2 == 2) {
						c1[1]->attack(*a1[1]);
					}
					else if(choice_2 == 3) {
						c1[1]->attack(*b1[0]);
					}
					else if(choice_2 == 4) {
						c1[1]->attack(*b1[1]);
					}
					else if(choice_2 == 5) {
						c1[1]->attack(*c1[0]);
					}
					else if(choice_2 == 6) {
						c1[1]->attack(*c1[1]);
					}
					else {
						cout << "По неизвестным причинам целитель начал лечить несуществующих союзников и не восстановил никому здоровье!" << endl;
					}
				}
				else if(c1[1]->name == "Заклинатель") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if(choice_2 == 1) {
						c1[1]->attack(*a2[0]);
					}
					else if(choice_2 == 2) {
						c1[1]->attack(*a2[1]);
					}
					else if(choice_2 == 3) {
						c1[1]->attack(*b2[0]);
					}
					else if(choice_2 == 4) {
						c1[1]->attack(*b2[1]);
					}
					else if(choice_2 == 5) {
						c1[1]->attack(*c2[0]);
					}
					else if(choice_2 == 6) {
						c1[1]->attack(*c2[1]);
					}
					else {
						cout << "По неизвестным причинам заклинатель начал заклинать несуществующих противников и не отнял ни у кого урон!" << endl;
					}
				}
				else if (c1[1]->name == "Архимаг") {
					cout << "Выберите две вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int choice_2_1;
					int choice_2_2;
					cin >> choice_2_1 >> choice_2_2;
					if(choice_2_1 == choice_2_2 || choice_2_1 >= choice_2_2) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(choice_2_1 == 2 && a2.size() == 1) {
							choice_2_1 = 1;
						}
						else if(choice_2_1 == 4 && b2.size() == 1) {
							choice_2_1 = 3;
						}
						else if(choice_2_1 == 6 && c2.size() == 1) {
							choice_2_1 = 5;
						}
						if((choice_2_1 == 1 || choice_2_1 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 3 || choice_2_1 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_1 == 5 || choice_2_1 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(choice_2_2 == 2 && a2.size() == 1) {
							choice_2_2 = 1;
						}
						else if(choice_2_2 == 4 && b2.size() == 1) {
							choice_2_2 = 3;
						}
						else if(choice_2_2 == 6 && c2.size() == 1) {
							choice_2_2 = 5;
						}
						if((choice_2_2 == 1 || choice_2_2 == 2) && a2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 3 || choice_2_2 == 4) && b2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((choice_2_2 == 5 || choice_2_2 == 6) && c2.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(choice_2_1 == 1) {
							if(choice_2_2 == 2) {
								c1[1]->attack(*a2[0],*a2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
							}
							else if(choice_2_2 == 3) {
								c1[1]->attack(*a2[0],*b2[0]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
							}
							else if(choice_2_2 == 4) {
								c1[1]->attack(*a2[0],*b2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[1]->attack(*a2[0],*c2[0]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[1]->attack(*a2[0],*c2[1]);
								if(a2[0]->health <= 0) {
									cout << a2[0]->name << " убит!" << endl;
									a2.erase(a2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 2) {
							if(choice_2_2 == 3) {
								c1[1]->attack(*a2[1],*b2[0]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
							}
							else if(choice_2_2 == 4) {
								c1[1]->attack(*a2[1],*b2[1]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[1]->attack(*a2[1],*c2[0]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 5) {
								c1[1]->attack(*a2[1],*c2[1]);
								if(a2[1]->health <= 0) {
									cout << a2[1]->name << " убит!" << endl;
									a2.erase(a2.begin() + 1);
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 3) {
							if(choice_2_2 == 4) {
								c1[1]->attack(*b2[0],*b2[1]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
							}
							else if(choice_2_2 == 5) {
								c1[1]->attack(*b2[0],*c2[0]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[1]->attack(*b2[0],*c2[1]);
								if(b2[0]->health <= 0) {
									cout << b2[0]->name << " убит!" << endl;
									b2.erase(b2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 4) {
							if(choice_2_2 == 5) {
								c1[1]->attack(*b2[1],*c2[0]);
								if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
								else if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
							}
							else if(choice_2_2 == 6) {
								c1[1]->attack(*b2[1],*c2[1]);
								if(b2[1]->health <= 0) {
									cout << b2[1]->name << " убит!" << endl;
									b2.erase(b2.begin() + 1);
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else if(choice_2_1 == 5) {
							if(choice_2_2 == 6) {
								c1[1]->attack(*c2[0],*c2[1]);
								if(c2[0]->health <= 0) {
									cout << c2[0]->name << " убит!" << endl;
									c2.erase(c2.begin());
								}
								else if(c2[1]->health <= 0) {
									cout << c2[1]->name << " убит!" << endl;
									c2.erase(c2.begin() + 1);
								}
							}
						}
						else {
							cout << "По неизвестным причинам архимаг начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else if(c1[1]->name == "Иллюзионист") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int choice_2;
					cin >> choice_2;
					if(choice_2 == 2 && a2.size() == 1) {
						choice_2 = 1;
					}
					else if(choice_2 == 4 && b2.size() == 1) {
						choice_2 = 3;
					}
					else if(choice_2 == 6 && c2.size() == 1) {
						choice_2 = 5;
					}
					if((choice_2 == 1 || choice_2 == 2) && a2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 3 || choice_2 == 4) && b2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((choice_2 == 5 || choice_2 == 6) && c2.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(choice_2 == 1) {
						c1[1]->attack(*a2[0]);
						if(a2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin());
						}
					}
					else if(choice_2 == 2) {
						c1[1]->attack(*a2[1]);
						if(a2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a2.erase(a2.begin() + 1);
						}
					}
					else if(choice_2 == 3) {
						c1[1]->attack(*b2[0]);
						if(b2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin());
						}
					}
					else if(choice_2 == 4) {
						c1[1]->attack(*b2[1]);
						if(b2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b2.erase(b2.begin() + 1);
						}
					}
					else if(choice_2 == 5) {
						c1[1]->attack(*c2[0]);
						if(c2[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin());
						}
					}
					else if(choice_2 == 6) {
						c1[1]->attack(*c2[1]);
						if(c2[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c2.erase(c2.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам иллюзионист начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else {
                cout << "К сожалению вы были слишком беспечны при выборе карты и потеряли свой ход!" << endl; 
            }
            if(d1.size() > 0){
				cout << "Хотите ли вы использовать какой-нибудь предмет? (y/n)" << endl;
				string choice_predmet;
				cin >> choice_predmet;
				if(choice_predmet == "y") {
					cout << "Выберите номер предмета, который вы хотите использовать..." << endl;
					int choice_3;
					cin >> choice_3;
					if(choice_3 == 8 && d1.size() ==1) {
						choice_3 = 7;
					}
					if(choice_3 == 7) {
						cout << "Выбран предмет " << d1[0]->name << endl;
						if(d1[0]->name == "Амулет") {
							cout << "Выберите союзника, которому хотите восстаановить здоровье (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[0]->use(*a1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 2) {
								d1[0]->use(*a1[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 3) {
								d1[0]->use(*b1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 4) {
								d1[0]->use(*b1[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 5) {
								d1[0]->use(*c1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 6) {
								d1[0]->use(*c1[1]);
								d1.erase(d1.begin());
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[0]->name == "Яд") {
							cout << "Выберите противника, у которого хотите отнять здоровье (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[0]->use(*a2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 2) {
								d1[0]->use(*a2[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 3) {
								d1[0]->use(*b2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 4) {
								d1[0]->use(*b2[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 5) {
								d1[0]->use(*c2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 6) {
								d1[0]->use(*c2[1]);
								d1.erase(d1.begin());
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[0]->name == "Эликсир") {
							cout << "Выберите союзника, которому хотите увеличить урон (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[0]->use(*a1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 2) {
								d1[0]->use(*a1[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 3) {
								d1[0]->use(*b1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 4) {
								d1[0]->use(*b1[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 5) {
								d1[0]->use(*c1[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 6) {
								d1[0]->use(*c1[1]);
								d1.erase(d1.begin());
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[0]->name == "Проклятие") {
							cout << "Выберите противника, которому хотите уменьшить урон (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[0]->use(*a2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 2) {
								d1[0]->use(*a2[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 3) {
								d1[0]->use(*b2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 4) {
								d1[0]->use(*b2[1]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 5) {
								d1[0]->use(*c2[0]);
								d1.erase(d1.begin());
							}
							else if(amulet_choice == 6) {
								d1[0]->use(*c2[1]);
								d1.erase(d1.begin());
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
					}
					else if(choice_3 == 8) {
						cout << "Выбран предмет " << d1[1]->name << endl;
						if(d1[1]->name == "Амулет") {
							cout << "Выберите союзника, которому хотите восстаановить здоровье (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[1]->use(*a1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 2) {
								d1[1]->use(*a1[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 3) {
								d1[1]->use(*b1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 4) {
								d1[1]->use(*b1[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 5) {
								d1[1]->use(*c1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 6) {
								d1[1]->use(*c1[1]);
								d1.erase(d1.begin() + 1);
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[1]->name == "Яд") {
							cout << "Выберите противника, у которого хотите отнять здоровье (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[1]->use(*a2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 2) {
								d1[1]->use(*a2[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 3) {
								d1[1]->use(*b2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 4) {
								d1[1]->use(*b2[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 5) {
								d1[1]->use(*c2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 6) {
								d1[1]->use(*c2[1]);
								d1.erase(d1.begin() + 1);
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[1]->name == "Эликсир") {
							cout << "Выберите союзника, которому хотите увеличить урон (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[1]->use(*a1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 2) {
								d1[1]->use(*a1[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 3) {
								d1[1]->use(*b1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 4) {
								d1[1]->use(*b1[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 5) {
								d1[1]->use(*c1[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 6) {
								d1[1]->use(*c1[1]);
								d1.erase(d1.begin() + 1);
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
						else if(d1[1]->name == "Проклятие") {
							cout << "Выберите противника, которому хотите уменьшить урон (1-6)..." << endl;
							int amulet_choice;
							cin >> amulet_choice;
							if(amulet_choice == 1) {
								d1[1]->use(*a2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 2) {
								d1[1]->use(*a2[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 3) {
								d1[1]->use(*b2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 4) {
								d1[1]->use(*b2[1]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 5) {
								d1[1]->use(*c2[0]);
								d1.erase(d1.begin() + 1);
							}
							else if(amulet_choice == 6) {
								d1[1]->use(*c2[1]);
								d1.erase(d1.begin() + 1);
							}
							else {
								cout << "Вы не выбрали ни одну из имеющихся карт, будте внимательнее в следующий раз!" << endl;
							}
						}
					}
				}
				else {
					cout << endl;
				}
			}
        }

        if(turn == -1) { // ход компьютера
            cout << "Ход компьютера..." << endl;
            int compChoice = rand() % 6;
            if(compChoice == 2 && a2.size() == 1) {
				compChoice = 1;
			}
			else if(compChoice == 4 && b2.size() == 1) {
				compChoice = 3;
			}
			else if(compChoice == 6 && c2.size() == 1) {
				compChoice = 5;
			}
			if((compChoice == 1 || compChoice ==2) && a2.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!";
			}
			else if((compChoice == 3 || compChoice ==4) && b2.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!";
			}
			else if((compChoice == 5 || compChoice ==6) && c2.empty()) {
				cout << "Бойцов больше нет, выберите другой класс!";
			}
            else if(compChoice == 1) {
                cout << "Выбрана карта " << a2[0]->name << endl;
                cout << "Выберите вражескую цель (1-6)..." << endl;
                int targetChoice = rand() % 6;
                if(targetChoice == 2 && a1.size() == 1) {
                    targetChoice = 1;
                }
                else if(targetChoice == 4 && b1.size() == 1) {
                    targetChoice = 3;
                }
                else if(targetChoice == 6 && c1.size() == 1) {
                    targetChoice = 5;
                }
                if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if(targetChoice == 1) {
                    a2[0]->attack(*a1[0]);
                    if(a1[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a1.erase(a1.begin());
                    }
                }
                else if(targetChoice == 2) {
                    a2[0]->attack(*a1[1]);
                    if(a1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a1.erase(a1.begin() + 1);
                    }
                }
                else if(targetChoice == 3) {
                    a2[0]->attack(*b1[0]);
                    if(b1[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b1.erase(b1.begin());
                    }
                }
                else if(targetChoice == 4) {
                    a2[0]->attack(*b1[1]);
                    if(b1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b1.erase(b1.begin() + 1);
                    }
                }
                else if(targetChoice == 5) {
                    a2[0]->attack(*c1[0]);
                    if(c1[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c1.erase(c1.begin());
                    }
                }
                else if(targetChoice == 6) {
                    a2[0]->attack(*c1[1]);
                    if(c1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c1.erase(c1.begin() + 1);
                    }
                }
                else {
                    cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
                }
            }
            else if(compChoice == 2) {
                cout << "Выбрана карта " << a2[1]->name << endl;
                cout << "Выберите вражескую цель (1-6)..." << endl;
                int targetChoice = rand() % 6;
                if(targetChoice == 2 && a1.size() == 1) {
                    targetChoice = 1;
                }
                else if(targetChoice == 4 && b1.size() == 1) {
                    targetChoice = 3;
                }
                else if(targetChoice == 6 && c1.size() == 1) {
                    targetChoice = 5;
                }
                if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
                    cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
                }
                else if(targetChoice == 1) {
                    a2[1]->attack(*a1[0]);
                    if(a1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a1.erase(a1.begin());
                    }
                }
                else if(targetChoice == 2) {
                    a2[1]->attack(*a1[1]);
                    if(a1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        a1.erase(a1.begin() + 1);
                    }
                }
                else if(targetChoice == 3) {
                    a2[1]->attack(*b1[0]);
                    if(b1[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b1.erase(b1.begin());
                    }
                }
                else if(targetChoice == 4) {
                    a2[1]->attack(*b1[1]);
                    if(b1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        b1.erase(b1.begin() + 1);
                    }
                }
                else if(targetChoice == 5) {
                    a2[1]->attack(*c1[0]);
                    if(c1[0]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c1.erase(c1.begin());
                    }
                }
                else if(targetChoice == 6) {
                    a2[1]->attack(*c1[1]);
                    if(c1[1]->health <= 0) {
                        cout << "Противник убит!" << endl;
                        c1.erase(c1.begin() + 1);
                    }
                }
                else {
                    cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
                }
            }
            else if(compChoice == 3) {
                cout << "Выбрана карта " << b2[0]->name << endl;
                if(b2[0]->name == "Стрелок") {
					cout << "Выберите три вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int targetChoise_1 = rand() % 6;
					int targetChoise_2 = rand() % 6;
					int targetChoise_3 = rand() % 6;
					if(targetChoise_1 == targetChoise_2 || targetChoise_1 == targetChoise_3 ||targetChoise_2 == targetChoise_3 || targetChoise_1 >= targetChoise_2 || targetChoise_1 >= targetChoise_3 || targetChoise_2 >= targetChoise_3) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(targetChoise_1 == 2 && a1.size() == 1) {
							targetChoise_1 = 1;
						}
						else if(targetChoise_1 == 4 && b1.size() == 1) {
							targetChoise_1 = 3;
						}
						else if(targetChoise_1 == 6 && c1.size() == 1) {
							targetChoise_1 = 5;
						}
						if((targetChoise_1 == 1 || targetChoise_1 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 3 || targetChoise_1 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 5 || targetChoise_1 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_2 == 2 && a1.size() == 1) {
							targetChoise_2 = 1;
						}
						else if(targetChoise_2 == 4 && b1.size() == 1) {
							targetChoise_2 = 3;
						}
						else if(targetChoise_2 == 6 && c1.size() == 1) {
							targetChoise_2 = 5;
						}
						if((targetChoise_2 == 1 || targetChoise_2 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 3 || targetChoise_2 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 5 || targetChoise_2 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_3 == 2 && a1.size() == 1) {
							targetChoise_3 = 1;
						}
						else if(targetChoise_3 == 4 && b1.size() == 1) {
							targetChoise_3 = 3;
						}
						else if(targetChoise_3 == 6 && c1.size() == 1) {
							targetChoise_3 = 5;
						}
						if((targetChoise_3 == 1 || targetChoise_3 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_3 == 3 || targetChoise_3 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_3 == 5 || targetChoise_3 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(targetChoise_1 == 1) {
							if(targetChoise_2 == 2) {
								if(targetChoise_3 == 3) {
									b2[0]->attack(*a1[0],*a1[1],*b1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
								}
								else if(targetChoise_3 == 4) {
									b2[0]->attack(*a1[0],*a1[1],*b1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[0]->attack(*a1[0],*a1[1],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[0],*a1[1],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 3) {
								if(targetChoise_3 == 4) {
									b2[0]->attack(*a1[0],*b1[0],*b1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[0]->attack(*a1[0],*b1[0],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[0],*b1[0],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[0]->attack(*a1[0],*b2[1],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[0],*b1[1],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[0],*c1[0],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 2) {
							if(targetChoise_2 == 3) {
								if(targetChoise_3 == 4) {
									b2[0]->attack(*a1[1],*b2[0],*b1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[0]->attack(*a1[1],*b1[0],*c1[0]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[1],*b1[0],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[0]->attack(*a1[1],*b1[1],*c1[0]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[1],*b1[1],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[0]->attack(*a1[1],*c1[0],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 3) {
							if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[0]->attack(*b1[0],*b1[1],*c1[0]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[0]->attack(*b1[0],*b1[1],*c1[1]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[0]->attack(*b1[0],*c1[0],*c1[1]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 4) {
							if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[0]->attack(*b1[1],*c1[0],*c1[1]);
									if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else {
							cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(targetChoice == 1) {
						b2[0]->attack(*a1[0]);
						if(a1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin());
						}
					}
					else if(targetChoice == 2) {
						b2[0]->attack(*a1[1]);
						if(a1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin() + 1);
						}
					}
					else if(targetChoice == 3) {
						b2[0]->attack(*b1[0]);
						if(b1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin());
						}
					}
					else if(targetChoice == 4) {
						b2[0]->attack(*b1[1]);
						if(b1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin() + 1);
						}
					}
					else if(targetChoice == 5) {
						b2[0]->attack(*c1[0]);
						if(c1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin());
						}
					}
					else if(targetChoice == 6) {
						b2[0]->attack(*c1[1]);
						if(c1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(compChoice == 4) {
                cout << "Выбрана карта " << b2[1]->name << endl;
                if(b2[1]->name == "Стрелок") {
					cout << "Выберите три вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int targetChoise_1 = rand() % 6;
					int targetChoise_2 = rand() % 6;
					int targetChoise_3 = rand() % 6;
					if(targetChoise_1 == targetChoise_2 || targetChoise_1 == targetChoise_3 ||targetChoise_2 == targetChoise_3 || targetChoise_1 >= targetChoise_2 || targetChoise_1 >= targetChoise_3 || targetChoise_2 >= targetChoise_3) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(targetChoise_1 == 2 && a1.size() == 1) {
							targetChoise_1 = 1;
						}
						else if(targetChoise_1 == 4 && b1.size() == 1) {
							targetChoise_1 = 3;
						}
						else if(targetChoise_1 == 6 && c1.size() == 1) {
							targetChoise_1 = 5;
						}
						if((targetChoise_1 == 1 || targetChoise_1 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 3 || targetChoise_1 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 5 || targetChoise_1 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_2 == 2 && a1.size() == 1) {
							targetChoise_2 = 1;
						}
						else if(targetChoise_2 == 4 && b1.size() == 1) {
							targetChoise_2 = 3;
						}
						else if(targetChoise_2 == 6 && c1.size() == 1) {
							targetChoise_2 = 5;
						}
						if((targetChoise_2 == 1 || targetChoise_2 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 3 || targetChoise_2 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 5 || targetChoise_2 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_3 == 2 && a1.size() == 1) {
							targetChoise_3 = 1;
						}
						else if(targetChoise_3 == 4 && b1.size() == 1) {
							targetChoise_3 = 3;
						}
						else if(targetChoise_3 == 6 && c1.size() == 1) {
							targetChoise_3 = 5;
						}
						if((targetChoise_3 == 1 || targetChoise_3 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_3 == 3 || targetChoise_3 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_3 == 5 || targetChoise_3 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(targetChoise_1 == 1) {
							if(targetChoise_2 == 2) {
								if(targetChoise_3 == 3) {
									b2[1]->attack(*a1[0],*a1[1],*b1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
								}
								else if(targetChoise_3 == 4) {
									b2[1]->attack(*a1[0],*a1[1],*b1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[1]->attack(*a1[0],*a1[1],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[0],*a1[1],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 3) {
								if(targetChoise_3 == 4) {
									b2[1]->attack(*a1[0],*b1[0],*b1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[1]->attack(*a1[0],*b1[0],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[0],*b1[0],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[1]->attack(*a1[0],*b2[1],*c1[0]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[0],*b1[1],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[0],*c1[0],*c1[1]);
									if(a1[0]->health <= 0) {
										cout << a1[0]->name << " убит!" << endl;
										a1.erase(a1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 2) {
							if(targetChoise_2 == 3) {
								if(targetChoise_3 == 4) {
									b2[1]->attack(*a1[1],*b2[0],*b1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
								}
								else if(targetChoise_3 == 5) {
									b2[1]->attack(*a1[1],*b1[0],*c1[0]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[1],*b1[0],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[1]->attack(*a1[1],*b1[1],*c1[0]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[1],*b1[1],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[1]->attack(*a1[1],*c1[0],*c1[1]);
									if(a1[1]->health <= 0) {
										cout << a1[1]->name << " убит!" << endl;
										a1.erase(a1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 3) {
							if(targetChoise_2 == 4) {
								if(targetChoise_3 == 5) {
									b2[1]->attack(*b1[0],*b1[1],*c1[0]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
								}
								else if(targetChoise_3 == 6) {
									b2[1]->attack(*b1[0],*b1[1],*c1[1]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
							else if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[1]->attack(*b1[0],*c1[0],*c1[1]);
									if(b1[0]->health <= 0) {
										cout << b1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										c1.erase(c1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else if(targetChoise_1 == 4) {
							if(targetChoise_2 == 5) {
								if(targetChoise_3 == 6) {
									b2[1]->attack(*b1[1],*c1[0],*c1[1]);
									if(b1[1]->health <= 0) {
										cout << b1[1]->name << " убит!" << endl;
										b1.erase(b1.begin() + 1);
									}
									else if(c1[0]->health <= 0) {
										cout << c1[0]->name << " убит!" << endl;
										b1.erase(b1.begin());
									}
									else if(c1[1]->health <= 0) {
										cout << c1[1]->name << " убит!" << endl;
										c1.erase(c1.begin() + 1);
									}
								}
							}
						}
						else {
							cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(targetChoice == 1) {
						b2[1]->attack(*a1[0]);
						if(a1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin());
						}
					}
					else if(targetChoice == 2) {
						b2[1]->attack(*a1[1]);
						if(a1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin() + 1);
						}
					}
					else if(targetChoice == 3) {
						b2[1]->attack(*b1[0]);
						if(b1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin());
						}
					}
					else if(targetChoice == 4) {
						b2[1]->attack(*b1[1]);
						if(b1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin() + 1);
						}
					}
					else if(targetChoice == 5) {
						b2[1]->attack(*c1[0]);
						if(c1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin());
						}
					}
					else if(targetChoice == 6) {
						b2[1]->attack(*c1[1]);
						if(c1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам воин начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(compChoice == 5) {
                cout << "Выбрана карта " << c2[0]->name << endl;
                if(c2[0]->name == "Целитель") {
					cout << "Выберите союзную цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if(targetChoice == 1) {
						c2[0]->attack(*a2[0]);
					}
					else if(targetChoice == 2) {
						c2[0]->attack(*a2[1]);
					}
					else if(targetChoice == 3) {
						c2[0]->attack(*b2[0]);
					}
					else if(targetChoice == 4) {
						c2[0]->attack(*b2[1]);
					}
					else if(targetChoice == 5) {
						c2[0]->attack(*c2[0]);
					}
					else if(targetChoice == 6) {
						c2[0]->attack(*c2[1]);
					}
					else {
						cout << "По неизвестным причинам целитель начал лечить несуществующих союзников и не восстановил никому здоровье!" << endl;
					}
				}
				else if(c2[0]->name == "Заклинатель") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if(targetChoice == 1) {
						c2[0]->attack(*a1[0]);
					}
					else if(targetChoice == 2) {
						c2[0]->attack(*a1[1]);
					}
					else if(targetChoice == 3) {
						c2[0]->attack(*b1[0]);
					}
					else if(targetChoice == 4) {
						c2[0]->attack(*b1[1]);
					}
					else if(targetChoice == 5) {
						c2[0]->attack(*c1[0]);
					}
					else if(targetChoice == 6) {
						c2[0]->attack(*c1[1]);
					}
					else {
						cout << "По неизвестным причинам заклинатель начал заклинать несуществующих противников и не отнял ни у кого урон!" << endl;
					}
				}
				else if (c2[0]->name == "Архимаг") {
					cout << "Выберите две вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int targetChoise_1;
					int targetChoise_2;
					if(targetChoise_1 == targetChoise_2 || targetChoise_1 >= targetChoise_2) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(targetChoise_1 == 2 && a1.size() == 1) {
							targetChoise_1 = 1;
						}
						else if(targetChoise_1 == 4 && b1.size() == 1) {
							targetChoise_1 = 3;
						}
						else if(targetChoise_1 == 6 && c1.size() == 1) {
							targetChoise_1 = 5;
						}
						if((targetChoise_1 == 1 || targetChoise_1 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 3 || targetChoise_1 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 5 || targetChoise_1 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_2 == 2 && a1.size() == 1) {
							targetChoise_2 = 1;
						}
						else if(targetChoise_2 == 4 && b1.size() == 1) {
							targetChoise_2 = 3;
						}
						else if(targetChoise_2 == 6 && c1.size() == 1) {
							targetChoise_2 = 5;
						}
						if((targetChoise_2 == 1 || targetChoise_2 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 3 || targetChoise_2 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 5 || targetChoise_2 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(targetChoise_1 == 1) {
							if(targetChoise_2 == 2) {
								c2[0]->attack(*a1[0],*a1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 3) {
								c2[0]->attack(*a1[0],*b1[0]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
							}
							else if(targetChoise_2 == 4) {
								c2[0]->attack(*a1[0],*b1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[0]->attack(*a1[0],*c1[0]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[0]->attack(*a1[0],*c1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 2) {
							if(targetChoise_2 == 3) {
								c2[0]->attack(*a1[1],*b1[0]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
							}
							else if(targetChoise_2 == 4) {
								c2[0]->attack(*a1[1],*b1[1]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[0]->attack(*a1[1],*c1[0]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 5) {
								c2[0]->attack(*a1[1],*c1[1]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 3) {
							if(targetChoise_2 == 4) {
								c2[0]->attack(*b1[0],*b1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[0]->attack(*b1[0],*c1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[0]->attack(*b1[0],*c1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 4) {
							if(targetChoise_2 == 5) {
								c2[0]->attack(*b1[1],*c1[0]);
								if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[0]->attack(*b1[1],*c1[1]);
								if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 5) {
							if(targetChoise_2 == 6) {
								c2[0]->attack(*c1[0],*c1[1]);
								if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else {
							cout << "По неизвестным причинам архимаг начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else if(c2[0]->name == "Иллюзионист") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(targetChoice == 1) {
						c2[0]->attack(*a1[0]);
						if(a1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin());
						}
					}
					else if(targetChoice == 2) {
						c2[0]->attack(*a1[1]);
						if(a1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin() + 1);
						}
					}
					else if(targetChoice == 3) {
						c2[0]->attack(*b1[0]);
						if(b1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin());
						}
					}
					else if(targetChoice == 4) {
						c2[0]->attack(*b1[1]);
						if(b1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin() + 1);
						}
					}
					else if(targetChoice == 5) {
						c2[0]->attack(*c1[0]);
						if(c1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin());
						}
					}
					else if(targetChoice == 6) {
						c2[0]->attack(*c1[1]);
						if(c1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам иллюзионист начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else if(compChoice == 6) {
                cout << "Выбрана карта " << c2[1]->name << endl;
                if(c2[1]->name == "Целитель") {
					cout << "Выберите союзную цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Лечить больше некого!" << endl;
					}
					else if(targetChoice == 1) {
						c2[1]->attack(*a2[0]);
					}
					else if(targetChoice == 2) {
						c2[1]->attack(*a2[1]);
					}
					else if(targetChoice == 3) {
						c2[1]->attack(*b2[0]);
					}
					else if(targetChoice == 4) {
						c2[1]->attack(*b2[1]);
					}
					else if(targetChoice == 5) {
						c2[1]->attack(*c2[0]);
					}
					else if(targetChoice == 6) {
						c2[1]->attack(*c2[1]);
					}
					else {
						cout << "По неизвестным причинам целитель начал лечить несуществующих союзников и не восстановил никому здоровье!" << endl;
					}
				}
				else if(c2[1]->name == "Заклинатель") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Заклинать больше некого!" << endl;
					}
					else if(targetChoice == 1) {
						c2[1]->attack(*a1[0]);
					}
					else if(targetChoice == 2) {
						c2[1]->attack(*a1[1]);
					}
					else if(targetChoice == 3) {
						c2[1]->attack(*b1[0]);
					}
					else if(targetChoice == 4) {
						c2[1]->attack(*b1[1]);
					}
					else if(targetChoice == 5) {
						c2[1]->attack(*c1[0]);
					}
					else if(targetChoice == 6) {
						c2[1]->attack(*c1[1]);
					}
					else {
						cout << "По неизвестным причинам заклинатель начал заклинать несуществующих противников и не отнял ни у кого урон!" << endl;
					}
				}
				else if (c2[1]->name == "Архимаг") {
					cout << "Выберите две вражеские цели в порядке возрастания номеров (1-6)..." << endl;
					int targetChoise_1;
					int targetChoise_2;
					if(targetChoise_1 == targetChoise_2 || targetChoise_1 >= targetChoise_2) {
						cout << "Выбранные цели должны быть разными и идти в порядке возрастания!" << endl;
					}
					else {
						if(targetChoise_1 == 2 && a1.size() == 1) {
							targetChoise_1 = 1;
						}
						else if(targetChoise_1 == 4 && b1.size() == 1) {
							targetChoise_1 = 3;
						}
						else if(targetChoise_1 == 6 && c1.size() == 1) {
							targetChoise_1 = 5;
						}
						if((targetChoise_1 == 1 || targetChoise_1 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 3 || targetChoise_1 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_1 == 5 || targetChoise_1 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						if(targetChoise_2 == 2 && a1.size() == 1) {
							targetChoise_2 = 1;
						}
						else if(targetChoise_2 == 4 && b1.size() == 1) {
							targetChoise_2 = 3;
						}
						else if(targetChoise_2 == 6 && c1.size() == 1) {
							targetChoise_2 = 5;
						}
						if((targetChoise_2 == 1 || targetChoise_2 == 2) && a1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 3 || targetChoise_2 == 4) && b1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if((targetChoise_2 == 5 || targetChoise_2 == 6) && c1.empty()) {
							cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
						}
						else if(targetChoise_1 == 1) {
							if(targetChoise_2 == 2) {
								c2[1]->attack(*a1[0],*a1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 3) {
								c2[1]->attack(*a1[0],*b1[0]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
							}
							else if(targetChoise_2 == 4) {
								c2[1]->attack(*a1[0],*b1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[1]->attack(*a1[0],*c1[0]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[1]->attack(*a1[0],*c1[1]);
								if(a1[0]->health <= 0) {
									cout << a1[0]->name << " убит!" << endl;
									a1.erase(a1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 2) {
							if(targetChoise_2 == 3) {
								c2[1]->attack(*a1[1],*b1[0]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
							}
							else if(targetChoise_2 == 4) {
								c2[1]->attack(*a1[1],*b1[1]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[1]->attack(*a1[1],*c1[0]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 5) {
								c2[1]->attack(*a1[1],*c1[1]);
								if(a1[1]->health <= 0) {
									cout << a1[1]->name << " убит!" << endl;
									a1.erase(a1.begin() + 1);
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 3) {
							if(targetChoise_2 == 4) {
								c2[1]->attack(*b1[0],*b1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
							}
							else if(targetChoise_2 == 5) {
								c2[1]->attack(*b1[0],*c1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[1]->attack(*b1[0],*c1[1]);
								if(b1[0]->health <= 0) {
									cout << b1[0]->name << " убит!" << endl;
									b1.erase(b1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 4) {
							if(targetChoise_2 == 5) {
								c2[1]->attack(*b1[1],*c1[0]);
								if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
								else if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
							}
							else if(targetChoise_2 == 6) {
								c2[1]->attack(*b1[1],*c1[1]);
								if(b1[1]->health <= 0) {
									cout << b1[1]->name << " убит!" << endl;
									b1.erase(b1.begin() + 1);
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else if(targetChoise_1 == 5) {
							if(targetChoise_2 == 6) {
								c2[1]->attack(*c1[0],*c1[1]);
								if(c1[0]->health <= 0) {
									cout << c1[0]->name << " убит!" << endl;
									c1.erase(c1.begin());
								}
								else if(c1[1]->health <= 0) {
									cout << c1[1]->name << " убит!" << endl;
									c1.erase(c1.begin() + 1);
								}
							}
						}
						else {
							cout << "По неизвестным причинам архимаг начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
						}
					}
				}
				else if(c2[1]->name == "Иллюзионист") {
					cout << "Выберите вражескую цель (1-6)..." << endl;
					int targetChoice = rand() % 6;
					if(targetChoice == 2 && a1.size() == 1) {
						targetChoice = 1;
					}
					else if(targetChoice == 4 && b1.size() == 1) {
						targetChoice = 3;
					}
					else if(targetChoice == 6 && c1.size() == 1) {
						targetChoice = 5;
					}
					if((targetChoice == 1 || targetChoice == 2) && a1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 3 || targetChoice == 4) && b1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if((targetChoice == 5 || targetChoice == 6) && c1.empty()) {
						cout << "Бойцов больше нет. Бить лежачих - это аморально!" << endl;
					}
					else if(targetChoice == 1) {
						c2[1]->attack(*a1[0]);
						if(a1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin());
						}
					}
					else if(targetChoice == 2) {
						c2[1]->attack(*a1[1]);
						if(a1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							a1.erase(a1.begin() + 1);
						}
					}
					else if(targetChoice == 3) {
						c2[1]->attack(*b1[0]);
						if(b1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin());
						}
					}
					else if(targetChoice == 4) {
						c2[1]->attack(*b1[1]);
						if(b1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							b1.erase(b1.begin() + 1);
						}
					}
					else if(targetChoice == 5) {
						c2[1]->attack(*c1[0]);
						if(c1[0]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin());
						}
					}
					else if(targetChoice == 6) {
						c2[1]->attack(*c1[1]);
						if(c1[1]->health <= 0) {
							cout << "Противник убит!" << endl;
							c1.erase(c1.begin() + 1);
						}
					}
					else {
						cout << "По неизвестным причинам иллюзионист начал сражаться с несуществующим противником и не нанес никому урона!" << endl;
					}
				}
            }
            else {
                cout << "К сожалению вы были слишком беспечны при выборе карты и потеряли свой ход!" << endl; 
            }
           
        }
        if(a2.empty() && b2.empty() && c2.empty()) { //конец сражения
            cout << "Вы победили в сражении!" << endl;
            break;
        }
        if(a1.empty() && b1.empty() && c1.empty()) {
            cout << "Все ваши воины убиты, вы больше не можете сражаться!" << endl;
            break;
        }

        turn *= -1;
    }

    return 0;
}
