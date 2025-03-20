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
