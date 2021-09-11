#include "pch.h"
#include "CppUnitTest.h"
#include "../Catan/src/controller/game/CatanBoard.h"
#include "../Catan/src/controller/game/CatanGame.h"
#include "../Catan/src/controller/events/CatanEvent.h"
#include "../Catan/src/controller/events/BuildRoadEvent.h"
#include "../Catan/src/controller/events/BuildSettlementEvent.h"
#include "../Catan/src/controller/game/states/CatanState.h"
#include "../Catan/src/controller/game/states/FirstTurnsState.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CatanTest
{
	TEST_CLASS(FirstTurnState_test)
	{

	public:

		CatanGame* test_game;
		CatanBoard test_board;
		FirstTurnState_test()
		{
			test_board.init();
			test_game = new CatanGame(test_board, PlayerId::PLAYER_FOUR);
		}

	public:

		// METHOD: handle              //(belongs to the virtual class CatanState)

		//sub-test1: Full first round simulation
		TEST_METHOD(handle_subtest1)
		{
			//////////////////////// player 1 sets his first settlement and road ////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event1(2, 2, VertexData::VertexDir::N, PlayerId::PLAYER_ONE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event1);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(2, 2, VertexData::VertexDir::N)->get_Building()));

			BuildRoadEvent event2(2, 2, EdgeData::EdgeDir::NW, PlayerId::PLAYER_ONE, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event2);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(2, 2, EdgeData::EdgeDir::NW)->get_path())); 
			

			/////////////////////// player 2 sets his first settlement and road //////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event3(3, 3, VertexData::VertexDir::N, PlayerId::PLAYER_TWO, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event3);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(3, 3, VertexData::VertexDir::N)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event4(3, 3, EdgeData::EdgeDir::NW, PlayerId::PLAYER_TWO, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event4);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(3, 3, EdgeData::EdgeDir::NW)->get_path())); //checking the the catan board was successfuly updated after the road was built


			/////////////////////// player 3 attempts to build a settlement on top of the settlement that player 2 has built //////////////////////////
			BuildSettlementEvent event5(3, 3, VertexData::VertexDir::N, PlayerId::PLAYER_THREE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event5);
			Assert::AreNotEqual(int(PlayerId::PLAYER_THREE), int(test_game->get_board().get_VertexData(3, 3, VertexData::VertexDir::N)->get_Player())); //checking that the given vertex is NOT owned by player three now

			/////////////////////// player 3 attempts to build a settlement that is adjacent to the settlement player 1 has built //////////////////////////
			BuildSettlementEvent event6(3, 1, VertexData::VertexDir::S, PlayerId::PLAYER_THREE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event6);
			Assert::AreNotEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(3, 1, VertexData::VertexDir::S)->get_Building())); //checking that the given vertex is NOT owned by player three now


			/////////////////////// player 3 sets his first settlement and road //////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event7(4, 4, VertexData::VertexDir::N, PlayerId::PLAYER_THREE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event7);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(4, 4, VertexData::VertexDir::N)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event8(4, 4, EdgeData::EdgeDir::NW, PlayerId::PLAYER_THREE, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event8);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(4, 4, EdgeData::EdgeDir::NW)->get_path())); //checking the the catan board was successfuly updated after the road was built


			/////////////////////// player 4(LAST PLAYER) sets his two settlements and two roads by order //////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event9(1, 5, VertexData::VertexDir::N, PlayerId::PLAYER_FOUR, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event9);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(1, 5, VertexData::VertexDir::N)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event10(1, 5, EdgeData::EdgeDir::NW, PlayerId::PLAYER_FOUR, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event10);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(1, 5, EdgeData::EdgeDir::NW)->get_path())); //checking the the catan board was successfuly updated after the road was built

			BuildSettlementEvent event11(5, 1, VertexData::VertexDir::N, PlayerId::PLAYER_FOUR, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event11);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(5, 1, VertexData::VertexDir::N)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event12(5, 1, EdgeData::EdgeDir::NW, PlayerId::PLAYER_FOUR, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event12);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(5, 1, EdgeData::EdgeDir::NW)->get_path())); //checking the the catan board was successfuly updated after the road was built


			/////////////////////// player 3 sets his second settlement and road //////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event13(4, 4, VertexData::VertexDir::S, PlayerId::PLAYER_THREE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event13);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(4, 4, VertexData::VertexDir::S)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event14(3, 5, EdgeData::EdgeDir::NE, PlayerId::PLAYER_THREE, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event14);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(3, 5, EdgeData::EdgeDir::NE)->get_path())); //checking the the catan board was successfuly updated after the road was built


			/////////////////////// player 2 sets his second settlement and road //////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event15(3, 3, VertexData::VertexDir::S, PlayerId::PLAYER_TWO, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event15);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(3, 3, VertexData::VertexDir::S)->get_Building())); //checking the the catan board was successfuly updated after the settlement was built

			BuildRoadEvent event16(2, 4, EdgeData::EdgeDir::NE, PlayerId::PLAYER_TWO, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event16);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(2, 4, EdgeData::EdgeDir::NE)->get_path())); //checking the the catan board was successfuly updated after the road was built

			//////////////////////// player 1 sets his second settlement and road ////////////////////////////////////////////////////////////////////
			BuildSettlementEvent event17(2, 2, VertexData::VertexDir::S, PlayerId::PLAYER_ONE, Events::BUILD_SETTLEMENT); //building settlement event
			test_game->handleEvent(event17);
			Assert::AreEqual(int(VertexData::Building::SETTLEMENT), int(test_game->get_board().get_VertexData(2, 2, VertexData::VertexDir::S)->get_Building()));

			BuildRoadEvent event18(1, 3, EdgeData::EdgeDir::NE, PlayerId::PLAYER_ONE, Events::BUILD_ROAD); //building road event(the road is valid since its attached to the settlement that was built prior)
			test_game->handleEvent(event18);
			Assert::AreEqual(int(EdgeData::Path::ROAD), int(test_game->get_board().get_EdgeData(1, 3, EdgeData::EdgeDir::NE)->get_path()));

		}


		








	};




}