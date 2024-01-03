#include <iostream>
#include "maze.h"


int main(){
  int n;

  std::cout << "\nDigite a ordem da matriz\n";
  std::cin >> n;  

  Maze *labirinto = new Maze(n);


  labirinto->leMatriz();
  labirinto->imprimeLabirinto();


  if (labirinto->VerificaSaidaLabirinto(1, 0)){   // verifica se tem saída a partir da posição (1, 0)
    std::cout << "\nPossui uma saida\n";
  } else
    std::cout << "\nNao possui uma saida\n";

  
  delete labirinto;
  return 0;
}