#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;


class MenuNonox : public Drawable {

private:

    Text menuText[5];
    string menuOption[5]={"New game","Score","Credits","Rules","Exit"};

    int _option;
    int _size, _stateWindow;
    float _yPosition;


    Texture titleTexture,backgroundTexture;
    Sprite titleSprite, backgroundSprite;
    Font font;

public:

     MenuNonox();
     void LoadDraw(sf::Vector2u ventanaSize);
     virtual void draw(RenderTarget& target, RenderStates states) const;
     int getStateWindow();
     void update(RenderWindow& window);


};
