/*
 * Case.cpp
 *
 *  Created on: 22 d�c. 2021
 *      Author: neyre
 */

#include "Case.h"
#include <iostream>
using namespace std;

Case::Case(string nom) {
	this->nom = nom;
	this->suivante = nullptr;
}

string Case::getNom() {
	return nom;
}
	
Case* Case::getSuivante() {
	return suivante;
}

void Case::setNom(string nom) {
	this->nom = nom;
}
	
void Case::setSuivante(Case* suivante) {
	this->suivante = suivante;
}

void Case::affiche() {
	cout << nom << endl;
}

void Case::arreterSur() {
	cout << "g�n�rique" << endl;
}


