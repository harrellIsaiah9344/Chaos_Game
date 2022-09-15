
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    VideoMode win(1920,1080,32);
    Font font;
    font.loadFromFile("./batmfa__.ttf");
    Text textbox("Please Click 3 times in order to set the vertices",font,12);
    textbox.setFillColor(sf::Color::Green);
    textbox.setOutlineColor(sf::Color::Red);
    textbox.setScale(2.4,2.5);
    textbox.setStyle(sf::Text::Bold);
    textbox.setPosition(1920/4,1080/4);
    RenderWindow window(win,"Chaos Game",Style::Default);
    Event event;
    //Mouse mouse1;
    vector<Vector2f> vertices;
    vector<Vector2f> points;
    Vector2f clicked;
    Vector2f randomPoint;
    window.draw(textbox);
    window.display();
    RectangleShape rect(Vector2f(1,1));
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
                    clicked.x = event.mouseButton.x;
                    clicked.y = event.mouseButton.y;
                    vertices.push_back(clicked);
                }
                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    if(vertices.size() >= 3)
                    {
                        window.clear();
                        int randomVertice;
                        randomPoint.x = event.mouseButton.x;
                        randomPoint.y = event.mouseButton.y;
                        points.push_back(randomPoint);
                        for(int i = 0; i < 500000; i++)
                        {
                            randomVertice = rand() % 3;
                            randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                            randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            window.draw(rect);
                        }
                        textbox.setString("You have enough vertices now");
                        textbox.setPosition(0,0);
                        window.draw(textbox);
                        window.display();
                    }
                    else{
                        textbox.setString("Please make sure to set \n 3 vertices before Right Clicking! \n Thank You!");
                        window.clear();
                        window.draw(textbox);
                        window.display();
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        
    }
}