#include "MyString.h"

using namespace std;

// 이번 강의의 목표: 구체적인 프로그래밍 능력 기르기
/*
작동예시(요구사항)

1.MyString(const char* init) 생성자: 리터럴로 MyString 인스턴스를 만들고 출력
2.find: 멤버함수로 시작 인덱스를 반환
3.복사생성자: =로 내용을 복사해서 초기화
4.isEqual 한글자도 빠짐없이 동일하면 true, 아니면 false
5.insert 삽입을 해서 새로운 인스턴스로 반환  
6.substring: (x, y) index x부터 y개만큼 가져와서 새로운 인스턴스로 반환
7.concat: 기존 문자열에 새로운 문자열을 붙여서 새로운 인스턴스로 반환
*/

// 비어 있는 MyString() 생성
MyString::MyString()
{
	str_ = nullptr; // 처음에는 null
	size_ = 0; // 내용이 없으니까 0 으로 초기화
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char* init)// 문자열리터럴의 포인터를 받아와서 초기화 
{
	// 크기(size_) 결정
	size_ = 0;
	while(init[size_] != '\0')
		size_++;

	// 메모리 할당
	str_ = new char[size_];

	// 데이터 복사
	memcpy(str_, init, size_);
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString& str)
{
	// 기본 복사 생성자는 포인터 주소만 복사하기 때문에 
	// 소멸시 오류 발생
	// 여기서는 새로 메모리를 할당 받아서 복사

	size_ = str.size_;
	str_ = new char[size_];
	memcpy(str_, str.str_, size_);

	/*
	 참고사항

	 c++ 복사생성자의 경우에 우리가 안만들어주면 내부적으로 만들어주기도 한다 
	 그런데 이 방식은 포인터 주소만 복사한다
	 소멸시 그 주소를 사용하는 곳에서 오류가 발생할 수 있기 때문에  
	 새로운 공간에 내용을 복사한다
	*/
}

// 소멸자
MyString::~MyString()
{
	// 메모리 해제
	if(str_ != nullptr) // null이아닐경우 해제 
	{
		delete[] str_;
		str_ = nullptr;
		size_ = 0;
	}
}

bool MyString::IsEmpty()
{
	return Length() == 0;
}

bool MyString::IsEqual(const MyString& str) // 편의상 참조& 사용
{
	// 힌트: str.str_, str.size_ 가능

	return false;
}

int MyString::Length()
{
	return size_;
}

void MyString::Resize(int new_size)
{
	// 메모리 재할당과 원래 갖고 있던 내용 복사
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num)
{
	// 복사할 인덱스: start, start + 1, ... , start + num - 1
	// assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

	MyString temp;

	// TODO:

	return temp;
}

MyString MyString::Concat(MyString app_str)
{
	MyString temp;

	// TODO: 

	return temp;
}

MyString MyString::Insert(MyString t, int start)
{
	assert(start >= 0);
	assert(start <= this->size_);

	MyString temp;

	// TODO:

	return temp;
}

int MyString::Find(MyString pat)
{
	//TODO:

	return -1;
}

void MyString::Print()
{
	for (int i = 0; i < size_; i++)
		cout << str_[i];
	cout << endl;
}

