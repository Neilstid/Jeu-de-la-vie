#include "GameOfLife.h" // Inclure le fichier .h
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout<<"\t\t\t\t\t\t\tJeu de la vie"<<std::endl;

    /*
    int Choix_Implementation;
    std::cout<<"Choix implementation :\n [1] : Utiliser schema predefini\n [2] : Creer son propre schema\n Choix : ";
    std::cin>>Choix_Implementation;
    */

    int HauteurGrille, LargeurGrille;
    std::cout<<"Taille de la grille : \n Hauteur : ";
    std::cin>>HauteurGrille;
    std::cout<<" Largeur : ";
    std::cin>>LargeurGrille;
    GameOfLife game(HauteurGrille, LargeurGrille); // définition d'un objet "game" de taille 50x50
    game.initialisation(); //Initialise la grille

    game.GrilleDefault(3);

    for(int i = 0; i<1000;i++){
        game.play();//Tour suivant
        game.affiche_grille(); //Affiche la grille
        usleep(50000);//Temps affichage entre chaque update
    }
  return 0;
}
