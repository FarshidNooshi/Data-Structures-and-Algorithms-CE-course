#include "Headers/Edge.h"

const double Edge::traficFactor = 0.3;

double Edge::Weight() {
	return length * (1.0 + trafic * traficFactor);
}