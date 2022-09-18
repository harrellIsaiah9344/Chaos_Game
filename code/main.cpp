#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
using namespace std;

int main()
{
    //declarations
    Event event;
    int j = 0;
    //window
    VideoMode win(1920, 1080, 32);
    RenderWindow window(win, "Chaos Game", Style::Default);
   
    //font declaration
    Font font;
    font.loadFromFile("arial.ttf");
    Text textbox("Please Click between 3 to 5 times in order to set the vertices", font, 15);
    textbox.setFillColor(sf::Color::Green);
    textbox.setOutlineColor(sf::Color::Red);
    textbox.setScale(2.4, 2.5);
    textbox.setStyle(sf::Text::Bold);
    textbox.setPosition(1920 / 4, 1080 / 4);
    
    //Mouse mouse1;
    vector<Vector2f> vertices;
    vector<Vector2f> points;
    Vector2f clicked;
    Vector2f randomPoint;
    RectangleShape rect(Vector2f(2, 2));
    rect.setPosition(1920 / 2, 1080 / 2);

    //draws inital prompt too click three times
    window.draw(textbox);
    window.display();
    sf::sleep(sf::seconds(2));
    window.clear();
    window.display();
    window.clear();
    window.display();

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                window.clear();
                window.display();
                //checks if left mouse button is clicked. If yes then pushback x and y position to vector of vertices
                //and displays point that was just clicked.
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    clicked.x = event.mouseButton.x;
                    clicked.y = event.mouseButton.y;
                    vertices.push_back(clicked);
                    rect.setPosition(vertices[j]);
                    window.draw(rect);
                    window.display();
                    j++;
                }
                //checks if right mouse button has been clicked. If it has it checks to see if 3 vetices have been passed
                //before running loop that will print out the pyramid
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (vertices.size() == 3)
                    {

                        textbox.setString("You have enough vertices now");
                        textbox.setFillColor(sf::Color::Green);
                        textbox.setOutlineColor(sf::Color::Green);
                        textbox.setPosition(0,0);
                        window.draw(textbox);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        window.clear();
                        window.display();
                        window.clear();
                        window.display();

                        int randomVertice;
                        randomPoint.x = event.mouseButton.x;
                        randomPoint.y = event.mouseButton.y;
                        points.push_back(randomPoint);
                        for (int i = 0; i < 50000; i++)
                        {
                            randomVertice = rand() % 3;
                            randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                            randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            window.draw(rect);
                            window.display();
                        }
                    }
                    //same algorithm accept with 4 vertices(square)
                    else if (vertices.size() == 4)
                    {
                        textbox.setFillColor(sf::Color::Green);
                        textbox.setOutlineColor(sf::Color::Green);
                        textbox.setString("You have enough vertices now");
                        textbox.setPosition(0, 0);
                        window.draw(textbox);
                        int randomVertice;
                        randomPoint.x = event.mouseButton.x;
                        randomPoint.y = event.mouseButton.y;
                        points.push_back(randomPoint);
                        for (int i = 0; i < 50000; i++)
                        {
                            randomVertice = rand() % 4;
                            randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                            randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            textbox.setFillColor(sf::Color::Transparent);
                            textbox.setOutlineColor(sf::Color::Transparent);
                            window.draw(rect);
                            window.display();
                        }
                    }
                    //same algorithm accept with 5 vertices(pentagon)
                    else if (vertices.size() == 5)
                    {
                      
                        textbox.setString("You have enough vertices now");
                        textbox.setFillColor(sf::Color::Green);
                        textbox.setOutlineColor(sf::Color::Green);
                        textbox.setPosition(0, 0);
                        window.draw(textbox);
                        int randomVertice;
                        randomPoint.x = event.mouseButton.x;
                        randomPoint.y = event.mouseButton.y;
                        points.push_back(randomPoint);
                        for (int i = 0; i < 100000; i++)
                        {
                            randomVertice = rand() % 5;
                            randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                            randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            textbox.setFillColor(sf::Color::Transparent);
                            textbox.setOutlineColor(sf::Color::Transparent);
                            window.draw(rect);
                            window.display();
                        }
                    }
                    //If less thent 3 error message
                    else if (vertices.size() < 3)
                    {
                        textbox.setString("Please make sure to set \n 3 vertices before Right Clicking! \n Thank You!");
                        window.draw(textbox);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        window.clear();
                        window.display();
                        window.clear();
                        window.display();
                    }
                    else if (vertices.size() > 5)
                    {
                        textbox.setString("Too many Vertices! Try Again!");
                        window.draw(textbox);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        window.close();
                    }

                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}