#include "DefaltMap.h"

DefaltMap::DefaltMap() { 
	for (int i = 0; i < High; i++) {
		for (int j = 0; j < Wide; j++) {
			floor[i][j] = std::make_unique<Sprite>();
			if (map[i][j] == 1) {
			
			}
		}
	}
	
	
}
