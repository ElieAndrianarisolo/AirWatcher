/*************************************************************************
 Data  -  description
-------------------
début                : 10/05/2023
copyright            : (C) 2023 Aya TALBI EL ALAMI 
e-mail               : aya.talbi-el-alami@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Data> (fichier Data.cpp) -----------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "Data.h"

//----------------------------------------------------------------- PUBLIC
Attributs attributs[4];

//-------------------------------------------- Getters et setters

vector<Capteur> Data::getListeCapteurs() const
{
    return listeCapteurs;
} //----- Fin de getListeCapteurs

vector<Cleaner> Data::getListeCleaners() const
{
    return listeCleaners;
} //----- Fin de getListeCleaners

vector<UtilisateurPrive> Data::getListeUtilisateurPrive() const
{
    return listeUtilisateursPrives;
} //----- Fin de getListeUtilisateurPrive

vector<Capteur>  Data::getListeCapteursPrives() const
{
    return listeCapteursPrives;
} //----- Fin de getListeCapteursPrives

Date Data::getDateDerniereVerification() const
{
    return dateDerniereVerification;
} //----- Fin de getDateDerniereVerification

//-------------------------------------------- Méthodes d'application

void Data::initialiserAttributs()
{
    int seuils_ozone[11] = {-1, 0, 30, 55, 80, 105, 130, 150, 180, 210, 240};
    Attributs ozone =  Attributs("O3", "µg/m3", "concentration d'ozone", seuils_ozone);

    int seuils_dioxyde_soufre[11] = {-1, 0, 40, 80, 120, 160, 200, 250, 300, 400, 500};
    Attributs dioxyde_soufre =  Attributs("SO2", "µg/m3", "concentration de dioxyde de soufre", seuils_dioxyde_soufre);

    int seuils_dioxyde_azote[11] = {-1, 0, 30, 55, 85, 110, 135, 165, 200, 275, 400};
    Attributs dioxyde_azote =  Attributs("NO2", "µg/m3", "concentration de dioxyde d'azote", seuils_dioxyde_azote);

    int seuils_particules_en_suspension[11] = {-1, 0, 7, 14, 21, 28, 35, 42, 50, 65, 80};
    Attributs particules_en_suspension =  Attributs("PM10", "µg/m3", "concentration de particules fines", seuils_particules_en_suspension);

    attributs[0] = ozone;
    attributs[1] = dioxyde_azote;
    attributs[2] = dioxyde_soufre;
    attributs[3] = particules_en_suspension;
}

void Data::initialiserCapteurs()
{
    string file_sensors = "sensors.csv";
    
    fstream fin;
    fin.open(file_sensors, ios::in);

    string line, id, lat, lng;
    double LAT, LNG;

    while(getline(fin, line))
    {
        
        stringstream str(line);
        getline(str, id, ';');
        id = id.substr(6, 2);

        int d = atoi(id.c_str());

        getline(str, lat, ';');
        LAT = stod(lat);

        getline(str, lng, ';');
        LNG = stod(lng);

        Capteur c(d, LAT, LNG, true);
        listeCapteurs.push_back(c);
    }

} //----- Fin de initialiserCapteurs

void Data::initialiserCleaners()
{
    string file_cleaners = "cleaners.csv";
    
    fstream fin;
    fin.open(file_cleaners, ios::in);

    string line, cleaner_id, cleaner_lat, cleaner_lng, temp;
    string jour_debut, mois_debut, annee_debut, jour_fin, mois_fin, annee_fin;
    double LAT, LNG;

    int JOUR_DEBUT, MOIS_DEBUT, ANNEE_DEBUT, JOUR_FIN, MOIS_FIN, ANNEE_FIN, CLEANER_ID, FOURNISSEUR_ID = 0;

    while(getline(fin, line))
    {
        
        stringstream str(line);
        getline(str, cleaner_id, ';');
        cleaner_id = cleaner_id.substr(7, 2);
        CLEANER_ID = atoi(cleaner_id.c_str());
        
        getline(str, cleaner_lat, ';');
        LAT = stod(cleaner_lat);

        getline(str, cleaner_lng, ';');
        LNG = stod(cleaner_lng);

        getline(str, annee_debut, '-');
        getline(str, mois_debut, '-');
        getline(str, jour_debut, ' ');
        JOUR_DEBUT = atoi(jour_debut.c_str());
        MOIS_DEBUT = atoi(mois_debut.c_str());
        ANNEE_DEBUT = atoi(annee_debut.c_str());

        getline(str, temp, ';'); 

        getline(str, annee_fin, '-');
        getline(str, mois_fin, '-');
        getline(str, jour_fin, ' ');
        JOUR_FIN = atoi(jour_fin.c_str());
        MOIS_FIN = atoi(mois_fin.c_str());
        ANNEE_FIN = atoi(annee_fin.c_str());
        
        getline(str, temp, ';');

        Cleaner c(CLEANER_ID, FOURNISSEUR_ID, LAT, LNG, Date(JOUR_DEBUT, MOIS_DEBUT, ANNEE_DEBUT), Date(JOUR_FIN, MOIS_FIN, ANNEE_FIN));
        listeCleaners.push_back(c);
        FOURNISSEUR_ID++;
    }

} //----- Fin de initialiserCleaners

void Data::initialiserDonneesPrives()
{
    string file_users= "users.csv";

    fstream fin;
    fin.open(file_users, ios::in);

    string line, user_id, capteur_id;
    int USER_ID, CAPTEUR_ID, NOTE = 0;

    while(getline(fin, line))
    {

        stringstream str(line);
        getline(str, user_id, ';');
        user_id = user_id.substr(4,2);
        USER_ID = atoi(user_id.c_str());

        getline(str, capteur_id, ';');
        capteur_id = capteur_id.substr(6, 2);
        CAPTEUR_ID = atoi(capteur_id.c_str());

        UtilisateurPrive u = UtilisateurPrive(USER_ID, "Peter", "Parker", "20 Rue Ingram, NYC, USA", "pparker", "mdp", true, ++NOTE, Date(1,2,2019));
        listeUtilisateursPrives.push_back(u);
        listeUtilisateursPrives[USER_ID].setCapteursPrives(listeCapteurs[CAPTEUR_ID]);

        listeCapteursPrives.push_back(listeCapteurs[CAPTEUR_ID]);
    }

} //----- Fin de initialiserDonneesPrives

void Data::initialiserMesures()
{
    string file_measurements = "measurements.csv";
    
    fstream fin;
    fin.open(file_measurements, ios::in);

    string line;
    int ANNEE, MOIS, JOUR, CAPTEUR_ID;
    Date debut;        
    double values[4];
    
    while(!fin.eof())
    {

        int i = 0;
        string annee, mois, jour, capteur_id, temp;
        
        while(i<4 && getline(fin, line))
        {

            stringstream str(line);
            string unite, mesure;

            if(line.size() > 0)
            {
                
                getline(str, annee, '-');
                getline(str, mois, '-');
                getline(str, jour, ' ');
                JOUR = atoi(jour.c_str());
                MOIS = atoi(mois.c_str());
                ANNEE = atoi(annee.c_str());
             
                getline(str, temp, ';');
                getline(str, capteur_id, ';');
                capteur_id = capteur_id.substr(6,2);  
                CAPTEUR_ID = atoi(capteur_id.c_str());

                getline(str, unite, ';');
                getline(str, mesure, ';');
                values[i] = stod(mesure);
                
                debut = Date(JOUR, MOIS, ANNEE);
                i++;
            }

        }

        listeCapteurs[CAPTEUR_ID].setMesure(Mesures(values, true, debut, attributs));
    }

} //----- Fin de initialiserMesures

double Data::calculerMoyenneAir(Zone * zone, Periode * periode)
{
    double qualite = 0;
    double nbCapteurs = 0;

    assert(listeCapteurs.size() > 0);
    if(!periode->estValide()){
        return -1;
    }
    
    for(int i = 0 ; i<listeCapteurs.size(); i++)
    {

        if(zone->contient(listeCapteurs[i].getLatitude(), listeCapteurs[i].getLongitude()))
        {
            
            nbCapteurs++;
            qualite += listeCapteurs[i].genererValeurQualite(periode);

            for(int j = 0; j<listeCapteursPrives.size(); j++)
            {
             
                if(listeCapteursPrives[j].getId() == listeCapteurs[i].getId())
                {

                    for(int m = 0; m<listeUtilisateursPrives.size(); m++)
                    {

                        vector<Capteur> c = listeUtilisateursPrives[m].getCapteursPrives();
                        
                        for (int p = 0; p<c.size(); p++)
                        {
                            if(c[p].getId() == listeCapteurs[i].getId())
                            {
                                listeUtilisateursPrives[m].augmenterNote();
                            }
                        }

                    }
                }

            }
    
        }

    }

    return qualite/nbCapteurs;
} //----- Fin de calculerMoyenneAir

tuple<bool, int>  Data::findFournisseur(int idF) const
{

    for(int i = 0; i<listeCleaners.size(); i++)
    {
        if(listeCleaners[i].getFournisseurId() == idF)
        {
            return make_tuple(true,  i);;
        }
    }

    return make_tuple(false,  -1);
} //----- Fin de findFournisseur

tuple<bool, int> Data::findUtilisateurPrive(int idUP) const
{

    for(int i = 0; i<listeUtilisateursPrives.size(); i++)
    {
        if(listeUtilisateursPrives[i].getId() == idUP)
        {
            return make_tuple(true,  i);
        }
    }

    return make_tuple(false,  -1);
} //----- Fin de findUtilisateurPrive

//-------------------------------------------- Constructeurs - destructeur

Data::Data()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Data>" << endl;
    #endif
} //----- Fin de Data


