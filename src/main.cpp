#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Physics Simulation");
    window.setFramerateLimit(60);
    //draw shape on window 
    sf::CircleShape ball(75);

    //Variables
    float startX = 50.0f;
    float startY = 50.0f;
    float xVelocityInitial = 5.0f;
    float yVelocityInitial = 0.0f;
    float accelX = 0.0f;
    float accelY = 9.8f;
    float currentX = startX;
    float currentY = startY;
    float previousVx = xVelocityInitial;
    float previousVy = yVelocityInitial;
    double dt = 0.05f;

    ball.setFillColor(sf::Color(255,165,0));
    ball.setPosition({startX, startY});

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //PHYSICS
        //CALCLUATION BALL VELOCITY
        float currentVx = previousVx + accelX * dt;
        float currentVy = previousVy + accelY * dt;
        previousVx = currentVx;
        previousVy = currentVy;
        //CALCULATION FOR BALL'S NEXT POSITION
        float nextX = currentX + (currentVx * dt);
        float nextY = currentY + (currentVy * dt);
        ball.setPosition({nextX,nextY});
        currentX = nextX;
        currentY = nextY;


        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        window.draw(ball);
        // end the current frame
        window.display();
        
    }





    // auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    // window.setFramerateLimit(144);

    // while (window.isOpen())
    // {
    //     while (const std::optional event = window.pollEvent())
    //     {
    //         if (event->is<sf::Event::Closed>())
    //         {
    //             window.close();
    //         }
    //     }

    //     window.clear();
    //     window.display();
    // }

 
}