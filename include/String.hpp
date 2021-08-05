#pragma once
#include "../include/Letter.hpp"
#include <SFML/Graphics.hpp>

namespace Matrix{
    
    class String{

        private:

        std::vector<Letter> _string;
        int                 letterCount = 5 + rand( )%20;
        float               speed = 1 + rand( )%5;

        public:

        String( int x , int y , sf::Text &text);
        void showString( sf::RenderWindow &window );
    };
}