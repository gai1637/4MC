#include "ColisionManager.h"

void ColisionManager::Reset() { coliders_.clear(); }

void ColisionManager::CheckColisionPair(Colider2D* coliderA, Colider2D* coliderB) 
{
	float PosALeft  = coliderA->GetLeftPosition();
	float PosARight = coliderA->GetRightPosition();
	float PosAUp    = coliderA->GetUpPosition();
	float PosADown  = coliderA->GetDownPosition();

	float PosBLeft  = coliderB->GetLeftPosition();
	float PosBRight = coliderB->GetRightPosition();
	float PosBUp    = coliderB->GetUpPosition();
	float PosBDown  = coliderB->GetDownPosition();

	if (PosALeft  < PosBRight && PosAUp   > PosBDown ||
		PosALeft  < PosBRight && PosADown < PosBUp   ||
		PosARight > PosBLeft  && PosAUp   > PosBDown || 
		PosARight > PosBLeft  && PosADown < PosBUp ) {
		coliderA->OnCollsion();
		coliderB->OnCollsion();
	}
}

void ColisionManager::CheckAllColisions() {
	std::list<Colider2D*>::iterator itrA = coliders_.begin();
	for (; itrA != coliders_.end(); ++itrA) {
		Colider2D* coliderA = *itrA;
		std::list<Colider2D*>::iterator itrB = itrA;
		itrB++;
		for (; itrB != coliders_.end(); ++itrB) {
			Colider2D* coliderB = *itrB;

			CheckColisionPair(coliderA, coliderB);
		}
	}

}

void ColisionManager::AddColider(Colider2D* colider) { coliders_.push_back(colider); }
