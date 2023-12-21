#pragma once

#include "bullet.h"
#include "enemy_bullet.h"

class Shooter
{
private:
    Shooter() {}
    static Shooter *instance;

public:
    void shoot_up(gameObject *shooter);
    void shoot_down(gameObject *shooter);
    void shoot_left(gameObject *shooter);
    void shoot_right(gameObject *shooter);
    void shoot(gameObject *shooter, int x, int y);
    void enemy_shoot(gameObject *shooter, int x, int y);
    static Shooter *Instance();
};

typedef Shooter TheShooter;