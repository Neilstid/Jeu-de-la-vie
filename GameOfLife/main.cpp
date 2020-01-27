#include "GameOfLife.h" // Inclure le fichier .h
#include <iostream>

int main()
{
    std::cout<<"\tJeu de la vie"<<std::endl;
    int HauteurGrille, LargeurGrille;

    std::cout<<"Taille de la grille : \n Hauteur : ";
    std::cin>>HauteurGrille;
    std::cout<<" Largeur : ";
    std::cin>>LargeurGrille;

    GameOfLife game(10, 20); // définition d'un objet "game" de taille 50x50
    game.affiche_grille(); //Affiche la grille creer
    game.initialisation(); //Initialise la grille

    for(int i = 0; i<5;i++){
        game.play();//Tour suivant
        game.affiche_grille(); //Affiche la grille
        std::cout<<std::endl; //Saut de ligne
    }
  return 0;
}
