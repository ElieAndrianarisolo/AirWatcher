/*************************************************************************
Zone  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Zone> (fichier Zone.h) ----------------
#if ! defined (ZONE_H)
#define ZONE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include "Zone.h"
#include <math.h>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Zone>
//
//------------------------------------------------------------------------

class Zone
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Getters et setters
    
    double getLat() const;
    // Mode d'emploi :
    // Retourne la latitude de la zone.
    // Contrat :
    // Aucun contrat spécifique.

    double getLong() const;
    // Mode d'emploi :
    // Retourne la longitude de la zone.
    // Contrat :
    // Aucun contrat spécifique.

    double getRayon() const;
    // Mode d'emploi :
    // Retourne le rayon de la zone.
    // Contrat :
    // Aucun contrat spécifique.

    void setLat(double lati);
    // Mode d'emploi :
    // Modifie la latitude de la zone.
    // Contrat :
    // Aucun contrat spécifique.

    void setLong(double longi);
    // Mode d'emploi :
    // Modifie la longitude de la zone.
    // Contrat :
    // Aucun contrat spécifique.

    void setRayon(double r);
    // Mode d'emploi :
    // Modifie le rayon de la zone.
    // Contrat :
    // Aucun contrat spécifique.
    
//-------------------------------------------- Méthodes d'application

    bool contient (double lati, double longi) const;
    // Mode d'emploi :
    // Vérifie si un point donné, défini par sa latitude et sa longitude, appartient à la zone.
    // Renvoie true si le point est contenu dans la zone, false sinon.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs
    
    friend ostream & operator<<(ostream & os, const Zone & z);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Zone.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Zone & operator = (const Zone & z);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Zone.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Constructeurs - destructeur

    Zone (double lati, double longi);
    // Mode d'emploi :
    // Constructeur de la classe Zone.
    // Crée une zone avec une latitude et une longitude spécifiées.
    // Le rayon est initialisé à 0.
    // Contrat :
    // Aucun contrat spécifique.

    Zone (double lati, double longi, double r);
    // Mode d'emploi :
    // Constructeur de la classe Zone.
    // Crée une zone avec une latitude, une longitude et un rayon spécifiés.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    
    double latitude;   // Latitude de la zone
    double longitude;  // Longitude de la zone
    double rayon;      // Rayon de la zone
};

#endif // Zone_H

