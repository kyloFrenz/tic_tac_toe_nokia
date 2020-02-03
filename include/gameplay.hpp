/*************************************************************
*   File: gameplay.hpp
*   Author: Fernando M.
*   
*   Description:
*       GamePlay class definition. This class provides
*       data and functions that handle the execution of the
*       game according to its rules.
*
*************************************************************/
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <iostream>
#include <memory>
#include "board.hpp"
#include "player.hpp"

class GamePlay{
  public:
    /*************************************************************
    * GamePlay constructor and destructor
    *************************************************************/
    GamePlay();
    ~GamePlay();

    /*************************************************************
    * Gameplay public functions
    *************************************************************/
    void Init(void);
    void Play(void);

  private:
    /*************************************************************
    * Private class constants
    *************************************************************/
    static const unsigned MAX_NUM_PLAYERS = 2;
    static const unsigned MAX_NUM_MOVES   = 9;

    /*************************************************************
    * Private members
    *************************************************************/
    unsigned int m_numMoves = MAX_NUM_MOVES;
    Board        m_board;

    std::array<std::shared_ptr<Player>, MAX_NUM_PLAYERS> m_players;

    /*************************************************************
    * Private functions
    *************************************************************/
    bool ValidateSelection(const unsigned int& pos);
    
};
#endif