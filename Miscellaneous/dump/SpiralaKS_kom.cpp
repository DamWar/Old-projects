#include <iostream>
#include <iomanip>
using namespace std;

void printSpiral(int wymysl,int size) //wspomniana funkcja
{
    //wymysl to liczba od której siê zaczyna
    //size to wysokosc/szerokosc
    int row = 0, col = 0;

    int boundary = (size*size) - (size-1); //potega wielkosci - wielkosc + 1
    int sizeLeft = size - 1; // pozostala wielkosc
    int flag = 1; //jest po to, by dzia³a³o co drugie przejœcie pêtli (bêdzie siê zmieniaæ tylko z 1 na 2 i mog³oby byæ typu prawda/fa³sz)

    char move = 'r';//oznaczenie kierunku przechodzenia

    try{//mmmmm, Twój ulubiony
        int** matrix = new int*[size];//deklaracja
        for(int i = 0; i < size; ++i)//tablicy
            matrix[i] = new int[size];//dynamicznej

        for (int i = (size*size)-1; i >= 0; i--)//od najwiekszej liczby dostepnej w zakresie (potega wielkosci, bo tyle elementow w taliby) do zera
        {
            if( wymysl < i ){//poczatkowe, wieksze liczby niz chcemy sa zastepowane zerami
                matrix[row][col] = 0;
            }else{
                matrix[row][col] = i;
            }


            switch (move)//w zaleznosci od kierunku zmienia
            {
                case 'r':
                    col += 1;
                    break;
                case 'l':
                    col -= 1;
                    break;
                case 'u':
                    row -= 1;
                    break;
                case 'd':
                    row += 1;
                    break;
            }

            if (i == boundary)//jesli dosz³o do granicy
            {
                boundary -= sizeLeft;//zmieñ granice(¿eby dostosowa³a siê do nastêpnego i)

                if (flag != 2)//jeœli nie jest to parzysty przebieg
                {
                    flag = 2;//nastêpny bêdzie parzystym
                }
                else//jeœli jest to parzysty (co drugi)
                {
                    flag = 1;//nastêpny bêdzie pierwszy
                    sizeLeft -= 1;//zmniejsz granice(bo co 2 przechodzi po troche mniej)
                }

                switch (move)//skoro uderzyliœmy w granice, to zmieniami kierunek(jeœli odwracasz pêtle, warto zmieniæ t¹ czêœæ i pocz¹tkow¹ wartoœæ move)
                {
                    case 'r':
                        move = 'd';
                        break;
                    case 'd':
                        move = 'l';
                        break;
                    case 'l':
                        move = 'u';
                        break;
                    case 'u':
                        move = 'r';
                        break;
                }
            }
        }

        for (row = 0; row < size; row++){//tutaj poprostu wypisuje te wartosci
            for (col = 0; col < size; col++){
                int n = matrix[row][col];
                cout << setw(5) << n << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < size; ++i) {//usuwa
            delete [] matrix[i];
        }
        delete [] matrix;
    }catch(bad_alloc){//no i dalsza czêœæ Twojego ulubionego
        cout << "Gdzie moja pamiec?";
    }
}

int main()
{
    int liczba;
    cin >> liczba; //to, od czego schodzi w dó³
    int i = 0;
    while(liczba > (i*i)) //ka¿dy normalny algorytm bazuje na wielkoœci wysokoœæ/szerokoœæ, wiêc to wyci¹gamy (d¹¿y do takiej potêgi, ¿eby nie by³a mniejsza od podanej liczby, wiêc liczba siê zmieœci)
        i++;

    printSpiral(liczba, i); //wszystko w funkcji wy¿ej
    return 0;
}
