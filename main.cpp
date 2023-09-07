#include "labirint.h"
#include <iostream>

using namespace std;

int main()
{
    Labirint l;
    ifstream input("labirint.txt");
    l.unesiPodatke(input);
    input.close();

    cout << l.udaljenost('A',9,'J',8) << endl;
    cout << l.udaljenost('J',8,'I',9) << endl;
    cout << l.udaljenost('A',9,'B',9) << endl;
    cout << l.udaljenost('A',9,'D',7) << endl;

    return 0;
}
