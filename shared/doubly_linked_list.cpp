#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template <typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node *left = nullptr;
		Node *right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	DoublyLinkedList(const DoublyLinkedList &list)
	{
		Node *current = list.first_;
		while (current)
		{
			this->PushBack(current->item);
			current = current->right;
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		// TODO:
		while (first_)
			PopFront();
	}

	bool IsEmpty()
	{
		return true; // TODO:
	}

	int Size()
	{
		int size = 0;

		// TODO:complete
		Node *current = first_;
		while(current)
		{
			current = current->right;
			size++;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node *current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			// TODO:complete
			while (true)
			{
				cout << current->item << " ";
				if (!current->right)
					break;

				current = current->right;
			}
			cout << endl;

			cout << "Backward: ";
			// TODO:complete
			while (true)
			{
				cout << current->item << " ";
				if (!current->left)
					break;

				current = current->left;
			}
			cout << endl;
		}
	}

	Node *Find(T item)
	{
		Node *current = first_;
		while (current)
		{
			if (current->item == item)
				return current;

			current = current->right;
		}

		// TODO:complete
		return current; // nullptr
	}

	void InsertBack(Node *node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:complete
			Node *temp = new Node;
			temp->item = item;
			temp->right = node->right;
			node->right = temp;

			if (temp->right)
				temp->right->left = temp;
			temp->left = node;
		}
	}

	void PushFront(T item)
	{
		// TODO:
	}

	void PushBack(T item)
	{
		// TODO:
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

		// TODO:complete
		Node *temp = first_;
		first_ = first_->right;
		if (first_)
			first_->left = nullptr;

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

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:complete
		Node *current = first_;

		if (current->right)
		{
			while (current->right->right)
				current = current->right;

			Node *temp = current->right;
			current->right = current->right->right;

			delete temp;
		}
		else
		{
			delete first_;
			first_ = nullptr;
		}
	}

	void Reverse()
	{
		// TODO:
		if (IsEmpty())
			return;
		else
		{
			Node *current = first_;
			Node *prev = nullptr;

			while (current)
			{
				prev = current;
				current = current->right;
				std::swap(prev->left, prev->right);
			}

			first_ = prev;
		}
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO:complete
	}

	T Back()
	{
		assert(first_);
		Node *current = first_;
		while (current->right)
			current = current->right;
		return current->item; // TODO:complete
	}

protected:
	Node *first_ = nullptr;
};