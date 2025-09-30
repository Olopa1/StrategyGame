#pragma once

#include "Component.hpp"
#include <iostream>
class Button: public Component
{
protected:
    void onClick() override{
        std::cout<<"Button clocked";
    }
    void onHover() override{
        std::cout<<"Button hovered";
    }
    void onDrag() override{
        std::cout<<"Dragged";
    }


public:
    Button(sf::Vector2f &rectangleSize, AppContext &appContext, std::string fontName = "default") :
    Component(rectangleSize,appContext,fontName){
        this->setText(std::string("Button"));
        ComponentStatesColor temp;
        temp.normalColor = sf::Color::Cyan;
        temp.hoverColor = sf::Color(255,100,10);
        temp.clickedColor = sf::Color::Green;
        this->setMainColors(temp);
        temp.clickedColor = temp.hoverColor = temp.clickedColor = sf::Color::Red;
        this->setBorderColors(temp);
        this->setBorderSize(5);
    }
    ~Button() = default;
};
