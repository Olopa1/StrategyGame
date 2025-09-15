#include "Widget.h"

void Widget::addComponent(std::string name, std::shared_ptr<sf::Drawable> component){
    this->components[name] = component;
};

void Widget::freeResources(){
    this->components.clear();
}


