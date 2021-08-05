#include "../include/Rain.hpp"

namespace Matrix{

    Rain::Rain( )
    {
        window = new sf::RenderWindow(  sf::VideoMode::getFullscreenModes( )[0] , "Matrix",sf::Style::Fullscreen );
        
        window->setFramerateLimit( 30 );

        font = new sf::Font( );
        font->loadFromFile("D:/Project1/MatrixDRain/resources/imminent-line.ttf");

        text = new sf::Text( );
        text->setFont( *font );

        int x = 0;
        int y = 0;
        for( unsigned i = 0 ; i < window->getSize( ).x / Letter::textsize ; i++)
        {
            String *drop = new String( x , y , *text );
            _rain.push_back( *drop );
            x += Letter::textsize;
            y =  -1000 + rand( )%1000;
        }
    }

    void Rain::LetsRain( )
    { 
        int animate = 1;
        bool take_picture = false;
        while(window->isOpen( ))
        {
            sf::Event event;
            while(window->pollEvent( event ))
            {
               switch (event.type)
                {
                case sf::Event::Closed:
                    window->close( );
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape :
                            window->close( );
                            break;
                        case sf::Keyboard::Space :
                            animate *= -1;
                            break;
                        case sf::Keyboard::P :
                            take_picture = true;
                            break;
                        default:
                            break;                        
                    }
                    break;                
                default:
                    break;
                }
            }
            if(animate == 1)
            {
            window->clear( );
            for( std::vector<String>::iterator it = _rain.begin( ); it < _rain.end( ) ; it++ )
            {
                it->showString( *window );
            }
            window->display();
            }

            if( take_picture )
            {
                sf::Texture _tex;
                _tex.create( window->getSize( ).x , window->getSize( ).y );
                _tex.update( *window );
                _tex.copyToImage( ).saveToFile("Background" + std::to_string(this->SS_count) + ".png");
                take_picture = false;
            }
        }
    }
}