/*  Toms Madžuls, tm22005
    B22. Sastādīt programmu, kura reizina un dala racionālus skaitļus, racionālos skaitļus uzdodot kā divu veselu skaitļu pāri 
    (1/3 tiek uzdota kā divi skaitļi 1 un 3). Rezultātam jābūt kā nesaīsināmam daļskaitlim. Risinājumā izmantot funkciju, 
    kas reizina divus racionālus skaitļus un funkciju, kas pārveido racionālu skaitli par nesaīsināmu daļskaitli.
    Programma izveidota: 12.10.2022 */
#include <iostream>
#include <numeric> //kodam nepieciesama c++17 versija, lai darbotos gcd()
using namespace std;
char izvele;

void saisinasana(int &a, int &b){ //lieto pec references 
    int dalitajs = gcd(a, b);
    a = a/dalitajs;                 //parveidoju funkciju, kur netiek veidoti un padoti jauni mainigie
    b = b/dalitajs;                 //bet vienkarsi atgriez tos pasus jau saisinatus
}

void dalisana(int lu, int ld, int ru, int rd){ 
    int dal1 = lu * rd;                         //dalisanas f-ja, reizinasana krustaa
    int dal2 = ld * ru;
    saisinasana(dal1, dal2);
    cout << "Dalijums: " << dal1 << " / " << dal2;
}

void reizinasana(int lu, int ld, int ru, int rd){
    int reiz1 = lu * ru;                        //tas pats kas dalisanas f-ja, tikai nereizina krusta
    int reiz2 = ld * rd; 
    saisinasana(reiz1, reiz2);
    cout << "Reizinajums: " << reiz1 << " / " << reiz2;
}

int main() {
    int m, n, x, y;
    do{
        cout << "Ievadiet 1. racionalo skaitli (m / n): ";
        cin >> m >> n;
        cout << "Ievadiet 2. racionalo skaitli (m / n): ";
        cin >> x >> y;
        if (n <= 0){
            cout << "1. Dalitajam jabut naturalam skaitlim!" << endl;
        }else if (y <= 0){
            cout << "2. Dalitajam jabut naturalam skaitlim!" << endl;
        }else{                                      //ja ievaditi pareizi racionali sk., tad darbiba notiek, citadak
        reizinasana(m, n, x, y);                    //tiek pazinots, ka dalitaji nebija atbilstosi prasibam
        cout << endl;
        dalisana (m, n, x, y);
        cout << endl << "Vai turpinat? y/n" << endl;
        cin >> izvele;
        }
    }while (izvele == 'y');
    return 0;
}