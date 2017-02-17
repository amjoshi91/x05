/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, clearBoard)
{
	bool checker = true;
	TicTacToeBoard TTT;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			TTT.placePiece(i,j);
	}
	TTT.clearBoard();
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(TTT.getPieceOnLoc(i, j)!='B')
				checker = false;
		}
	}
	ASSERT_TRUE(checker);		
}

TEST(TicTacToeBoardTest, checkWinner)
{
	TicTacToeBoard TTT;	
	bool check;
	if(TTT.getWinner() == X || TTT.getWinner() == O)
	{
		check = true;
	}
	ASSERT_FALSE(check);
}

TEST(TicTacToeBoardTest, checkToggle)
{
	bool checker = false;
	TicTacToeBoard TTT;
	if(TTT.getTurn() == 'X')
	{
		TTT.placePiece(0, 0);
		if(TTT.getTurn() == 'O')
		{
			TTT.placePiece(0,1);
			if(TTT.getTurn() == 'X')
				checker = true;
		}
	}
	else
	{
		TTT.placePiece(0,0);
		if(TTT.getTurn() == 'X')
		{
			TTT.placePiece(0,1);
			if(TTT.getTurn() == 'O')
				checker = true;
		}
	}
	ASSERT_TRUE(checker);
}














