#pragma once

class DoubleLinkedList
{
private:
	struct Node {
		int item_;
		Node* next_;
		Node* prev_;

		Node(int item, Node* next = nullptr, Node* prev = nullptr) {
			item_ = item;
			next_ = next;
			prev_ = prev;
		}
	};

	Node* head_;
	Node* tail_;

	Node* head() const;
	Node* searchPtr(Node* xNode);
	Node* searchPtr(int item);
	void insert(Node* x);
	void remove(Node* x);
	
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& other) noexcept;
	~DoubleLinkedList();
	DoubleLinkedList& operator= (const DoubleLinkedList* other);
	DoubleLinkedList* operator= (const DoubleLinkedList& other);
	bool isEmpty();
	void print();
	void backprint();
	void insert(int item);
	void remove(int item);
	bool search(int item);
};