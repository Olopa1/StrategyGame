#pragma once

#include "Container.hpp"
#include <list>

class ContainerH : public Container
{
private:
    void recalculatePos(){
        float cumWidth = padding;
        sf::Vector2f parentPos = boundingRect->getPosition();
        for(auto component : componments){
            component->setPosRelativeToParent(parentPos, sf::Vector2f(cumWidth, padding));
            cumWidth += component->getComponentSize().x + padding;
        }
    };
    std::list<std::shared_ptr<Component>> componments;

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
    ContainerH(sf::Vector2f containerSize, float margin = 0, float padding = 0) : Container(containerSize, margin, padding){};

    void addComponent(std::shared_ptr<Component> component){
        if(component)
            componments.push_back(component);
    };

    void addComponent(std::shared_ptr<Component> component, uint32_t position){
        if(component){
            componments.insert(std::next(componments.begin(), position), component);
        }
    };

    std::shared_ptr<Component> getComponent(uint32_t position){
        if(position >= componments.size()) return nullptr;
        return *std::next(componments.begin(), position);
    }

    std::shared_ptr<Component> removeComponent(uint32_t position){
        if(position >= componments.size()) return nullptr;
        auto removedElement = componments.erase(std::next(componments.begin(), position));
        return *removedElement;
    };

    void displayComponents(sf::RenderWindow &window) override{
        window.draw(*boundingRect);
        this->recalculatePos();
        for(auto component : componments){
           window.draw(*component);
        }
    }

    void clearContainer(){
        componments.clear();
    }


    ~ContainerH() = default;
};   