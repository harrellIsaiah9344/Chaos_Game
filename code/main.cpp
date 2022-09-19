#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
using namespace sf;
using namespace std;

int main()
{
    //declarations
    Event event;
    int j = 0;
    srand((int)time(0));
    //window
    VideoMode win(1920, 1080, 32);
    RenderWindow window(win, "Chaos Game", Style::Default);
    
    //sounds
    SoundBuffer cheerBuffer;
    cheerBuffer.loadFromFile("Cheer.wav");
    Sound cheer;
    cheer.setBuffer(cheerBuffer);

    SoundBuffer kazooBuffer;
    kazooBuffer.loadFromFile("Kazoo.wav");
    Sound Kazoo;
    Kazoo.setBuffer(kazooBuffer);
   
    SoundBuffer BeepBuffer;
    BeepBuffer.loadFromFile("Beep.wav");
    Sound Beep;
    Beep.setBuffer(BeepBuffer);

   
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
    vector<Vector2f> vertices, lastvertices,lastLastVertices;
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
                Beep.play();
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
                            //Making random point half way away from our planted vertices
                            randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                            randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                            //putting this point in a vector and printing it to screen
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            window.draw(rect);
                            window.display();
                        }
                        cheer.play();
                        Kazoo.play();
                    }
                    //same algorithm accept with 4 vertices(square)
                    else if (vertices.size() == 4)
                    {
                        textbox.setFillColor(sf::Color::Green);
                        textbox.setOutlineColor(sf::Color::Green);
                        textbox.setString("You have enough vertices now");
                        textbox.setPosition(0, 0);
                        window.draw(textbox);
                        int randomVertice , lastvert = 0;
                        //generate a random point for the half way point
                        randomPoint.x = 1920/2;
                        randomPoint.y = 1000/2;
                        points.push_back(randomPoint);
                        for (int i = 0; i < 20000; i++)
                        {
                            randomVertice = rand() % 4;
                            if (randomVertice != lastvert)
                            {

                                //Making random point half way away from our planted vertices
                                randomPoint.x = (points[i].x + vertices[randomVertice].x) / 2;
                                randomPoint.y = (points[i].y + vertices[randomVertice].y) / 2;
                                //putting this point in a vector and printing it to screen
                                points.push_back(randomPoint);
                                rect.setPosition(points[i]);
                                window.draw(rect);
                                window.display();
                            }
                            else
                            {
                                points.push_back(randomPoint);
                            }
                            //making or current point the last one
                            lastvert = randomVertice;
                        }
                        cheer.play();
                        Kazoo.play();
                    }
                    //same algorithm accept with 5 vertices(pentagon)
                    else if (vertices.size() == 5)
                    {
                        float scalar = 5 / 8.0;
                        textbox.setString("You have enough vertices now");
                        textbox.setFillColor(sf::Color::Green);
                        textbox.setOutlineColor(sf::Color::Green);
                        textbox.setPosition(0, 0);
                        window.draw(textbox);
                        int randomVertice, lastvert, lastlastvert = 0;
                        randomPoint.x = 1920 / 2;
                        randomPoint.y = 1080 / 2;
                        points.push_back(randomPoint);
                        for (int i = 0; i < 10000; i++)
                        {
                            randomVertice = rand() % 5;
                            //Making random point half way away from our planted vertices
                            randomPoint.x = points[i].x + (vertices[randomVertice].x - points[i].x) * scalar;
                            randomPoint.y = points[i].y + (vertices[randomVertice].y - points[i].y) * scalar;
                            //putting this point in a vector and printing it to screen
                            points.push_back(randomPoint);
                            rect.setPosition(points[i]);
                            window.draw(rect);
                            window.display();
                        }
                        cheer.play();
                        Kazoo.play();
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