#include <iostream>
#include <cstring>
using namespace std;

struct node {
  int number;
  node *next;
};

void check_numbers(char *argv, int *&numbers_array, int *numbers_count) {
  for (int i = 0; i < strlen(argv); i++) {
    if (argv[i] >= '0' && argv[i] <= '9')
      ;
    else
      (*numbers_count)++;
  }
  (*numbers_count)++;

  numbers_array = new int[(*numbers_count)];

  for (int i = 0; i < (*numbers_count); i++) {
    numbers_array[i] = 0;
  }
  int y = 0;
  for (int i = 0; i < strlen(argv) + 1; i++)
    if (argv[i] >= '0' && argv[i] <= '9')

      numbers_array[y] = numbers_array[y] * 10 + argv[i] - '0';
    else
      y++;
}

void fill_array(int numbers_array[], int argc, char **argv) {
  for (int i = 0; i < argc - 1; i++) numbers_array[i] = atoi(argv[i + 1]);
}

node *fill_list(int numbers_array[], int numbers_count) {
  node *first = nullptr;
  node *current = nullptr;
  for (int i = 0; i < numbers_count; i++) {
    node *node = new node{numbers_array[i], nullptr};
    if (current == nullptr) {
      current = node;
      first = current;
      continue;
    }
    current->next = node;
    current = node;
  }
  return first;
}

bool IsEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head, node *&last, int number);
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current);

bool isEmpty(node *head) {
  if (head == nullptr)
    return true;
  else
    return false;
}
char menu() {
  char choice;
  cout << "1. Распечатать список" << endl;
  cout << "2. Добавить элемент в список" << endl;
  cout << "3. Удалить элемент" << endl;
  cout << "4. Найти позиции элементов" << endl;
  cout << "5. Заменить элемент на другой " << endl;
  cout << "6. Отсортировать элемент списка" << endl;
  cout << "7. Завершить работу" << endl;
  cin >> choice;
  return choice;
}
void insertAsFirstElement(node *&head, node *&last, int number) {
  node *temp = new node;
  temp->number = number;
  temp->next = nullptr;
  head = temp;
  last = temp;
}
void insert(node *&head, node *&last, int number) {
  if (isEmpty(head))
    insertAsFirstElement(head, last, number);
  else {
    node *temp = new node;
    temp->number = number;
    temp->next = nullptr;
    last->next = temp;
    last = temp;
  }
}
void remove(node *&head, node *&last) {
  if (isEmpty(head))
    cout << "Список пуст." << endl;
  else if (head == last) {
    delete head;
    head == nullptr;
    last == nullptr;
  } else {
    node *temp = head;
    head = head->next;
    delete temp;
  }
}
void showList(node *current) {
  if (isEmpty(current))
    cout << "Список пуст." << endl;
  else {
    cout << "Список:" << endl;
    while (current != nullptr) {
      cout << current->number << endl;
      current = current->next;
    }
  }
}
int main(int argc, char *argv[]) {
  int *numbers_array = nullptr;
  int numbers_count = 0;
  node *head = nullptr;
  node *last = nullptr;
  char choice;
  int number;

  if (argc == 2) {
    check_numbers(argv[1], numbers_array, &numbers_count);
  } else if (argc > 2) {
    numbers_count = argc - 1;
    numbers_array = new int[numbers_count];
    fill_array(numbers_array, argc, argv);
  }
  node *first = fill_list(numbers_array, numbers_count);
  do {
    choice = menu();
    switch (choice) {
      case '2':
        cout << "Введите элемент списка:";
        cin >> number;
        insert(head, last, number);
        break;
      case '3':
        remove(head, last);
        break;
      case '1':
        showList(head);
        break;
      default:
        cout << "system exit" << endl;
    }
  } while (choice != '7');
}
