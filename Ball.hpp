#pragma once

#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {

private:
    Point    m_point;                               // координаты ценр шара (x,y)
    Velocity m_velocity;                            // скорость шара (vx, vy)

    double m_r;                                     // радиус (r)

    double m_color_red;                             // цвет шара {r,g,b}
    double m_color_green;
    double m_color_blue;

    bool   m_isCollidable;                          // участвует ли шар в столкновении     
                               
    double m_mass;                                  // масса шара

public:
    void setVelocity(const Velocity& velocity);     // задать скорость шара
    Velocity getVelocity() const;
    void draw(Painter& painter) const;              // для отображения шара
    void setCenter(const Point& center);            // координаты центра шара
    Point getCenter() const;        
    double getRadius() const;
    double getMass() const;
};
