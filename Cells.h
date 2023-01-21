#pragma once
#ifndef cells
#define cells
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// void grid(sf::RenderWindow& window, int rows, int col);


class Cells {

    public:

        sf::RectangleShape cell_shape;

        enum States {

            LIVING,
            DEAD

        };

        Cells(int xpos, int ypos, States curr_state);

        States getState();

        int getY() const;

        int getX() const ;

        void setPos(int x, int y);
    private:

        int xPos;

        int yPos;

        States current_cell_state;




};

Cells::Cells(int xpos, int ypos, States curr_state){
    //problem found maybe
    xPos = xpos;

    yPos = ypos;


    current_cell_state = curr_state;

    cell_shape = sf::RectangleShape(sf::Vector2f(10,10)) ;

    cell_shape.setFillColor(sf::Color::Green);

    cell_shape.setOutlineColor(sf::Color::Black);
    
    cell_shape.setPosition(xpos,ypos);


}

Cells::States Cells::getState(){
    return current_cell_state;
}

int Cells::getY() const{
    return yPos;
}

int Cells::getX() const {
    return xPos;
}


void Cells::setPos(int x, int y){
    xPos = x;

    yPos = y;

    cell_shape.setPosition(x,y);
}




#endif