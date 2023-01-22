#pragma once
#ifndef grid
#define grid
#include <vector>
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>


class Grid{

    private:

        int height;

        int width;


        bool is_running;




    public:
        std::vector<sf::Vertex> the_grid;
        //iterate over the cell height first

        //then for every "height " you iterate through the width so as to avoid a 2D vector 
        Grid(int Height, int Width);

        void setWidth(int Width);

        void setHeight(int Height);
        int getHeight() const;
        int getWidth() const;

        void setRun(bool x);

        void exec(int w_width, int w_height);





};

Grid::Grid(int Height, int Width){

    height = Height;

    width = Width;

    is_running = false;

}

void Grid::setRun(bool x){
    is_running = x;
}

void Grid::exec(int w_width, int w_height)
{
    // totalistic cellular automata with a Moore neighborhood
    //less than 2 living cells then the cell will die
    //2 or 3surroudning cells it will live
    //4 or more then it will die
    //if dead and has exaclty 3 cells around it then it will become alive
    // create the window
    
    //Cells::setQUAD_SIZE(4);
    Cells::getQUAD_SIZE();
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Cellular Automata!");
    
    //the_grid((window.getSize().x / Cells::getQUAD_SIZE())* (window.getSize().y /Cells::getQUAD_SIZE()));
    
    const int WIDTH = window.getSize().x / Cells::getQUAD_SIZE();
    srand(std::time(nullptr));
    //std::vector<sf::Vertex>> the_grid;
    for (unsigned int x = 0; x < window.getSize().x /Cells::getQUAD_SIZE(); x++){
        for (unsigned int y = 0 ; y < window.getSize().y/ Cells::getQUAD_SIZE(); y++){
            sf::Vertex t_left;
            sf::Vertex t_right;
            sf::Vertex b_right;
            sf::Vertex b_left;

            float pixel_x = x * Cells::getQUAD_SIZE();

            float pixel_y = y * Cells::getQUAD_SIZE();
            //Vector2 (T X, T Y)
            t_left.position = {pixel_x, pixel_y};

            t_right.position = {pixel_x + WIDTH, pixel_y};

            b_right.position = {pixel_x + WIDTH, pixel_y + WIDTH};
             
            b_left.position = {pixel_x, pixel_y + WIDTH};

            
            uint8_t r = rand() % 255;


            t_left.color = {r,r,r};
            t_right.color = {r,r,r};
            b_left.color = {r,r,r};
            b_right.color = {r,r,r};

            the_grid.push_back(t_left);
            the_grid.push_back(b_left);
            the_grid.push_back(b_right);
            the_grid.push_back(t_right);
            




        }
        
    }



    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();

            }
        }

        // clear the window with orange color
        window.clear();

        window.draw(the_grid.data(), the_grid.size(), sf::Quads);
    
        window.display();
    }

}
void Grid::setWidth(int Width){
    width = Width; 
}
void Grid::setHeight(int Height){
    height = Height;
}


int Grid::getHeight() const{
    return height;
}
int Grid::getWidth() const{
    return width;
}



#endif