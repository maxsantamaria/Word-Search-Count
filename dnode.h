template<class T>
class dnode
{
private:
	T data_field;
	// forward pointer
	dnode<T>* link_field;
	// backward pointer
	dnode<T>* prev_field;

public:
	// TODO:add member functions
	dnode(T value, dnode<T>* next=NULL, dnode<T>* prev=NULL){data_field = value; 
		link_field = next; prev_field = prev;};
	
	void set_link(dnode<T>* next){link_field = next;};
	void set_prev(dnode<T>* prev){prev_field = prev;};
	void set_data(T value){data_field = value;};

	dnode<T>* link(){return link_field;};
	dnode<T>* prev(){return prev_field;};
	T data(){return data_field;};
};

template<class T>
void list_head_insert(dnode<T>*& head_ptr, const T entry){
	dnode<T>* node = new dnode<T>(entry, head_ptr);
	head_ptr -> set_prev(node);
}

template<class T>
void list_insert(dnode<T>*& prev_ptr, const T entry){
	dnode<T>* node = new dnode<T>(entry, prev_ptr -> link(), prev_ptr);
	if (prev_ptr -> link())
	{
		prev_ptr -> link() -> set_prev(node);	
	}
	prev_ptr -> set_link(node);
}

template<class T>
void list_clear(dnode<T>*& head_ptr){
	dnode<T>* node = head_ptr;
	dnode<T>* remove_node;
	while(node){
		remove_node = node;
		node = node -> link();
		delete remove_node;
	}
}