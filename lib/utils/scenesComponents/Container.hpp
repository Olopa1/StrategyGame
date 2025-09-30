#pragma once

#include "Component.hpp"


class Container : Component{
protected:

    void setTargetPosition(){
        if(boundingRect){
            boundingRect->setPosition(originalPosition);
            boundingRect->move(sf::Vector2f(margin,margin));
        }

    }
    std::shared_ptr<sf::RectangleShape> boundingRect;
    float margin = 0.0f;
    float padding = 0.0f;
    sf::Vector2f originalPosition;
public:

    Container() = default;
    Container(sf::Vector2f containerSize, float margin = 0, float padding = 0){
        this->margin = margin;
        this->padding = padding;
        containerSize.x += padding * 2;
        containerSize.y += padding * 2;
        boundingRect = std::make_shared<sf::RectangleShape>(containerSize);
    }

    void setMargin(float margin){
        this->margin = margin;
        this->setTargetPosition();
    }

    void setPadding(float padding){
        this->padding = padding;
    }

    void setContainerPosition(sf::Vector2f &position){
        originalPosition = position;
        setTargetPosition();
    }

    sf::Vector2f getContainerSize(){
        if(boundingRect){
            return this->boundingRect->getSize();
        }
    }

    sf::Vector2f getContainerPos(){
        return boundingRect->getPosition();
    }

    void setBackgroundColor(sf::Color color){
        boundingRect->setFillColor(color);
    }

    void setBorderColor(sf::Color color){
        boundingRect->setOutlineColor(color);
    }

    void setBorderSize(float size){
        boundingRect->setOutlineThickness(size);
    }
    virtual void displayComponents(sf::RenderWindow &window) = 0;
    
    ~Container() = default;
};


