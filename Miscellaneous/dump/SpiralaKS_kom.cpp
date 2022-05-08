#include <iostream>
#include <iomanip>
using namespace std;

void printSpiral(int wymysl,int size) //wspomniana funkcja
{
    //wymysl to liczba od kt�rej si� zaczyna
    //size to wysokosc/szerokosc
    int row = 0, col = 0;

    int boundary = (size*size) - (size-1); //potega wielkosci - wielkosc + 1
    int sizeLeft = size - 1; // pozostala wielkosc
    int flag = 1; //jest po to, by dzia�a�o co drugie przej�cie p�tli (b�dzie si� zmienia� tylko z 1 na 2 i mog�oby by� typu prawda/fa�sz)

    char move = 'r';//oznaczenie kierunku przechodzenia

    try{//mmmmm, Tw�j ulubiony
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

            if (i == boundary)//jesli dosz�o do granicy
            {
                boundary -= sizeLeft;//zmie� granice(�eby dostosowa�a si� do nast�pnego i)

                if (flag != 2)//je�li nie jest to parzysty przebieg
                {
                    flag = 2;//nast�pny b�dzie parzystym
                }
                else//je�li jest to parzysty (co drugi)
                {
                    flag = 1;//nast�pny b�dzie pierwszy
                    sizeLeft -= 1;//zmniejsz granice(bo co 2 przechodzi po troche mniej)
                }

                switch (move)//skoro uderzyli�my w granice, to zmieniami kierunek(je�li odwracasz p�tle, warto zmieni� t� cz�� i pocz�tkow� warto�� move)
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
    }catch(bad_alloc){//no i dalsza cz�� Twojego ulubionego
        cout << "Gdzie moja pamiec?";
    }
}

int main()
{
    int liczba;
    cin >> liczba; //to, od czego schodzi w d�
    int i = 0;
    while(liczba > (i*i)) //ka�dy normalny algorytm bazuje na wielko�ci wysoko��/szeroko��, wi�c to wyci�gamy (d��y do takiej pot�gi, �eby nie by�a mniejsza od podanej liczby, wi�c liczba si� zmie�ci)
        i++;

    printSpiral(liczba, i); //wszystko w funkcji wy�ej
    return 0;
}
