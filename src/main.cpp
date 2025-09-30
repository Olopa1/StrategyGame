#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AppContext.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "ContainerH.hpp"
using namespace std;

int main()
{
    AppContext appContext;
    appContext.resourceManager.setFont("default","C:\\dominik_rzeczy\\programy\\gra\\StrategyGame\\static\\fonts\\comic.ttf");
    auto window = sf::RenderWindow(sf::VideoMode({appContext.config.windowWidht, appContext.config.windowHeight}), "CMake SFML Project");
    Button component = Button(sf::Vector2f(100.0f, 100.0f), appContext);
    component.setPosAbsolute(sf::Vector2f(100.0f,100.0f));
    window.setFramerateLimit(appContext.config.fpsCap);

    ContainerH container(sf::Vector2f(1000, 500), 10, 10);
    
    container.setBackgroundColor(sf::Color::Yellow);
    container.setBorderSize(5);
    container.setBorderColor(sf::Color::Red);
    
    container.setContainerPosition(sf::Vector2f(100,0));

    for (int i = 0 ; i < 5; i++){
        auto btn = std::make_shared<Button>(sf::Vector2f(100.0f, 100.0f), appContext);
        btn->setText(std::string("Btn"));
        container.addComponent(btn);    
    }
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

        container.displayComponents(window);
        sf::sleep(sf::milliseconds(100));
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
