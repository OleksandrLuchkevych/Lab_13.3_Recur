#include <iostream>
using namespace std;


typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void Add(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void Replace(Elem*& first, Elem*& last, Elem* tmp)
{
    if (tmp == NULL)
    {
        first = last;
        return;
    }

    Elem* temp = tmp->prev;
    tmp->prev = tmp->next;
    tmp->next = temp;

    Replace(first, last, tmp->prev);
}

void PrintList(Elem*& first)
{
    if (first == NULL)
        return;

    cout << first->info << " ";
    PrintList(first->next);

}

int main()
{
    Elem* first = NULL,
        * last = NULL;
    Add(first, last, 1);
    Add(first, last, 2);
    Add(first, last, 1);
    Add(first, last, 4);
    Add(first, last, 3);
    Add(first, last, 7);

    cout << "Initial list: ";
    PrintList(first);
    cout << endl << endl;
    cout << "Replaced list: ";
    Replace(first, last, first);
    PrintList(first);

    return 0;
}
