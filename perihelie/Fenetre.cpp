#include "Fenetre.h"

Fenetre::Fenetre(void){
	fen = new sf::Window();
	fen->create(sf::VideoMode(1000,1000), titre);
	fen->setFramerateLimit(fps);
	fen->setVerticalSyncEnabled(true);
}

void Fenetre::onRun(void){
	while (fen->isOpen()) {
		while (fen->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				fen->close();
			}
		}
	}
}