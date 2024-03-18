#pragma once

#include"Vector3.h"
#include<memory>
using namespace std;
class Colider2D {
public:
	template<class T> using unique_ptr=std::unique_ptr<T>;
	void SetSize(float size) { this->size_ = size; }
	float GetSize() { return size_; }
	virtual void OnCollsion(){};
	virtual float GetLeftPosition() const = 0;
	virtual float GetUpPosition() const = 0;
	virtual float GetDownPosition() const = 0;
	virtual float GetRightPosition() const = 0;
	virtual ~Colider2D() = default;
	float size_ = 64.f;
protected:
	


};
