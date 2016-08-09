#include "Fenetre.h"

Fenetre::Fenetre(void){
	fen_ = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow());
	fen_->create(sf::VideoMode(1000,1000), titre);
	fen_->setFramerateLimit(fps);
	fen_->setVerticalSyncEnabled(true);
	
	posRT_.push_back(sf::Vector2f(R0,T0));
	posRT_.push_back(sf::Vector2f(R0+0.01,T0));
	
	std::cout << std::scientific;
	
	circle_.setRadius(GM/10);
	circle_.setFillColor(sf::Color::Black);
	circle_.setPosition(500 - GM/10, 500 - GM/10);
}

void Fenetre::onRun(void){
	
	sf::Vertex line[2];
	unsigned i = 1;
	double l = R0 * T0 / sqrt(R0 - 3.0);
	double v = 0.0;
	while (fen_->isOpen()) {
		
		fen_->clear(sf::Color::White);
		while (fen_->pollEvent(e_)) {
			if (e_.type == sf::Event::Closed) {
				fen_->close();
			}
		}
		
		//sf::sleep(sf::milliseconds(loop_sleep));
		calculatePositionRTheta(i,l);
		++i;
		calculatePositionXY(i);
		calculateFormatedPosition(i);
		
		for (unsigned n = 0; n < posFormated_.size() - 1; ++n) {
			line[0] = sf::Vertex(static_cast<sf::Vector2f>(posFormated_[n]),sf::Color::Blue);
			line[1] = sf::Vertex(static_cast<sf::Vector2f>(posFormated_[n+1]),sf::Color::Blue);
			fen_->draw(line,2,sf::Lines);
		}
		v = sqrt(pow(posXY_[i].x-posXY_[i-1].x,2)+pow(posXY_[i].y-posXY_[i-1].y,2));
		std::cout << "v : " << v << " r : "<< posRT_.back().x << " t: " << posRT_.back().y << std::endl;
		
		fen_->draw(circle_);
		fen_->display();
	}
}

void Fenetre::calculatePositionRTheta(unsigned i, double l)
{
	double r,t = 0.0;
	//l = pow(posRT_[i].x, 2) * deltaT/TAU;
	//posRT_[i].y - posRT_[i- 1].y
	//std::cout << posRT_[i].y << " : " << posRT_[i- 1].y << " : " << pow(posRT_[i].x, 2) << std::endl;
//	r = 2.0 * posRT_[i].x - posRT_[i - 1].x + TAU * TAU * (-(GM/(pow(posRT_[i].x, 2)))+(l*l/(pow(posRT_[i].x, 3)))-(3 * GM * l / (pow(posRT_[i].x, 4))));
//	t = posRT_[i].y + TAU *(l/ 0.5*(pow((r + posRT_[i].x),2)));
	
	r = TAU* (-(1/pow(posRT_[i - 1].x, 2))+(l*l/pow(posRT_[i - 1].x, 3))-(3*l*l*GM/pow(posRT_[i - 1].x, 4))) + posRT_[i].x;
	t = TAU * (l / pow(r, 2)) + posRT_[i].y;
		//std::cout << l << " : " << r << " : " << t << std::endl;
	posRT_.push_back(sf::Vector2f(r,t));
	
}

void Fenetre::calculatePositionXY(unsigned i)
{
	double x,y;
	posXY_.clear();
	for (unsigned n = 0; n < posRT_.size(); ++n) {
		x = posRT_[n].x*cos(posRT_[n].y);
		y = posRT_[n].x*sin(posRT_[n].y);
		posXY_.push_back(sf::Vector2f(x,y));
	}
}

void Fenetre::calculateFormatedPosition(unsigned i)
{
	posFormated_.clear();
	sf::Vector2f tmp;
	double pixelX = 1000.0/100.0;
	double pixelY = 1000.0/100.0;
	//std::cout << pixelX << " : " << pixelY << std::endl;
	for (unsigned n = 0; n < posXY_.size(); ++n) {
		tmp.x = 500.0 - posXY_[n].x * pixelX;
		tmp.y = 500.0 - posXY_[n].y * pixelY;
		posFormated_.push_back(static_cast<sf::Vector2u>(tmp));
	}
}




