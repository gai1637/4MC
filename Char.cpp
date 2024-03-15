#include "Char.h"




Vector3 Char::GetLeftUpPosition() const { 
	Vector3 worldPos;
	worldPos = worldTransform_.translation_;




	return  worldPos; 


}

Vector3 Char::GetRightUpPosition() const 
{ 
	
	Vector3 worldPos;
	worldPos.x = worldTransform_.translation_.x+size;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;
	return  worldPos; 
}

Vector3 Char::GetLeftDownPosition() const 
{
	Vector3 worldPos;
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y+size;
	worldPos.z = worldTransform_.translation_.z;
	return  worldPos; 
}

Vector3 Char::GetRightDownPosition() const
{ 
	Vector3 worldPos;
	worldPos.x = worldTransform_.translation_.x+size;
	worldPos.y = worldTransform_.translation_.y+size;
	worldPos.z = worldTransform_.translation_.z;
	return  worldPos; 
}
