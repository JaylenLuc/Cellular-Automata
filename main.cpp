
#include "Grid.h"
#include <vector>
#include <iostream>


const std::int32_t window_width = 720; //columns

const std::int32_t window_height = 480; //rows

int main()
{
    Grid cell_main(window_width,window_height);

    cell_main.setRun(true);

    std::cout << "Emergent Phenomon Simulation Running" << std::endl;

    cell_main.exec(window_width,window_height);

    return 0;
}


