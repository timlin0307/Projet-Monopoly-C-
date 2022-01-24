/*
 * Gare.cpp
 *
 *  Created on: 18 d�c. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Gare.h"

Gare ::Gare(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo,Joueur* jref,  bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	appartient_a=jref;
}

void Gare :: arreterSur(Joueur* j, int de)
{
	if (nom_joueur == "")
	{
		cout << "la case n'appartient � personne" << endl;
		cout << "le prix d'achat est de " << prixAchat << endl;
		cout << "votre solde de compte en banque est " << (*j).getSolde() << endl;
		cout << "souhaitez vous l'acheter ?" << endl;
		cout << "Si oui taper 1, si non taper 2" << endl;
		int achat;
		cin >> achat ;

		if (achat == 1)
		{
			(*j).debiter(prixAchat);
			nom_joueur = (*j).getNom();
			appartient_a = j;
			(*j).setNbGare(1);
			cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
		}
	}

	else if (hypotheque == false )
	{
		cout << "la case appartient � " << nom_joueur << endl;
		this -> calcul_loyer();
		int a_payer = loyer;
		(*appartient_a).crediter(a_payer);
		(*j).debiter(a_payer);
		cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
	}
	else
	{
		cout << "la case appartient � " << nom_joueur << endl;
		cout << "elle est hypoth�qu�e tu n'as rien a pay�" << endl;
	}
}

void Gare :: calcul_loyer()
{
	int i = (*appartient_a).getNbGare();
	loyer = 25 * 2^(i);
}

Joueur * Gare :: getJoueur()
{
	return appartient_a;
}

void Gare :: setJoueur(Joueur * j)
{
	appartient_a = j;
}

Gare :: Gare()
:Propriete()
{
	appartient_a=nullptr;
}
