#pragma once

#include <stdint.h>
#include <list>
#include <math.h>
#include <thread>
#include <SFML/Graphics.hpp>
#include "AppContext.hpp"

#define DEFAULT_FONT "default"

enum ShapeType{
    CIRCLE = 0,
    RECTANGLE,
    CONVEX,
};

struct ComponentStatesColor{
    sf::Color normalColor;
    sf::Color clickedColor;
    sf::Color hoverColor;
};

struct ComponentStatesTexture{
    std::shared_ptr<sf::Texture> normalTexture;
    std::shared_ptr<sf::Texture> clickedTexture;
    std::shared_ptr<sf::Texture> hoverTexture;
};


class Component : public sf::Drawable
{
protected:
    //fields
    std::shared_ptr<sf::Shape> componentShape = nullptr;
    std::shared_ptr<sf::Text> componentText = nullptr;
    std::thread onClickThread;
    std::thread onClicjDrag;
    std::thread onClickHover;
    bool isMovable = false;
    struct ComponentStatesColor componenetMainColors;
    struct ComponentStatesColor componentBorderColors;
    struct ComponentStatesTexture componentTextures;

    //methods
    virtual void draw(sf::RenderTarget &targer, sf::RenderStates states) const override;
    void setTextToCenter();
    void startListener();

    virtual void onClick() = 0; 
    virtual void onHover() = 0;
    virtual void onDrag() = 0;

    // to implement"
    void changeColorToClick();
    void changeColorToNormal();
    void changeColorToHover();
public:
    Component() = default;
    Component(sf::Vector2f &rectangleSize, AppContext &appContext, std::string fontName = DEFAULT_FONT);
    Component(float radius, AppContext &appContext,std::size_t pointCount = 30, std::string fontName = DEFAULT_FONT);
    Component(std::list<sf::Vector2f> &vectors, size_t points_count, AppContext &appContext, std::string fontName = DEFAULT_FONT);


    
    void setMainColors(const ComponentStatesColor &colors);
    void setBorderColors(const ComponentStatesColor &colors);
    void setBorderSize(float size);
    void setPosAbsolute(sf::Vector2f &position);
    void setPosRelativeToParent(sf::Vector2f &position, sf::Vector2f &marginOffset);
    void move(sf::Vector2f &offset);
    void setText(std::string &text);
    void eventListener(const sf::Event &event,const sf::RenderWindow &window);
    sf::Vector2f getComponentSize();
    ~Component() = default;
};