#include <iostream>
#include <vector>

using namespace std;

class Heap {
  static const int SIZE = 1000000; // ������������ ������ ����
  int *h;         // ��������� �� ������ ����
  int HeapSize; // ������ ����
public:

  //void addelem(int);
  //void outHeap();  // ����� ��������� ���� � ����� ����
  //void out();  // ����� ��������� ���� � ����� �������
  //int getmax();  // �������� ������� (������������� ��������)
  //void heapify(int);  // ������������ ����
  // ����������� ����
  Heap() {
  h = new int[SIZE];
  HeapSize = 0;
}
// ���������� �������� ����
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
// ����� ��������� ���� � ����� ����
void outHeap() {
  int i = 0;
  int k = 1;
  while(i < HeapSize) {
    while((i < k) && (i < HeapSize)) {
      cout << h[i] << " ";
      i++;
    }
    cout << endl;
    k = k * 2 + 1;
  }
}
// ����� ��������� ���� � ����� �������
void out() {
  for(int i=0; i< HeapSize; i++) {
    cout << h[i] << " "; }
  cout << endl;
}
// ������������ ����
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

// �������� ������� (������������� ��������)
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
  int k;
  int n;
  double m;
  cin >> m;
  n = (int)m;
    if ( n <= 0) {
    cout << "Nepravellnyi vvod";
    return 0;
  }
  for(int i = 0; i < n; i++) {
    cout << "Vvedite element " << i+1 << " ";
    cin >> k;
    heap.addelem(k);
  }
  heap.outHeap();
  cout  << endl;
  heap.out();
  cout  << endl << "Max element " << heap.getmax();
  cin.get();cin.get();
  return 0;
}
