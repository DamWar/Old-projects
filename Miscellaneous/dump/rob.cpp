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
    long long int xMin = 0;
    long long int yMin = 0;
    long long int xMax = 0;
    long long int yMax = 0;
    int i = 0;
    long long int udane = 0;
    bool czyMniejszeX = false;
    bool czyWiekszeX = false;
    bool czyMniejszeY = false;
    bool czyWiekszeY = false;
    bool zapisaneX = false;
    bool zapisaneY = false;
    bool noToNiezleLiczby = false;
    short int toBreak = 0;

    if( x == xPoczatkowe && y == yPoczatkowe )
            ++udane;

    while (true){
        if ( d[i] < t ){
            t -= (d[i]+1);
            y += d[i];
            if( yMin > y ){
                yMin = y;
            }
            if( yMax < y ){
                yMax = y;
            }
            if( ++i == n ){//niepewna postiteracja
                i = 0;
                tPrzebiegu = tPoczatkowe - t;
                goto dodacX;
            }
        }
        else{
            if( t != 0 )
            y += t;
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


        if ( d[i] < t ){
            t -= (d[i]+1);
            x += d[i];
            if( xMin > x ){
                xMin = x;
            }
            if( xMax < x ){
                xMax = x;
            }
            if( ++i == n ){
                i = 0;
                tPrzebiegu = tPoczatkowe - t;
                goto odjacY;
            }
        }
        else{
            if( t != 0 )
            x += t;
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
        if ( d[i] < t ){
            t -= (d[i]+1);
            y -= d[i];
            if( yMin > y ){
                yMin = y;
            }
            if( yMax < y ){
                yMax = y;
            }
            if( ++i == n ){
                i = 0;
                tPrzebiegu = tPoczatkowe - t;
                goto odjacX;
            }
        }
        else{
            if( t != 0 )
            y -= t;
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


        if ( d[i] < t ){
            t -= (d[i]+1);
            x -= d[i];
            if( xMin > x ){
                xMin = x;
            }
            if( xMax < x ){
                xMax = x;
            }
            if( ++i == n ){
                i = 0;
                tPrzebiegu = tPoczatkowe - t;
                goto dodacY;
            }
        }
        else{
            if( t != 0 )
            x -= t;
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

    }

    while (true){
        dodacY: if ( d[i] < t ){
            t -= (d[i]+1);
            y += d[i];
            if( ++i == n ){//check
                i = 0;
                if( yMin < 0 ){//prawdopodobnie do usuniecia warunek mniejsze od 0
                    if( (y + yMin) > yPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (y + yMax) < yPoczatkowe ){
                    ++toBreak;
                }
                if( xMin < 0 ){
                    if( (x + xMin) > xPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (x + xMax) < xPoczatkowe ){
                    ++toBreak;
                }
                if( toBreak == 4 )
                    break;
                else
                    toBreak = 0;
                if( x == 0 && y == 0 ){
                    udaneRotacji = udane;
                    noToNiezleLiczby = true;
                    break;
                }
            }
        }
        else{
            if( t != 0 )
            y += t;
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

        dodacX: if ( d[i] < t ){
            t -= (d[i]+1);
            x += d[i];
            if( ++i == n ){
                i = 0;
                if( yMin < 0 ){
                    if( (y + yMin) > yPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (y + yMax) < yPoczatkowe ){
                    ++toBreak;
                }
                if( xMin < 0 ){
                    if( (x + xMin) > xPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (x + xMax) < xPoczatkowe ){
                    ++toBreak;
                }
                if( toBreak == 4 )
                    break;
                else
                    toBreak = 0;
                if( x == 0 && y == 0 ){
                    udaneRotacji = udane;
                    noToNiezleLiczby = true;
                    break;
                }
            }
        }
        else{
            if( t != 0 )
            x += t;
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

        odjacY: if ( d[i] < t ){
            t -= (d[i]+1);
            y -= d[i];
            if( ++i == n ){
                i = 0;
                if( yMin < 0 ){
                    if( (y + yMin) > yPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (y + yMax) < yPoczatkowe ){
                    ++toBreak;
                }
                if( xMin < 0 ){
                    if( (x + xMin) > xPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (x + xMax) < xPoczatkowe ){
                    ++toBreak;
                }
                if( toBreak == 4 )
                    break;
                else
                    toBreak = 0;
                if( x == 0 && y == 0 ){
                    udaneRotacji = udane;
                    noToNiezleLiczby = true;
                    break;
                }
            }
        }
        else{
            if( t != 0 )
            y -= t;
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


        odjacX: if ( d[i] < t ){
            t -= (d[i]+1);
            x -= d[i];
            if( ++i == n ){
                i = 0;
                if( yMin < 0 ){
                    if( (y + yMin) > yPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (y + yMax) < yPoczatkowe ){
                    ++toBreak;
                }
                if( xMin < 0 ){
                    if( (x + xMin) > xPoczatkowe ){
                        ++toBreak;
                    }
                }
                if( (x + xMax) < xPoczatkowe ){
                    ++toBreak;
                }
                if( toBreak == 4 )
                    break;
                else
                    toBreak = 0;
                if( x == 0 && y == 0 ){
                    udaneRotacji = udane;
                    noToNiezleLiczby = true;
                    break;
                }
            }
        }
        else{
            if( t != 0 )
            x -= t;
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

    }
    if( noToNiezleLiczby == true ){
        if ( udane != 0 ){
            udaneRotacji=3;// mozliwe, ze zle oblicza udaneRotacji
            int czasRotacji = tPoczatkowe - t;
            long long int tempObl = t / czasRotacji;//ile razy wykona sie pelna rotacja(w zaokragleniu int)
            //tempObl = t / tempObl;//ile razy wykona sie pelna rotacja(w zaokragleniu int)
            czasRotacji = t - tempObl*czasRotacji; //czy zostalo jeszcze baterii
            if( czasRotacji != 0 ){
                tempObl *= udaneRotacji;
                tempObl += udane;
                //kolejne, ostatnie przebiegi
                cout << tempObl;
                return 0;
            }
            tempObl *= udaneRotacji;
            tempObl += udane;
            cout << tempObl;
            return 0;
        }
    }
    /*else if( x == xPoczatkowe && y == yPoczatkowe )
        ++udane;*/

    cout << udane;

    return 0;
}
