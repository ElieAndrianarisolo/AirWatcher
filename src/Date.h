/*************************************************************************
 Date  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined (DATE_H)
#define DATE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <ctime>
#include <vector>
#include <iostream>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//------------------------------------------------------------------------

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Getters et setters

    int getJour() const;
    // Mode d'emploi :
    // Retourne la valeur du jour de la date.
    // Contrat :
    // Aucun contrat spécifique.

    int getMois() const;
    // Mode d'emploi :
    // Retourne la valeur du mois de la date.
    // Contrat :
    // Aucun contrat spécifique.

    int getAnnee() const;
    // Mode d'emploi :
    // Retourne la valeur de l'année de la date.
    // Contrat :
    // Aucun contrat spécifique.

    void setJour(int jj);
    // Mode d'emploi :
    // Modifie la valeur du jour de la date.
    // Contrat :
    // Aucun contrat spécifique.

    void setMois(int mm);
    // Mode d'emploi :
    // Modifie la valeur du mois de la date.
    // Contrat :
    // Aucun contrat spécifique.

    void setAnnee(int an);
    // Mode d'emploi :
    // Modifie la valeur de l'année de la date.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Méthodes d'application

    bool precede (Date uneDate) const;
    // Mode d'emploi :
    // Vérifie si la date courante précède la date passée en paramètre.
    // Contrat :
    // Aucun contrat spécifique.

    vector<int> today();
    // Mode d'emploi :
    // Obtient la date d'aujourd'hui
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs
    
    friend ostream & operator<<(ostream & os, const Date & uneDate);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Cleaner.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Date & operator = (const Date & uneDate);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Date.
    // Contrat :
    // Aucun contrat spécifique.

    bool operator == (const Date & uneDate) const;
    // Mode d'emploi :
    // Surcharge de l'opérateur de comparaison == pour la classe Date.
    // Contrat :
    // Aucun contrat spécifique.

    bool operator<=(const Date& other) const;
    // Mode d'emploi :
    // Surcharge de l'opérateur de comparaison <= pour la classe Date.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Constructeurs - destructeur

    Date();
    // Mode d'emploi (constructeur par défaut) :
    // Construit une date avec les valeurs par défaut (jactuel, mactuel, aactuelle).
    // Contrat :
    // Aucun contrat spécifique.

    Date (int jj, int mm , int an);
    // Mode d'emploi :
    // Construit une date avec les valeurs spécifiées pour le jour, le mois et l'année.
    // Contrat :
    // Aucun contrat spécifique.
    
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    
    int jour;   // Le jour de la date
    int mois;   // Le mois de la date
    int annee;  // L'année de la date        
};

#endif // DATE_H

