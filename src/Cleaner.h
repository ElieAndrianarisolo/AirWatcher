/*************************************************************************
 Cleaner  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined (CLEANER_H)
#define CLEANER_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <limits>
#include <tuple>
#include <cmath>
#include "Date.h"
#include "Zone.h"
#include "Periode.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Data; // Déclaration anticipée de la classe Data

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Getters et setters

    int getId() const;
    // Mode d'emploi :
    // Renvoie l'identifiant du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    int getFournisseurId() const;
    // Mode d'emploi :
    // Renvoie l'identifiant du fournisseur associé au Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    double getLatitude() const;
    // Mode d'emploi :
    // Renvoie la latitude du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    double getLongitude() const;
    // Mode d'emploi :
    // Renvoie la longitude du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    Date getStart() const;
    // Mode d'emploi :
    // Renvoie la date de début de validité du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    Date getStop() const;
    // Mode d'emploi :
    // Renvoie la date de fin de validité du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setId(int id);
    // Mode d'emploi :
    // Définit l'identifiant du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setFournisseurId(int id);
    // Mode d'emploi :
    // Définit l'identifiant du fournisseur associé au Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setLatitude(double lati);
    // Mode d'emploi :
    // Définit la latitude du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setLongitude(double longi);
    // Mode d'emploi :
    // Définit la longitude du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setStart(Date start);
    // Mode d'emploi :
    // Définit la date de début de validité du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

    void setStop(Date stop);
    // Mode d'emploi :
    // Définit la date de fin de validité du Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

//----------------------------------------------------- Méthode pour l'application

    tuple<double, double> voirImpact(Data objData) const;
    // Mode d'emploi :
    // Calcule et renvoie l'impact du Cleaner sous forme d'un tuple (impact, rayon).
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const Cleaner & cleaner);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Cleaner.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Cleaner & operator = (const Cleaner & cleaner);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Constructeurs - destructeur
    
    Cleaner (int id, int fournisseurId, double lati, double longi, Date start, Date stop);
    // Mode d'emploi :
    // Constructeur de la classe Cleaner.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    
    int id;                 // Identifiant du Cleaner
    int fournisseurId;      // Identifiant du fournisseur associé au Cleaner
    double latitude;        // Latitude du Cleaner
    double longitude;       // Longitude du Cleaner
    Date start;             // Date de début de validité du Cleaner
    Date stop;              // Date de fin de validité du Cleaner
};

#endif // CLEANER_H
