// smallestk.cpp
// compile with
// c++ -o sk smallestk.cpp -std=c++11
// execute with
// ./sk
#include<iostream>
#include<set>
#include<cmath>
#include<cstdlib>
using namespace std;
void setmaker(const int&, const int&, set<int>&);

void setofk(int n, const int& a, set<int>& c, set<int>& d, int pos = 1) {
	if ((!d.empty())&&(pos >= *(d.begin()))) {
		return;
	}
	if (n == 1 || c.find(n) != c.end()) {
		if (d.find(pos) == d.end()) d.insert(pos);
		return;
	}
	for (auto i = c.rbegin(); i != c.rend(); ++i) {
		if (*i>n) continue;
		auto tempiter2=i;
		auto tempiter1=i;
		if(*i==1) {
			setofk(1,a,c,d,pos+n-1);
		}
		else if(*i!=1&&(n-*i)<*(--tempiter1))
		{
			int temp=1;
			int tempv=n-*i;
			while(tempv>*(++tempiter2)){
				tempv-=*i;
				++temp;
			}
			setofk(tempv,a,c,d,pos+temp);
		}
		else{
			setofk(n - *i, a, c, d, pos + 1);
		}
	}
}

int smallestk(const int& n, const int& a) {
	set<int>c, kset;
	setmaker(n, a, c);
	setofk(n, a, c, kset);
	return *(kset.begin());
}

int main()
{
	cout << "enter the n,a: " << endl;
	int n;
	int a;
	cin >> n >> a;
	cout << "smallest k is: " << smallestk(n, a) << endl;

	return 0;
}






void setmaker(const int& n, const int& a, set<int>& c) {
	int runner = 1;
	int num = 0;
	while (num <= n) {
		num = pow(runner, a);
		if ((num <= n) && (c.find(num) == c.end())) {
			c.insert(num);
		}
		++runner;
	}
}
