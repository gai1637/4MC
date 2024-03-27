#pragma once

#include"Vector3.h"
#include<memory>
#include"ColisionTypeIDef.h"
using namespace std;
class Colider2D {
public:
	template<class T> using unique_ptr=std::unique_ptr<T>;
	void SetSize(float size) { this->size_ = size; }
	float GetSize() { return size_; }
	virtual void OnCollsion([[maybe_unused]]Colider2D* other){};
	virtual float GetLeftPosition() const = 0;
	virtual float GetUpPosition() const = 0;
	virtual float GetDownPosition() const = 0;
	virtual float GetRightPosition() const = 0;
	virtual ~Colider2D() = default;
	uint32_t GetTpeID() const { return typeID_;}
	void SetTypeID(uint32_t typeID) { typeID_ = typeID; }
		
	float size_ = 64.f;
	uint32_t typeID_ = 0u;
protected:
	


};
