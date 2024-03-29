#ifndef MATRIXHPP
#define MATRIXHPP

#include "piece.hpp"

class Matrix {
    private:
        // coordinates of the top left corner 
        int x;
        int y;

        // dimensions of the matrix (board)
        int width;
        int height;

        // width and height of a single cell
        int cellW;
        int cellH;

        // borders storing graphical information
        float cellBorder;
        float matrixBorder;

        // contains the values of every cell
        // 0 for empty, a positive int if filled
        int **matrix;

        bool isValidCell(int, int);
        bool isFreeCell(int, int);

        void moveDownRows(int);

        int embedPiece(Piece&);

        void drawCell(sf::RenderWindow&, int, int, int);
        void drawPiece(sf::RenderWindow&, Piece&);
        void drawOutline(sf::RenderWindow&);
        void drawMatrix(sf::RenderWindow&);
        void drawNextBox(sf::RenderWindow&, pieceShape, sf::Text&);

    public:
        Matrix(int, int, int, int);
        // ~Matrix();

        int getWidth();
        int getHeight();
        int **getMatrix();

        int clearRows();

        int movePiece(Piece&, int);
        int dropPiece(Piece&);
        int rotatePiece(Piece&, int);

        void draw(sf::RenderWindow&, Piece&, pieceShape, sf::Text&);
};

#endif