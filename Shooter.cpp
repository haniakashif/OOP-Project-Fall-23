#include "Shooter.h"

void Shooter::shoot_up(gameObject *shooter)
{
    gameObject *bullet = new Bullet();
    bullet->set_velocity(0, -3);
    bullet->load(shooter->get_x(), shooter->get_y() - 30, 8, 15, "bullet", 0, 18);
}

void Shooter::shoot_down(gameObject *shooter)
{
    gameObject *bullet = new Bullet();
    bullet->set_velocity(0, 3);
    bullet->load(shooter->get_x(), shooter->get_y() + 30, 8, 15, "bullet", 35, 18);
}

void Shooter::shoot_left(gameObject *shooter)
{
    gameObject *bullet = new Bullet();
    bullet->set_velocity(-3, 0);
    bullet->load(shooter->get_x() - 30, shooter->get_y() + 15, 15, 9, "bullet", 0, 9);
}

void Shooter::shoot_right(gameObject *shooter)
{
    gameObject *bullet = new Bullet();
    bullet->set_velocity(3, 0);
    bullet->load(shooter->get_x() + 30, shooter->get_y() + 15, 15, 9, "bullet", 0, 0);
}

void Shooter::shoot(gameObject *shooter, int x, int y)
{
    gameObject *bullet = new Bullet();
    bullet->set_velocity(x, y);
    bullet->load(shooter->get_x() + x, shooter->get_y() + y, 15, 9, "bullet", 0, 0);
}

Shooter *Shooter::instance = nullptr;

Shooter *Shooter::Instance()
{
    if (instance == nullptr)
    {
        instance = new Shooter();
    }
    return instance;
}