#include "animate.h"

animate::animate(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Go Java >:D!");

    window.setFramerateLimit(FRAME_RATE);
}

void animate::Draw(){
//    system.Draw(window);

}

void animate::update(){
//    system.Step();
}

void animate::render(){
    window.clear();
    Draw();
    window.display();
}

void animate::processEvents(){
    sf::Event event;

    float mouseX, mouseY;

    while (window.pollEvent(event)){

        switch (event.type){
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Left:
                break;
            case sf::Keyboard::Right:
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
            //            mouseX = event.mouseMove.x;
            //            mouseY = event.mouseMove.y;

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
