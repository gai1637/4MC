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
	virtual Vector3 GetLeftUpPosition() const = 0;
	virtual Vector3 GetRightUpPosition() const = 0;
	virtual Vector3 GetLeftDownPosition() const = 0;
	virtual Vector3 GetRightDownPosition() const = 0;
	virtual ~Colider2D() = default;

protected:
	float size_ = 64.f;


};
