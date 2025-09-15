#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

class Widget
{


public:
    
    Widget(/* args */);
    ~Widget();

    void setupWidget(std::map<std::string,std::shared_ptr<sf::Drawable>> components);
    void drawWidget();
    void addComponent(std::string name, std::shared_ptr<sf::Drawable> component);
    int closeWidget();
protected:
    std::map<std::string,std::shared_ptr<sf::Drawable>> components;
    void freeResources();

};
