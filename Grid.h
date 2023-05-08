#pragma once
#ifndef grid
#define grid
#include <vector>
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <set>
#include <map>
#include <iostream>
#include <map>

//#include <windows.h>
 
// Library effective with Linux
#include <unistd.h>


class Grid{

    private:

        int height;

        int width;


        bool is_running;




    public:
    
        std::vector<sf::Vertex> the_grid;
        //iterate over the cell height first

        std::vector<std::vector<Cells>> the_cells;
        static const std::int32_t window_width = 1280; //columns

        static const std::int32_t window_height = 720; //rows

        //then for every "height " you iterate through the width so as to avoid a 2D vector 
        Grid();
        void conway_update();
        void setWidth(int Width);

        void setHeight(int Height);
        int getHeight() const;
        int getWidth() const;

        void setRun(bool x);

        void exec(std::string rule);

        void init_populate(const int WIDTH);

        void pop_grid(const int WIDTH);
	void three4_update();




};
sf::RenderWindow window(sf::VideoMode(Grid::window_width, Grid::window_height), "Cellular Automata!");
Grid::Grid(){


    is_running = false;

}

void Grid::setRun(bool x){
    is_running = x;
}

void Grid::conway_update(){

    //dead
    //exactly 3 lviing then it will live
    int total = 0;
    //iterates every col then every row in the col
    // std::cout << the_cells.size()<<std::endl;
    
    // std::cout << the_cells[0].size() << std::endl;
    // std::cout << window.getSize().x/Cells::getQUAD_SIZE() << std::endl;
    // std::cout << window.getSize().y/Cells::getQUAD_SIZE() << std::endl;

    //cols are 90
    //rows are 60
    int width = window_width/Cells::getQUAD_SIZE();
    int height = window_height/Cells::getQUAD_SIZE();
    for (int x= 0 ; x < width; x++){
        for (int y = 0 ; y < height; y++){
            total = 0;
            //dead cases
            //false is dead
            if (!the_cells[x][y].getState()){
                //check left
                if (x > 0  && the_cells[x-1][y].getState()){
                    total ++;
                }
                //check NW
                //std::cout << x << "  ----  "<< y << std::endl;
                if (x > 0 && y > 0 && the_cells[x-1][y-1].getState()){
                    total ++;
                }
                // //check up 
                if (y > 0 && the_cells[x][y-1].getState()){
                    total++;
                }
                // //check NE
                if (y >0 && x < width -1 && the_cells[x+1][y-1].getState()){
                    total++;
                }
                if (total > 3){
                    continue;
                }
                // //check right
                if (x < width -1 && the_cells[x+1][y].getState()){
                    total ++;
                }
                // //check SE
                //logic may be wrong
                if (y < height-1  && x < width-1 && the_cells[x+1][y+1].getState()){
                    total ++;
                }
                // //check south
                if (y < height-1 && the_cells[x][y+1].getState()){
                    total ++;
                }
                // //check SW
                if (y < height -1 && x > 0 && the_cells[x-1][y+1].getState()){
                    total++;

                }
                //this if total moore neighbors are equal to 3 then dead cell will live
                if (total == 3){
                    the_cells[x][y].setState(true);

                }
                

                
            }else{
                if (x > 0  && the_cells[x-1][y].getState()){
                    total ++;
                }
                //check NW
                //std::cout << x << "  ----  "<< y << std::endl;
                if (x > 0 && y > 0 && the_cells[x-1][y-1].getState()){
                    total ++;
                }
                // //check up 
                if (y > 0 && the_cells[x][y-1].getState()){
                    total++;
                }
                // //check NE
                if (y >0 && x < width -1 && the_cells[x+1][y-1].getState()){
                    total++;
                }
                if (total > 3){
                    the_cells[x][y].setState(false);
                    continue;
                }
                // //check right
                if (x < width -1 && the_cells[x+1][y].getState()){
                    total ++;
                }
                // //check SE
                //logic may be wrong
                if (y < height-1  && x < width-1 && the_cells[x+1][y+1].getState()){
                    total ++;
                }
                // //check south
                if (y < height-1 && the_cells[x][y+1].getState()){
                    total ++;
                }
                // //check SW
                if (y < height -1 && x > 0 && the_cells[x-1][y+1].getState()){
                    total++;

                }
                //this if total moore neighbors are equal to 3 then dead cell will live
                if (!(total == 2 || total == 3)){
                    the_cells[x][y].setState(false);

                }
            }
            
            //alive cases
            //totalistic moore neighborhood lk up
            //living 
            //if 1 or less neighbors are alive then it dies 
            //2 or 3 then alive cell will live
            //4 or more then cell will die

        }
    }

}
void Grid::three4_update(){
		
    int total = 0;
    //iterates every col then every row in the col
    // std::cout << the_cells.size()<<std::endl;
    
    // std::cout << the_cells[0].size() << std::endl;
    // std::cout << window.getSize().x/Cells::getQUAD_SIZE() << std::endl;
    // std::cout << window.getSize().y/Cells::getQUAD_SIZE() << std::endl;

    //cols are 90
    //rows are 60
    int width = window_width/Cells::getQUAD_SIZE();
    int height = window_height/Cells::getQUAD_SIZE();
    for (int x= 0 ; x < width; x++){
        for (int y = 0 ; y < height; y++){
            total = 0;
            //dead cases
            //false is dead
	    //3,4
            if (!the_cells[x][y].getState()){
                //check left
                if (x > 0  && the_cells[x-1][y].getState()){
                    total ++;
                }
                //check NW
                //std::cout << x << "  ----  "<< y << std::endl;
                if (x > 0 && y > 0 && the_cells[x-1][y-1].getState()){
                    total ++;
                }
                // //check up 
                if (y > 0 && the_cells[x][y-1].getState()){
                    total++;
                }
		                // //check NE
                if (y >0 && x < width -1 && the_cells[x+1][y-1].getState()){
                    total++;
                }
                // //check right
                if (x < width -1 && the_cells[x+1][y].getState()){
                    total ++;
                }if (total == 5){
			continue;
		}

                // //check SE
                //logic may be wrong
                if (y < height-1  && x < width-1 && the_cells[x+1][y+1].getState()){
                    total ++;
                }
                // //check south
                if (y < height-1 && the_cells[x][y+1].getState()){
                    total ++;
                }
                // //check SW
                if (y < height -1 && x > 0 && the_cells[x-1][y+1].getState()){
                    total++;

                }
                //this if total moore neighbors are equal to 3 then dead cell will live
                if (total == 3 || total == 4){
                    the_cells[x][y].setState(true);

                }
                

                
            }else{
		//3,4
                if (x > 0  && the_cells[x-1][y].getState()){
                    total ++;
                }
                //check NW
                //std::cout << x << "  ----  "<< y << std::endl;
                if (x > 0 && y > 0 && the_cells[x-1][y-1].getState()){
                    total ++;
                }
                // //check up 
                if (y > 0 && the_cells[x][y-1].getState()){
                    total++;
                }
                // //check NE
                if (y >0 && x < width -1 && the_cells[x+1][y-1].getState()){
                    total++;
                }
                // //check right
                if (x < width -1 && the_cells[x+1][y].getState()){
                    total ++;
                }
                if (total == 5){
                    the_cells[x][y].setState(false);
                    continue;
                }

                // //check SE
                //logic may be wrong
                if (y < height-1  && x < width-1 && the_cells[x+1][y+1].getState()){
                    total ++;
                }
                // //check south
                if (y < height-1 && the_cells[x][y+1].getState()){
                    total ++;
                }
                // //check SW
                if (y < height -1 && x > 0 && the_cells[x-1][y+1].getState()){
                    total++;

                }
                //this if total moore neighbors are equal to 3 then dead cell will live
                if (!(total == 4 || total == 3)){
                    the_cells[x][y].setState(false);

                }
            }

        }
    }

}

void Grid::init_populate(const int WIDTH){
    for (unsigned int x = 0; x < window.getSize().x /Cells::getQUAD_SIZE(); x++){
        std::vector<Cells> v;
        //every vector in the_cells is a col ;
        the_cells.push_back(v);
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

            
            uint8_t r  = rand() % 255;
            //if ()

            if (r % 47 == 0){
                r = 225;
            }else{
                r = 0;
            }
            t_left.color = {r,r,r}; 
            t_right.color = {r,r,r};
            b_left.color = {r,r,r};
            b_right.color = {r,r,r};
            


            the_cells[x].push_back(Cells(t_left, b_left, b_right, t_right, r));

            the_grid.push_back(t_left);
            the_grid.push_back(b_left);
            the_grid.push_back(b_right);
            the_grid.push_back(t_right);
            




        }
        
    }
}

void Grid::pop_grid(const int WIDTH){
    the_grid.clear();
    for (unsigned int x = 0; x < the_cells.size(); x++){
        //std::vector<Cells> v;
        //every vector in the_cells is a col ;
        //the_grid.push_back(v);
        for (unsigned int y = 0 ; y <the_cells[x].size(); y++){

            // float pixel_x = x * Cells::getQUAD_SIZE();

            // float pixel_y = y * Cells::getQUAD_SIZE();
            // //Vector2 (T X, T Y)
            // the_cells[x][y].t_left.position = {pixel_x, pixel_y};

            // the_cells[x][y].t_right.position = {pixel_x + WIDTH, pixel_y};

            // the_cells[x][y].b_right.position = {pixel_x + WIDTH, pixel_y + WIDTH};
             
            // the_cells[x][y].b_left.position = {pixel_x, pixel_y + WIDTH};
            
            the_grid.push_back(the_cells[x][y].t_left);
            the_grid.push_back(the_cells[x][y].b_left);
            the_grid.push_back(the_cells[x][y].b_right);
            the_grid.push_back(the_cells[x][y].t_right);

            
            
            //the_cells[x][y].test();
            //std::cout << x<< " "<< y << std::endl;



        }
        
    }

}

void Grid::exec(std::string  rule)
{	
	std::function<void(void)> rule_func;
	if (rule == "1") rule_func = std::bind(&Grid::conway_update,this);
	if (rule == "2") rule_func = std::bind(&Grid::three4_update,this);
	
	
    // totalistic cellular automata with a Moore neighborhood
    //less than 2 living cells then the cell will die
    //2 or 3surroudning cells it will live
    //4 or more then it will die
    //if dead and has exaclty 3 cells around it then it will become alive
    // create the window
    
    //Cells::setQUAD_SIZE(4);
    Cells::getQUAD_SIZE();
    
    //the_grid((window.getSize().x / Cells::getQUAD_SIZE())* (window.getSize().y /Cells::getQUAD_SIZE()));
    
    const int WIDTH = window.getSize().x / Cells::getQUAD_SIZE();
    srand(std::time(nullptr));
    //std::vector<sf::Vertex>> the_grid;
    //for every col for every item in teh col
    //std::cout << window.getSize().x << std::endl;
    init_populate(WIDTH);



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

        //std::cout << "here"<<std::endl;
        

       rule_func();
       //three4_update();
       //conway_update();

        
        // std::cout << "-"<<std::endl;
        // std::cout << "---"<<std::endl;

        //we might also have to update grid data 
        pop_grid(WIDTH);
        //just make stuff  happen on the screen bruh
        //populate(WIDTH);
        pop_grid(WIDTH);
        //std::cout << the_grid.size() << std::endl;
        window.draw(the_grid.data(), the_grid.size(), sf::Quads);
 
        window.display();
        //sleep(1);
        usleep(50000);
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
