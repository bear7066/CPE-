#include <iostream>
using namespace std;

// line 9 --> n �Ψӭp��n�洫���Ÿ�
// line 14 --> �Yn%2==1 �h�����A�ӤS��n++�A�ҥH�i�H�@���洫
// line 20 --> �ݥ洫����(���˧��r��)�A�h�L�X

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