#include "../include/String.hpp"

namespace Matrix{

    String::String( int x , int y , sf::Text &text)
    {
        bool first = rand( )%4 == 1;

        for(int i = 0 ; i < this->letterCount ; i++)
        {
        Letter *letter = new Letter(x,y,this->speed,first , text);
        this->_string.push_back(*letter);
        y -= letter->textsize;
        first = false;
        }
    }

    void String::showString( sf::RenderWindow &window)
    {
        for( std::vector<Letter>::iterator it = this->_string.begin( ) ; it < this->_string.end( ) ; it++)
        {
            it->show( window );
        }
    }

}