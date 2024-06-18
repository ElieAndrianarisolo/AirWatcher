/*************************************************************************
Main -  description

début      : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Interface du module <Main> (fichier Main.h) ----------------------------
#if ! defined (MAIN_H)
#define MAIN_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <regex>
#include <sstream>
#include <chrono>
#include "Zone.h"
#include "Date.h"
#include "Periode.h"
#include "Personne.h"
#include "Attributs.h"
#include "Mesures.h"
#include "Capteur.h"
#include "Cleaner.h"
#include "Personne.h"
#include "UtilisateurPrive.h"
#include "Fournisseur.h"
#include "AgentGouvernement.h"
#include "Data.h"

//------------------------------------------------------------------------
// Rôle du module <Main> :
// Définir la fonction main et se charger du chemin d'exécution de 
// l'application et de l'interface avec l'utilisateur
//------------------------------------------------------------------------

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------------- Constantes

//---------------------------------------------------------- Types publics

vector<double> init;
vector<double> perf1; // Vecteur de performances de l'algo 1
vector<double> perf2; // Vecteur de performances de l'algo 2

//---------------------------------------------------- Fonctions publiques

int main();
// Mode d'emploi :
// Point d'entrée de l'application
// Contrat :
// Aucun contrat spécifique.

bool estFormatZoneValide(const string& zone);
// Mode d'emploi :
// Vérifie si le format d'une zone est valide.
// Contrat :
// Aucun contrat spécifique.

bool estFormatPeriodeValide(const string& periode);
// Mode d'emploi :
// Vérifie si le format d'une période est valide.
// Contrat :
// Aucun contrat spécifique.

bool estFormatNumeroValide(const string& numero);
// Mode d'emploi :
// Vérifie si le format d'un numéro est valide.
// Contrat :
// Aucun contrat spécifique.

bool estFormatIdValide(const string& id);
// Mode d'emploi :
// Vérifie si le format d'un ID est valide.
// Contrat :
// Aucun contrat spécifique.

bool estFormatDateValide(int annee, int mois, int jour);
// Mode d'emploi :
// Vérifie si le format d'une date est valide.
// Contrat :
// Aucun contrat spécifique.

bool estBissextile(int annee);
// Mode d'emploi :
// Vérifie si une année est bissextile.
// Contrat :
// Aucun contrat spécifique.

string enleverZeros(const string& str);
// Mode d'emploi :
// Enlève les zéros non significatifs d'une chaîne de caractères.
// Contrat :
// Aucun contrat spécifique.

#endif // MAIN_H
