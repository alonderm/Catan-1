#include "pch.h"
#include "CppUnitTest.h"
#include "../Catan/src/controller/game/CatanBoard.h"
#include "../Catan/src/controller/game/CatanGame.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CatanTest
{
	TEST_CLASS(CatanGame_test)
	{
	
	public:
		
		CatanGame* test_game;
		CatanBoard test_board;
		CatanGame_test() 
		{
			test_board.init();
			test_game = new CatanGame(test_board, PlayerId::PLAYER_FOUR);
		}
			
	
	
	public:

		// sub-test 1: checking if an unregisterd player is able to build a settlement
		TEST_METHOD(build_settlement_subtest1)
		{

			Assert::AreEqual(false, test_game->build_settlement(PlayerId::PLAYER_FIVE,2,3,VertexData::VertexDir::N) );

		}


		//sub-test 2: checking if a registerd player can build a settlement not on his turn
		TEST_METHOD(build_settlement_subtest2)
		{

			Assert::AreEqual(false, test_game->build_settlement(PlayerId::PLAYER_TWO, 2, 3, VertexData::VertexDir::N)); // turn = PLAYER_ONE

		}
		
		//sub-test 3: checking if a settlement was built on a valid vertex && that the vertex map was updated(valid -> is not taken,and on an actual existing vertex)
		TEST_METHOD(build_settlement_subtest3)
		{

			Assert::AreEqual(true, test_game->build_settlement(PlayerId::PLAYER_ONE, 2, 3, VertexData::VertexDir::N)); // turn = PLAYER_ONE
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT) , int(test_game->get_board().get_VertexData(2, 3, VertexData::VertexDir::N)->get_Building()));

		}

	
	




	};
}
