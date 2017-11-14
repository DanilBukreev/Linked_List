#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

template <typename T>
struct node {
  T field;
  struct node *next;
  struct node *prev;
};

template <typename T>
class List {
 public:
   void init() {}
   void print() {}
   void Append(T elem) {}
   void Prepend(T elem) {}
   void InsertAt(int index, T elem) {}
   void Remove(T elem) {}
};
template <typename T>
class ArrayList : public List<T> {
 public:
  int N;
  T *arr;
  void setarr(T *A) { arr = A; }
  void setN(int n) { N = n; }
};
template <typename T>
class ListList : public List<T> {
 public:
  int N;
  node<T> *fst;
  node<T> *lst;
  ListList() {
    fst = new node<T>;
    fst->next = NULL;
    fst->prev = NULL;
    lst = new node<T>;
    lst->next = NULL;
    lst->prev = NULL;
  }

  void setN(int n) { N = n; }

  void init() {
    int i;
    T elem;
    node<T> *temp = fst;
    for (i = 0; i < N; i++) {
      cin >> elem;
      node<T> *temp1, *p;
      temp->field = elem;  // записываем данные в текущий узел
      if (i == N - 2) lst->prev = temp;
      if (i != N - 1) {
        p = new node<T>;
        p->next = NULL;  // новому элементу присваиваем значение
                         //указателя предыдущего
        p->prev = temp;
        temp->next = p;  // текущий указывает на только что созданный
        // lst->prev=temp;
        temp = p;  // текущим становится только что созданный
      }
    }
    lst->field = temp->field;
    lst->next = NULL;
  }
  void print() {
    cout << "Текущий список" << endl;
    node<T> *temp = fst;
    // while (temp->next!=NULL)
    for (int i = 0; i < N; i++) {
      cout << temp->field << "->" << endl;
      temp = temp->next;
    }
    if (N==0) {
	   cout <<"Список пуст" << endl;
	}
  }
  void Prepend(T elem) {
    int i;
    node<T> *temp = new node<T>;
    temp->next = fst;
    temp->field = elem;
    fst = temp;
    N++;
  }

  void Append(T elem) {
    struct node<T> *temp = fst;
    if (N == 0)
      Prepend(elem);
    else {
      for (int i = 0; i < N - 1; i++) temp = temp->next;
      node<T> *temp1 = new node<T>;
      temp->next = temp1;
      temp1->field = elem;
      temp1->next = NULL;
      N++;
    }
  }

  void InsertAt(int index, T elem) {
    node<T> *temp = fst;
    node<T> *temp1;  //
    node<T> *temp2 = new node<T>;
    int i;
    if (index == 0) Prepend(elem);
    if (index == N) Append(elem);
    if (index != 0 && index != N) {
      for (i = 0; i < index - 1; i++) {
        temp = temp->next;
      }
      temp1 = temp->next;
      temp->next = temp2;
      temp2->field = elem;
      temp2->next = temp1;
      N++;
    }
  }
  T Get(int index) {
    if (index > N || index < 0)
      return 404;
    else {
      node<T> *temp = fst;
      int i;
      for (i = 0; i < index; i++) temp = temp->next;
      return (temp->field);
    }
  }
  void Remove(T elem) {
    T field;
    node<T> *temp = fst;
    node<T> *temp1;
    while (temp->next != NULL) {
      if (temp->next->field == elem) {
        temp1 = temp->next;
        temp->next = temp->next->next;
        delete temp1;
        N--;
      }
      temp = temp->next;
    }
    if (elem != field) {
      cout << "ошибка.Нет такого элемента." << endl;
    }
  }
};
void menu() {
  cout << "1. Распечатать список" << endl;
  cout << "2. Добавить элемент в список" << endl;
  cout << "3. Удалить элемент" << endl;
  cout << "4. Найти позиции элементов" << endl;
  cout << "5. Заменить элемент на другой " << endl;
  cout << "6. Отсортировать элемент списка" << endl;
  cout << "7. Завершить работу" << endl;
}
int main() {
  int c, n, k;
  string s;
  cout << "Введите 1 для начала работы" << endl;
  cin >> c;
  ArrayList<int> A;
  switch (c) {
    case 1: {
      cout << "Введите количество элементов списка, а затем введите элементы"
           << endl;
      ListList<int> A;
      int n;
      cin >> n;
      A.setN(n);
      A.init();
      do {
        menu();
        cin >> c;
        switch (c) {
          case 2: {
            int elem;
            cout << "Введите элемент " << endl;
            cin >> elem;
            A.Append(elem);
            break;
          }
          case 3: {
            int elem;
            int N;
            cout << "Какой элемент будем удалять?" << endl;
            cin >> elem;             
               A.Remove(elem);
            break;
          }
          case 1: {
            A.print();
            break;
          }
          case 4: {
            int index;
            cout << "Введите индекс" << endl;
            cin >> index;
            if ((index > n) or (index < 0))
              cout << "Ошибка! Слишком большой индекс" << endl;
            else {
              cout << "Элемент с индексом '" << index << "' = " << A.Get(index)
                   << endl;
            }
            break;
          }
          case 7: {
            cout << "Вы хотите выйти из программы ? (y,N):" << endl;
            cin >> s;
            if (s == "yes" || s == "YES" || s == "Yes" || s == "Y" || s == "y")
              cout << "Всего доброго!" << endl;
            break;
          }
        }
      } while (s != "yes" && s != "YES" && s != "Yes" && s != "Y" && s != "y");
      break;
    }
  }
  return 0;
}
