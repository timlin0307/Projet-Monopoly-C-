/*
 * de.h
 *
 *  Created on: 17 d�c. 2021
 *      Author: basti
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#ifndef DE_H_
#define DE_H_
class de{
protected :
	int nbFaces;
	int valeur;
public:
	de();
	de(int nbFaces);
	int getNbfaces();
	int getValeur();
};


#endif /* DE_H_ */
