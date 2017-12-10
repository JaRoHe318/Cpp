#include "animate.h"

animate::animate(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Go Java >:D!");

    window.setFramerateLimit(FRAME_RATE);
}

void animate::Draw(){
//        system.Draw(window);

    //This is the current origin
    sf::RectangleShape yaxis(sf::Vector2f(LINE_WIDTH,SCREEN_HEIGHT));
    yaxis.setPosition(sf::Vector2f(500-(LINE_WIDTH/2),0));
    yaxis.setFillColor(sf::Color(100,100,100));
//    yaxis.setFillColor(sf::Color::Red);
    window.draw(yaxis);

    sf::RectangleShape xaxis(sf::Vector2f(SCREEN_WIDTH,LINE_WIDTH));
    xaxis.setPosition(sf::Vector2f(0,300-(LINE_WIDTH/2)));
    xaxis.setFillColor(sf::Color(100,100,100));
//    xaxis.setFillColor(sf::Color::Red);
    window.draw(xaxis);

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

//    float mouseX, mouseY;

    while (window.pollEvent(event)){

        switch (event.type){
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:

            switch(event.key.code){
            case sf::Keyboard::Left:
                //Move Graph Left
                break;
            case sf::Keyboard::Right:
                //Move Graph Right
                break;
            case sf::Keyboard::I:
                //zoom in
                break;
            case sf::Keyboard::O:
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
