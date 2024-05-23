#include <iostream>

#include "../shared/stack.cpp"

using namespace std;

Stack<char> tower[3];

void PrintTowers()
{
	cout << "Towers" << endl;
	cout << "0: ";
	tower[0].Print();
	cout << "1: ";
	tower[1].Print();
	cout << "2: ";
	tower[2].Print();
}

// 실제로 디스크를 움직여서 스택들을 업데이트
void MoveDisk(int from, int to)
{
	if (tower[from].IsEmpty())
	{
		cout << "Tower " << from << " is empty." << endl;
		exit(0); // 오류 강제 종료
	}

	auto disk = tower[from].Top();

	// 받을 타워가 비어 있으면 뭐든지 받을 수 있음
	// 알파벳 순서여야 받을 수 있음 (역순 X)
	if (!tower[to].IsEmpty() && tower[to].Top() > disk)
	{
		cout << "Cannot place " << disk << " on " << tower[to].Top() << endl;
		exit(0); // 오류 강제 종료
	}

	tower[from].Pop(); 
	tower[to].Push(disk);

	cout << "Move disk " << disk << " from " << from << " to " << to << endl;
	PrintTowers();
}

void RecurMoveDisks(int n, int from, int temp, int to)
{
	// TODO:
	if(n == 0)
		return;
	RecurMoveDisks(n - 1, from, to, temp); // n-1개를 from -> temp

	MoveDisk(from, to);	// n개를 from -> to(가장 큰 것)

	RecurMoveDisks(n - 1, temp, from, to); // 그 위에 n-1개를 temp에서 to로 보내기
}
//이 소스는 하노이의탑을 재귀로 푼 문제인데 소스의 진행 순서를 번호를매겨서 상세하게 설명해줘
/*
아이디어 
a, b, c 3개의 disk와 1, 2, 3의 스택이 있으면 
1.총 길이에서 하나를 뺀 2개를 먼저 2스택으로 옮긴다  
2.그리고 가장 아래에 있는 원반을 3스택으로 옮긴다
3.2스택에 있는 원반을 3스택으로 옮긴다  
이렇게 해서 문제를 쪼갤 수 있는 n-1문제가 된다  
이 아이디어를 구현한것이 RecurMoveDisks다  

구체적인 구현  
1.n-1개의 디스크를 from에서 temp로 보낸다.
2.그리고 하나 남아있는 가장 큰 디스크를 from에서 to로 보낸다
3.그리고 1에서 temp로 보냈던 n-1개의 디스크들을 from으로 보낸다 

진행순서
1.1차 재귀 호출 (3개의 디스크 전체 이동):
hanoi(3, "A", "C", "B") 호출
가장 큰 디스크(3번)를 이동하기 전에, 작은 두 개의 디스크를 보조 기둥인 "B"로 이동시켜야 함
1-1차 호출: hanoi(2, "A", "B", "C")

2.2차 재귀 호출 (2개의 디스크 이동):
hanoi(2, "A", "B", "C") 호출
가장 큰 디스크(2번)를 이동하기 위해 작은 디스크(1번)를 보조 기둥인 "C"로 이동시켜야 함
2-1차 호출: hanoi(1, "A", "C", "B")

3.기본 단계 (디스크 1개 이동):
hanoi(1, "A", "C", "B") 호출
디스크 1개이므로 바로 이동: move(1, "A", "C")

4.디스크 2번 이동:
이제 디스크 2번을 "A"에서 "B"로 이동: move(2, "A", "B")

5.1차 재귀 호출의 나머지:
2-2차 호출: hanoi(1, "C", "B", "A")
hanoi(1, "C", "B", "A") 호출
디스크 1번을 "C"에서 "B"로 이동: move(1, "C", "B")

6.디스크 3번 이동:
이제 디스크 3번을 "A"에서 "C"로 이동: move(3, "A", "C")

7.최종 재귀 호출 (2개의 디스크 "B"에서 "C"로 이동):
1-2차 호출: hanoi(2, "B", "C", "A")

8.2차 재귀 호출 반복 (2개의 디스크 이동):
hanoi(2, "B", "C", "A") 호출
가장 큰 디스크(2번)를 이동하기 위해 작은 디스크(1번)를 보조 기둥인 "A"로 이동시켜야 함
2-1차 호출: hanoi(1, "B", "A", "C")

9.기본 단계 (디스크 1개 이동):
hanoi(1, "B", "A", "C") 호출
디스크 1번을 "B"에서 "A"로 이동: move(1, "B", "A")

10.디스크 2번 이동:
디스크 2번을 "B"에서 "C"로 이동: move(2, "B", "C")

11.최종 재귀 호출의 나머지:
2-2차 호출: hanoi(1, "A", "C", "B")
hanoi(1, "A", "C", "B") 호출
디스크 1번을 "A"에서 "C"로 이동: move(1, "A", "C")
*/
int main()
{
	int num_disks = 3;

	for (int i = 0; i < num_disks; i++)
		tower[0].Push('A' + i);

	PrintTowers();

	// MoveDisk(0, 2); // <- 디스크 하나만 움직이는 함수 tower 0 -> tower 2

	RecurMoveDisks(num_disks, 0, 1, 2);

	return 0;
}
