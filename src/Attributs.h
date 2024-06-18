/*************************************************************************
 Attributs  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI 
e-mail               : aya.talbi-el-alami@insa-lyon.fr 
*************************************************************************/

//---------- Interface de la classe <Attributs> (fichier Attributs.h) ----------------
#if ! defined (ATTRIBUTS_H)
#define ATTRIBUTS_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>
#include <vector>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attributs>
// Représente les attributs d'une mesure
//------------------------------------------------------------------------

class Attributs
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Getters et setters

    string getId() const;
    // Mode d'emploi :
    // Retourne l'identifiant de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

    string getUnite() const;
    // Mode d'emploi :
    // Retourne l'unité de mesure de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

    string getDescription() const;
    // Mode d'emploi :
    // Retourne la description de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

    void setId(string id);
    // Mode d'emploi :
    // Modifie l'identifiant de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

    void setUnite(string unit);
    // Mode d'emploi :
    // Modifie l'unité de mesure de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

    void setDescription(string des);
    // Mode d'emploi :
    // Modifie la description de l'attribut.
    // Contrat :
    // Aucun contrat spécifique.

//----------------------------------------------------- Méthode pour l'application

    int getIndiceATMO(double valeur) const;
    // Mode d'emploi :
    // Retourne l'indice ATMO en fonction d'une valeur donnée.
    // Contrat :
    // Aucun contrat spécifique.

//------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator<<(ostream & os, const Attributs & attributs);
    // Mode d'emploi :
    // Surcharge de l'opérateur de flux de sortie << pour la classe Attributs.
    // Contrat :
    // Le flux de sortie doit être valide et ouvert avant d'appeler cette surcharge.

    Attributs & operator = (const Attributs & attributs);
    // Mode d'emploi :
    // Surcharge de l'opérateur d'affectation pour la classe Attributs.
    // Contrat :
    // Aucun contrat spécifique.

//-------------------------------------------- Constructeurs - destructeur
    
    Attributs();
    // Mode d'emploi :
    // Constructeur par défaut de la classe Attributs.
    // Contrat :
    // Aucun contrat spécifique.

    Attributs(string id, string unit, string des, int seuils[]);
    // Mode d'emploi :
    // Constructeur de la classe Attributs.
    // Initialise les attributs avec les valeurs fournies.
    // Contrat :
    // Aucun contrat spécifique.


protected:
//----------------------------------------------------- Attributs protégés

    string Id;                      // Identifiant de l'attribut
    string unite;                   // Unité de mesure de l'attribut
    string description;             // Description de l'attribut
    int seuils[11];                   // Tableau de seuils pour l'attribut
};

#endif // Attributs_H

