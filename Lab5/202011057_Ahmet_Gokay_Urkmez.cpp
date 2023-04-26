#include <iostream>
using namespace std;

//class Matrix;

template<class T>
class Node{
public:
	T data;
	Node<T>* next = NULL;
	Node(T d) {
		data = d;
		next = NULL;
	}
};

template<class T>
class LinkedList { 
private:
  Node<T> *first;
  Node<T> *last;
  Node<T> *iter;
  int cnt; // easily get the current # of items in the list
public:
    LinkedList( ) {last = first = iter = NULL; cnt=0;}
    bool isEmpty( ) { return first == NULL; }
    int getCnt( ) { return cnt; }
    
    void append(T elt){
    	Node<T> *newNode = new Node<T>(elt);
    	
    	if(isEmpty()){
    		last = first = newNode;
		}
		else {
			last->next = newNode;
			last = last->next;
		}
		++cnt;
	}
	
    void insert(T elt, int i){ // i=0 first
    	Node<T>* newNode(elt);
    	if(i==0) {
    		newNode->next = first;
			first = newNode;  
		}
		else {
			iter = first;
    		for(int j=1; j<i; ++j) {
    			iter = iter->next;
			}
			newNode->next = iter->next;
			iter->next = newNode;
		}
		
		++cnt;
	}
    
    void deleteLast() {
    	if(cnt == 1){
    		first=last=NULL;
		}
		else {
			iter = first;
			for(int i=0; i<cnt-1; ++i) {
				iter = iter->next;
			}
			iter->next = NULL;
			last = iter;
		}
		
		--cnt;
	}
	
    void deleteFirst(T& elt);
    
    void deleteNth(T& elt, int n);
};

template <class T>
class StackLL {
private:
   LinkedList<T> data;
   int Top;
   int Capacity;
public:
   StackLL( ) {}
   StackLL(T val) {data.append("");}
   bool isEmpty( ) { return data.isEmpty( ); }
   int cntElts( ) { return data.getCnt(); }
   void pop() { data.deleteLast();};
   void push(T x) { data.append(x);}
};

int main(int argc, char *argv[]) {
   StackLL<int> S1;
   StackLL<string> S2("3");
   //StackLL<Matrix> *S3= new StackLL<Matrix>();

   if(S1.isEmpty( )) cout << "S1 is empty"<<endl;
   
   cout << "S2 size:" << S2.cntElts() << endl;
   cout << "S1 size:" << S1.cntElts() << endl;
	
   S1.push(7);
   if(S1.isEmpty( )) cout << "S1 is empty"<<endl;
   cout << "S1 size:" << S1.cntElts() << endl;
   
   
   
   return 0;
}
