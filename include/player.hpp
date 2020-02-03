/*************************************************************
*   File: player.hpp
*   Author: Fernando M.
*   
*   Description:
*       Player class definition. This class provides
*       data and functions that handle the behavior of
*       tic tac toe players.
*
*************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <memory>

/*************************************************************
* Player class definition
*************************************************************/
class Player{
  public:
    /*************************************************************
    * Player constructor and destructor
    *************************************************************/
    Player(std::string name, bool p1);
    ~Player();

    /*************************************************************
    * Public funtions
    *************************************************************/
    const std::string& GetName(void) const;
    const char& GetMark(void) const;
    unsigned int SelectPos(void) const;

  private:
    /*************************************************************
    * Private class constants
    *************************************************************/
    const static unsigned int MIN_POS_VALUE     = 1;
    const static unsigned int MAX_POS_VALUE     = 9;
    const static unsigned int INVALID_POS_VALUE = 0;

    /*************************************************************
    * Private members
    *************************************************************/
    std::string m_name;
    char        m_mark;
};

#endif