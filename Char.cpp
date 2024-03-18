#include "Char.h"

float Char::GetLeftPosition() const 
{ 
	return worldTransform_.translation_.x; 
}

float Char::GetRightPosition() const 
{ 
	return worldTransform_.translation_.x+size_-1; 
}

float Char::GetDownPosition() const 
{ 
	return worldTransform_.translation_.y+size_-1; 
}

float Char::GetUpPosition() const 
{ 
	return worldTransform_.translation_.y+size_; 
}

