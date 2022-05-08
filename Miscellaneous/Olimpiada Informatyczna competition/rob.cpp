#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    long long int t;
    scanf("%d %lld", &n, &t);
    long long int tPoczatkowe = t;
    long long int tPrzebiegu;
    int udaneRotacji;
    int d[n];
    for ( int j = 0; j < n; ++j ){
        scanf("%d", &d[j]);
    }
    int xPoczatkowe;
    int yPoczatkowe;
    scanf("%d %d", &xPoczatkowe, &yPoczatkowe);
    long long int x = 0;
    long long int y = 0;
    int i = 0;
    long long int udane = 0;
    bool czyMniejszeX = false;
    bool czyWiekszeX = false;
    bool czyMniejszeY = false;
    bool czyWiekszeY = false;
    bool zapisaneX = false;
    bool zapisaneY = false;
    bool noToNiezleLiczby = false;
    bool koniecBaterii = false;
    bool odejmij = false;

    //sprawdzenie w przypadku, gdy ktoras z szukanych wspolrzednych jest rowna 0
    if( x == xPoczatkowe ){
        if( y == yPoczatkowe ){
            ++udane;
            odejmij = true;
        }
        else if( y > yPoczatkowe ){
            if( czyMniejszeY )
                ++udane;
            else
                czyWiekszeY = true;
        }
        else{
            if( czyWiekszeY )
                ++udane;
            else
                czyMniejszeY = true;
        }
    }if( y == yPoczatkowe ){
        if( x != xPoczatkowe ){
            if( x > xPoczatkowe ){
                if( czyMniejszeX )
                    ++udane;
                else
                    czyWiekszeX = true;
            }
            else{
                if( czyWiekszeX )
                    ++udane;
                else
                    czyMniejszeX = true;
            }
        }
    }

    while (true){
        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            y += d[i];
        }
        else{
            if( t != 0 ){
                y += t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            tPrzebiegu = tPoczatkowe - t;
            goto dodacX;
        }

        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            x += d[i];
        }
        else{
            if( t != 0 ){
                x += t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            tPrzebiegu = tPoczatkowe - t;
            goto odjacY;
        }

        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            y -= d[i];
        }
        else{
            if( t != 0 ){
                y -= t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x > xPoczatkowe ){
                if( czyMniejszeX )
                    ++udane;
                else
                    czyWiekszeX = true;
            }
            else{
                if( czyWiekszeX )
                    ++udane;
                else
                    czyMniejszeX = true;
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            tPrzebiegu = tPoczatkowe - t;
            goto odjacX;
        }

        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            x -= d[i];
        }
        else{
            if( t != 0 ){
                x -= t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            tPrzebiegu = tPoczatkowe - t;
            goto dodacY;
        }
    }

    while (true){
        dodacY:
        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            y += d[i];
        }
        else{
            if( t != 0 ){
                y += t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            if( x == 0 && y == 0 ){
                udaneRotacji = udane;
                noToNiezleLiczby = true;
                break;
            }
        }

        dodacX:
        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            x += d[i];
        }
        else{
            if( t != 0 ){
                x += t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            if( x == 0 && y == 0 ){
                udaneRotacji = udane;
                noToNiezleLiczby = true;
                break;
            }
        }

        odjacY:
        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            y -= d[i];
        }
        else{
            if( t != 0 ){
                y -= t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            if( x == 0 && y == 0 ){
                udaneRotacji = udane;
                noToNiezleLiczby = true;
                break;
            }
        }

        odjacX:
        if ( koniecBaterii == true ){
            break;
        }
        if ( d[i] < t ){
            t -= (d[i]+1);
            x -= d[i];
        }
        else{
            if( t != 0 ){
                x -= t;
                koniecBaterii = true;
            }else
                break;
        }
        if ( czyMniejszeY || czyWiekszeY )
            zapisaneY = true;
        if( x == xPoczatkowe ){
            if( y == yPoczatkowe )
                ++udane;
            else if( y > yPoczatkowe ){
                if( czyMniejszeY )
                    ++udane;
                else
                    czyWiekszeY = true;
            }
            else{
                if( czyWiekszeY )
                    ++udane;
                else
                    czyMniejszeY = true;
            }
        }
        if( zapisaneY ){
            czyWiekszeY = false;
            czyMniejszeY = false;
        }
        zapisaneY = false;

        if ( czyMniejszeX || czyWiekszeX )
            zapisaneX = true;
        if( y == yPoczatkowe ){
            if( x != xPoczatkowe ){
                if( x > xPoczatkowe ){
                    if( czyMniejszeX )
                        ++udane;
                    else
                        czyWiekszeX = true;
                }
                else{
                    if( czyWiekszeX )
                        ++udane;
                    else
                        czyMniejszeX = true;
                }
            }
        }
        if( zapisaneX ){
            czyWiekszeX = false;
            czyMniejszeX = false;
        }
        zapisaneX = false;
        if( ++i == n ){
            i = 0;
            if( x == 0 && y == 0 ){
                udaneRotacji = udane;
                noToNiezleLiczby = true;
                break;
            }
        }
    }
    if( noToNiezleLiczby == true ){
        if ( udane != 0 ){// mozliwe, ze zle oblicza udaneRotacji
            int czasRotacji = tPoczatkowe - t;
            long long int tempObl = tPoczatkowe / czasRotacji;//ile razy wykona sie pelna rotacja(w zaokragleniu int)
            //tempObl = t / tempObl;//ile razy wykona sie pelna rotacja(w zaokragleniu int)
            czasRotacji = tPoczatkowe - tempObl*czasRotacji; //czy zostalo jeszcze baterii
            if ( odejmij == true ){
                --udaneRotacji;
            }
            if( czasRotacji != 0 ){
                tempObl *= udaneRotacji;
                if ( odejmij == true ){
                    ++tempObl;
                }
                //raczej nie tempObl += udane;
                udane = 0;
                t = czasRotacji;
                if( x == xPoczatkowe ){
                    if( y != yPoczatkowe ){
                        if( y > yPoczatkowe ){
                            if( czyMniejszeY )
                                ++udane;
                            else
                                czyWiekszeY = true;
                        }
                        else{
                            if( czyWiekszeY )
                                ++udane;
                            else
                                czyMniejszeY = true;
                        }
                    }
                }if( y == yPoczatkowe ){
                    if( x != xPoczatkowe ){
                        if( x > xPoczatkowe ){
                            if( czyMniejszeX )
                                ++udane;
                            else
                                czyWiekszeX = true;
                        }
                        else{
                            if( czyWiekszeX )
                                ++udane;
                            else
                                czyMniejszeX = true;
                        }
                    }
                }
                while (true){//kolejne, ostatnie przebiegi
                    if ( koniecBaterii == true ){
                        break;
                    }
                    if ( d[i] < t ){
                        t -= (d[i]+1);
                        y += d[i];
                    }
                    else{
                        if( t != 0 ){
                            y += t;
                            koniecBaterii = true;
                        }else
                            break;
                    }
                    if ( czyMniejszeY || czyWiekszeY )
                        zapisaneY = true;
                    if( x == xPoczatkowe ){
                        if( y == yPoczatkowe )
                            ++udane;
                        else if( y > yPoczatkowe ){
                            if( czyMniejszeY )
                                ++udane;
                            else
                                czyWiekszeY = true;
                        }
                        else{
                            if( czyWiekszeY )
                                ++udane;
                            else
                                czyMniejszeY = true;
                        }
                    }
                    if( zapisaneY ){
                        czyWiekszeY = false;
                        czyMniejszeY = false;
                    }
                    zapisaneY = false;

                    if ( czyMniejszeX || czyWiekszeX )
                        zapisaneX = true;
                    if( y == yPoczatkowe ){
                        if( x != xPoczatkowe ){
                            if( x > xPoczatkowe ){
                                if( czyMniejszeX )
                                    ++udane;
                                else
                                    czyWiekszeX = true;
                            }
                            else{
                                if( czyWiekszeX )
                                    ++udane;
                                else
                                    czyMniejszeX = true;
                            }
                        }
                    }
                    if( zapisaneX ){
                        czyWiekszeX = false;
                        czyMniejszeX = false;
                    }
                    zapisaneX = false;
                    if( ++i == n ){
                        i = 0;
                    }

                    if ( koniecBaterii == true ){
                        break;
                    }
                    if ( d[i] < t ){
                        t -= (d[i]+1);
                        x += d[i];
                    }
                    else{
                        if( t != 0 ){
                            x += t;
                            koniecBaterii = true;
                        }else
                            break;
                    }
                    if ( czyMniejszeY || czyWiekszeY )
                        zapisaneY = true;
                    if( x == xPoczatkowe ){
                        if( y == yPoczatkowe )
                            ++udane;
                        else if( y > yPoczatkowe ){
                            if( czyMniejszeY )
                                ++udane;
                            else
                                czyWiekszeY = true;
                        }
                        else{
                            if( czyWiekszeY )
                                ++udane;
                            else
                                czyMniejszeY = true;
                        }
                    }
                    if( zapisaneY ){
                        czyWiekszeY = false;
                        czyMniejszeY = false;
                    }
                    zapisaneY = false;

                    if ( czyMniejszeX || czyWiekszeX )
                        zapisaneX = true;
                    if( y == yPoczatkowe ){
                        if( x != xPoczatkowe ){
                            if( x > xPoczatkowe ){
                                if( czyMniejszeX )
                                    ++udane;
                                else
                                    czyWiekszeX = true;
                            }
                            else{
                                if( czyWiekszeX )
                                    ++udane;
                                else
                                    czyMniejszeX = true;
                            }
                        }
                    }
                    if( zapisaneX ){
                        czyWiekszeX = false;
                        czyMniejszeX = false;
                    }
                    zapisaneX = false;
                    if( ++i == n ){
                        i = 0;
                    }

                    if ( koniecBaterii == true ){
                        break;
                    }
                    if ( d[i] < t ){
                        t -= (d[i]+1);
                        y -= d[i];
                    }
                    else{
                        if( t != 0 ){
                            y -= t;
                            koniecBaterii = true;
                        }else
                            break;
                    }
                    if ( czyMniejszeY || czyWiekszeY )
                        zapisaneY = true;
                    if( x == xPoczatkowe ){
                        if( y == yPoczatkowe )
                            ++udane;
                        else if( y > yPoczatkowe ){
                            if( czyMniejszeY )
                                ++udane;
                            else
                                czyWiekszeY = true;
                        }
                        else{
                            if( czyWiekszeY )
                                ++udane;
                            else
                                czyMniejszeY = true;
                        }
                    }
                    if( zapisaneY ){
                        czyWiekszeY = false;
                        czyMniejszeY = false;
                    }
                    zapisaneY = false;

                    if ( czyMniejszeX || czyWiekszeX )
                        zapisaneX = true;
                    if( y == yPoczatkowe ){
                        if( x > xPoczatkowe ){
                            if( czyMniejszeX )
                                ++udane;
                            else
                                czyWiekszeX = true;
                        }
                        else{
                            if( czyWiekszeX )
                                ++udane;
                            else
                                czyMniejszeX = true;
                        }
                    }
                    if( zapisaneX ){
                        czyWiekszeX = false;
                        czyMniejszeX = false;
                    }
                    zapisaneX = false;
                    if( ++i == n ){
                        i = 0;
                    }

                    if ( koniecBaterii == true ){
                        break;
                    }
                    if ( d[i] < t ){
                        t -= (d[i]+1);
                        x -= d[i];
                    }
                    else{
                        if( t != 0 ){
                            x -= t;
                            koniecBaterii = true;
                        }else
                            break;
                    }
                    if ( czyMniejszeY || czyWiekszeY )
                        zapisaneY = true;
                    if( x == xPoczatkowe ){
                        if( y == yPoczatkowe )
                            ++udane;
                        else if( y > yPoczatkowe ){
                            if( czyMniejszeY )
                                ++udane;
                            else
                                czyWiekszeY = true;
                        }
                        else{
                            if( czyWiekszeY )
                                ++udane;
                            else
                                czyMniejszeY = true;
                        }
                    }
                    if( zapisaneY ){
                        czyWiekszeY = false;
                        czyMniejszeY = false;
                    }
                    zapisaneY = false;

                    if ( czyMniejszeX || czyWiekszeX )
                        zapisaneX = true;
                    if( y == yPoczatkowe ){
                        if( x != xPoczatkowe ){
                            if( x > xPoczatkowe ){
                                if( czyMniejszeX )
                                    ++udane;
                                else
                                    czyWiekszeX = true;
                            }
                            else{
                                if( czyWiekszeX )
                                    ++udane;
                                else
                                    czyMniejszeX = true;
                            }
                        }
                    }
                    if( zapisaneX ){
                        czyWiekszeX = false;
                        czyMniejszeX = false;
                    }
                    zapisaneX = false;
                    if( ++i == n ){
                        i = 0;
                    }
                }

                tempObl += udane;
                cout << tempObl;
                return 0;
            }
            tempObl *= udaneRotacji;
            if ( odejmij == true )
                ++tempObl;
            cout << tempObl;
            return 0;
        }
    }
    /*else if( x == xPoczatkowe && y == yPoczatkowe )
        ++udane;*/

    cout << udane;

    return 0;
    //po koncu baterii bez powtorzenia
}
