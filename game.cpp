#include "game.hpp"

using namespace std;

Pehota::Pehota()
{
	attack_distance = 1;
	damage = 3;
	health = 10;
	distance = 1;
	fraction = "Воин";
	name = "Пехота";
}

void Pehota::attack(Person& a) {
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

void Pehota::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Pehota::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}


Vor::Vor()
{
	attack_distance = 1;
	damage = 2;
	health = 10;
	distance = 1;
	fraction = "Воин";
	name = "Вор";
}
    
void Vor::attack(Person& a) {
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
void Vor::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Vor::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}


void Berserk::attack(Person& a) {
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

void Berserk::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}	
}
void Berserk::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Paladin::attack(Person& a) {
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

void Paladin::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}	
}
void Paladin::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Celitel::attack(Person& a) {
	if(a.health > 0) {
		a.health += heal;
		cout << "Вы восстановили " << heal << " здоровья" << " у " << a.name << endl;
	}
	else {
		cout << a.name << " мертв, ему нельзя восстановить здоровье!" << endl;
	}
}

void Celitel::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Celitel::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Zaclinatel::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Zaclinatel::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}	
}

void Zaclinatel::attack(Person& a) {
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

void Arhimag::attack(Person&a) {
	if (a.distance == 564) {
		cout << "Сюрприз" << endl;
	}
}
void Arhimag::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Arhimag::attack(Person& a, Person& b) {
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

void Illuzionist::attack(Person &a) {
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

void Illuzionist::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Illuzionist::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Strelok::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Strelok::attack(Person&a) {
	if (a.distance == 564) {
		cout << "Сюрприз" << endl;
	}
}
void Strelok::attack(Person &a, Person &b, Person &c) {
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

void Eger::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Eger::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Eger::attack(Person &a) {
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

void Antimag::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Antimag::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Antimag::attack(Person &a) {
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

void Assasin::attack(Person&a, Person&b) {
	if (a.distance == b.distance) {
		cout << "Сюрприз!" << endl;
	}
}
void Assasin::attack(Person&a, Person&b, Person&c) {
	if (a.distance == b.distance && a.distance == c.distance) {
		cout << "Сюрприз!" << endl;
	}
}

void Assasin::attack(Person &a) {
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

void Amulet::use(Person &a) {
	if(a.health > 0) {
		a.health += 5;
		cout << "Вы увеличили здоровье " << a.name << " на 5 единиц" << endl;
	}
	else
	{
		cout << a.name << " мертв, ему нелзя восстановить здоровье!" << endl;
	}
}

void Yad::use(Person &a) {
	a.health -= 4;
	cout << "Вы уменьшили здоровье " << a.name << " на 4 единицы" << endl;
}

void Eleksir::use(Person &a) {
	a.damage +=1;
	cout << "Вы повысили урон " << a.name << " на 1 единицу" << endl;
}

void Proklyatie::use(Person &a) {
	if(a.damage >=2 ) {
		a.damage -= 1;
		cout << "Вы понизили урон " << a.name << " на 1 единицу" << endl;
	}
	else {
		cout << "У противника итак предельно низкий урон, отбирать последнее - некрасиво!" << endl;
	}
}
