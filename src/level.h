#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

struct Object
{
    int GetPropertyInt(std::string name);
    float GetPropertyFloat(std::string name);
    std::string GetPropertyString(std::string name);

    std::string name;
    std::string type;
    sf::Rect<int> rect;
    std::map<std::string, std::string> properties;

	sf::Sprite sprite;
};

struct Layer
{
    int opacity;
    std::vector<sf::Sprite> tiles;
};

class Level
{
public:
    bool LoadFromFile(const std::string &filepath);

    Object GetObject(const std::string &name)const;
    std::vector<Object> GetObjects(const std::string &name)const;
    void Draw(sf::RenderWindow &window)const;
    sf::Vector2i GetTileSize()const;

private:
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;
    int m_firstTileID;
    sf::Rect<float> m_drawingBounds;
    sf::Texture m_tilesetImage;
    std::vector<Object> m_objects;
    std::vector<Layer> m_layers;
};
