
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
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>


#define WIDTH  300
#define HEIGHT 300


using namespace sf;
using namespace Metaballs;



void drawBuffer(sf::Image * buffer, sf::Texture * texture, sf::Sprite * sprite, sf::RenderWindow& window)
{
    // Sprite buffer   
    texture->loadFromImage(*buffer);    
    sprite->setTexture(*texture);    
    
    window.draw(*sprite);

}


int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Metaballs - Jorge Barcena", sf::Style::Default, ContextSettings(32));
    
    // Buffer
    sf::Texture * texture = new sf::Texture();
    sf::Sprite  * sprite = new sf::Sprite();
    sf::Image   * buffer = new sf::Image();

    buffer->create(WIDTH, HEIGHT, sf::Color(0, 0, 0));
    const sf::Uint8* ptr = buffer->getPixelsPtr();
    std::vector<sf::Uint8> pixels(ptr, ptr + WIDTH * HEIGHT * 4);

    Ball::window = &window;
    Ball::window_size = toolkit::Vector2f({ WIDTH, HEIGHT });

    window.setVerticalSyncEnabled(true);

    bool running = true;

    /* initialize random seed: */
    srand(time(NULL));

    std::vector<Ball*> agents;

    for (size_t i = 0; i < 5; i++)
    {
        agents.push_back(new Ball(
            Helper::generateRandom(5,12),
            toolkit::Vector2f({ Helper::generateRandom(0, 1), Helper::generateRandom(0, 1) }),
            Helper::generateRandom(1,3),
            toolkit::Vector2f({ Helper::generateRandom(0, WIDTH), Helper::generateRandom(0, HEIGHT) })));

    }

    do
    {
        // Process window events:

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
            
        }

        Ball::Update(0);

        // Render:
        window.clear();

        sf::Uint8* pixel_ptr = pixels.data();

        for (unsigned int x = 0; x < WIDTH; ++x)
        {
            for (unsigned int y = 0; y < HEIGHT; ++y)
            {
                float sum = 0;

                for (auto agent : agents)
                {
                    float d = 1 / Helper::distance(toolkit::Vector2f({ x,y }), agent->position);
                    sum += 500 * agent->radius * d;

                }
               
                auto color = Helper::getColorInScreenRange((int)sum, 255, 255, WIDTH, HEIGHT);

                color = Helper::hsv(color.r, color.g, color.b);

                *(pixel_ptr++) = color.r;
                *(pixel_ptr++) = color.g;
                *(pixel_ptr++) = color.b;
                *(pixel_ptr++) = color.a;



            }

        }


        buffer->create(WIDTH, HEIGHT, pixels.data());      
        drawBuffer(buffer, texture, sprite, window);
       
        window.display();

    } while (running);


    return EXIT_SUCCESS;
}
