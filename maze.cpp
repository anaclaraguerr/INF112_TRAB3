#include <iostream>
#include "maze.h"


Maze::Maze(int n){  // construtor
  this->_n = n;
  labirinto = new int* [_n];

  for (int i = 0; i < _n; i++)
    labirinto[i] = new int[_n];
  
}

Maze::~Maze(){    // destrutor
  for (int i = 0; i < _n; i++)
    delete[] labirinto[i];
  

  delete labirinto;
}


void Maze::leMatriz(){
  std::cout << "\nInsira a matriz:\n";
  
  for (int i = 0; i < _n; i++){
    for (int j = 0; j < _n; j++){
      std::cin >> labirinto[i][j];
    }
  }
}


void Maze::imprimeLabirinto(){
  std::cout << "\nO labirinto:\n";

  for (int i = 0; i < _n; i++){
    for (int j = 0; j < _n; j++){
      std::cout << labirinto[i][j] << " ";
    }

    std::cout << "\n";
  }
}


bool Maze::VerificaSaidaLabirinto(int x, int y){
  
  if (x < 0 || y < 0 || x >= _n || y >= _n)     // verifica se (x,y) nao pertence a matriz
    return false;
  

  if (labirinto[x][y] == 1 || labirinto[x][y] == 100)    //verifica se (x,y) eh parede ou se ja foi verificada
    return false;
  

  if (labirinto[x][y] == 7)   // saida = 7
    return true;
  

  labirinto[x][y] = 100;     // sinaliza que (x,y) ja foi verificada


  if (VerificaSaidaLabirinto(x, y + 1))   // saida a direita
    return true;
  

  if (VerificaSaidaLabirinto(x, y - 1))   // saida a esqueda
    return true;
  

  if (VerificaSaidaLabirinto(x + 1, y))   // saida em baixo
    return true;
  

  if (VerificaSaidaLabirinto(x - 1, y))   // saida em cima
    return true;
  

  return false;
}