#include "GameOfLife.h" // Inclure le fichier .h
#include <iostream>
#include <stdlib.h>

// Constructeur
GameOfLife::GameOfLife(int numLines, int numCols) {
    _numLines = numLines;//Nombre de ligne de la grille
    _numCols = numCols;//Nombre de colonne de la grille

    /*
    //Affiche les parametre choisi
    std::cout<<std::endl<<"Parametre :"<<std::endl;
    std::cout<<"Nombre de ligne =" << numLines <<std::endl;
    std::cout<<"Nombre de colonne =" << numCols <<std::endl<<std::endl;
    */

    //met toute la grille a 0 avant de choisir les celulle vivante
    for (int Fill_Ligne = 0; Fill_Ligne < numLines; Fill_Ligne++){//Parcours les lignes
        for (int Fill_Colonne = 0; Fill_Colonne < numCols; Fill_Colonne++){//Parcours les colonnes

            //Initialise les 2 grilles
            _grid[Fill_Ligne][Fill_Colonne] = 0; //Met les valeurs a 0
            _OldGrid[Fill_Ligne][Fill_Colonne] = 0; //Met les valeurs a 0

        }
    }

}

GameOfLife::GameOfLife(){

}

// Initialisation du jeu
void GameOfLife::initialisation() {
    int choiceUser = 1;
    int HauteurAlive = 0, LargeurAlive = 0;

    //Affiche l'explication pour rentrer les valeurs
    std::cout<<"Axe y "<<std::endl;
    std::cout<<_numLines<<"^"<<std::endl;
    std::cout<<" |"<<std::endl;
    std::cout<<"0|---->"<<std::endl;
    std::cout<<"  0  "<<_numCols<<std::endl;
    std::cout<<"Axe x"<<std::endl;

    //Choix des cellules vivantes
    while(choiceUser == 1){
        std::cout<<"Quel cellule est vivante a l'initialisation ?"<<std::endl;
        std::cout<<"Axe y de la cellule : ";
        std::cin>>HauteurAlive;//Position de la ligne de la cellule

        std::cout<<"Axe x de la cellule : ";
        std::cin>>LargeurAlive;//Position de la colonne de la cellule

        //Mise a jour des valeur
        _grid[HauteurAlive][LargeurAlive] = 1;
        _OldGrid[HauteurAlive][LargeurAlive] = 1;

        //Autre cellule vivante ?
        std::cout<<"Rentrer un autre cellule vivante"<<std::endl;
        std::cout<<"[1] : Oui"<<std::endl<<"[2] : Non"<<std::endl<<"Choix : ";
        std::cin>>choiceUser;
    }
}

// Mise à jour du statut des cellules lors d'une itération
void GameOfLife::play() {
    for (int Fill_Ligne = 0; Fill_Ligne < _numLines; Fill_Ligne++){
        for (int Fill_Colonne = 0; Fill_Colonne < _numCols; Fill_Colonne++){

            //Changement des etat de la celulle
            if(_grid[Fill_Ligne][Fill_Colonne] == 1 && (GameOfLife::nbAlivedNeighbours(Fill_Ligne,Fill_Colonne)>3 || GameOfLife::nbAlivedNeighbours(Fill_Ligne,Fill_Colonne)<2)){//Surpopulation
                _grid[Fill_Ligne][Fill_Colonne] = 0;//Cellule meurt
            }else if(_grid[Fill_Ligne][Fill_Colonne] == 0 && GameOfLife::nbAlivedNeighbours(Fill_Ligne,Fill_Colonne)==3){//Bonne condition
                _grid[Fill_Ligne][Fill_Colonne] = 1;//Naissance
            }

        }
    }

    //Mise a jour de _OldGrid
    for (int Fill_Ligne = 0; Fill_Ligne < _numLines; Fill_Ligne++){
        for (int Fill_Colonne = 0; Fill_Colonne < _numCols; Fill_Colonne++){
             _OldGrid[Fill_Ligne][Fill_Colonne] = _grid[Fill_Ligne][Fill_Colonne];
        }
    }
}

// Calcule le nombre de voisins à (i,j) qui sont vivants
int GameOfLife::nbAlivedNeighbours(int i, int j) {
    int minH, maxH, minL, maxL;//initialisation des variables

    //Le min en hauteur
    if(i-1>=0){
        minH = i-1;
    }else{
        minH = i;
    }

    //Le min en largeur
    if(j-1>=0){
        minL = j-1;
    }else{
        minL = j;
    }

    //Le max en hauteur
    if(i+1<_numLines){
        maxH = i+1;
    }else{
        maxH = i;
    }

    //le max en largeur
    if(j+1<_numCols){
        maxL = j+1;
    }else{
        maxL = j;
    }

    /*
    std::cout<<"Case visite : "<<"Hauteur : ["<<minH<<","<<maxH<<"]"<<std::endl;
    std::cout<<"Case visite : "<<"Largeur : ["<<minL<<","<<maxL<<"]"<<std::endl;
    std::cout<<"Nombre de voisin : ";
    */

    //compte le nombre de voisin vivant
    int nbAliveArround = 0;
    for (int Fill_Ligne = minH; Fill_Ligne <= maxH; Fill_Ligne++){
        for (int Fill_Colonne = minL; Fill_Colonne <= maxL; Fill_Colonne++){
            //std::cout<< _OldGrid[Fill_Ligne][Fill_Colonne];
            if(_OldGrid[Fill_Ligne][Fill_Colonne] == 1){
                nbAliveArround++;
            }
        }
        //std::cout<<std::endl;
    }

    nbAliveArround -= _OldGrid[i][j];//Nombre total vivant autour moins lui meme

    //std::cout<<nbAliveArround<<std::endl;
    return nbAliveArround;//renvoie le nombre de vivant autour de la cellule
}

//Affiche la grille actuel
void GameOfLife::affiche_grille(){

    system("CLS");//clear le terminal

    //Parcours la grille
    for (int Fill_Ligne = 0; Fill_Ligne < _numLines; Fill_Ligne++){
        for (int Fill_Colonne = 0; Fill_Colonne < _numCols; Fill_Colonne++){

            if(_grid[Fill_Ligne][Fill_Colonne] == 1){
                std::cout<<"* ";//Cellule vivante
            }else{
                std::cout<<" ";//Cellule morte
            }

        }
        std::cout<<std::endl;//ligne suivante
    }
}

//initialise une grille par default
void GameOfLife::GrilleDefault(int choixGrille){
    switch(choixGrille){//choisi la bonne grille en fonction du choix de l'utilisateur
    case 1 ://situation stable tour 4
        {
            ResizeGrille(10,20);
            _grid[5][7] = 1;
            _OldGrid[5][7] = 1;
            _grid[5][8] = 1;
            _OldGrid[5][8] = 1;
            _grid[6][8] = 1;
            _OldGrid[6][8] = 1;
            _grid[5][9] = 1;
            _OldGrid[5][9] = 1;
            _grid[5][10] = 1;
            _OldGrid[5][10] = 1;
            _grid[5][11] = 1;
            _OldGrid[5][11] = 1;
            break;
        }
    case 2 :
        {
             ResizeGrille(10,20);
            _grid[5][7] = 1;
            _OldGrid[5][7] = 1;
            _grid[5][8] = 1;
            _OldGrid[5][8] = 1;
            _grid[5][9] = 1;
            _OldGrid[5][9] = 1;
            break;
        }
    case 3 :
        {
             ResizeGrille(40,85);
            _grid[20][40] = 1;
            _OldGrid[20][40] = 1;
            _grid[20][41] = 1;
            _OldGrid[20][41] = 1;
            _grid[21][41] = 1;
            _OldGrid[21][41] = 1;
            _grid[21][42] = 1;
            _OldGrid[21][42] = 1;
            _grid[22][42] = 1;
            _OldGrid[22][42] = 1;
            _grid[22][43] = 1;
            _OldGrid[22][43] = 1;
            break;
        }
    case 4 :
        {
             ResizeGrille(40,85);
            _grid[20][40] = 1;
            _OldGrid[20][40] = 1;
            _grid[20][41] = 1;
            _OldGrid[20][41] = 1;
            _grid[20][42] = 1;
            _OldGrid[20][42] = 1;
            _grid[20][43] = 1;
            _OldGrid[20][43] = 1;
            _grid[20][44] = 1;
            _OldGrid[20][44] = 1;
            _grid[20][45] = 1;
            _OldGrid[20][45] = 1;
            _grid[20][46] = 1;
            _OldGrid[20][46] = 1;
            _grid[20][47] = 1;
            _OldGrid[20][47] = 1;
            _grid[20][48] = 1;
            _OldGrid[20][48] = 1;
            _grid[20][49] = 1;
            _OldGrid[20][49] = 1;
            break;
        }
    default://Cas par default du switch
        break;
    }
}

//Permet de redimensionner la grille
void GameOfLife::ResizeGrille(int numLines, int numCols){
    _numLines = numLines;//Nombre de ligne de la grille
    _numCols = numCols;//Nombre de colonne de la grille

    /*
    //Affiche les parametre choisi
    std::cout<<std::endl<<"Parametre :"<<std::endl;
    std::cout<<"Nombre de ligne =" << numLines <<std::endl;
    std::cout<<"Nombre de colonne =" << numCols <<std::endl<<std::endl;
    */

    //met toute la grille a 0 avant de choisir les celulle vivante
    for (int Fill_Ligne = 0; Fill_Ligne < numLines; Fill_Ligne++){//Parcours les lignes
        for (int Fill_Colonne = 0; Fill_Colonne < numCols; Fill_Colonne++){//Parcours les colonnes

            //Initialise les 2 grilles
            _grid[Fill_Ligne][Fill_Colonne] = 0; //Met les valeurs a 0
            _OldGrid[Fill_Ligne][Fill_Colonne] = 0; //Met les valeurs a 0

        }
    }
}
