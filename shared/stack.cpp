﻿#pragma once

#include <cassert>
#include <iostream>

template<typename T> // 템플릿 사용
class Stack
{
public:
	Stack(int capacity = 1)
	{
		assert(capacity > 0);
		Resize(capacity);
	}

	~Stack()
	{
		if (stack_) delete[] stack_;
	}

	void Resize(int new_capacity)
	{
		T* new_stack = new T[new_capacity];
		memcpy(new_stack, stack_, sizeof(T) * Size());
		if (stack_) delete[] stack_;
		stack_ = new_stack;
		capacity_ = new_capacity;
	}

	bool IsEmpty() const
	{
		return top_ == -1; // TODO:
	}

	int Size() const
	{
		return top_ + 1; //TODO:
	}

	void Print()
	{
		using namespace std;

		for (int i = 0; i < Size(); i++) // Size() 사용
			cout << stack_[i] << " ";
		cout << endl;
	}

	// Returns TOP element of stack.
	T& Top() const
	{
		assert(!IsEmpty());

		return stack_[top_];
	}

	// Insert item into the TOP of the stack
	void Push(const T& item)
	{
		// TODO: 필요하면 리사이즈 
		if(top_ == capacity_ - 1)
			Resize(capacity_ * 2);

		// TODO:
		// top += 1 vs ++top
		// stack_[++top_] = item;
		top_ += 1;
		stack_[top_] = item;
	}

	// Delete the TOP element of the stack
	void Pop()
	{
		assert(!IsEmpty());

		// TODO:
		top_--;
		// top-- vs top -= 1

		/*
			int나 char처럼 크기가 고정된게 아니라 String과 같은 객체타입은 
			소멸자를 수동으로 호출해주는것이 필요하지만 여기서는 필요없다
		*/
		// stack[top--].~T(); // 소멸자를 수동으로 호출
	}

protected: // 뒤에서 상속해서 사용
	T* stack_ = nullptr;
	int top_ = -1; // 0 아님
	int capacity_ = 0;
};
