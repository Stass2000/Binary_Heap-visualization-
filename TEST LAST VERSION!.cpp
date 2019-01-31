#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
std::ofstream output("C:\\Users\\User\\Downloads\\Binary Heap\\output.txt", ios::out);

class Heap {
  static const int SIZE = 1000000; // максимальный размер кучи
  int *h;         // указатель на массив кучи
  int HeapSize; // размер кучи
public:

  //void addelem(int);
  //void outHeap();  // вывод элементов кучи в форме кучи
  //void out();  // вывод элементов кучи в форме массива
  //int getmax();  // удаление вершины (максимального элемента)
  //void heapify(int);  // упорядочение кучи
  // конструктор кучи
  Heap() {
  h = new int[SIZE];
  HeapSize = 0;
}
// добавление элемента кучи
void addelem(int n) {
  int i, parent;
  i = HeapSize;
  h[i] = n;
  parent = (i-1)/2;
  while(parent >= 0 && i > 0)  {
    if(h[i] > h[parent]) {
      int temp = h[i];
      h[i] = h[parent];
      h[parent] = temp;
    }
    i = parent;
    parent = (i-1)/2;
  }
  HeapSize++;
}
// вывод элементов кучи в форме кучи
void outHeap() {
  int i = 0;
  int k = 1;
  while(i < HeapSize) {
    while((i < k) && (i < HeapSize)) {
      output << h[i] << " ";
      i++;
    }
    output << endl;
    k = k * 2 + 1;
  }
}
// вывод элементов кучи в форме массива
void out() {
  for(int i=0; i< HeapSize; i++) {
    cout << h[i] << " "; }
  cout << endl;
}
// упорядочение кучи
void heapify(int i) {
  int left, right;
  int temp;
  left = 2 * i + 1;
  right = 2 * i + 2;
  if(left < HeapSize) {
    if(h[i] < h[left]) {
      temp = h[i];
      h[i] = h[left];
      h[left] = temp;
      heapify(left);
    }
  }
  if(right < HeapSize) {
    if(h[i] < h[right]) {
      temp = h[i];
      h[i] = h[right];
      h[right] = temp;
      heapify(right);
    }
  }
}

// удаление вершины (максимального элемента)
int getmax() {
  int x;
  x = h[0];
  h[0] = h[HeapSize-1];
  HeapSize--;
  heapify(0);
  return(x);
}
};

int main() {
  Heap heap;
  int k, check;
  int n;
  double m, a;

std::ifstream input("C:\\Users\\User\\Downloads\\Binary Heap\\input.txt", ios::in);
    int weightNotFull, cardsCount, weightToFull = 0;
    input >> m;
  n = (int)m;
    if ( n <= 0) {
     output << "Nepravelnyi vvod";
     output.close();
    return 0;
  }
    for (int i = 0; i < n; ++i)
    {
        input >> k;
        heap.addelem(k);
    }
    heap.outHeap();
    input >> check;
    if (check < 1) {
    output << "Nepravelnyi vvod";
        output.close();
        return 0;
        }
    for (int i = 0; i < check; ++i)
    {
        input >> a;
        if (a == 1) {
        input >> k;
        heap.addelem(k);
        }
        if (a == 2) {
        output << "Max element" << " " << heap.getmax() << std::endl;
        }
        if (a == 3) {
        heap.outHeap();
        output << std::endl;
        }
        if (a != 1 && a != 2 && a != 3) {
    output << "Nepravelnyi vvod";
        output.close();
        return 0;
        }
    }
    input.close();
        //heap.outHeap();
        //output << "Max element" << " " << heap.getmax();
    output.close();
  cin.get();cin.get();
  return 0;
}
