
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
    Mouse mouse1;
    vector<Vector2f> vertices;
    vector<Vector2f> points;
    Vector2f clicked;

    RectangleShape rect(Vector2f(10,10));
    rect.setPosition(1920/2,1080/2);
    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {

            if(event.type == Event::MouseLeft && vertices.size() < 3)
            {
                clicked.x = event.mouseButton.x;
                clicked.y = event.mouseButton.y;
            vertices.push_back(clicked);
            }
            else if (event.mouseButton.button == Mouse::Right)
            {
                cout << "goodbye";
            }
            else if(event.KeyPressed == Keyboard::Escape)
            {
                window.close();
            }

        }
    window.clear();
    window.draw(rect);
    
   window.display();
    }
}