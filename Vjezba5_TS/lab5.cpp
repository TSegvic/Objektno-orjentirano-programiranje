#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<random>
using namespace std;
class Karta {
public:
	int broj;
	string znak;
	Karta(int broj,const string znak):broj(broj),znak(znak){}
	void ispisi() const {
		cout << broj << " " << znak;
	}
};
class Mac {
private:
	vector<Karta> karte;
	const vector<string> znakovi = { "Spade","Bastoni","Kupe","Dinari" };
public:
	Mac() {
		for (const auto& znak : znakovi)
		{
			for (int broj = 1;broj <= 10;broj++)
			{
				karte.emplace_back(broj, znak);
			}
				
		}
	}
	void promjesaj()
	{
		random_device rd;
		mt19937 g(rd());
		shuffle(karte.begin(), karte.end(), g);
	}
	vector<Karta> podijeli(int brk)
	{
		vector<Karta> ruka(karte.begin(), karte.begin() + brk);
		karte.erase(karte.begin(), karte.begin() + brk);
		return ruka;
	}
};
class Igrac {
public:
	string ime;
	vector<Karta> karte;
	int bodovi;
	Igrac(const string ime):ime(ime),bodovi(0){}
	void dodajKarte(const vector<Karta>& noveKarte)
	{
		karte.insert(karte.end(), noveKarte.begin(), noveKarte.end());
	}
	void ispisKarte()const {
		cout << ime << " ima karte: ";
		for (const auto& karta : karte)
		{
			karta.ispisi();
			cout << ", ";
		}
		cout << endl;
	}
	void izracun()
	{
		int brSpade[11] = { 0 };
		int brBate[11] = { 0 };
		int brKupe[11] = { 0 };
		int brDinar[11] = { 0 };
		for (const auto& karta : karte)
		{
			if (karta.znak == "Spade")
			{
				brSpade[karta.broj]++;
			}
			else if (karta.znak == "Bastoni")
			{
				brBate[karta.broj]++;
			}
			else if (karta.znak == "Kupe")
			{
				brKupe[karta.broj]++;
			}
			else if (karta.znak == "Dinari")
			{
				brDinar[karta.broj]++;
			}
		}
		if (brSpade[1] > 0 && brSpade[2] > 0 && brSpade[3] > 0)bodovi += 3;
		if (brBate[1] > 0 && brBate[2] > 0 && brBate[3] > 0)bodovi += 3;
		if (brKupe[1] > 0 && brKupe[2] > 0 && brKupe[3] > 0)bodovi += 3;
		if (brDinar[1] > 0 && brDinar[2] > 0 && brDinar[3] > 0)bodovi += 3;
		int ukupni[11] = { 0 };
		for (const auto& karta : karte)
		{
			ukupni[karta.broj]++;
		}
		for (int i = 1;i < 3;i++)
		{
			if (ukupni[i] == 3)
			{
				bodovi += 3;
			}
			else if (ukupni[i] == 4)
			{
				bodovi += 4;
			}
		}
	}
};
int main()
{
	int brigraca;
	cout << "Unesi broj igraca (2 ili 4): ";
	cin >> brigraca;
	vector<Igrac> igraci;
	for (int i = 0;i < brigraca;i++)
	{
		string ime;
		cout << "Unesite ime " << i + 1 << ". igraca: ";
		cin >> ime;
		igraci.emplace_back(ime);
	}
	Mac mac;
	mac.promjesaj();
	for (auto& igrac : igraci)
	{
		igrac.dodajKarte(mac.podijeli(10));
	}
	cout << "Kare podjeljene racunanje akuze"<<endl;
	for (auto& igrac : igraci)
	{
		igrac.ispisKarte();
		igrac.izracun();
		cout << igrac.ime << " ima " << igrac.bodovi << " bodova iz akuze"<<endl;
	}
	return 0;
}