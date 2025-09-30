#pragma once 

#include <SFML/Graphics.hpp>
#include <map>

class ResourceManager{
public:
    sf::Font& getFont(const std::string &path){
        if(this->fonts.find(path) == this->fonts.end()){
            auto newFont = std::make_unique<sf::Font>();
            if(!newFont->openFromFile(path)){
                throw std::runtime_error("Cannot load path to font. Path: " + path);
            }
        }
        return *this->fonts[path];
    };

    sf::Texture& getTexure(const std::string &path){
        if(this->textures.find(path) == this->textures.end()){
            auto newTexture = std::make_unique<sf::Texture>();
            if(!newTexture->loadFromFile(path)){
                throw std::runtime_error("Cannot load path to texture. Path: " + path);
            }
        }
        return *this->textures[path];
    };

    void setFont(const std::string &fontKey, const std::string &fontPath){
        auto newFont = std::make_unique<sf::Font>();
        if(!newFont->openFromFile(fontPath)){
            throw std::runtime_error("Cannot load path to font. Path: " + fontPath);
        }
        this->fonts.emplace(fontKey,std::move(newFont));
    }

private:
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
    
};