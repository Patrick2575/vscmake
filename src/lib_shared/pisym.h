#pragma once

#include "libdef.h"
#include <memory>

class Random;

class EXPORT_SYMBOL piMonteCarloSimulation
{
public:
   piMonteCarloSimulation();
   ~piMonteCarloSimulation();
   double aproxPi();

private:
	std::unique_ptr<Random> m_rnd;
};