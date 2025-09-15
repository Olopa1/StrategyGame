#pragma once

#include <stdint.h>
#include <list>
#include <SFML/Graphics.hpp>
#include "AppContext.hpp"

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
    bool isMovable = false;
    struct ComponentStatesColor componenetMainColors;
    struct ComponentStatesColor componentBorderColors;
    struct ComponentStatesTexture componentTextures;

    //methods
    virtual void draw(sf::RenderTarget &targer, sf::RenderStates states) const override;

public:
    Component() = default;
    Component(sf::Vector2f &rectangleSize, AppContext &appContext, std::string fontName = "default");
    Component(float radius, AppContext &appContext,std::size_t pointCount = 30, std::string fontName = "default");
    Component(std::list<sf::Vector2f> &vectors, size_t points_count, AppContext &appContext, std::string fontName = "default");

    virtual void onClick() = 0; 
    virtual void onHover() = 0;
    virtual void onDrag() = 0;
    
    void setMainColors(const ComponentStatesColor &colors);
    void setBorderColors(const ComponentStatesColor &colors);
    void setBorderSize(float size);
    ~Component() = default;
};