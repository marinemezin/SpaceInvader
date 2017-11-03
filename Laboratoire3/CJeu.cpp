#include <iostream>

#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(0,5);
	T2 = new CTour(0,10);
	T3 = new CTour(0,15);
	score = 0;
}