#pragma once

#include "queue.cpp"

#include <cassert>
#include <iostream>
#include <iomanip>

// Double Ended Queue (덱, dequeue와 구분): 양쪽 끝을 모두 사용할 수 있음
template <typename T>
class Deque : public Queue<T>
{

	typedef Queue<T> Base;

public:
	Deque(int capacity)
		: Queue<T>(capacity)
	{
	}

	T &Front()
	{
		return Base::Front();
	}

	T &Back()
	{
		return Base::Rear();
	}

	void PushFront(const T &item)
	{
		if (Base::IsFull())
			Base::Resize();

		// TODO:
		// queue_[front_] = item;
		// front_ = (front_ - 1 + capacity_) % capacity_;

		/*
		부모클래스의 멤버변수에 접근하기위해 Base::를 붙인다
		front에 item을 넣고 front를 하나 뒤로 빼야하는데  
		원형큐니까 하나를 뺀 다음 용량으로 나머지 연산을 해준다  
		
		예를들어 현재 front의 인덱스가 0이고 용량이 10이었으면 
		(0 - 1 + 10) % 10이 되어 
		0인덱스에 item이 할당되고 front는 가장 마지막에 있는 9가 된다
		*/

		Base::queue_[Base::front_] = item;
		Base::front_ = (Base::front_ - 1 + Base::capacity_) % Base::capacity_;
	}

	void PushBack(const T &item)
	{
		Base::Enqueue(item);
	}

	void PopFront()
	{
		Base::Dequeue();
	}

	void PopBack()
	{
		assert(!Base::IsEmpty());

		// TODO:
		rear_ = (rear_ - 1 + Base::capacity_) % Base::capacity_;
	}

private:
	// Queue와 동일
	int& rear_ = Base::rear_; // Base::가 앞에 붙는게 불편하면 이런식으로 정리할 수도 있다
};
