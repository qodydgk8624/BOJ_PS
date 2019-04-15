// BOJ - 17120

// Emoji

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
	ea(":cat:");/*
	ea(":cat2:");
	ea(":smile_cat:");
	ea(":joy_cat:");
	ea(":smiley_cat:");
	ea(":heart_eyes_cat:");
	ea(":smirk_cat:");
	ea(":kissing_cat:");
	ea(":pouting_cat:");
	ea(":crying_cat_face:");
	ea(":scream_cat:");*/
	//ea("::");
	//ea("::");
	
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
		if(a == ':') str=':',finding=1;
		else if(a == '\n')
		{
			if(hasEmoji) puts("YES");
			else puts("NO");
			str="", finding = 0, hasEmoji = 0;
		}
	}
	
}
