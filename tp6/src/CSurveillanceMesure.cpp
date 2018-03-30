#include<iostream>
using namespace std;
#include "CSurveillanceMesure.h"
#include <cstdlib>

CSurveillanceMesure::CSurveillanceMesure(float valdefaut)
{

    int i = 0;
    while (i<10)
    {
        this->tabMesures[i] = valdefaut;
        i++;
    }
    this->nbMesures = 0;
}

bool CSurveillanceMesure::mesurer()
{
    float n;
    int j = 1;
    cout << "rentrez une mesure" << endl;
    cin >> n;

    if (this->nbMesures == 10)
    {
        while (j<10)
            {
                this->tabMesures[j-1] = this->tabMesures[j];
                j++;
            }
    this->tabMesures[9] = n;
    return true;

    }
    else
    {
        this->tabMesures[this->nbMesures] = n;
        this->nbMesures = this->nbMesures + 1;
        return true;
    }
    return false;


}

float CSurveillanceMesure::valMesuree()
{
        return this->tabMesures[(this->nbMesures-1)];
}

float CSurveillanceMesure::valMin()
{
    int i = 0;
    int minimum;
    minimum = this->tabMesures[0];

    while (i < this->nbMesures)
        {
            if (this->tabMesures[i] <  minimum)
                {
                    minimum = this->tabMesures[i];
                }
                i++;
            }
            return minimum;
}

float CSurveillanceMesure::valMax()
{
    int maximum;
    int i = 0;
    maximum = this->tabMesures[0];

       while (i < this->nbMesures)
            {
              if (this->tabMesures[i] >  maximum)
                {
                    maximum = this->tabMesures[i];
                }
                i++;
            }
            return maximum;
}

float CSurveillanceMesure::moyenne()
{
    int i = 0;
    float somme = 0;
    float moyenne;

while (i < this->nbMesures)
        {
            somme = this->tabMesures[i] + somme;
            i++;
        }

    moyenne = somme/this->nbMesures;
    return moyenne;
}


void CSurveillanceMesure::tritableau()
{
    int i = 0;
    float temp;

        while (i < (this->nbMesures-1))
        {
            if(this->tabMesures[i+1] < this->tabMesures[i])
                   {
                       temp = this->tabMesures[i];
                       this->tabMesures[i] = this->tabMesures[i+1];
                       this->tabMesures[i+1] = temp;
                   }
                i++;
        }
}

float CSurveillanceMesure::mediane()
{
    int i = 0;
    float tab[10];
    float mediane;
    //int test;

    while(i<10)
    {
        tab[i] = this->tabMesures[i];
        i++;
    }

    tritableau();

    if(this->nbMesures%2 == 0)
    {
        mediane = this->tabMesures[this->nbMesures/2] + this->tabMesures[this->nbMesures/2-1];
        mediane = mediane/2;
    }
    else
    {
       mediane  = this->tabMesures[(this->nbMesures-1)/2];
    }
    i = 0;
    while(i<10)
    {
        this->tabMesures[i] = tab[i];
        i++;
    }
    return mediane;

}
bool CSurveillanceMesure::moyenneGlissante(float &moyenne, int nbvaleurs, int indiceMesure1)
{
    float somme = 0;
    int i = indiceMesure1-1;
    while (i<nbvaleurs)
    {
        somme = this->tabMesures[i] + somme;
        i++;
    }
    moyenne = somme / nbvaleurs;
    return true;
}
void CSurveillanceMesure::affichemesures()
{
    system("cls");
    int i = 0;
    while (i<10)
    {
        cout << "valeur numero " << i+1 << " = " << this->tabMesures[i] << endl;
        i++;
    }
    cout << " " << endl;
    cout << "appuyez sur une touche pour revenir au menu principal (appuyez sur 0 pour cacher les mesures)" << endl;
    cin >> i;
    if(i==0)
    {
        system("cls");
    }
}



