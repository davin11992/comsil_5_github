#include "LinkedList.h"

//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template<typename T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0)
				return false;

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T> *current = this->first; // 현재 스택의 첫 번째 노드를 가리키는 포인터 current를 설정
			element = current->data; //current(맨 앞 노드)의 데이터를 element에 저장
			this->first = this->first->link; // first를 다음 노드로 갱신
			delete current;	//current 노드 삭제
			this->current_size--; // 스택의 노드 개수를 1 감소
			
			return true;
			}
};
