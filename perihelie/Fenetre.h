#pragma once

#include "Inclusion.h"
#include "Constante.h"

class Fenetre : public sf::Window
{
public:
	Fenetre(void);
	void onRun(void);
private:
	sf::Window* fen;
	sf::Event e;
};