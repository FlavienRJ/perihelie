#pragma once

#include "Inclusion.h"

const sf::String	titre		= "Perihelie";
const int			fps			= 60;
const float			epsilon		= 1/(float)fps;
const int			loop_sleep	= 1;
const double		R0			= 1000.0;
const double		T0			= 0.0;
const double		TAU			= 0.000000001;
const double		GM			= 100;
const double		deltaT		= 0.00000000000001;

//R0 = 100
//T0 = 0
//TAU = 1.0
//GM = 1

//const double		R0			= 1000.0;
//const double		T0			= 0.0;
//const double		TAU			= 0.1;
//const double		GM			= 100;
//const double		deltaT		= 0.00000000000001;