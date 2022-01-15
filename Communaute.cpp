/*
 * Communaute.cpp
 *
 *  Created on: 22 d�c. 2021
 *      Author: neyre
 */

#include "Communaute.h"
#include "joueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string* Communaute::lecture() {					// pour lire dans le fichier txt
	string* tab = new string[16];
	ifstream monFlux(this->fileName);
	string* res = nullptr;
	if(monFlux) {
	   	int i = 0;
	    string ligne;
	    while (getline(monFlux,ligne)) {
	      	tab[i] = ligne;   
	    	i++;
	   	}
	    res = tab;
	}
	monFlux.close();
	return res;
}

void Communaute::ecriture(string* tab) {		// pour �crire dans le fichier txt
	string const nomFichier(this->fileName);
	ofstream monFlux(nomFichier.c_str());
	if(monFlux)	{
	 	for(int i = 0 ; i < 16 ;i++)
	     	 monFlux << tab[i] << endl ;
	}
	else
	 	cout << "WARNING - Impossible d'ouvrir le fichier" << endl;    
	monFlux.close();
}

void Communaute::melanger() {   				// pour m�langer le paquet de cartes
	string* tab = Communaute::lecture();
	random_shuffle(tab, tab+16);
	Communaute::ecriture(tab);
}

string Communaute::piocher() {					// pioche la premiere carte du paquet et la remet au talon
	cout << "Vous avez pioch� la carte : " << endl;
	string* tab = Communaute::lecture();
	string* newTab = new string[16];
	for (int i = 0; i < 15; i++) {
		newTab[i] = tab[i+1];
	}
	newTab[15] = tab[0];
	Communaute::ecriture(newTab);
	return tab[0];
}

Communaute::Communaute(string nom, string fileName):Case(nom) {	// constructeur qui m�lange une fois le paquet en d�but de partie
	this->fileName = fileName;
	Communaute::melanger();
}


void Communaute::arreterSur(joueur* j, int de) {
	cout << "fonction d�riv�e";
	string ligne = Communaute::piocher();
	
	string sep = "-";
	vector<string> words{};
	size_t pos;
	while ((pos = ligne.find(sep)) != string::npos) {// tant qu'on trouve un caract�re s�parateur
		words.push_back(ligne.substr(0, pos));		// comme un append
	    ligne.erase(0, pos + sep.length());			// on supprime ce qui a d�j� �t� examin�
	}
	
	string type = words[0];
	if (type=="ANNIVERSAIRE") {
		cout << "test" << endl;
	}
	else if (type=="GAIN") {
		cout << "test" << endl;
		j->crediter(100);
	}
	else if (type=="LIBERE") {
		cout << "test" << endl;
	}
	else if (type=="PERTE") {
		cout << "test" << endl;
	}
	else if (type=="DILEMNE") {
		cout << "test" << endl;
	}
	else if (type=="PION") {
		cout << "test" << endl;
	}
}
