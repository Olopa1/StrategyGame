#include "Component.hpp"

void Component::setMainColors(const ComponentStatesColor &colors){
    this->componenetMainColors = colors;
    if(this->componentShape){
        this->componentShape->setFillColor(colors.normalColor);
    }
}

void Component::setBorderColors(const ComponentStatesColor &colors){
    this->componentBorderColors = colors;
    if(this->componentShape){
        this->componentShape->setOutlineColor(colors.normalColor);
    }
}

void Component::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    if(this->componentShape && this->componentText){
        target.draw(*this->componentShape, states);
        target.draw(*this->componentText, states);
    }
}

void Component::setBorderSize(float size){
    if(size >= 0 || this->componentShape){
        this->componentShape->setOutlineThickness(size);
    }
}

Component::Component(sf::Vector2f &rectangleSize, AppContext &appContext, std::string fontName){
    auto rectanghleShape = std::make_shared<sf::RectangleShape>(rectangleSize);
    this->componentShape = rectanghleShape;
    this->componentText = std::make_shared<sf::Text>(appContext.resourceManager.getFont(fontName), "");
}

Component::Component(float radius, AppContext &appContext, std::size_t pointCount,std::string fontName){
    auto circleShape = std::make_shared<sf::CircleShape>(radius,pointCount);
    this->componentShape = circleShape;
    this->componentText = std::make_shared<sf::Text>(appContext.resourceManager.getFont(fontName), "");
}

Component::Component(std::list<sf::Vector2f> &vectors, size_t points_count, AppContext &appContext, std::string fontName){
    if(vectors.size() != points_count) throw std::runtime_error("Cannot create convex shaped component.\nNumber of vectors must be the same as number of poitns.");
    auto convexShape = std::make_shared<sf::ConvexShape>();
    convexShape->setPointCount(points_count);
    auto listElement = vectors.begin();
    for(size_t i = 0 ; i < points_count;i++){
        convexShape->setPoint(i,*listElement);
        listElement++;
    }
    this->componentText = std::make_shared<sf::Text>(appContext.resourceManager.getFont(fontName), "");
}

void Component::setTextToCenter(){
    if(this->componentShape && this->componentText){
        auto currentShapePos = this->componentShape->getPosition();
        auto currentShapeBoundingRect = this->componentShape->getGlobalBounds();
        auto currentTextBoundingRect = this->componentText->getGlobalBounds();
        float xOffsetForText = abs(currentShapeBoundingRect.size.x/2 - currentTextBoundingRect.size.x/2);
        float yOffsetForText = abs(currentShapeBoundingRect.size.y/2 - currentTextBoundingRect.size.y/2);
        sf::Vector2f newTextPos(currentShapePos.x + xOffsetForText, currentShapePos.y + yOffsetForText);
        this->componentText->setPosition(newTextPos);
    }
}

void Component::setPosAbsolute(sf::Vector2f &position){
    if(this->componentShape){
        this->componentShape->setPosition(position);
        this->setTextToCenter();
    }
}

void Component::setPosRelativeToParent(sf::Vector2f &position, sf::Vector2f &marginOffset){
    if(this->componentShape){
        this->componentShape->setPosition(position);
        this->componentShape->move(marginOffset);
        this->setTextToCenter();
    }
}

void Component::move(sf::Vector2f &offset){
    if(this->componentShape && this->componentText){
        this->componentShape->move(offset);
        this->componentText->move(offset);
    }
}

void Component::setText(std::string &text){
    if(this->componentShape && this->componentText){
        this->componentText->setString(text);
        this->setTextToCenter();
    }
}

void Component::eventListener(const sf::Event &event,const sf::RenderWindow &window){
    if(event.is<sf::Event::MouseButtonPressed>()){
        std::thread clickT(
            [this](){
                this->onClick();
            });
    }
}

sf::Vector2f Component::getComponentSize(){
    return this->componentShape->getGlobalBounds().size;
}