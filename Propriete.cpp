/*
 * Propriete.cpp
 *
 *  Created on: 18 d�c. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Propriete.h"
#include "Joueur.h"


Propriete :: Propriete(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, bool hypotheque ) /* on ne met pas Case casesuiv dans le constructeur ? */
: Case(nomcase)
{
	this -> loyer = loyer;
	prixAchat = prixachat;
	nom_joueur = nomjoueur;
	val_hypotheque = valhypo;
	this -> hypotheque = hypotheque;
}

void Propriete :: setLoyer(int loyer)
{
	this -> loyer = loyer;
}

int Propriete :: getLoyer()
{
	return(loyer);
}

void Propriete :: setPrixAchat(int prix)
{
	prixAchat = prix;
}

int Propriete :: getPrixAchat()
{
	return(prixAchat);
}

void Propriete :: setNomJoueur(string nom)
{
	nom_joueur = nom;
}

string Propriete :: getNomJoueur()
{
	return(nom_joueur);
}

void Propriete :: setHypotheque(bool b)
{
	hypotheque = b;
}


bool Propriete :: getHypotheque()
{
	return hypotheque;
}

int Propriete :: getvalhypo()
{
	return val_hypotheque;
}


Propriete :: Propriete()
:Case()
{
	this -> loyer = 0;
	prixAchat = 0;
	nom_joueur = "";
	val_hypotheque = 0;
	this -> hypotheque = false;
}

