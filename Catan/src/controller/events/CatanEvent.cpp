#include "CatanEvent.h"

PlayerId
CatanEvent::getPlayerId(void) {
	return this->playerId;
}

void
CatanEvent::setPlayerId(PlayerId _playerId) {
	this->playerId = _playerId;
}

Events
CatanEvent::getEvent() {
	return this->eventType;
}