#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>

using namespace sf;
int main()
{
    VideoMode win(1280,960);
    
    Window window(win,"Chaos Game",Style::Fullscreen);

    std::vector<int> points; 
    while (window.isOpen())
    {
            if(Mouse::isButtonPressed(Mouse::Left) && points.size() < 6)
            {
            points.push_back(Mouse::getPosition(window).x);
            points.push_back(Mouse::getPosition(window).y);
            }
        }
    
    }
}