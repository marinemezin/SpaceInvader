#include <iostream>

#include "CJeu.h"

CJeu::CJeu()
{
	T1 = new CTour(30,10);
	T2 = new CTour(30,20);
	T3 = new CTour(30,30);
	score = 0;
}

CJeu::~CJeu()
{

}

void CJeu::Afficher()
{

}