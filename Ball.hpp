#pragma once

#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

#include "Color.hpp"

class Ball {

private:
    Point    m_point;                               // координаты ценр шара (x,y)
    Velocity m_velocity;                            // скорость шара (vx, vy)
    Color    m_color;

    double m_radius{-1};                            // радиус (r)

    // double m_color_red;                          // цвет шара {r,g,b}
    // double m_color_green;
    // double m_color_blue;

    bool   m_isCollidable;                          // участвует ли шар в столкновении     
                               
    double m_mass;                                  // масса шара

public:

    Ball(){}
    Ball(const Point& center, const Velocity& velocity
        , const Color& color, const double radius, const bool isCol)
    : m_point(center)
    , m_velocity(velocity)
    , m_color(color)
    , m_radius(radius)
    , m_isCollidable(isCol){
        
        m_mass = (4.0/3.0) * M_PI * std::pow(m_radius, 3); 
    }

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
};
