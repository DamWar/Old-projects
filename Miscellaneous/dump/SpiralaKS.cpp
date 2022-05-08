#include <iostream>
#include <iomanip>
using namespace std;

void printSpiral(int wymysl,int size)
{
    int row = 0, col = 0;

    int boundary = (size*size) - (size-1);
    int sizeLeft = size - 1;
    int flag = 1;

    char move = 'r';

    try{
        int** matrix = new int*[size];
        for(int i = 0; i < size; ++i)
            matrix[i] = new int[size];

        for (int i = (size*size)-1; i >= 0; i--)
        {
            if( wymysl < i ){
                matrix[row][col] = 0;
            }else{
                matrix[row][col] = i;
            }


            switch (move)
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

            if (i == boundary)
            {
                boundary -= sizeLeft;

                if (flag != 2)
                {
                    flag = 2;
                }
                else
                {
                    flag = 1;
                    sizeLeft -= 1;
                }

                switch (move)
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

        for (row = 0; row < size; row++){
            for (col = 0; col < size; col++){
                int n = matrix[row][col];
                cout << setw(5) << n << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < size; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }catch(bad_alloc){
        cout << "Gdzie moja pamiec?";
    }
}

int main()
{
    int size;
    cin >> size;
    int i = 0;
    while(size > (i*i))
        i++;

    printSpiral(size, i);
    return 0;
}
