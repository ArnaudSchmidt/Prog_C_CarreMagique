
#include <stdio.h>
#include <stdlib.h>
#define Dimension 13

//On d�finit une structure qui correspondra � la position d'une case dans le carr� magique.
typedef struct Position
{

    int x;
    int y;

}Position;

//On d�clare les prototypes (ils sont expliqu�s individuellement plus bas).
void Initialisation(Position *pPosi, int tabCarre[][Dimension]);
void RempliTab(Position *pPosi, int tabCarre[][Dimension], int NumCase);
int Augmente(int valeur);
int Diminue(int valeur);

int main()
//BUT :
//ENTREE :
//SORTIE :
{

    //On initialise les diff�rentes variables utiles.
    int tabCarre[Dimension][Dimension];
    int Cases = Dimension * Dimension;
    int NumCase;
    Position Posi;

    //On d�clare �galement un poiteur pour acc�der � la variable depuis d'autres fonctions/proc�dures.
    Position *pPosi = &Posi;

    Initialisation(pPosi, tabCarre);

    //On passe sur tout le tableau afin de changer la valeur des cases.
    for(NumCase = 2 ; NumCase <= Cases ; NumCase++)
    {

        RempliTab(pPosi, tabCarre, NumCase);

    }

    //On repasse une derni�re fois sur le tableau pour afficher chacune des cases.
    for(Posi.y = Dimension - 1; Posi.y >= 0; Posi.y--)
    {

        for(Posi.x = 0; Posi.x <= Dimension - 1; Posi.x++)
        {

            printf("%d \t",tabCarre[Posi.x][Posi.y]);

        }

        printf("\n");

    }

    return 0;

}


void Initialisation(Position *pPosi, int tabCarre[][Dimension])
//BUT : Proc�dure qui initialise tout le tableau, en deux temps : d'abord elle le remplit de 0, puis elle met en place le 1 au dessus du milieu du carr�.
//ENTREE : Le pointeur de la position de la case qu'on consulte ainsi que le tableau du carr� magique.
//SORTIE : Un tableau pr�t � �tre utilis�.
{

    //Premi�re partie : on remplit le tableau de 0.
    for(pPosi -> x = 0; pPosi -> x <= Dimension - 1; pPosi -> x++)
    {

        for(pPosi -> y = 0; pPosi -> y <= Dimension - 1; pPosi -> y++)
        {

            tabCarre[pPosi -> x][pPosi -> y] = 0;

        }

    }

    //Deuxi�me partie : on met en place le 1, notre point de d�part.
    pPosi -> x = Dimension / 2;
    pPosi -> y = Dimension / 2 + 1;
    tabCarre[pPosi -> x][pPosi -> y] = 1;

}


void RempliTab(Position *pPosi, int tabCarre[][Dimension], int NumCase)
//BUT : Remplace les 0 dans le tableau, si on tombe sur un chiffre autre que 0, on ira sur la case en haut � gauche de celle o� l'on �tait.
//ENTREE : La position o� on commence, le tableau contenant le carr� magique et la valeur que doit prendre la case.
//SORTIE : Un carr� magique pr�t � �tre affich�.
{

    //On initialise les variables utiles, dont un switch permettant de v�rifier l'�tat de compl�tion du tableau.
    int killswitch = 1;
    pPosi -> x = Augmente(pPosi -> x);
    pPosi -> y = Augmente(pPosi -> y);

    while(killswitch)
    {

        if(tabCarre[pPosi -> x][pPosi -> y] == 0)
        {

            tabCarre[pPosi -> x][pPosi -> y] = NumCase;
            killswitch = 0;

        }
        else
        {

            pPosi -> x = Diminue(pPosi -> x);
            pPosi -> y = Augmente(pPosi -> y);

        }

    }

}


int Augmente(int valeur)
//BUT : Incr�mente la valeur entr�e ou donne une nouvelle valeur qui n'est pas hors du tableau.
//ENTREE : Une valeur.
//SORTIE : La valeur d'entr�e +1, sauf si on �tait au bord du tableau, auquel cas on est renvoy� sur le c�t� oppos�.
{

    if(valeur == Dimension - 1)
        return 0;
    else
        return ++valeur;

}


int Diminue(int valeur)
//BUT : D�cr�mente la valeur entr�e ou donne une nouvelle valeur qui n'est pas hors du tableau.
//ENTREE : Une valeur.
//SORTIE : La valeur d'entr�e -1, sauf si on �tait au bord du tableau, auquel cas on est renvoy� sur le c�t� oppos�.
{

    if(valeur == 0)
        return Dimension - 1;
    else
        return --valeur;

}


