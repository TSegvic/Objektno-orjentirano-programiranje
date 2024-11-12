#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int brpon(string a, string b)
{
	int n = 0;
	int pos = a.find(b);
	while (pos != string::npos)
	{
		n++;
		pos = a.find(b, b.length() + pos);
	}
	return n;
}
void ispravi(string& a)
{
	for (int i = 0; i < a.length()-1; i++)
	{
		if ((ispunct(a.at(i))||a.at(i)==' ') && a.at(i - 1) == ' ')
		{
			a.erase(i - 1,1);
			i--;
		}
		if (ispunct(a.at(i)) && a.at(i + 1) != ' ')
		{
			a.insert(i + 1, " ");
		}
	}
}
void prored(vector<string>&a)
{
	string str;
	int n;
	cout <<endl<< "upisi broj stringova ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout <<endl<< "upisi " << i + 1 << ". string"<<endl;
		cin >> str;
		a.push_back(str);
	}
	for (int i = 0; i < a.size(); i++)
	{
		reverse(a.at(i).begin(), a.at(i).end());
	}
	sort(a.begin(), a.end());
}
/*bool samoglasnik(char a)
{
	tolower(a);
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	else
		return 0;
}
void tolatin(string& a)
{
	int n = 0;
	int brojsug = 1;
	int broj = a.length();
	if (samoglasnik(a.at(n)))
	{
		a += "hay";
	}
	else
	{
		n++;
		while (!samoglasnik(a.at(n)))
		{
			brojsug++;
			n++;
		}
		string b=a.substr(0, brojsug);
		string c = a.substr(brojsug, a.length() - brojsug);
		a.replace(0,1, c);
		a.erase(c.length(), c.length()+1);
		a += b;
		a += "ay";
		
	}
	cout << endl << a;
}
void transform(vector<string> &a)
{
	string b = a.at(rand() % a.size());
	string rj;
	int pos=0;
	for (int i = 0; i < b.length(); i++)
	{
		if (ispunct(b.at(i)) || b.at(i) == ' ')
		{
			rj = b.substr(pos, i);
			tolatin(rj);
			pos = i+1;
		}
	}

}*/
int main()
{
	//string a="qwertzr";
	/*string b = "r";
	
	cout<<"Broj ponavljanja drugog string u prvom je : "<<brpon(a, b)<<endl;*/
	string krivo = "Ja bih ,                    ako ikako mogu , ovu recenicu napisala ispravno.";
	ispravi(krivo);
	cout << krivo<<endl;
	vector<string> d;
	/*prored(d);
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i)<<endl;
	}*/

}