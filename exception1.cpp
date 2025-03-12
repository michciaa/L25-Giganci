#include <iostream>
using namespace std;

int main()
{
    try
    {
        int age = 15;
        if(age >= 18)
        {
            cout << "Dostęp przyznany" << endl;
        }
        else {
            throw(age);
        }
    }
    catch(int age)
    {
        cout << "Dostęp zablokowany, twój wiek: " << age << ". Wymagany wiek: 18" << endl;
    }

  return 0;
}
