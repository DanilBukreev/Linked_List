#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
struct node {
  T field;
  struct node *next;
};
template <typename T>
class ListList {
 public:
  int N;
  node<T> *fst;
  ListList() {  // конструктор класса - все что объявляется в конструкте
                // присутствует при объявлении  класса в дальнейшем
    fst = new node<T>;
    fst->next = NULL;
  }

  void setN(int n) { N = n; }

  void init() {
    int i;
    T elem;
    node<T> *temp = fst;
    for (i = 0; i < N; i++) {
      cin >> elem;
      node<T> *p;
      temp->field = elem;  // записываем данные в текущий узел
      if (i != N - 1) {
        p = new node<T>;
        p->next = NULL;  // новому элементу присваиваем значение
                         //указателя предыдущего
        temp->next = p;  // текущий указывает на только что созданный
        temp = p;  // текущим становится только что созданный
      }
    }
  }
  void print() {
    node<T> *temp = fst;
     if (N == 0) {
      cout << "Список пуст" << endl;
      exit(1);
    }
    do {
      for (int i = 0; i < N; i++) {
        cout << temp->field;
        if (temp->next != NULL) {
          cout << "->";
        }
        temp = temp->next;
      }
    } while (temp != NULL);
   
  }
  void Prepend(T elem) {
    int i;
    node<T> *temp = new node<T>;
    temp->next = fst;  // указатель только что созданный на новый узел
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
      node<T> *temp1 = new node<T>;  // создаем структуру типа ноде
      temp->next = temp1;  // темп самый последний узел -
      temp1->field = elem;
      temp1->next = NULL;
      N++;
    }
  }

  void InsertAt(int index, T elem) {
    node<T> *temp = fst;
    node<T> *temp1;
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
      for (i = 0; i < index; i++) temp = temp->next;  // в цикле доходим
      //до нужного элемента
      return (temp->field);
    }
  }
  void Sort()  // сортировка пузырьком
  {
    node<T> *temp = fst;
    bool exit = false;  //
    while (!exit)       // значение цикла тру
    {
      exit = true;                       // на каждом шаге проверка не отсортирован ли массив.
      for (int i = 0; i < (N - 1); i++)  // текущий эл меньше след.
      {
        if (temp->field > temp->next->field)  // всегда сравнивает текущий
                                              // и след за ним
        {
          node<T> *temp1 = new node<T>;
          temp1->field = temp->field;
          temp->field = temp->next->field;
          temp->next->field = temp1->field;

          exit = false;
        }
        temp = temp->next;
      }
      temp = fst;
    }
  }
  void Remove(T elem) {  // elem вводим что бы удалить
    node<T> *temp = fst;
    node<T> *temp1;
    while (temp->next != NULL) {
      if (temp->next->field == elem) {  //  смотрим след элем списка.
        temp1 = temp->next;             // темп1 - храним адрес узла, который будем удалять
        temp->next = temp->next->next;  // перекидываем указатель на 2 элемент
        delete temp1;
        N--;
        return;
      }
      temp = temp->next;
    }
    cout << "Элемент отсутствует" << endl;
  }
};
void menu() {
  cout << " " << endl;
  cout << "1. Распечатать список" << endl;
  cout << "2. Добавить элемент в список" << endl;
  cout << "3. Удалить элемент" << endl;
  cout << "4. Найти позиции элементов" << endl;
  cout << "5. Заменить элемент на другой " << endl;
  cout << "6. Отсортировать элемент списка" << endl;
  cout << "7. Завершить работу" << endl;
}
int main() {
  int c, n;
  string s;
  cout << "Введите 1 для начала работы" << endl;
  cin >> c;
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

          case 6: {
            A.Sort();
            A.print();
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
