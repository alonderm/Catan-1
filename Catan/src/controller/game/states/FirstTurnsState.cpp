#include "FirstTurnsState.h"
#include "..\..\events\CatanEvent.h"
#include "..\..\game\CatanBoard.h"
#include "..\..\events\BuildRoadEvent.h"
#include "..\..\events\BuildSettlementEvent.h"

CatanState* FirstTurnsState::handle(CatanGame& catanGame, CatanEvent& catanEvent)
{
	
	if (catanGame.getturn() == catanEvent.getPlayerId()) //if a player is trying to build on his turn
	{
		
			if (catanEvent.getEvent() == Events::BUILD_SETTLEMENT) //if its a build settlement event
			{
				if (this->buildings_hist[int(catanEvent.getPlayerId())] < 2) //if the player has not built 2 settlements yet
				{
					BuildSettlementEvent& settlement_event = (BuildSettlementEvent&)catanEvent; //settlement_event is now casted to be of type 'BuildSettlementEvent'
					if (catanGame.build_settlement(settlement_event.getPlayerId(), settlement_event.get_q(), settlement_event.get_r(), settlement_event.get_dir()))
					{
						this->buildings_hist[int(settlement_event.getPlayerId())]++; //updates the amount of settlements the player has built
						
					}

				}

				return NULL;
			}

			if (catanEvent.getEvent() == Events::BUILD_ROAD) //if its a build road event
			{
				if (this->roads_hist[int(catanEvent.getPlayerId())] < 2 && (this->roads_hist[int(catanEvent.getPlayerId())] < this->buildings_hist[int(catanEvent.getPlayerId())])) //if the player has not built 2 roads yet AND has less roads than settlements
				{
					
					BuildRoadEvent& road_event = (BuildRoadEvent&)catanEvent; //road_event is now casted to be of type 'BuildRoadEvent'
					if (catanGame.build_road(catanEvent.getPlayerId(), road_event.get_q(), road_event.get_r(), road_event.get_dir())) //if the road was successfuly built
					{
						this->roads_hist[int(catanEvent.getPlayerId())]++; //updates the amount of roads the player has built
						if (this->buildings_hist[int(catanEvent.getPlayerId())] == 2 && this->roads_hist[int(catanEvent.getPlayerId())] == 2) // if its the last road that the player should build
						{

							if (catanGame.getturn() == PlayerId::PLAYER_ONE) //if its the last road of the first player
							{
								// return "next_State" , TODO: add the next state 
								printf("check!"); //temporary only!!!
								return NULL; //temporary only!!!
								
							}

						}

						if (this->roads_hist[int(catanGame.getPlayerCount())] == 2) // if the turns are reversed after the last player has built 2 settlements and roads
						{
							catanGame.decrement_turn(); // move to the turn of the previous player in queue
						}

						else if(!(catanGame.getPlayerCount() == catanEvent.getPlayerId()))
						{
							catanGame.increment_turn(); //move on to the turn of the next player in queue
						}


					}
					
					return NULL;

				}

			}

			return NULL; // if it is not 'build road' event nor 'build settlement' event,do nothing

	}

	return NULL; //if its an event that was called from a player NOT ON HIS TURN

	
}


// TODO: add observer actions according to the specified event
