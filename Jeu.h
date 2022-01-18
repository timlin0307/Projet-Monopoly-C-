/*
 * Jeu.h
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#ifndef JEU_H_
#define JEU_H_
#include <string>
#include "Joueur.h"
using namespace std;

class Jeu {
    protected:
	Joueur* *joueurs;
	int tourdejeu;
	int nb_joueurs;

    public:
	Jeu();
	int compteur();
	int getNbjoueurs();
	void setNbjoueurs(int nb_joueurs);
	void setJoueurs();
	Joueur** getJoueurs();
	void afficheJoueurs();
};



#endif /* JEU_H_ */
