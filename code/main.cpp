
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    VideoMode win(1920,1080,32);
    
    RenderWindow window(win,"Chaos Game",Style::Default);
    Event event;
    //Mouse mouse1;
    vector<Vector2f> vertices;
    vector<Vector2f> points;
    Vector2f clicked;

    RectangleShape rect(Vector2f(10,10));
    rect.setPosition(1920/2,1080/2);
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {   
            if(event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        window.clear();
        window.draw(rect);
        window.display();
    }
}