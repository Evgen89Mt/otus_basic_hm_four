#include "Ball.hpp"
#include <cmath>

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    m_velocity = velocity;

    // Point tmp{velocity.vector()};
    // m_xv = tmp.x;
    // m_yv = tmp.y;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return m_velocity;
    // return Velocity{Point(m_xv,m_yv)};
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки

    std::cout << "Drawing ball at (" << m_point.x << ", " << m_point.y << ") radius " 
    << m_radius << std::endl;

    painter.draw(m_point, m_radius, m_color);
    //void draw(const Point& center, double radius, const Color& color);

    // Point pt(m_x,m_y);
    // Color col(m_color_red, m_color_green, m_color_blue);
    // painter.draw(pt, m_radius, col);
}



/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    // m_point.x = center.x;
    // m_point.y = center.y;

    m_point = center;
    // m_x = center.x; m_y = center.y;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    return m_point;

    // return Point(m_x, m_y);
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return m_radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    return m_mass;
}