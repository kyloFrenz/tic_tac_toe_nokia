/*************************************************************
*   File: gameplay.cpp
*   Author: Fernando M.
*   
*   Description:
*       GamePlay class implementation. This class provides
*       data and functions that handle the execution of the
*       game according to its rules.
*
*************************************************************/
#include "gameplay.hpp"

/*************************************************************
*   Function Name: GamePlay
*
*   Description:
*       GamePlay constructor. Prints game message.
*
*************************************************************/
GamePlay::GamePlay(){
    std::cout << "------- TIC TAC TOE -------" << std::endl;
}

/*************************************************************
*   Function Name: ~GamePlay
*
*   Description:
*       GamePlay destructor. Prints goodbye message.
*
*************************************************************/
GamePlay::~GamePlay(){
    std::cout << "GoodBye!" << std::endl;
}

/*************************************************************
*   Function Name: Init
*
*   Description:
*       Initializes game. Waits for players to join.
*
*************************************************************/
void GamePlay::Init(void){
    for(unsigned int playerIdx = 0; playerIdx < MAX_NUM_PLAYERS; playerIdx++){
        std::cout << std::endl << "Waiting for player" << (playerIdx + 1) << ". Please enter your name." << std::endl;
        std::string playerName;
        std::cin >> playerName;
        bool isPlayer1 = (playerIdx == 0);
        m_players[playerIdx] = std::make_shared<Player>(playerName, isPlayer1);
    }
}

/*************************************************************
*   Function Name: Play
*
*   Description:
*       Play the game. A player makes a move, checks if 
*       the game has been won by completing a row, column
*       or diagonal.
*       Game finishes by either winning or having filled 
*       all the positions without any player winning.
*
*************************************************************/
void GamePlay::Play(void){
    unsigned int playerIdx = 0;
    std::cout << "\n\n\t\tLet's Play!" << std::endl;
    std::cout << "Each player will select a position on the board. Positions are depicted in the board below:" << std::endl;
    m_board.DisplayHelpBoard();
    std::cout << "\nA player wins by selecting all positions in a row, a column or a diagonal." << std::endl;

    while(m_numMoves){
        const std::shared_ptr<Player> currentPlayer = m_players[playerIdx];
        std::cout << "\n\n-----------------------------------------------------------" << std::endl;
        std::cout << "Number of Moves: " << (MAX_NUM_MOVES - m_numMoves) << "\tPlayer at turn: " << currentPlayer->GetName() << std::endl;
        const unsigned int pos = currentPlayer->SelectPos();
        
        if(pos != 0 && ValidateSelection(pos)){
            m_board.FillPosition(pos, currentPlayer->GetMark());
            m_board.DisplayPlayBoard();
            if((m_numMoves < 6) && (m_board.ColumnCheck() || m_board.RowCheck() || m_board.DiagCheck())){
                std::cout << std::endl << currentPlayer->GetName() << " Is the Winner!" << std::endl;
                return;
            }
            playerIdx ^= 1;
            m_numMoves--;
        }
    }
    std::cout << "\nNobody wins. Try Again" << std::endl;
}

/*************************************************************
*   Function Name: ValidateSelection
*
*   Description:
*       Checks that a selection is valid (selection not 
*       taken yet)
*
*************************************************************/
bool GamePlay::ValidateSelection(const unsigned int& pos){
    return m_board.ValidPosition(pos);
}
