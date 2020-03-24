
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef BALL_HEADER
#define BALL_HEADER

#include "Model2D.hpp"
#include <SFML/Graphics.hpp>

using namespace toolkit;

namespace Metaballs
{


    /*
    * Maneja un objeto del tipo Ball
    */
    class Ball : public Model2D
    {

    public:

        static std::vector<Ball*>    instances;           //Instancias de los Ball

        static sf::RenderWindow *    window;              // Instancia de la ventana de render

        static toolkit::Vector2f     window_size; // Tamaño de la pantalla


    public:
        
        float                         radius;         // Radio

        toolkit::Vector2f             direction;      // Radio

        float                         speed;          // Velocidad

    public:

        /*
        * Contructor que recibe los parametros de como va a ser la pelota en cuestion
        */
        Ball(
            float             _radius,
            Vector2f          _direction,
            float             _speed,
            Vector2f          _startPosition
        );
      
        /*
        * Busca la siguiente posicion de la pelota
        */
        void update(float delta);
  

        /*
        * No permitimos que se salga de un limite
        */
        void limits();

        /*
        * Llama a la funcion update() de todos las pelotas almacenados
        */
        static void Update(float delta)
        {
            for (Ball* ball : instances)
            {
                ball->update(delta);
            }
        };

       
    };

}

#endif