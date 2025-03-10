#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    // vektor buat simpen data
    std::vector<int> heap;

    void heapifyDown(int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        
        // swap untuk anak yg lebih besar dr parent
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
            
    }

    void heapifyUp(int i) {
        int parent = (i - 1)/2;
        if (parent >= 0 && heap[i] > heap[parent]) {
            std::swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    int n;

    void HeapInsert() {

        // input banyaknya angka
        std::cout << "input banyaknya data:";
        std::cin >> n;

        // input angka
        for (int i = 0; i < n; i++){
            int item;
            std::cout << "angka ke-" << i+1 << ": ";
            std::cin >> item;
            heap.push_back(item);
            heapifyUp(heap.size() - 1);
        }
    }

    int getMax() {
        // cari angka tebesar
        int x = heap[0];
        for (int i = 1; i < heap.size(); i++) {
            if (heap[i] > x) {
                x = heap[i];
            }
        }
        return x;
    }

    void printHeap() {
        cout << "Heap: ";
        for (int data : heap) {
            cout << data << " ";
        }
        cout << endl;
    }
};

int main () {
    MaxHeap heap;
    heap.HeapInsert();
    heap.printHeap();
    cout << "Parent heap: " << heap.getMax() << endl;

    return 0;
}