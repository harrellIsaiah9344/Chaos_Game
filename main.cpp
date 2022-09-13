#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>

using namespace sf;
int main()
{
    
    VideoMode win(1280,960);
    
    Window window(win,"Chaos Game",Style::Fullscreen);
    Event event;
    Mouse mouse1;
    Keyboard keyboard1;
    std::vector<int> points; 
    while (window.pollEvent(event))
    {
            if(event.type == Event::MouseLeft && points.size() < 6)
            {
            points.push_back(mouse1.getPosition(window).x);
            points.push_back(mouse1.getPosition(window).y);
            }

        
        
     
   
    
    }
    if(keyboard1.Escape)
        {
            window.close();
        }
    for(int i = 0; i < 6; i++)
    {
        std::cout << points[i] << endl;
    }
}