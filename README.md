## Tiled Map Editor loader for SFML

This repository contains:

- `src/TmxLevel.h` and `src/TmxLevel.cpp` &mdash; `*.tmx` file parser
- `lib/tinyxml2/tinyxml2.h` and `lib/tinyxml2/tinyxml2.cpp` &mdash; external library Tinyxml2 used to parse TMX format
- `src/GameScene.h`, `src/GameScene.cpp`, `src/GameView.h`, `src/GameView.cpp`, `src/main.cpp` &mdash; small demo application

My apprecations to:
- TMX loader class based on this article: [habrahabr.ru/post/199064](https://habrahabr.ru/post/199064/)
- Original author http://en.sfml-dev.org/forums/index.php?topic=3023.0

Improvements comparing to original article:

- Optimized drawing: used faster object visiting in Debug builds and view rectangle clipping before draw:

```cpp
void TmxLevel::Draw(sf::RenderTarget &target)const
{
    const sf::FloatRect viewportRect = target.getView().getViewport();

    // Draw all tiles (and don't draw objects)
    for (const auto &layer : m_layers)
    {
        for (const auto &tile : layer.tiles)
        {
            if (viewportRect.intersects(tile.getLocalBounds()))
            {
                target.draw(tile);
            }
        }
    }
}
```

- Tileset image described in `<image>` element now can handle `"trans"` attribute which defines backround color for transparent image.

- Load failure now causes exception, which can be catched in the following maner (in `main()` function):

```cpp
try
{
    TmxLevel level;
    level.LoadFromFile("res/platformer.tmx");
}
catch (const std::exception &ex)
{
    std::cerr << ex.what() << std::endl;
    return 1;
}
```

- Classes renamed to have `Tmx` prefix

- Fixed a lot of warnings and important issues in coding style


## Loader limitations

- It doesn't support compressed TMX files. You have to change your Tiled preferences to save as plain XML.
- It currently only handles one tilesheet. This shouldn't really be a problem.
- It currently has no support for isometric maps

![Screenshot](img/game_and_editor_compare.png)
