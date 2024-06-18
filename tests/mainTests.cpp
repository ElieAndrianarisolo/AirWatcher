/*************************************************************************
mainTests.cpp -   Zone de tests pour les fonctionnalités importantes
                  du logiciel AirWatcher
                  Les méthodes sont classées dans l'ordre alphabétique
                  aucun autre ordre ne prévaut

début      : 10/05/2023
copyright            : (C) 2023 Billy VILLEROY
e-mail               : billy.villeroy@insa-lyon.fr
*************************************************************************/

//Réalisation du module <mainTests.cpp> (fichier mainTests.cpp)-------------------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "../src/Zone.h"
#include "../src/Date.h"
#include "../src/Data.h"
#include "../src/Periode.h"
#include "../src/Attributs.h"
#include "../src/Mesures.h"
#include "../src/Capteur.h"
#include "../src/Cleaner.h"
#include "../src/Personne.h"
#include "../src/AgentGouvernement.h"
//----------------------------------------------------------------- PUBLIC

//---------------------------------------------------- Fonctions publiques

//Test du calcul de l'indice ATMO
void TestAttributGetIndice()
{
  double value;
  int seuils[11] ={-1,0,30,55,80,105,130,150,180,210,240};
  Attributs attributs("",(string)"",(string)"",seuils);

  //Récupération des données de std.in
  cin >> value;

  cout << attributs.getIndiceATMO(value) << endl;

}

//Test du calcul de la qualité de l'air sur une période
void TestCapteurQualite()
{
  Data d;

  //Récupération des données comprises dans les .csv
  d.initialiserAttributs();
  d.initialiserCapteurs();
  d.initialiserMesures();

  vector<Capteur> v = d.getListeCapteurs();

  double val;
  int jd,md,ad,jf,mf,af;

  //Récupération des données de std.in
  cin >> jd;
  cin >> md;
  cin >> ad;
  cin >> jf;
  cin >> mf;
  cin >> af;

  Date dd(jd,md,ad);
  Date df(jf,mf,af);

  val = v.at(0).genererValeurQualite(new Periode(dd,df));
  if(val==-1)
    cerr << "la période de temps est incorrecte" << endl;
  else
    cout << val << endl;

}

//Test de l'impact des purificateurs
void TestCleanerImpact(){
  Data d;

  //Récupération des données comprises dans les .csv
  d.initialiserAttributs();
  d.initialiserCapteurs();
  d.initialiserMesures();
  d.initialiserCleaners();

  vector<Cleaner> liste = d.getListeCleaners();
  tuple<double,double> imp = liste.at(0).voirImpact(d);

  cout << get<0>(imp)<<endl;
  cout << get<1>(imp)<<endl;
}

//Test du calcul de la moyenne de la qualité de l'air dans une zone pour une période donnée
void TestDataMoyenne(){

  double latitude, longitude, rayon,moy;
  int jd,md,ad,jf,mf,af;

  Data d;

  //Récupération des données comprises dans les .csv
  d.initialiserAttributs();
  d.initialiserCapteurs();
  d.initialiserMesures();

  //Récupération des données de std.in
  cin >> latitude;
  cin >> longitude;
  cin >> rayon;

  cin >> jd;
  cin >> md;
  cin >> ad;
  cin >> jf;
  cin >> mf;
  cin >> af;
  
  Date dd(jd,md,ad);
  Date df(jf,mf,af);
  
  moy = d.calculerMoyenneAir(new Zone(latitude,longitude,rayon), new Periode(dd,df));
  if(moy!=moy)
    cerr << "Impossible de connaître la qualité de l’air, aucun capteur dans la zone sélectionnée" << endl;
  else if(moy==-1)
    cerr << "La période de temps est incorrecte" << endl;
  else
    cout << moy << endl;

}

//Test sur la date précédente
void TestDatePrecede()
{
  Date date(10,10,2001);
  int jTest, mTest, aTest;

  //Récupération des données de std.in
  cin >> jTest;
  cin >> mTest;
  cin >> aTest;

  cout << date.precede(Date(jTest,mTest,aTest)) << endl;
}

//Test du calcul de la qualité de l'air sur une mesure avec valeur manquante
void TestMesureQualiteM()
{
  double values[3] = {50.25, 74.5, 41.5};
  int seuils_ozone[11] = {-1, 0, 30, 55, 80, 105, 130, 150, 180, 210, 240};
  int seuils_dioxyde_soufre[11] = {-1, 0, 40, 80, 120, 160, 200, 250, 300, 400, 500};
  int seuils_dioxyde_azote[11] = {-1, 0, 30, 55, 85, 110, 135, 165, 200, 275, 400};
  int seuils_particules_en_suspension[11] = {-1, 0, 7, 14, 21, 28, 35, 42, 50, 65, 80};
  
  Attributs ozone =  Attributs("O3", "µg/m3", "concentration d'ozone", seuils_ozone);
  Attributs dioxyde_soufre =  Attributs("SO2", "µg/m3", "concentration de dioxyde de soufre", seuils_dioxyde_soufre);
  Attributs dioxyde_azote =  Attributs("NO2", "µg/m3", "concentration de dioxyde d'azote", seuils_dioxyde_azote);
  Attributs particules_en_suspension =  Attributs("PM10", "µg/m3", "concentration de particules fines", seuils_particules_en_suspension);

  
  Attributs attributs[4] = {ozone,dioxyde_azote,dioxyde_soufre,particules_en_suspension};

  Mesures mesure(values,true,Date(),attributs);

  cout << mesure.calculQualiteAir() << endl;

}

//Test du calcul de la qualité de l'air sur une mesure avec l'ensemble des valeurs
void TestMesureQualiteO()
{
  double values[4] = {48.5, 75.75, 38,46.5};
  int seuils_ozone[11] = {-1, 0, 30, 55, 80, 105, 130, 150, 180, 210, 240};
  Attributs ozone =  Attributs("O3", "µg/m3", "concentration d'ozone", seuils_ozone);

  int seuils_dioxyde_soufre[11] = {-1, 0, 40, 80, 120, 160, 200, 250, 300, 400, 500};
  Attributs dioxyde_soufre =  Attributs("SO2", "µg/m3", "concentration de dioxyde de soufre", seuils_dioxyde_soufre);

  int seuils_dioxyde_azote[11] = {-1, 0, 30, 55, 85, 110, 135, 165, 200, 275, 400};
  Attributs dioxyde_azote =  Attributs("NO2", "µg/m3", "concentration de dioxyde d'azote", seuils_dioxyde_azote);

  int seuils_particules_en_suspension[11] = {-1, 0, 7, 14, 21, 28, 35, 42, 50, 65, 80};
  Attributs particules_en_suspension =  Attributs("PM10", "µg/m3", "concentration de particules fines", seuils_particules_en_suspension);

  Attributs attributs[4] = {ozone,dioxyde_azote,dioxyde_soufre,particules_en_suspension};
  Mesures mesure(values,true,Date(),attributs);

  cout << mesure.calculQualiteAir() << endl;

}

//Test de la validité de la période
void TestPeriodeEstValide()
{
  int jd,md,ad;
  int jf,mf,af;

  //Récupération des données du std.in
  cin >> jd;
  cin >> md;
  cin >> ad;
  cin >> jf;
  cin >> mf;
  cin >> af;

  Periode periode(Date(jd,md,ad),Date(jf,mf,af));
  cout << periode.estValide() << endl;

}

//Test de l'inclusion d'une date dans une période
void TestPeriodeIncluse()
{
  int jt,mt,at;
  Periode periode(Date(1,1,2001),Date(1,1,2002));

  //Récupération des données du std.in
  cin >> jt;
  cin >> mt;
  cin >> at;

  cout << periode.inclu(Date(jt,mt,at)) << endl;

}

//Test de l'inclusion d'un capteur dans une zone
void TestZoneContient()
{
  char carLu[4];
  double latTest, longTest,value;
  int nbParam = 0;

  Zone zone(1, 1);
  zone.setRayon(10);

  if(cin.getline(carLu,'\n')){
      latTest = (double) atof(carLu);
      nbParam++;
      if(cin.getline(carLu,'\n')){
        longTest = strcmp(&carLu[0],"-")==0?  -(double) atof(carLu):(double) atof(carLu);
        nbParam++;
      }
  }

  switch (nbParam)
  {
  case 0:
    cerr << "Aucune valeur n'a été spécifiée" << endl;
    break;
  case 1:
    cerr << "Une valeur n'a pas été spécifiée" << endl;
    break;
  default:
    cout << zone.contient(latTest, longTest) << endl;
    break;
  }
  
}

int main(int argc, char const *argv[])
{
    switch(atoi(argv[1]))
    {
        case 1:
          TestAttributGetIndice();
        break;
        case 2:
          TestCapteurQualite();
        break;
        case 3:
          TestCleanerImpact();
          break;
        case 4:
          TestDataMoyenne();
        break;
        case 5:
          TestDatePrecede();
        break;
        case 6:
          TestMesureQualiteM();
        break;
        case 7:
          TestMesureQualiteO();
          break; 
        case 8:
          TestPeriodeEstValide();
        break;
        case 9:
          TestPeriodeIncluse();
        break;
        case 10:
          TestZoneContient();
        break;  
        
    }
    return 0;
} //----- Fin de mainTest