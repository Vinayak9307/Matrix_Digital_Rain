#pragma once

#include "../include/String.hpp"
#include "../include/Letter.hpp"
#include <SFML/Graphics.hpp>

namespace Matrix{

    class Rain{

        private:

        sf::RenderWindow    *window;
        sf::Font            *font;
        sf::Text            *text;
        std::vector<String> _rain;
        int SS_count        = 0;

        public:

        Rain( );
        
        void LetsRain( );

    };
}