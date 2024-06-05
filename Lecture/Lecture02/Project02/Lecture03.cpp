#include <iostream>

using namespace std;
int main()
{
	int num = 0;
	string name;
	cout << "백호영: 아힘들다.." <<endl;

	while (num !=18) 
	{
		cout << "나쁜놈의 이름과 나이를 입력하세요.\n";
		cin >> name >> num;
	}
	cout << "백호영: 누님보다 "<< num <<"살이나 어린주제에" << num <<"나쁜사람" << endl;
	return 0;
}