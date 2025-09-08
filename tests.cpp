#include <gtest/gtest.h>
#include "game.hpp"

// Проверка корректной инициализации Pehota
TEST(CharacterTest, PehotaInitialization) {
    Pehota p;
    EXPECT_EQ(p.attack_distance, 1);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 1);
    EXPECT_EQ(p.fraction, "Воин");
    EXPECT_EQ(p.name, "Пехота");
}

// Проверка атаки Pehota по другому персонажу
TEST(CharacterTest, PehotaAttack) {
    Pehota p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Pehota с неправильной дистанцией
TEST(CharacterTest, PehotaAttackOutOfRange) {
    Pehota p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Vor
TEST(CharacterTest, VorInitialization) {
    Vor p;
    EXPECT_EQ(p.attack_distance, 1);
    EXPECT_EQ(p.damage, 2);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 1);
    EXPECT_EQ(p.fraction, "Воин");
    EXPECT_EQ(p.name, "Вор");
}

// Проверка атаки Vor по другому персонажу
TEST(CharacterTest, VorAttack) {
    Vor p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Vor с неправильной дистанцией
TEST(CharacterTest, VorAttackOutOfRange) {
    Vor p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Berserk
TEST(CharacterTest, BerserkInitialization) {
    Berserk p;
    EXPECT_EQ(p.attack_distance, 1);
    EXPECT_EQ(p.damage, 5);
    EXPECT_EQ(p.health, 6);
    EXPECT_EQ(p.distance, 1);
    EXPECT_EQ(p.fraction, "Воин");
    EXPECT_EQ(p.name, "Берсерк");
}

// Проверка атаки Berserk по другому персонажу
TEST(CharacterTest, BerserkAttack) {
    Berserk p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Berserk с неправильной дистанцией
TEST(CharacterTest, BerserkAttackOutOfRange) {
    Berserk p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Paladin
TEST(CharacterTest, PaladinInitialization) {
    Paladin p;
    EXPECT_EQ(p.attack_distance, 1);
    EXPECT_EQ(p.damage, 4);
    EXPECT_EQ(p.health, 11);
    EXPECT_EQ(p.distance, 1);
    EXPECT_EQ(p.fraction, "Воин");
    EXPECT_EQ(p.name, "Паладин");
}

// Проверка атаки Paladin по другому персонажу
TEST(CharacterTest, PaladinAttack) {
    Paladin p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Paladin с неправильной дистанцией
TEST(CharacterTest, PaladinAttackOutOfRange) {
    Paladin p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Strelok
TEST(CharacterTest, StrelokInitialization) {
    Strelok p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Лучник");
    EXPECT_EQ(p.name, "Стрелок");
}

// Проверка атаки Strelok по другому персонажу
TEST(CharacterTest, StrelokAttack) {
    Strelok p;
    Person* enemy_1 = new Pehota();
    Person* enemy_2 = new Pehota();
    Person* enemy_3 = new Pehota();
    int initial_health_1 = enemy_1->health;
    int initial_health_2 = enemy_2->health;
    int initial_health_3 = enemy_3->health;
    
    p.attack(*enemy_1, *enemy_2, *enemy_3);
    EXPECT_LE(enemy_1->health, initial_health_1); // здоровье должно уменьшиться или остаться (если промах)
    EXPECT_LE(enemy_2->health, initial_health_2);
    EXPECT_LE(enemy_3->health, initial_health_3);
    
    delete enemy_1;
    delete enemy_2;
    delete enemy_3;
}

// Проверка атаки Strelok с неправильной дистанцией
TEST(CharacterTest, StrelokAttackOutOfRange) {
    Strelok p;
    Person* enemy_1 = new Pehota();
    Person* enemy_2 = new Pehota();
    Person* enemy_3 = new Pehota();
    enemy_1->distance = 5; // Вне диапазона атаки
    enemy_2->distance = 5;
    enemy_3->distance = 5;
    int initial_health_1 = enemy_1->health;
    int initial_health_2 = enemy_2->health;
    int initial_health_3 = enemy_3->health;
    
    p.attack(*enemy_1, *enemy_2, *enemy_3);
    EXPECT_EQ(enemy_1->health, initial_health_1); // здоровье не должно измениться
    EXPECT_LE(enemy_2->health, initial_health_2);
    EXPECT_LE(enemy_3->health, initial_health_3);
    
    delete enemy_1;
    delete enemy_2;
    delete enemy_3;
}

// Проверка корректной инициализации Eger
TEST(CharacterTest, EgerInitialization) {
    Eger p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Лучник");
    EXPECT_EQ(p.name, "Егерь");
}

// Проверка атаки Eger по другому персонажу
TEST(CharacterTest, EgerAttack) {
    Eger p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Eger по магу
TEST(CharacterTest, EgerAttack_1) {
    Eger p;
    Person* enemy = new Celitel();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Eger с неправильной дистанцией
TEST(CharacterTest, EgerAttackOutOfRange_1) {
    Eger p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Antimag
TEST(CharacterTest, AntimagInitialization) {
    Antimag p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Антимаг");
    EXPECT_EQ(p.name, "Антимаг");
}

// Проверка атаки Antimag по другому персонажу
TEST(CharacterTest, AntimagAttack) {
    Antimag p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Antimag с неправильной дистанцией
TEST(CharacterTest, AntimagAttackOutOfRange) {
    Antimag p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Assasin
TEST(CharacterTest, AssasinInitialization) {
    Assasin p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Лучник");
    EXPECT_EQ(p.name, "Ассасин");
}

// Проверка атаки Assasin по другому персонажу
TEST(CharacterTest, AssasinAttack) {
    Assasin p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Assasin с неправильной дистанцией
TEST(CharacterTest, AssasinAttackOutOfRange) {
    Assasin p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Celitel
TEST(CharacterTest, CelitelInitialization) {
    Celitel p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.heal, 2);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Маг");
    EXPECT_EQ(p.name, "Целитель");
}

// Проверка атаки Celitel по другому персонажу
TEST(CharacterTest, CelitelAttack) {
    Celitel p;
    Person* ally = new Pehota();
    int initial_health = ally->health;
    
    p.attack(*ally);
    EXPECT_GE(ally->health, initial_health); // здоровье должно увеличиться или остаться (если промах)
    
    delete ally;
}

// Проверка атаки Celitel с неправильным здоровьем
TEST(CharacterTest, CelitelAttackOutOfRange) {
    Celitel p;
    Person* ally = new Pehota();
    ally->health = -1; // Вне диапазона атаки
    int initial_health = ally->health;
    
    p.attack(*ally);
    EXPECT_EQ(ally->health, initial_health); // здоровье не должно измениться
    
    delete ally;
}

// Проверка корректной инициализации Zaclinatel
TEST(CharacterTest, Zaclinatelnitialization) {
    Zaclinatel p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 1);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Маг");
    EXPECT_EQ(p.name, "Заклинатель");
}

// Проверка атаки Zaclinatel по другому персонажу
TEST(CharacterTest, ZaclinatelAttack) {
    Zaclinatel p;
    Person* enemy = new Pehota();
    int initial_damage = enemy->damage;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->damage, initial_damage); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Zaclinatel с неправильной дистанцией
TEST(CharacterTest, ZaclinatelAttackOutOfRange) {
    Zaclinatel p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_damage = enemy->damage;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->damage, initial_damage); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Arhimag
TEST(CharacterTest, ArhimagInitialization) {
    Arhimag p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Маг");
    EXPECT_EQ(p.name, "Архимаг");
}

// Проверка атаки Arhimag по другому персонажу
TEST(CharacterTest, ArhimagAttack) {
    Arhimag p;
    Person* enemy_1 = new Pehota();
    Person* enemy_2 = new Pehota();
    int initial_health_1 = enemy_1->health;
    int initial_health_2 = enemy_2->health;
    
    p.attack(*enemy_1, *enemy_2);
    EXPECT_LE(enemy_1->health, initial_health_1); // здоровье должно уменьшиться или остаться (если промах)
    EXPECT_LE(enemy_2->health, initial_health_2);
    
    delete enemy_1;
    delete enemy_2;
}

// Проверка атаки Arhimag с неправильной дистанцией
TEST(CharacterTest, ArhimagAttackOutOfRange) {
    Arhimag p;
    Person* enemy_1 = new Pehota();
    Person* enemy_2 = new Pehota();
    enemy_1->distance = 5; // Вне диапазона атаки
    enemy_2->distance = 5;
    int initial_health_1 = enemy_1->health;
    int initial_health_2 = enemy_2->health;
    
    p.attack(*enemy_1, *enemy_2);
    EXPECT_EQ(enemy_1->health, initial_health_1); // здоровье не должно измениться
    EXPECT_LE(enemy_2->health, initial_health_2);
    
    delete enemy_1;
    delete enemy_2;
}

// Проверка корректной инициализации Illuzionist
TEST(CharacterTest, IlluzionistInitialization) {
    Illuzionist p;
    EXPECT_EQ(p.attack_distance, 2);
    EXPECT_EQ(p.damage, 3);
    EXPECT_EQ(p.health, 10);
    EXPECT_EQ(p.distance, 2);
    EXPECT_EQ(p.fraction, "Иллюзионист");
    EXPECT_EQ(p.name, "Иллюзионист");
}

// Проверка атаки Illuzionist по другому персонажу
TEST(CharacterTest, IlluzionistAttack) {
    Illuzionist p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}

// Проверка атаки Illuzionist с неправильной дистанцией
TEST(CharacterTest, IlluzionistAttackOutOfRange) {
    Illuzionist p;
    Person* enemy = new Pehota();
    enemy->distance = 5; // Вне диапазона атаки
    int initial_health = enemy->health;
    
    p.attack(*enemy);
    EXPECT_EQ(enemy->health, initial_health); // здоровье не должно измениться
    
    delete enemy;
}

// Проверка корректной инициализации Amulet
TEST(CharacterTest, AmuletInitialization) {
    Amulet p;
    EXPECT_EQ(p.fraction, "Предмет");
    EXPECT_EQ(p.name, "Амулет");
}

// Проверка использования Amulet на персонаже
TEST(CharacterTest, AmuletUse) {
    Amulet p;
    Person* ally = new Pehota();
    int initial_health = ally->health;
    
    p.use(*ally);
    EXPECT_GE(ally->health, initial_health); // здоровье должно увеличиться или остаться (если промах)
    
    delete ally;
}

// Проверка использвания Amulet с неправильнм здоровьем
TEST(CharacterTest, AmuletUseOutOfRange) {
    Amulet p;
    Person* ally = new Pehota();
    ally->health = -1; // Вне диапазона использования
    int initial_health = ally->health;
    
    p.use(*ally);
    EXPECT_EQ(ally->health, initial_health); // здоровье не должно измениться
    
    delete ally;
}

// Проверка корректной инициализации Yad
TEST(CharacterTest, YadInitialization) {
    Yad p;
    EXPECT_EQ(p.fraction, "Предмет");
    EXPECT_EQ(p.name, "Яд");
}

// Проверка использования Yad на другом персонаже
TEST(CharacterTest, YadUse) {
    Yad p;
    Person* enemy = new Pehota();
    int initial_health = enemy->health;
    
    p.use(*enemy);
    EXPECT_LE(enemy->health, initial_health); // здоровье должно уменьшиться или остаться (если промах)
    
    delete enemy;
}


// Проверка корректной инициализации Eleksir
TEST(CharacterTest, EleksirInitialization) {
    Eleksir p;
    EXPECT_EQ(p.fraction, "Предмет");
    EXPECT_EQ(p.name, "Эликсир");
}

// Проверка использования Eleksir на персонаже
TEST(CharacterTest, EleksirUse) {
    Eleksir p;
    Person* ally = new Pehota();
    int initial_damage = ally->damage;
    
    p.use(*ally);
    EXPECT_GE(ally->damage, initial_damage); // здоровье должно увеличиться или остаться (если промах)
    
    delete ally;
}

// Проверка корректной инициализации Proklyatie
TEST(CharacterTest, ProklyatieInitialization) {
    Proklyatie p;
    EXPECT_EQ(p.fraction, "Предмет");
    EXPECT_EQ(p.name, "Проклятие");
}

// Проверка использования Proklyatie на персонаже
TEST(CharacterTest, ProklyatieUse) {
    Proklyatie p;
    Person* enemy = new Pehota();
    int initial_damage = enemy->damage;
    
    p.use(*enemy);
    EXPECT_LE(enemy->damage, initial_damage); // здоровье должно увеличиться или остаться (если промах)
    
    delete enemy;
}
