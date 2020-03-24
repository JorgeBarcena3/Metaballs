
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Ángel on november of 2017                                       *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  angel.rodriguez@esne.edu                                                   *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MODEL2D_HEADER
#define MODEL2D_HEADER

#include <vector>
#include <SFML\Graphics\Color.hpp>
#include <SFML/Graphics.hpp>
#include <Vector.hpp>


using namespace toolkit;
namespace sf { class RenderWindow; }

namespace Metaballs
{


    class Model2D
    {

       
    public:

        typedef toolkit::Vector2f Vector2f;
        // Atributos de transformación:

        Vector2f	  position;
        float		  angle;
        float		  scale;

        // Atributos de animación:

        sf::Color     polygonColor;



    public:

        Model2D()
        {
           

        }


        void set_position(float x, float y)
        {
            position = Vector2f({ x, y });
        }

        void set_angle(float new_angle)
        {
            angle = new_angle;
        }

        void set_scale(float new_scale)
        {
            scale = new_scale;
        }

        void set_color(sf::Color new_color)
        {
            polygonColor = new_color;
        }

        void update(float delta)
        {
        }

        void render();

    };

}

#endif
