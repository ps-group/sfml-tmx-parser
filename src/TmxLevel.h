#pragma once

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>

struct TmxObject
{
    int GetPropertyInt(std::string name);
    float GetPropertyFloat(std::string name);
    std::string GetPropertyString(std::string name);

    void MoveBy(const sf::Vector2f &movement);
    void MoveTo(const sf::Vector2f &position);

    std::string name;
    std::string type;
    sf::IntRect rect;
    std::map<std::string, std::string> properties;

	sf::Sprite sprite;
};

struct TmxLayer
{
    int opacity;
    std::vector<sf::Sprite> tiles;
};

class TmxLevel
{
public:
    bool LoadFromFile(const std::string &filepath);

    TmxObject GetObject(const std::string &name)const;
    std::vector<TmxObject> GetObjects(const std::string &name)const;
    sf::Vector2i GetTileSize()const;

    // Принимает любую цель для рисования, например, sf::RenderWindow.
    void Draw(sf::RenderTarget &target)const;

private:
    int m_width;
    int m_height;
    int m_tileWidth;
    int m_tileHeight;
    int m_firstTileID;
    sf::FloatRect m_drawingBounds;
    sf::Texture m_tilesetImage;
    std::vector<TmxObject> m_objects;
    std::vector<TmxLayer> m_layers;
};
