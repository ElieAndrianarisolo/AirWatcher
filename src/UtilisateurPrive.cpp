/*************************************************************************
UtilisateurPrive  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//Réalisation de la classe <UtilisateurPrive> (fichier UtilisateurPrive.cpp)------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "UtilisateurPrive.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Getters et setters

bool UtilisateurPrive::getFiabilite() const
{
    return fiabilite;
} //----- Fin de getFiabilite

void UtilisateurPrive::setFiabilite(bool fiab)
{
   fiabilite = fiab;
} //----- Fin de setFiabilite

int UtilisateurPrive::getNote() const
{
    return note;
} //----- Fin de getNote

void UtilisateurPrive::setNote(int grade)
{
    note = grade;
} //----- Fin de setNote

Date UtilisateurPrive::getDateDerniereVerification() const
{
    return dateDerniereVerification;
} //----- Fin de getDateDerniereVerification

void UtilisateurPrive::setDateDerniereVerification(Date newDate)
{
    dateDerniereVerification = newDate;
} //----- Fin de setDateDerniereVerification

vector <Capteur> UtilisateurPrive::getCapteursPrives() const
{
    return capteursPrives;
} //----- Fin de getCapteursPrives

void UtilisateurPrive::setCapteursPrives(Capteur capteursPrives)
{
    this->capteursPrives.push_back(capteursPrives);
} //----- Fin de setCapteursPrive

//-------------------------------------------- Méthodes d'application

void UtilisateurPrive::augmenterNote()
{
    ++note;
} //----- Fin de augmenterNote

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const UtilisateurPrive & unUtilisateurPrive)
{
    os << "UtilisateurPrive : {id : " << unUtilisateurPrive.id << ", prenom : " << unUtilisateurPrive.prenom << ", nom :  " << unUtilisateurPrive.nom << "adresse : " << unUtilisateurPrive.adresse << ", login : " << unUtilisateurPrive.login << ", mot de passe : " << unUtilisateurPrive.motDePasse << ", fiabilite : " << unUtilisateurPrive.fiabilite << ", note : " << unUtilisateurPrive.note << endl;
    
    for(int i=0; i<unUtilisateurPrive.capteursPrives.size(); i++)
    {
        os << unUtilisateurPrive.capteursPrives[i];
    }
    
    return os; 
} //----- Fin de operator <<

UtilisateurPrive &UtilisateurPrive::operator=(const UtilisateurPrive &unUtilisateurPrive)
{
    id = unUtilisateurPrive.id;
    prenom = unUtilisateurPrive.prenom;
    nom = unUtilisateurPrive.nom;
    adresse = unUtilisateurPrive.adresse;
    login = unUtilisateurPrive.login;
    motDePasse = unUtilisateurPrive.motDePasse;
    fiabilite = unUtilisateurPrive.fiabilite;
    note = unUtilisateurPrive.note;
    dateDerniereVerification = unUtilisateurPrive.dateDerniereVerification;

    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

UtilisateurPrive::UtilisateurPrive(int newId, string newPrenom, string newNom, string newAdresse, string newLogin, string newMotDePasse, bool newFiabilite, int newNote, Date newDate) : Personne(newId,newPrenom,newNom,newAdresse,newLogin,newMotDePasse), fiabilite(newFiabilite), note(newNote), dateDerniereVerification(newDate)
{
    #ifdef MAP
        cout << "Appel au constructeur de <UtilisateurPrive>" << endl;
    #endif
} //----- Fin de UtilisateurPrive
