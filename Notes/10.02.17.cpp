10/02/17


template <class T>
struct node{
	
node(const T& item):_item(item){}

friend ostream& operator <<(ostream& outs, const node<T> n){
	outs<<"["<<n._item<<"]";
	return outs;
k



	T_item;
	node<T>* next;
}


template <class T>
void swap(T& a,T& b){
	T temp = a;
	a=b;
	b=temp;
}

int main(int argc, char const *argv[])
{
	node<int> n(5);
	node<string>n("Jessy");

	node<int> * head_ptr;
	_insert_head(node<T>* &head_ptr,const T& item);

	return 0;
}

node<T>* Search(node<T>* head_ptr,T key){
	node<T>* w = head_ptr;
	while(w!=null){
		if((*w)._item==key/*same as w->_item*/){

			return w;
		}
		w=w->next;
	}
}