#include<iostream>
using namespace std;
#include "CSurveillanceMesure.h"
#include <cstdlib>

CSurveillanceMesure::CSurveillanceMesure(float valdefaut)
{

    int i = 0; //compteur
    while (i<10)
    {
        this->tabMesures[i] = valdefaut; //on initialise le tableau de mesures avec la valeur par défaut
        i++;
    }
    this->nbMesures = 0; //on initialise le nombre de valeurs a 0
}

bool CSurveillanceMesure::mesurer()
{
    float mesure; //mesure rentree par l'utilisateur
    int j = 1;
    cout << "rentrez une mesure" << endl;
    cin >> mesure;

    if (this->nbMesures == 10) //si le tableau est plein, il faut "supprimer" la premiere mesure du tableau et decaler les autres mesures
    {
        while (j<10) //on parcourt tout le tableau
            {
                this->tabMesures[j-1] = this->tabMesures[j]; //on remplace la case j-1 du tableau par la case j
                j++; //compteur boucle
            }
    this->tabMesures[9] = mesure; //on range la mesure rentree par l'utilisateur dans la derniere case du tableau
    system("cls");
    return true; //tout s'est bien passe
    //il est important de noter que l'on incremente plus notre nombre de mesures, le tableau etant deja plein
    }
    else //si le tableau n'est pas plein
    {
        this->tabMesures[this->nbMesures] = mesure; //on range la mesure dans le tableau
        this->nbMesures = this->nbMesures + 1; //on incremente le nombre de mesure
        system("cls");
        return true; //tout s'est bien passe
    }
    return false; //quelque chose s'est mal deroule


}

float CSurveillanceMesure::valMesuree()
{
        return this->tabMesures[(this->nbMesures-1)]; //on renvoie la derniere valeur dans le tableau
}

float CSurveillanceMesure::valMin()
{
    int i = 0; //compteur de boucle
    int minimum;
    minimum = this->tabMesures[0]; //on initialise minimum a la premiere valeur du tableau

    while (i < this->nbMesures) //on effectue l'operation pour le nombre de mesures
        {
            if (this->tabMesures[i] <  minimum) //on cherche a savoir lorsqu'on parcourt le tableau, si une des valeurs est inferieure a la variable "minimum"
                {
                    minimum = this->tabMesures[i]; //si oui, alors minimum prend cette valeur
                }
                i++; //incrementation compteur
            }
            return minimum; //on renvoie le minimum
}

float CSurveillanceMesure::valMax()
{
    int maximum;
    int i = 0; //compteur de boucle
    maximum = this->tabMesures[0]; //on initialise maximum a la premiere valeur du tableau

       while (i < this->nbMesures) //on effectue l'operation pour le nombre de mesures
            {
              if (this->tabMesures[i] >  maximum) //on cherche a savoir lorsqu'on parcourt le tableau, si une des valeurs est superieure a la variable "maximum"
                {
                    maximum = this->tabMesures[i]; //si oui, alors maximum prend cette valeur
                }
                i++; //incrementation compteur
            }
            return maximum; //on renvoie le maximum
}

float CSurveillanceMesure::moyenne()
{
    int i = 0; //compteur de boucle
    float moyenne = 0; //moyenne des nombres

while (i < this->nbMesures) //on effectue l'operation pour le nombre de mesures
        {
            moyenne = this->tabMesures[i] + moyenne; //on fait la somme de toutes les mesures
            i++; //incrementation compteur
        }

    moyenne = moyenne/this->nbMesures; //on divise la somme des nombres par le nombre de mesures pour obtenir la moyenne
    return moyenne; //on renvoie la moyenne
}


void CSurveillanceMesure::tritableau()
{
    float tmp; //valeur temporaire pour stocker une valeur
    int i = 0; //compteur
    int j = 0; //compteur


    while (j < this->nbMesures-1) //on effectue l'operation pour tout le tableau
    {
        while (i < (this->nbMesures-1)) //on va parcourir tout le tableau, et faire "remonter" la mesure la plus haute en haut du tableau
        {
            if(this->tabMesures[i] > this->tabMesures[i+1]) //on regarde la valeur du tableau est superieure a la valeur qui suit
                   {
                       tmp = this->tabMesures[i]; //on stocke la valeur du tableau dans la variable temporaire
                       this->tabMesures[i] = this->tabMesures[i+1]; //on remplace la valeur du tableau par sa velru suivante
                       this->tabMesures[i+1] = tmp; //puis la valeur suivante recoit la valeur stockee dans variable temporaire
                       // on a interverti deux valeurs avec succes
                    }

                i++;
        }
        i = 0;
        j++;
    }
}

float CSurveillanceMesure::mediane()
{
    int i = 0; //compteur
    float tab[10]; //on declare un tableau de 10 flottants
    float mediane; //mediane

    while(i<10)
    {
        tab[i] = this->tabMesures[i]; //on copie notre tableau dans notre tableau nouvellement créé
        i++;
    }

    tritableau(); //on appelle la fonction qui va trier notre tableau dans l'ordre croissant

    if(this->nbMesures%2 == 0) //on regarde le reste de la division par 2 du nombre de mesures, pour tester la parite
    {
        mediane = this->tabMesures[this->nbMesures/2] + this->tabMesures[this->nbMesures/2-1]; //ici le nombre de mesures est pair, on va donc faire la somme des mesures du milieu
        mediane = mediane/2; //puis les diviser par 2 pour obtenir la moyenne
    }
    else
    {
       mediane  = this->tabMesures[(this->nbMesures-1)/2]; //si le nombre de mesures est impair, on prend juste la valeur au milieu
    }
    i = 0; //on remet le compteur a 0
    while(i<10)
    {
        this->tabMesures[i] = tab[i]; //on annule le tri du tableau, pour retrouver notre ordre original
        i++;
    }
    return mediane; //on renvoie la mediane

}
bool CSurveillanceMesure::moyenneGlissante(float &moyenne, int nbvaleurs, int indiceMesure1)
{
    int i = 0;
    int j = indiceMesure1-1;

    while (i<nbvaleurs)
    {
        moyenne = this->tabMesures[j] + moyenne;
        i++;
        j++;
    }
    moyenne = moyenne / nbvaleurs;
    if (moyenne == -1)
    {
        return false;
    }
    else
    {
       return true;
    }
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



