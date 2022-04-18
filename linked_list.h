#ifndef LINKED_LIST
#define LINKED_LIST
using namespace std;

template<class T>
class LinkedList {
public:

	class Node {
		T data;
		Node* next;
	public:
		Node(T& item, Node* ptr = nullptr) { data = item; next = ptr; }
	};

	Node* head, tail;

	LinkedList() : head(nullptr) {}
	void make_empty() { head = tail = nullptr; }
	bool is_empty() { return head == nullptr; }
	void insert_to_end(Node* node) {
		if (is_empty())
			head = tail = node;
		else
			tail->next = node;
	}
	void delete_after(Node* node) {

	}
	~LinkedList() {
		Node* next, curr = head;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

};

#endif
