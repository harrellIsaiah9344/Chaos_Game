#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>

using namespace sf;
int main()
{
    VideoMode win(1280,960);
    
    Window window(win,"Chaos Game",Style::Fullscreen);

    std::vector<int> points; 
    RectangleShape DrawPoints();
    while (window.isOpen())
    {
        while(points.size() < 3)
        {
            if(Mouse::isButtonPressed(Mouse::Left))
            {
            points.push_back(Mouse::getPosition(window).x);
            points.push_back(Mouse::getPosition(window).y);
            }
        }
    
    }

}