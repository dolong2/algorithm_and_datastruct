#include<iostream>
using namespace std;
template <typename T> class List {
private:
    T data=0;
    List<T>* next = nullptr;
public:
    void add(T data);
    T get(int index);
    void remove(int index);
};
template<typename T>
void List<T>::add(T data) {
    if (this->next == nullptr) {
        this->data = data;
    }
    this->next->add(data);
}
template<typename T>
T List<T>::get(int index) {
    if (index == 0) {
        return this->data;
    }
    this->get(--index);
}
template<typename T>
void List<T>::remove(int index) {
    if (index == 1) {
        List<T> temp = *this->next;
        this->next = this->next->next;
        return;
    }
    remove(--index);
}
int main() {
    List<int> list;
    list.add(1);
}
