#include <iostream>
#include <string>
using namespace std;

typedef char T;

T* add_entry(T* list, const T& new_entry,
                  int& size, int& capacity);
T* remove_entry(T* list, const T& delete_me,
                     int& size, int& capacity);

T* allocate(int capacity);

void copy_list(T *dest, T* src, int many_to_copy);
T* search_entry(T* list, const T& find_me, int size);

void print_list(T* list, int size);

void test_string();

int main(){
    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;



    cout<<endl<<endl<<endl<<"============================================="<<endl<<endl;
    return 0;
}


