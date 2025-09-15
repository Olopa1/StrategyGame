#include <SFML/Graphics.hpp>
#include <iostream>
#include "AppContext.hpp"
using namespace std;

int main()
{
    AppContext appContext;

    auto window = sf::RenderWindow(sf::VideoMode({appContext.config.windowWidht, appContext.config.windowHeight}), "CMake SFML Project");
    window.setFramerateLimit(appContext.config.fpsCap);
    sf::ConvexShape polygon;
    polygon.setPointCount(3);
    polygon.setPoint(0, sf::Vector2f(0, 0));
    polygon.setPoint(1, sf::Vector2f(0, 20));
    polygon.setPoint(2, sf::Vector2f(25, 5));
    polygon.setOutlineColor(sf::Color::Red);
    polygon.setOutlineThickness(5);
    polygon.setPosition({100, 100});


    try{
        sf::Font font("C:\\dominik_rzeczy\\programy\\gra\\StrategyGame\\static\\fonts\\comic.ttf");
        sf::Text text(font);

        text.setCharacterSize(30);
        text.setFillColor(sf::Color::Blue);
        text.setOutlineColor(sf::Color::White);
        text.setString("Tekst");


    while (window.isOpen())
    {
        


        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(polygon);
        window.draw(text);
        window.display();
    }
        }catch(std::exception e){
        e.what();
        char c;
        std::cin >> c; 
        //    return 0;


    }
}
