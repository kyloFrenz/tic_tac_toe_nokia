/*************************************************************
*   File: board.cpp
*   Author: Fernando M.
*   
*   Description:
*       Board class implementation. This class provides
*       data and functions that handle the usage of the
*       tic tac toe board.
*
*************************************************************/
#include <board.hpp>

/*************************************************************
*   Function Name: Board
*
*   Description:
*       Board Constructor. It clears the board.
*
*************************************************************/
Board::Board(){
    Clear();
}

/*************************************************************
*   Function Name: ~Board
*
*   Description:
*       Board Destructor. Stubbed
*
*************************************************************/
Board::~Board(){
    //Stubbed
}

/*************************************************************
*   Function Name: DisplayHelpBoard
*
*   Description:
*       This function prints the help board to stdout
*
*************************************************************/
void Board::DisplayHelpBoard(void){
    _DisplayBoard(HELP_BOARD_ARRAY);
};

/*************************************************************
*   Function Name: DisplayPlayBoard
*
*   Description:
*       This function prints the current playable board to
*       stdout.
*
*************************************************************/
void Board::DisplayPlayBoard(void){
    _DisplayBoard(m_boardArray);
}

/*************************************************************
*   Function Name: ValidPosition
*
*   Description:
*       This function checks that selected position hasn't
*       been taken.
*
*************************************************************/
bool Board::ValidPosition(const unsigned int& pos){
    bool valid = true;
    unsigned int row;
    unsigned int column;
    ConvertPosTo2D(pos, row, column);
    if(m_boardArray[row][column] != ' '){
        std::cout << "Position " << pos << " is already taken." << std::endl;
        std::cout << "Please select a different position." << std::endl;
        valid = false;
    }
    return valid;
}

/*************************************************************
*   Function Name: RowCheck
*
*   Description:
*       This function checks if any player has completed
*       a row.
*
*************************************************************/
bool Board::RowCheck(void){
    bool check = false;
    for(unsigned int row = 0; row < NUMBER_OF_ROWS_UINT; row++){
        if((m_boardArray[row][0] != ' ') && 
            (m_boardArray[row][0] == m_boardArray[row][1]) && 
            (m_boardArray[row][1] == m_boardArray[row][2])){
                check = true;
        }
    }
    return check;
}

/*************************************************************
*   Function Name: ColumnCheck
*
*   Description:
*       This function checks if any player has completed
*       a column.
*
*************************************************************/
bool Board::ColumnCheck(void){
    bool check = false;
    for(unsigned int column = 0; column < NUMBER_OF_COLUMNS_UINT; column++){
      if((m_boardArray[0][column] != ' ') && 
         (m_boardArray[0][column] == m_boardArray[1][column]) && 
         (m_boardArray[1][column] == m_boardArray[2][column])){
            check = true;
      }
    }
    return check;
}

/*************************************************************
*   Function Name: DiagCheck
*
*   Description:
*       This function checks if any player has completed
*       a diagonal.
*
*************************************************************/
bool Board::DiagCheck(void){
    if((m_boardArray[0][0] != ' ') && (m_boardArray[0][0] == m_boardArray[1][1]) && (m_boardArray[1][1] == m_boardArray[2][2])){
        return true;
    }

    if((m_boardArray[2][0] != ' ') &&(m_boardArray[2][0] == m_boardArray[1][1]) && (m_boardArray[1][1] == m_boardArray[0][2])){
        return true;
    }

    return false;
}

/*************************************************************
*   Function Name: FillPosition
*
*   Description:
*       This function fills a selected position with the
*       mark corresponding to the player who made the selection.
*
*************************************************************/
void Board::FillPosition(const unsigned int& pos, const char& mark){
    unsigned int row;
    unsigned int column;
    ConvertPosTo2D(pos, row, column);
    m_boardArray[row][column] = mark;
}

/*************************************************************
*   Function Name: ConvertPosTo2D
*
*   Description:
*       Converts single digit selection to multidimensional
*       array row and column indeces.
*
*************************************************************/
void Board::ConvertPosTo2D(const unsigned int& pos, unsigned int& row, unsigned int& column){
    row = (pos - 1) / 3;
    column = (pos - 1) - (3 * row);
}

/*************************************************************
*   Function Name: _DisplayBoard
*
*   Description:
*       This function displays the board passed as parameter.
*
*************************************************************/
void Board::_DisplayBoard(const boardArray_t& boardArray){
    std::cout << std::endl;
    for(unsigned int row = 0; row < NUMBER_OF_ROWS_UINT; row++){
      std::cout << "  " << boardArray[row][0] << "  |";
      std::cout << "  " << boardArray[row][1] << "  |";
      std::cout << "  " << boardArray[row][2] << "  \n";
      if(row != (NUMBER_OF_ROWS_UINT - 1)){
        std::cout << "-----------------\n";
      }
    }
}

/*************************************************************
*   Function Name: Clear
*
*   Description:
*       This function clears the board.
*
*************************************************************/
void Board::Clear(void){
    for(unsigned int row = 0; row < NUMBER_OF_ROWS_UINT; row++){
      for(unsigned int column = 0; column < NUMBER_OF_COLUMNS_UINT; column++){
        m_boardArray[row][column] = EMPTY_SPOT_CHAR;
      }
    }
}