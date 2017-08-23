#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
#include <bitset>
#include <fstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int Time = 100;
int run(string s);
void encode(string name);
void saveWrong();
void build();
void check(int t = Time);
string testname = "test";
string stdname = "std";
string makedata = "makedata";
int main()
{
	build();
	check();
	return 0;
}
void check(int t)
{
	int wrong = 0;
	for (int i = 1;i <= t;i++){
		run(makedata+" >input.txt");
		run(testname+" <input.txt >output1.txt");
		run(stdname +" <input.txt >output2.txt");
		if (run("fc output1.txt output2.txt")){
			wrong++;
			saveWrong();
			cout<<"Wrong Answer on test"<<i<<endl;
			cout<<"Continue?(y/n?): ";
			char c;cin>>c;
			if (c != 'n') continue;
			else break;
		}
		else cout<<"Accepted test"<<i<<endl;
	}
	if (!wrong) cout <<"All accepted"<<endl;
	else{
		cout<<"Display wrong data?(y/n):";
		char c;cin>>c;
		if (c == 'y') run("type WrongData.txt");
	}
}
int run(string s)
{
	int ret = system(s.c_str());
	return ret;
}
void encode(string name)
{
	int t = run("g++ "+name+".cpp -o "+name);
	if (t){
		cout<<"Error"<<endl;
		exit(-1);
	}
}

void saveWrong()
{
	static int t = 0;
	++t;
	stringstream tt;tt<<t;
	run("echo \"Test Data "+tt.str()+":\" >> WrongData.txt");
	run("type input >> WrongData.txt");
	run("echo \"---------------\" >> WrongData.txt");
	run("echo \"Correct Answer:\" >> WrongData.txt");
	run("type output2 >> WrongData.txt");
	run("echo \"--------------\" >>WrongData.txt");
	run("echo \"Output Answer:\" >> WrongData.txt");
	run("type output1 >> WrongData.txt");
	run("echo \"---------------------------\" >>WrongData.txt");

}
void build()
{
	encode(makedata);
	encode(testname);
	encode(stdname);
	run("echo 'a' > WrongData.txt");
	run("del WrongData.txt");
}
