#include <vector>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printParentheses(string& str) {
	stack<int> st;
	
	for(int i=0; i<str.length(); ++i) {
		if(str[i] == '(') {
			st.push(i);
		}
		else if(str[i] == ')') {
			cout << "(" << st.top() << "," << i << ")";
			st.pop();
		}
	}	
}

int main() {
	string str;
	getline(cin >> ws, str);
	
	printParentheses(str);
}
