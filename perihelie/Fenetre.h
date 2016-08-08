#pragma once

#include "Inclusion.h"
#include "Constante.h"

using T_val = std::vector<sf::Vector2f>;

class Fenetre : public sf::Window
{
public:
	Fenetre(void);
	void onRun(void);
	void calculatePositionRTheta(unsigned i);
	void calculatePositionXY(unsigned i);
	void calculateFormatedPosition(unsigned i);
	
private:
	std::unique_ptr<sf::RenderWindow> fen_;
	sf::Event e_;
	
	T_val posRT_;
	T_val posXY_;
	std::vector<sf::Vector2u> posFormated_;
};