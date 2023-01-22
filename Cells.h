#pragma once
#ifndef cells
#define cells
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// void grid(sf::RenderWindow& window, int rows, int col);


class Cells {

    public:

        static int16_t QUAD_SIZE;

        enum States {

            LIVING,
            DEAD

        };

        Cells(int xpos, int ypos, States curr_state);

        States getState();

        static int16_t getQUAD_SIZE(){
            return QUAD_SIZE;
        }

        static void setQUAD_SIZE(int16_t x){

            QUAD_SIZE = x;
        }
    private:

        int xPos;

        int yPos;

        States current_cell_state;




};

int16_t Cells::QUAD_SIZE = 8;




Cells::Cells(int xpos, int ypos, States curr_state){
    //problem found maybe


}

Cells::States Cells::getState(){
    return current_cell_state;
}



#endif