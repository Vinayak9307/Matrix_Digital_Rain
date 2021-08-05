#pragma once

#include <SFML/Graphics.hpp>

namespace Matrix {

    class Letter{

        int         posx , posy;
        int         value = 'A';
        float       speed;
        int         SwitchInterval = 15 + rand() % 50;
        bool        first;
        sf::Text    _text;

        public:
        
        Letter( int x , int y , float speed , bool first , sf::Text &text );
        static int  textsize;
        void        show( sf::RenderWindow &window );

    };
}