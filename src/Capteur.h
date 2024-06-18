/*************************************************************************
 Capteur  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI 
e-mail               : aya.talbi-el-alami@insa-lyon.fr 
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined (CAPTEUR_H)
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <vector>
#include "Mesures.h"
#include "Periode.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
// Cette classe représente un capteur qui enregistre des mesures.
// Chaque capteur est caractérisé par un identifiant, une position géographique
// (latitude et longitude) et un statut de validité. Les mesures enregistrées
// par le capteur sont stockées dans un vecteur.
//------------------------------------------------------------------------

class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Getters et setters
    
    int getId() const; 
    // Mode d'emploi :
    // Retourne l'identifiant du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    void setId(int id);
    // Mode d'emploi :
    // Modifie l'identifiant du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    double getLatitude() const;
    // Mode d'emploi :
    // Retourne la latitude du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    void setLatitude(double latitude);
    // Mode d'emploi :
    // Modifie la latitude du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    double getLongitude() const;
    // Mode d'emploi :
    // Retourne la longitude du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    void setLongitude(double longitude);
    // Mode d'emploi :
    // Modifie la longitude du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    bool getValide() const;
    // Mode d'emploi :
    // Retourne le statut de validité du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    void setValide(bool status);
    // Mode d'emploi :
    // Modifie le statut de validité du capteur.
    // Contrat :
    // Aucun contrat spécifique.

    vector<Mesures> getMesure() const;
    // Mode d'emploi :
    // Retourne les mesures enregistrées par le capteur.
    // Contrat :
    // Aucun contrat spécifique.

    void setMesure(Mesures  m);
    // Mode d'emploi :
    // Ajoute une mesure au capteur.
    // Contrat :
    // Aucun contrat spécifique.


//----------------------------------------------------- Méthode pour l'application

    void invaliderCapteur();
    // Mode d'emploi :
    // Invalide le capteur en modifiant son statut de validité.
    // Contrat :
    // Aucun contrat spécifique.

    double genererValeurQualite(Periode * p);

//------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const Capteur & c);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Capteur.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Capteur & operator = (const Capteur & c);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Capteur.
    // Contrat :
    // Aucun contrat spécifique.
    
//-------------------------------------------- Constructeurs - destructeur

    Capteur(int id, double lat, double lng, bool valide);
    // Mode d'emploi :
    // Constructeur de la classe Capteur.
    // Contrat :
    // Aucun contrat spécifique.

protected:
//----------------------------------------------------- Attributs protégés

    int identifiant;                        // Identifiant du capteur
    double latitude;                        // Latitude du capteur
    double longitude;                       // Longitude du capteur
    bool valide;                            // Statut de validité du capteur
    vector<Mesures> mesures;                // Mesures enregistrées par le capteur
};

#endif // CAPTEUR_H

