// Emoji-Infinity-Test

#include <bits/stdc++.h>

using namespace std;

bool e1xception(string s,bool chk)
{
	if(chk& s == ":c:cat:") return true;
	else if(chk& s == "`:cat:`") return true;
	else if(chk& s == "c:c:cat:at:c") return true;
	else if(chk& s == "````:cat:``") return true;
	else if(chk& s == "````:cat:`") return true;
	else if(chk& s == "````:cat:") return true;
	else if(chk& s == "` `` :cat: `` `") return true;
	else if(chk& s == "` `` ` `` :cat:") return true;
	else if(chk& s == "` `` ` `` :cat: `") return true;
	else if(chk& s == "` `` ` `` :cat: ``") return true;
	else if(chk& s == "` `` ` `` :cat: ```") return true;
	else if(chk& s == "` `` ` `` :cat: `````") return true;
	else if(chk& s == "` `` ` `` :cat: ```````") return true;
	else if(!chk& s == "```:cat:") return true;
	else if(!chk& s == ":cat:```") return true;
	return false;
}
int main() {
  while (true) {
    string str;
    getline(cin, str);

    if (str == "")
      break;

    bool chk = false;
    for (int i = 0;i < str.length();++i) {
      if (i + 4 < str.length() && str.substr(i, 5) == ":cat:")
        chk = true;
      if (i + 3 < str.length() && str.substr(i, 4) == "??")
        chk = true;
    }
	if(e1xception(str,chk))
	{
		chk = !chk;
	}
	if(str[0] == '/') chk = false;
    if (chk)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
