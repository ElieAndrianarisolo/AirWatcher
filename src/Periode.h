/*************************************************************************
Periode  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Periode> (fichier Periode.h) ----------------
#if ! defined ( PERIODE_H )
#define PERIODE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Periode>
// Représente une période de temps entre une date de début et 
// une date de fin
//------------------------------------------------------------------------

class Periode
{
//----------------------------------------------------------------- PUBLIC

public:
//---------------------------------------------------------- Getters et setters
    
    Date getDebut() const;
    // Mode d'emploi :
    // Retourne la date de début de la période.
    // Contrat :
    // Aucun contrat spécifique.

    Date getFin() const;
    // Mode d'emploi :
    // Retourne la date de fin de la période.
    // Contrat :
    // Aucun contrat spécifique.

    void setDebut(Date deb);
    // Mode d'emploi :
    // Modifie la date de début de la période.
    // Contrat :
    // Aucun contrat spécifique.

    void setFin(Date fin);
    // Mode d'emploi :
    // Modifie la date de fin de la période.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Méthodes d'application

    bool estValide() const;
    // Mode d'emploi :
    // Vérifie si la période est valide, c'est-à-dire si la date de début est antérieure ou égale à la date de fin.
    // Renvoie true si la période est valide, false sinon.
    // Contrat :
    // Aucun contrat spécifique.

    bool inclu(Date uneDate) const;
    // Mode d'emploi :
    // Vérifie si une date donnée est incluse dans la période.
    // Renvoie true si la date est incluse dans la période, false sinon.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs

    Periode & operator = (const Periode & p);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Periode.
    // Contrat :
    // Aucun contrat spécifique.

    friend ostream & operator<<(ostream & os, const Periode & p);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Periode.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

//-------------------------------------------- Constructeurs - destructeur

    Periode (Date deb, Date fin);
    // Mode d'emploi :
    // Constructeur de la classe Periode.
    // Crée une période avec une date de début et une date de fin spécifiées.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    
    Date debut; // Date de début de la période
    Date fin;   // Date de fin de la période
};

#endif // PERIOD_H

