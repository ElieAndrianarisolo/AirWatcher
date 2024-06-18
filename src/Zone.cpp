/*************************************************************************
Zone  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Elie ANDRIANARISOLO
e-mail               : elie.andrianarisolo@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Zone> (fichier Zone.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Zone.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Getters et setters

double Zone::getLat() const
{
    return latitude;
} //----- Fin de getLat

double Zone::getLong() const
{
    return longitude;
} //----- Fin de getLong

double Zone::getRayon() const
{
    return rayon;
} //----- Fin de getRayon

void Zone::setLat(double lati){
    latitude = lati;
} //----- Fin de setLat

void Zone::setLong(double longi)
{
    longitude = longi;
} //----- Fin de setLong

void Zone::setRayon(double r)
{
    rayon = r;
} //----- Fin de setRayon

//-------------------------------------------- Méthodes d'application

bool Zone::contient(double lati, double longi) const
{
    return ((pow((latitude - lati), 2.0) + pow((longitude - longi), 2.0)) <= pow(rayon, 2.0));
} //----- Fin de contient

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Zone & z)
{
    os << "Zone : {latitude : " << z.latitude << ", longitude : " << z.longitude << ", rayon :  " << z.rayon << "}";   

    return os; 
} //----- Fin de operator <<

Zone &Zone::operator=(const Zone &z)
{
    latitude = z.latitude;
    longitude = z.longitude;
    rayon = z.rayon;

    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Zone::Zone(double lati, double longi)
{
    latitude = lati;
    longitude = longi;
    rayon = 0;

    #ifdef MAP
        cout << "Appel au constructeur de <Zone>" << endl;
    #endif
} //----- Fin de Zone

Zone::Zone(double lati, double longi, double r)
{
    latitude = lati;
    longitude = longi;
    rayon = r;

    #ifdef MAP
        cout << "Appel au constructeur de <Zone>" << endl;
    #endif
} //----- Fin de Zone
