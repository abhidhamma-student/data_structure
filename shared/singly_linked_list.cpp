﻿#pragma once

#include <cassert>
#include <stdint.h>

template <typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node *next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList &list)
	{
		// TODO: 연결 리스트 복사
		Node *current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO: 모두 삭제
		while (first_)
        	PopFront();
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환

		return size;
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO: 수정
	}

	T Back()
	{
		assert(first_);

		return T(); // TODO: 수정
	}

	Node *Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환(complete)
		Node *current = first_;

		while (current)
		{
			// 처음부터 찾다가 아이템이 같으면 리턴
			if (current->item == item)
				return current;

			current = current->next;
		}

		return current; // nullptr
	}

	void InsertBack(Node *node, T item)
	{
		// TODO:(complete)
		Node *temp = new Node;
		temp->item = item;
		temp->next = node->next;
		node->next = temp;
	}

	void Remove(Node *n)
	{
		assert(first_);

		if (first_ == n)
		{
			first_ = first_->next;
			delete n;
			return;
		}

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:(complete)
		Node *prev = first_;
		while (prev->next)
		{
			if (prev->next == n)
				break;

			prev = prev->next;
		}
		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

		// 새로운 노드 만들기
		// TODO:
		Node *temp = new Node;
		temp->item = item;

		// 연결 관계 정리
		// TODO:
		temp->next = first_;
		first_ = temp;
	}

	void PushBack(T item)
	{
		if (first_)
		{
			// TODO:
			Node *current = first_;
			while (current->next)
				current = current->next;

			Node *new_node = new Node;
			new_node->item = item;
			new_node->next = nullptr;

			current->next = new_node;
		}
		else
			PushFront(item);
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		Node *temp = first_;
		first_ = first_->next;

		// TODO: 메모리 삭제(complete)
		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.
		assert(first_);

		Node *second_last = first_;

		while (second_last->next->next)
			second_last = second_last->next;

		Node *temp = second_last->next;
		second_last->next = second_last->next->next;

		// TODO: 메모리 삭제(complete)
		delete temp;
	}

	void Reverse()
	{
		// TODO:
		Node *current = first_;
		Node *previous = nullptr;

		while (current)
		{
			Node *temp = previous;
			previous = current;
			current = current->next;
			previous->next = temp;
		}

		first_ = previous;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node *current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					// cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						 << current->item << ", "
						 << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

protected:
	Node *first_ = nullptr;

	bool print_debug_ = false;
};