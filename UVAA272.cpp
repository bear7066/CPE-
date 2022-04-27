#include <iostream>
using namespace std;

// line 9 --> n 用來計算要交換的符號
// line 14 --> 若n%2==1 則替換，而又有n++，所以可以一直交換
// line 20 --> 待交換完畢(掃瞄完字串)，則印出

int main() {
	char s;
	int n = 0;
	while (cin.get(s)) {

		if (s == '"') {
			n++;
			if (n % 2 == 1)
				cout << "``";
			else
				cout << "''";
		}
		else
			cout << s;
	}
}