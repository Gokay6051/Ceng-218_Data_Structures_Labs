#include <iostream>

using namespace std;
	
template<class T>
class LinkedNode{
public:
	T data;
	LinkedNode<T> *next = NULL;	
	
	LinkedNode(T elt){
		data = elt;
		this->next=NULL;
	}
};


template<class T>
class LinkedList{
private:
	LinkedNode<T> *first;
	LinkedNode<T> *last;
	int cnt;

public:
	LinkedList() {first=last=NULL; cnt=0;}
	
	bool isEmpty() {return first==NULL;}	
	
	T Top() {
		if(isEmpty()==1) {return -1;}
		return last->data;
	}
	
	int Size() {return cnt;}
	
	void deleteLast() {
		if(isEmpty()==1) {return;}
		LinkedNode<T> *iter = first;
		while(iter->next!=last)
			iter=iter->next;
		
		last=iter;
		last->next=NULL;
		--cnt;
	}
	
	void Swap() { //direkt data da deðiþebilir. Ben node deðiþtirdim.
		if(cnt<=1) {return;}
		
		if(cnt==2) { //bu duruma özel yazýlmalý
			
			
			return;
		}
		
		LinkedNode<T> *iter = first;
		while(iter->next->next != last) {iter = iter->next;}
		
		last->next = iter->next;
		iter->next = last;
		last = last->next;
		last->next = NULL;
	}
	
	//sonradan eklenenler
	void append(T elt){
    	LinkedNode<T> *newNode = new LinkedNode<T>(elt);
    	
    	if(isEmpty()){
    		last = first = newNode;
		}
		else {
			last->next = newNode;
			last = last->next;
		}
		++cnt;
	}
};


template<class T>
class StackLL{
private:
	LinkedList<T> data;
	
public:
	stackLL() {}
	
	T top(){return data.Top();}
	int size() {return data.Size();}
	void pop() {data.deleteLast();}
	void swap() {data.Swap();}
	
	//sonradan eklenenler
	//StackLL(T val) {data.append(val);}
   	bool isEmpty( ) { return data.isEmpty( ); }
   	void push(T x) { data.append(x);}
};


int main() {
	StackLL<int> S1;

   	if(S1.isEmpty( )) cout << "S1 is empty"<<endl;

   	cout << "S1 size:" << S1.size() << endl;
	
   	S1.push(7);
   	if(S1.isEmpty( )) cout << "S1 is empty"<<endl;
   	
   	cout << "S1 size:" << S1.size() << endl;
   	cout << "S1 top:" << S1.top() << endl;
   	
   	S1.push(13);
   	S1.push(22);
   	
   	cout << "S1 size:" << S1.size() << endl;
   	cout << "S1 top:" << S1.top() << endl;
   	
   	S1.push(32);
   	
   	cout << "S1 size:" << S1.size() << endl;
   	cout << "S1 top:" << S1.top() << endl;
   	
   	S1.swap();
   	
   	cout << "S1 size:" << S1.size() << endl;
   	cout << "S1 top:" << S1.top() << endl;
   
   	return 0;
}
