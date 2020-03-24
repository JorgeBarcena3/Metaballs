
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Ball.hpp"
#include "../headers/MathHelper.hpp"

#define PI   3.1415
#define PI2  2 * PI
#define RAD  PI / 180

using namespace Metaballs;
using namespace sf;

//Inicializacion de la lista de balls
std::vector<Ball*> Ball::instances = {};

sf::RenderWindow* Ball::window = nullptr;

toolkit::Vector2f Ball::window_size = toolkit::Vector2f({0,0});

/*
* Divide la esfera en vertices de igual distancia
*/
Metaballs::Ball::Ball(
    float             _radius,
    Vector2f          _direction,
    float             _speed,
    Vector2f          _startPosition) : Model2D({ })
{

    radius = _radius;                                    // Radio
    set_position(_startPosition[0], _startPosition[1]);  // Posicionamos la pelota en esa posicion
    direction = _direction;
    speed = _speed;
    Ball::instances.push_back(this);                     //Añadimos el objeto a la lista de entidades

}

/*
* Busca la siguiente posicion de la pelota
*/
void Ball::update(float delta)
{
    limits();

    Helper::normalize(&direction);
    direction *= speed;
    set_position(position[0] + direction[0], position[1] + direction[1]);

    Model2D::update(delta);
};

void Metaballs::Ball::limits()
{   

    if (position[0] < 0)
    {
        direction[0] *= -1;
    }
    else if (position[0] > Ball::window_size[0])
    {
        direction[0] *= -1;

    }

    if (position[1] < 0)
    {
        direction[1] *= -1;
    }
    else if (position[1] > Ball::window_size[1])
    {
        direction[1] *= -1;
    }
}
