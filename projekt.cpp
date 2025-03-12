#include <iostream>
using namespace std;

struct Para // Node
{
    int dana;
    Para * next;

    Para(int value): dana(value), next(nullptr) {}
};

class LinkedList
{
    public:
        LinkedList(): begin(nullptr){}

        ~LinkedList()
        {
            wyczysc();
        }

        void dodaj(int value)
        {
            Para * nowaPara = new Para(value);

            if(begin == nullptr)
            {
                begin = nowaPara;
            }
            else
            {
                Para * tmp = begin;
                while(tmp->next != nullptr)
                {
                    tmp = tmp->next;
                }

                tmp->next = nowaPara;

            }
        }

        int pobierz(int index)
        {
            Para * tmp = begin;

            int i = 0;

            while(tmp != nullptr)
            {
                if(i == index)
                {
                    return tmp->dana;
                }
                tmp = tmp->next;
                i++;
            }
            return 0;
        }

        void wyczysc()
        {
            Para * tmp = begin;

            while(tmp != nullptr)
            {
                Para * next = tmp->next;
                delete tmp;
                tmp = next;
            }
            begin = nullptr;
        }

    private:

    Para * begin;

};

int main()
{
    LinkedList lista;
    lista.dodaj(1);
    lista.dodaj(2);

    cout << "Pierwszy element:" << lista.pobierz(0) << endl;
    cout << "Drugi element:" << lista.pobierz(1) << endl;

    lista.wyczysc();

    lista.dodaj(3);
    lista.dodaj(4);

    cout << "Pierwszy element:" << lista.pobierz(0) << endl;
    cout << "Drugi element:" << lista.pobierz(1) << endl;

    return 0;
}