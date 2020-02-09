/*************************************************************
*   File: player.cpp
*   Author: Fernando M.
*
*   Description:
*       Player class implementation. This class provides
*       data and functions that handle the behavior of
*       tic tac toe players.
*
*************************************************************/
#include "player.hpp"
#include <cstdlib>

/*************************************************************
*   Function Name: Player
*
*   Description:
*       Player constructor.
*       Prints welcome message. Assigns mark to player.
*
*************************************************************/
Player::Player(std::string name, bool p1) : m_name(name){
    std::cout << "Welcome, " << m_name << " your mark will be ";
    if(p1){
        std::cout << "'O'." << std::endl;
        m_mark = '0';
    }
    else{
        std::cout << "'X'." << std::endl;
        m_mark = 'X';
    }
}

/*************************************************************
*   Function Name: ~Player
*
*   Description:
*       Player destructor.
*
*************************************************************/
Player::~Player(){
    //Stubbed
}

/*************************************************************
*   Function Name: GetName
*
*   Description:
*       Returns reference to player's name
*
*************************************************************/
const std::string& Player::GetName(void) const{
    return m_name;
}

/*************************************************************
*   Function Name: GetMark
*
*   Description:
*       Returns reference to player's mark
*
*************************************************************/
const char& Player::GetMark(void) const{
    return m_mark;
}

/*************************************************************
*   Function Name: SelectPos
*
*   Description:
*       Waits for user to select a position and validates
*       that it's in the range of selectable positions (1-9).
*       Function returns the selected position if valid.
*       It returns 0 if invalid.
*
*************************************************************/
unsigned int Player::SelectPos(void) const{
    unsigned int number;
    char pos;
    std::cout << m_name << ", your turn to select a position -> ";
    std::cin >> pos;

    if(!std::isdigit(pos)){
      std::cout << "You have entered a non numeric character." << std::endl;
      return INVALID_POS_VALUE;
    }

    number = pos - '0';
    if(number < MIN_POS_VALUE || number > MAX_POS_VALUE){
        std::cout << "The position selected is outside of the 1 - 9 range." << std::endl
                    << "Please select a different position." << std::endl;
        return INVALID_POS_VALUE;
    }
    return number;
}
