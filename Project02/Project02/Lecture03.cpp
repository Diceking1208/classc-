#include <iostream>

using namespace std;
int main()
{
	int num = 0;
	string name;
	cout << "��ȣ��: �������.." <<endl;

	while (num !=18) 
	{
		cout << "���۳��� �̸��� ���̸� �Է��ϼ���.\n";
		cin >> name >> num;
	}
	cout << "��ȣ��: ���Ժ��� "<< num <<"���̳� �������" << num <<"���ۻ��" << endl;
	return 0;
}