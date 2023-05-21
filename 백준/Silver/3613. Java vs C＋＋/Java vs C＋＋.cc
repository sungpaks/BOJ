#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string src);

int main()
{
	string src;
	cin >> src;
	cout << convert(src);
}

string convert(string src)
{
	int i = 0;
	int flag = 0; //1이면 java, 2면 C++
	string result; //ㄷㄷㄷ NULL로 초기화하면 안되넹
	if (('A'<=src[0]&&src[0]<='Z') || src[0] == '_' || src.empty()) return "Error!";
	while (src[i])
	{
		if (!('A' <= src[i] && src[i] <= 'Z') && !('a' <= src[i] && src[i] <= 'z') && src[i] != '_') return "Error";
		if (src[i] == '_') //C++형식
		{
			if (i >= src.length() - 1 || flag == 1 || !('a'<=src[i+1] && src[i]<='z')) return "Error!"; //이미 java형식이었는데, C++형식이 나옴
			else result += src[++i] - 32;
			flag = 2;
		}
		else if ('A' <= src[i] && src[i] <= 'Z') //java형식
		{
			if (flag == 2) return "Error!";
			else 
			{
				result += '_';
				result += src[i] + 32;
			}
			flag = 1;
		}
		else result += src[i];
		i++;
	}
	//if (flag == 0) return "Error!";
	return result;
}