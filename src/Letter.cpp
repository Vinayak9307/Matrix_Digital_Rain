#include "../include/Letter.hpp"

namespace Matrix{

    Letter::Letter( int x , int y , float speed , bool first , sf::Text &text ):_text( text )
    {
        this->posx = x;
        this->posy = y;
        this->speed = speed;
        this->first = first;
        this->_text.setCharacterSize( this->textsize );
    }

    void Letter::show( sf::RenderWindow &window )
    {
        if( this->posy % this->SwitchInterval == 0)
        {
            this->value = 'A' + rand( ) % 26;
        }

        this->_text.setString( (char)this->value );

        if( this->first )
        {
            this->_text.setFillColor(sf::Color(0,255,70,255));
            this->_text.setOutlineColor(sf::Color::White);
            this->_text.setOutlineThickness(1.f);
        }
        else
        {
            this->_text.setFillColor(sf::Color(0,255,70,255));
        }

        this->_text.setPosition( sf::Vector2f(this->posx , this->posy ));
        window.draw( this->_text );

        this->posy > (int)window.getSize( ).y ? this->posy = 0 : this->posy += this->speed;

    }

    int Letter::textsize = 10;
}