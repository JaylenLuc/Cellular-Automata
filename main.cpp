
#include "Grid.h"
#include <vector>
#include <iostream>


const std::int32_t window_width = 3840; //columns

const std::int32_t window_height = 2160; //rows

int main()
{
	//1 -- should add the option to allow the users to change the rule set
	//to a predetermiuned set of rules
	//2 -- could allow users to change color of alive and dead cells
	std::string rule_set ;
	std::cout << "Select corresponding code to choose a rule set: "<<std::endl;
	std::cout << "1 : Conway's game of life (B3/S23; totalistic moore)"<<std::endl;
	std::cout << "2 : Rule 34 (B34/S34); totalistic moore)"<<std::endl;
	std::cin >> rule_set;
	Grid cell_main;

	std::cin.ignore();

	cell_main.setRun(true);

	std::cout << "Emergent Phenomon Simulation Running" << std::endl;

	cell_main.exec(rule_set);

	return 0;
}


