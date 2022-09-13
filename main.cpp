#include <SFML/Graphics.hpp>
#include <RectangleShape.hpp>
#include <SFML/Window.hpp>
#include <Font.hpp>
#include <Text.hpp>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
using namespace sf;

//Documentation https://www.sfml-dev.org/documentation/2.5.1/index.php

int main()
{
        // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Welcome to Chaos game! Click three random points in window to begin!!!!!!!", font, 50);
    

    VideoMode win(1280,960);
    
    Window window(win,"Chaos Game",Style::Fullscreen);

// Opening window and testing

    std::vector<int> points.s; 
    RectangleShape rect{Vector2f{20,20}};

    //setposition for rectangle
    rect.setPosition(1920/2 1080/2);
    rect.setFillColor(Color::Blue);
    
    //clear everything form last run frame
    window.clear();
    //other stuff
    window.draw();
    window.display();

    vector<Vector2f> vertices;
    vector<Vector2f> points;

    RectangleShape DrawPoints();
    DrawPoints.setSize(1);
    // draw main window
    Event event;
    while (window.isOpen())
    {

        while(points.size() < 3)
        {
            //mouse click event
            if(Mouse::isButtonPressed(Mouse::Left))
            {
                cout << " the left mouse was clicked!" << endl;
                cout << " mouse x:: " << event.mouseButton.x << endl;
                cout << " mouse y:: " << event.mouseButton.y << endl;
                points.push_back(Mouse::getPosition(window).x);
                points.push_back(Mouse::getPosition(window).y);
                Rect1(points[0],points[1]);
                clicked.x = event.mouseButton.x;
                clicked.x = event.mouseButton.y;
            }
        }



    
    }
    

}

