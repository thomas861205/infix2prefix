#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Priority(char ch){
	if (ch == '*' || ch == '/') return 1;
	else if (ch == '+' || ch == '-') return 2;
	else return 10;
}

void Postfix(string prefix){
	stack<char> operators;
	operators.push('#');

	int i = -1;
	while(i != prefix.length()){
		if (prefix[i+1] >= 48 && prefix[i+1] <= 57) cout << prefix[i+1];
		else if (prefix[i+1] == '+' || prefix[i+1] == '-' || prefix[i+1] == '*' || prefix[i+1] == '/'){
			for (; Priority(operators.top()) <= Priority(prefix[i + 1]); operators.pop()){
				cout << operators.top();
			}
			operators.push(prefix[i+1]);
		}
		else;
		i++;
	}
	while(operators.top() != '#'){
		cout << operators.top();
		operators.pop();
	}
}

int main(){
	string prefix;

	cin >> prefix;
	Postfix(prefix);

	return 0;
}