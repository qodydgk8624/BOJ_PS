// BOJ - 17111

// Is it rated?

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> el;

void ea(string s)
{
	el.push_back(s);
}
void emoji_setup()
{
	ea("round");
	
}

int chk(string s)
{
	int cmp=0;
	for(int i=0; i<el.size(); i++)
		if(el[i]==s)
		{
			return cmp=1;
		}
	return cmp;
}

int main()
{
	emoji_setup();
	string str;
	int hasEmoji = 0,finding = 0;
	char a;
	while((a = getchar()) != -1)
	{
		if(finding && a != '\n' && !hasEmoji)
		{
			if(a <= 'Z' && a >= 'A')
   				a = a - ('Z' - 'z');
			str += a;
			if(chk(str)) hasEmoji = 1,finding = 0, str = "";
		}
		if(a == 'R' || a == 'r') str='r',finding=1;
		else if(a == '\n')
		{
			if(hasEmoji) puts("1");
			else puts("0");
			return 0;
		}
	}
	
}
