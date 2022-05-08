#include <iostream>
int main()
{
    int liczba1;
    int liczba2;
    std::cout << "Kalkulator" << std::endl;
    std::cout << "Wprowadz liczby rozne w zakresie od -2'147'483'648 do 2'147'483'647 do obliczen:" << std::endl;
    std::cin >> liczba1;
    std::cin >> liczba2;
    std::cout << "Dodawanie(1), Odejmowanie(2), Mno¿enie(3), Dzielenie(4), Rezygnuj(5)" << std::endl;
    int znak;
    std::cin >> znak;
    if(liczba1 && liczba2 && znak)
                                                                                                                    {
    do
                                    {
        switch(znak)
    {
    case 1:
        std::cout << liczba1 + liczba2 << std::endl;
        break;
    case 2:
        std::cout << liczba1 - liczba2 << std::endl;
        break;
    case 3:
        std::cout << liczba1 * liczba2 << std::endl;
        break;
    case 4:
        std::cout << liczba1 / liczba2 << std::endl;
        break;
    default:
        std::cout << "Nieprawidlowy znak" << std::endl;
        break;
    }
    std::cout << "Wprowadz liczby rozne od 0 do obliczen:" << std::endl;
    std::cin >> liczba1;
    std::cin >> liczba2;
    std::cout << "Dodawanie(1), Odejmowanie(2), Mno¿enie(3), Dzielenie(4), Rezygnuj(5)" << std::endl;
    std::cin >> znak;
                                    } while( znak != 5 && liczba1 != 0 && liczba2 != 0 && liczba1 >= -2147483648 && liczba2 <= 2147483647 && liczba1 <= 2147483647 && liczba2 >= -2147483648 && znak <= 2147483647 && znak >= -2147483648);
                                                                                                                    }
    std::cout << "Koniec" << std::endl;
    return 0;
}
