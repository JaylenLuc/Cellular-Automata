#pragma once
#ifndef cells
#define cells
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// void grid(sf::RenderWindow& window, int rows, int col);


class Cells {

    public:
        enum States {

            LIVING,
            DEAD

        };

        static int16_t QUAD_SIZE;

        Cells(sf::Vertex & t_left, sf::Vertex & b_left,sf::Vertex & b_right,sf::Vertex & t_right, int i);

        bool getState();

        void test();

        void setState(bool b );

        static int16_t getQUAD_SIZE(){
            return QUAD_SIZE;
        }

        static void setQUAD_SIZE(int16_t x){

            QUAD_SIZE = x;
        }

        sf::Vertex  t_left;

        sf::Vertex  b_left;
        sf::Vertex  b_right;
        sf::Vertex  t_right;
    private:


        int xPos;

        int yPos;

        States current_cell_state;




};

int16_t Cells::QUAD_SIZE = 8;




Cells::Cells(sf::Vertex & t_left, sf::Vertex & b_left,sf::Vertex & b_right,sf::Vertex & t_right, int i){
    
    this->t_left = t_left;

    this->b_left = b_left;

    this->b_right = b_right;

    this->t_right = t_right;
    if (i == 225){
        current_cell_state = DEAD;

    }else{
        current_cell_state = LIVING;
    }

}

bool Cells::getState(){
    if (current_cell_state == LIVING){
        return true;
    }
    return false;
    //return current_cell_state;
}

void Cells::setState(bool b){

    if (b){
        current_cell_state = LIVING;
        //black
        t_left.color = {0,0,0}; 
        t_right.color = {0,0,0}; 
        b_left.color = {0,0,0}; 
        b_right.color = {0,0,0}; 
    }else{
        current_cell_state = DEAD;
        //white
        t_left.color = {225,225,225}; 
        t_right.color = {225,225,225};
        b_left.color = {225,225,225};
        b_right.color = {225,225,225};
    }
}

void Cells::test (){
    std::cout << "exists"<< std::endl;
}
#endif