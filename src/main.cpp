#include <SFML/Graphics.hpp>


//Declaring functions
void drawJeopardySquares(sf::RectangleShape shape, sf::RenderWindow& window);


int main()
{

    // Jeopardy Boxes as rect
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Blue);
    rect.setSize(sf::Vector2f(1920/6, 1080/6));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(3);



    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
/*
 *
 *  get mouse position over boxes for clicks
 *
 *
 *
 *
 */


        window.clear();

        drawJeopardySquares(rect, window);

        window.display();
    }
}


void drawJeopardySquares(sf::RectangleShape shape, sf::RenderWindow& window)
{
    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            shape.setPosition(sf::Vector2f(x * (1920 / 6), y * (1080u / 6)));
            window.draw(shape);
        }
    }
};