/*************************************************************************
 Attributs  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI
e-mail               : aya.talbi-el-alami@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attributs> (fichier Attributs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Attributs.h"

//----------------------------------------------------------------- PUBLIC

//---------------------------------------------------------- Getters et setters

string Attributs::getDescription() const
{
    return description;
} //----- Fin de getDescription

string Attributs::getId() const
{
    return Id;
} //----- Fin de getId

string Attributs::getUnite() const
{
    return unite;
} //----- Fin de getUnite

void Attributs::setId(string id) 
{
    Id = id;
} //----- Fin de setId

void Attributs::setUnite(string unit)
{
    unite = unit;
} //----- Fin de setUnite

void Attributs::setDescription(string des)
{
    description = des;
} //----- Fin de setDescription

//-------------------------------------------------- Méthodes d'application

int Attributs::getIndiceATMO(double valeur) const
{
    for(int i = 1; i < 10; i++)
    {
        
        if(valeur < seuils[i])
        {
            return i-1;
        }

    }

    return 10;
} //----- Fin de getIndiceATMO

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream & os, const Attributs & attributs)
{
    os << "---- Attributs : " << attributs.Id << "----" << endl;
    os << "Unité : " << attributs.unite << endl;
    os << "Description : " << attributs.description << endl;

    return os;
} //----- Fin de operator <<

Attributs &Attributs::operator=(const Attributs &attributs) 
{
    Id = attributs.Id;
    unite = attributs.unite;
    description = attributs.description;
    
    for (int i = 0; i < 11; i++) 
    {
        seuils[i] = attributs.seuils[i]; 
    }   

    return (*this);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur

Attributs::Attributs()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Attributs>" << endl;
    #endif
} //----- Fin de Attributs

Attributs::Attributs(string id, string unit, string des, int seuil[])
{

    #ifdef MAP
        cout << "Appel au constructeur de <Attributs>" << endl;
    #endif

    Id = id;
    unite = unit;
    description = des;

    for (int i = 0; i < 11; i++) 
    {
        seuils[i] = seuil[i]; 
    }   
} //----- Fin de Attributs





