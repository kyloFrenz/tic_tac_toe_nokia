#include <array>
#include <iostream>
#include <memory>
#include "gameplay.hpp"

int main(void){
  GamePlay ticTacToe;
  ticTacToe.Init();
  ticTacToe.Play();
  return 0;
}
