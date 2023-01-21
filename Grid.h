#pragma once
#ifndef grid
#define grid
#include <vector>
#include "Cells.h"
#include <SFML/Graphics.hpp>


class Grid{

    private:

        int height;

        int width;


        bool is_running;




    public:
        std::vector<std::vector<Cells>> the_grid;
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
    
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Cellular Automata!");
    sf::View view = window.getDefaultView();

    
    for (int i = 0; i < height; i++){
        std::vector<Cells> row_vec;
        for (int y = 0; y < width; y++){

            row_vec.push_back(*new Cells(y,i,Cells::LIVING));//LINKER ERROR HERE
        }
        the_grid.push_back(row_vec);
    }




    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::Resized) {
            // resize my view
            view.setSize({
                    static_cast<float>(event.size.width),
                    static_cast<float>(event.size.height)
            });
            window.setView(view);
            }
        }

        // clear the window with orange color
        window.clear();
        for (std::vector<Cells> & i : the_grid){
            for (Cells & y : i){
                
                window.draw(y.cell_shape);
            }
        }

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