#pragma once
#include "Ball.hpp"
#include <vector>

class Physics {
  public:
    Physics(double timePerTick = 0.001);
    //Граница
    void setWorldBox(const Point& topLeft, const Point& bottomRight);
    // Основной метод, двжижок
    void update(std::vector<Ball>& balls, size_t ticks) const;

  private:
    // столкновение шаров
    void collideBalls(std::vector<Ball>& balls) const;
    // столкновение с границами
    void collideWithBox(std::vector<Ball>& balls) const;
    // меняем позицию шаров
    void move(std::vector<Ball>& balls) const;
    void processCollision(Ball& a, Ball& b,
                          double distanceBetweenCenters2) const;

  private:
    Point topLeft;
    Point bottomRight;
    double timePerTick;
};
