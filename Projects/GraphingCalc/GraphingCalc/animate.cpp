#include "animate.h"

animate::animate(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "G r a p h i n g   C a l c u l a t o r !");
    window.setFramerateLimit(FRAME_RATE);
    system.setEquation();
}

void animate::Draw(){
    system.Draw(window);

}

void animate::update(){
    system.Step();
}

void animate::render(){
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)){

        switch (event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::S:
                //set equation
                system.setEquation();
                break;
            case sf::Keyboard::D:
                //set domain
                system.setDomain();
                break;
            case sf::Keyboard::Left:
                //Move Graph Left
                system.Pan('l');
                break;
            case sf::Keyboard::Right:
                //Move Graph Right
                system.Pan('r');
                break;
            case sf::Keyboard::I:
                system.Zoom('i');
                //zoom in
                break;
            case sf::Keyboard::O:
                system.Zoom('o');
                //zoom out
                break;
            case sf::Keyboard::H:
                //Set Home?
                break;
            case sf::Keyboard::Escape:
                window.close();
                break;
            }
            break;

        case sf::Event::MouseEntered:
            break;
        case sf::Event::MouseLeft:
            break;
        case sf::Event::MouseMoved:
            break;
        case sf::Event::MouseButtonReleased:
            break;

        default:
            break;
        }
    }
}

void animate::run(){
    while (window.isOpen()){
        processEvents();
        update();
        render(); //clear/draw/display
    }
}
