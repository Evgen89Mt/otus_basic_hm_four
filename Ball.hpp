#pragma once

#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

#include "Color.hpp"

class Ball {

private:
    Point    m_point;                               
    Velocity m_velocity;                            
    Color    m_color;

    // double m_x, m_y, m_xv, m_yv;
    // double m_color_red;                             // цвет шара {r,g,b}
    // double m_color_green;
    // double m_color_blue;

    double m_radius{-1};                            

    bool   m_isCollidable;                          
                               
    double m_mass;                                  



public:
    // Ball(){}
    // Ball(const double x, const double y, const double xv, const double yv
    //     , const double red, const double green, const double blue
    //     , const double radius, bool isCollidable)
    //     :m_x(x), m_y(y), m_xv(xv), m_yv(yv)
    //     ,m_color_red(red), m_color_green(green), m_color_blue(blue)
    //     ,m_radius(radius),m_isCollidable(isCollidable){
    //     // m_point.x = x;
    //     // m_point.y = y;
    //     // m_velocity.setVector(Point{xv, yv});
    //     // m_color = Color {red,green, blue};
    //     m_mass = (4.0/3.0) * M_PI * std::pow(m_radius, 3); 
    // }

    Ball(const Point& center, const Velocity& velocity
        , const Color& color, const double radius, const bool isCol)
    : m_point(center)
    , m_velocity(velocity)
    , m_color(color)
    , m_radius(radius)
    , m_isCollidable(isCol){
        m_mass = (4.0/3.0) * M_PI * std::pow(m_radius, 3); 
    }

    Ball(const double x, const double y, const double vx, const double vy
        , const double red, const double green, const double blue
        , const double radius, bool isCollidable)
        : m_point(Point{x,y})
        // , m_velocity(Velocity{vx, vy})
        , m_velocity(Point{vx,vy})
        , m_color(Color{red, green, blue})
        , m_radius(radius)
        , m_isCollidable(isCollidable)
        {
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
