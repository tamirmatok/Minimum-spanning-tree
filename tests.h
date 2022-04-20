#include "linked_list.h"
#include <iostream>
using namespace std;


void test_linked_list() {
	LinkedList<int> lst;
	Node<int>* test_node = nullptr;
	cout << "After declaring on Linked_list isempty return : " << lst.is_empty() << endl;
	for (int i = 1; i <= 5; i++) {
		lst.insert_to_end(i);
		if (i == 3)
			test_node = lst.tail;
		
	}
	cout << "After Inserting : " << endl;
	Node<int>* current = lst.head->next;
		while (current != nullptr) {
			cout << current->data << ", ";
			current = current -> next;
		}
	cout << endl;
	cout << "deleting After 3 (means deleting 4 ) : " << endl;
	lst.delete_after(test_node);
	current = lst.head->next;
	while (current != nullptr) {
		cout << current->data << ", ";
		current = current->next;
	}
	cout << endl;

	cout << "deleting All list : " << endl;
	current = lst.head;
	while (current != lst.tail)
		lst.delete_after(current);
	
	cout << "After deleting isempty return : " << lst.is_empty() << endl;
}
