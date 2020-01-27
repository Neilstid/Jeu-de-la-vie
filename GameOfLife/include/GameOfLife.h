#include <vector>

// Définition de la classe
class GameOfLife
{
    public: //Méthodes et opérateurs de la classe

        // Constructeur qui permet de construire un objet de la classe
        GameOfLife(int numLines, int numCols);
        GameOfLife();

        void initialisation(); //Initialisation du jeu
        void play(); //Mise à jour du statut des cellules lors d'une itération
        int nbAlivedNeighbours(int i, int j); //Nombre de voisins vivants pour (i,j)
        void affiche_grille(); //affiche le resultat
        void GrilleDefault(int choixGrille); //Defini une grille par default

    protected :
        void ResizeGrille(int numLines, int numCols);

    private: //Les attributs de la classe
        int _numLines; //Nombre de lignes de la grille
        int _numCols; //Nombre de colonnes de la grille

        // La grille qui contient le statut des cellules 1 si cellule vivante,
        // 0 si elle est morte. Elle est définie comme un vecteur de vecteur de int
        int  _grid[500][500];//Grille Actuel
        int _OldGrid[500][500];//Grille memoire qui stocke l'etat precedent pour la fonction nbAlivedNeighbours

};
