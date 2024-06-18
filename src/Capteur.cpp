/*************************************************************************
 Capteur  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI
e-mail               : aya.talbi-el-alami@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Capteur.h"
//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------ Getters et setters

int Capteur::getId() const
{
    return identifiant;
} //----- Fin de getId

double Capteur::getLatitude() const
{
    return latitude;
} //----- Fin de getLatitude

double Capteur::getLongitude() const
{
    return longitude;
} //----- Fin de getLongitude

bool Capteur::getValide() const
{
    return valide;
} //----- Fin de getValide

vector<Mesures> Capteur::getMesure() const
{
    return mesures;
} //----- Fin de getMesure

void Capteur::setId(int Id)
{
    identifiant = Id;
} //----- Fin de setId

void Capteur::setLatitude(double lat)
{
    latitude = lat;
} //----- Fin de setLatitude

void Capteur::setLongitude(double lng)
{
    longitude = lng;
} //----- Fin de setLongitude

void Capteur::setValide(bool status)
{
    valide = status;
} //----- Fin de setValide

void Capteur::setMesure(Mesures m)
{
    mesures.push_back(m);
} //----- Fin de setMesure

//-------------------------------------------------- Méthodes d'applications

void Capteur::invaliderCapteur()
{
    valide = false;
} //----- Fin de invaliderCapteur

double Capteur::genererValeurQualite(Periode * p)
{
    //On teste si la période est valide
    if(!p->estValide()){
        return -1;
    }

    double qualite = 0.0;
    double nbMesures = 0.0;
    
    for(int i = 0; i<mesures.size(); i++)
    {

        if(p->inclu(mesures[i].getDate()))
        {
            qualite += mesures[i].calculQualiteAir();
            nbMesures++;
        }

    }

    return qualite/nbMesures;
} //----- Fin de genererValeurQualite

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Capteur & c)
{
    os << "---- Capteur n°" << c.identifiant << "----" << endl;
    os << "Localisation : Lat : " << c.latitude << "; Long : " << c.longitude << endl;
    os << "Mesures : " << endl;
    
    for(int i=0; i<c.mesures.size(); i++)
    {
        os << c.mesures[i] << " ";
    }

    os << endl;

    return os;
} //----- Fin de operator <<

Capteur &Capteur::operator=(const Capteur &c)
{

    identifiant = c.identifiant;
    latitude = c.latitude;
    longitude = c.longitude;
    valide = c.valide;
    mesures = c.mesures;
    
    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Capteur::Capteur(int id, double lat, double lng, bool status)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif

    identifiant = id;
    latitude = lat;
    longitude = lng;
    valide = status;
} //----- Fin de Capteur


