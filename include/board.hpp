/*************************************************************
*   File: board.hpp
*   Author: Fernando M.
*   
*   Description:
*       Board class definition. This class provides
*       data and functions that handle the usage of the
*       tic tac toe board.
*
*************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <memory>
#include <array>

/*************************************************************
* Board class definition
*************************************************************/
class Board{
public:
  /*************************************************************
  * Board constructor and destructor
  *************************************************************/
  Board();
  ~Board();

  /*************************************************************
  * Public functions
  *************************************************************/
  void DisplayHelpBoard(void);
  void DisplayPlayBoard(void);
  bool ValidPosition(const unsigned int& pos);
  void FillPosition(const unsigned int& pos, const char& mark);
  bool RowCheck(void);
  bool ColumnCheck(void);
  bool DiagCheck(void);

private:
  /*************************************************************
  * Private static constants & typedefs
  *************************************************************/
  static const unsigned int NUMBER_OF_ROWS_UINT     = 3;
  static const unsigned int NUMBER_OF_COLUMNS_UINT  = 3;
  static const char         EMPTY_SPOT_CHAR         = ' ';

  typedef std::array<std::array<char, NUMBER_OF_ROWS_UINT>, NUMBER_OF_COLUMNS_UINT> boardArray_t; 
  const boardArray_t        HELP_BOARD_ARRAY        = {{{'1','2','3'}, {'4','5','6'}, {'7','8','9'}}};

  /*************************************************************
  * Private members
  *************************************************************/
  boardArray_t m_boardArray;

  /*************************************************************
  * Private functions
  *************************************************************/
  void ConvertPosTo2D(const unsigned int& pos, unsigned int& row, unsigned int& column);
  void _DisplayBoard(const boardArray_t& boardArray);
  void Clear(void);
  
};

#endif