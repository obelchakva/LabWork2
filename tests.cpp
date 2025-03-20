#include <gtest/gtest.h>
#include "game.cpp" // Подключаем исходный файл, так как нет отдельного game.h

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
