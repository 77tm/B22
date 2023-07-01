/*  Toms Madžuls, tm22005
    B22. Sastādīt programmu, kura reizina un dala racionālus skaitļus, racionālos skaitļus uzdodot kā divu veselu skaitļu pāri 
    (1/3 tiek uzdota kā divi skaitļi 1 un 3). Rezultātam jābūt kā nesaīsināmam daļskaitlim. Risinājumā izmantot funkciju, 
    kas reizina divus racionālus skaitļus un funkciju, kas pārveido racionālu skaitli par nesaīsināmu daļskaitli.
    Programma izveidota: 03.10.2022 */

#include <iostream>
#include <numeric>
using namespace std;
int reizinasana(int m, int n, int x, int y);
int lielakais_dalitajs(int n);
int dalitajs;

int lielakais_dalitajs(int n) {
	int i;
	for (i = n; i >= 1; --i) {  //for (i = n; i >= 1; --i)
		if (n % i == 0) //ja i dalas ar n, tad tas ir lielakais dalitajs
            return i;
	}
	return 0; //ja n ir 1, tad atgriez 0
}

void reduceFraction(int lu, int ld, int ru, int rd)
{
    int d = gcd(lu, ru);
 
    lu = lu / d;
    ru = ru / d;
 
    cout << "x = " << d << ", y = " << d << endl;
}
 

int dalisana(int lu, int ld, int ru, int rd){
    int dal1 = lu * rd;
    int dal2 = ld * ru;
    if (dal2 > dal1){
        dalitajs = lielakais_dalitajs(dal1);
    }else{
        dalitajs = lielakais_dalitajs(dal2);
    }
    int gala1 = dal1/dalitajs;
    int gala2 = dal2/dalitajs;
    cout << "Dalijums: " << gala1 << " / " << gala2;
    return 0;
}

int reizinasana(int lu, int ld, int ru, int rd){
    int reiz1 = lu * ru;
    int reiz2 = ld * rd;
    if (reiz2 > reiz1){
        dalitajs = lielakais_dalitajs(reiz1);
    }else{
        dalitajs = lielakais_dalitajs(reiz2);
    }
    int gal1 = reiz1/dalitajs;
    int gal2 = reiz2/dalitajs;
    cout << "Reizinajums: "  << gal1 << " / " << gal2;
    return 0;
}

int main() {
    int m, n, x, y;
    cout << "Ievadiet 1. racionalo skaitli (m / n): ";
    cin >> m >> n;
    cout << "Ievadiet 2. racionalo skaitli (m / n): ";
    cin >> x >> y;
    reizinasana(m, n, x, y);
    cout << endl;
    dalisana (m, n, x, y);
    cout << endl;
    reduceFraction(m, n, x, y);
  return 0;
}