#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    int cnt, n = 0, j, i, c, x, y, a[25][3], curent, stari[25], fin[25], nr_stari, nr_alf, nr_fin, ini;
    char alf [25], cuvant[256], z;
    ifstream f("fisier.txt");
    f>>nr_stari;
    for(i = 0; i < nr_stari; i++)
        f >> stari[i];

    f>>nr_alf;
    for(i = 0; i < nr_alf; i++)
        f>>alf[i];
    f>>ini;
    cout<<ini<<endl;
    f >> nr_fin;
    for(i = 0; i < nr_fin; i++)
        f >> fin[i];
    while(f >> x)
    {
        f >> y;
        f >> z;
        a[n][0] = x;
        a[n][1] = y;
        a[n][2] = int(z);
        n++;
    }
    for(i = 0; i < n; i++)
    {
            cout<< a[i][0]<< " " << a[i][1]<< " " << char(a[i][2]);
        cout<< endl;
    }
    cin.get(cuvant, 256);
    if( cuvant[0] == '*')
     {
         j = 0;
         cout << "ramana in starea initiala " << ini;
         for(i = 0; i < nr_fin; i++)
            {
                if(ini == fin[i])
                j++;
            }
        if( j != 0 )
            cout << " care este finala";
        else
            cout << " care nu este finala";
    }
    else
    {
    curent = ini;
    cout <<"starea initiala este: " << curent << endl;
    cout << "starile prin care trece sunt: "<< curent << " ";
    for(c = 0; c < strlen(cuvant); c++)
    {   cnt = 0;
        for( i = 0; i < n; i++)
        {
            if ( curent == a[i][0] && int(cuvant[c]) == a[i][2])
                {
                    cnt = 1;
                    curent = a[i][1];
                    break;
                }
        }
        if ( cnt == 0)
        {
            cout << endl;
            cout << "caracterul " << cuvant[c] << " nu apartine limbajului sau nu exista tranzitie din starea " << curent << " pentru el" ;
            return 0;
        }
        cout << curent <<" " ;
    }
    cout << endl;
    cout << "starea in care am ramas: "<<curent << endl;
    j = 0;
    for(i = 0; i < nr_fin; i++)
        {
            if(curent == fin[i])
                j++;
        }
    cout << endl;
    if(j == 0)
        cout << "Nu am ajuns in stare finala";
    else
        cout << "Am ajuns in stare finala";
    }
    return 0;
}
