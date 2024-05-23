#include "../shared/Queue.cpp"

#include <iostream>

// 큐는 영어에서 줄서있는것을 말하는 일반적인 단어다

int main()
{
	// FIFO(First In First Out)

	Queue<char> q(2); // capacity_ = 2에서 시작 (메모리 증가 확인)

	q.SetDebugFlag(true);

	q.Print();

	q.Enqueue('A');
	q.Print();

	q.Enqueue('B');
	q.Print();

	q.Enqueue('C');
	q.Print();

	q.Enqueue('D');
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	q.Dequeue();
	q.Print();

	for (char c = 'E'; c <= 'K'; c++)
	{
		q.Enqueue(c);
		q.Print();
	}

	return 0;
}
