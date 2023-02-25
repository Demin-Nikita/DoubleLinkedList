#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {
	head_ = nullptr;
	tail_ = nullptr;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other) noexcept {
	head_ = other.head_;
	tail_ = other.tail_;
}

DoubleLinkedList::~DoubleLinkedList() {
	if (head_) {
		Node* next = head_;
		while (next) {
			next = next->next_;
			delete head_;
			head_ = next;
		}
	}
}

bool DoubleLinkedList::isEmpty() {
	return (head_ == nullptr && tail_ == nullptr);
}

DoubleLinkedList::Node* DoubleLinkedList::head() const {
	return head_;
}

void DoubleLinkedList::print() {
	if (isEmpty()) {
		std::cout << std::endl;
		return;
	}

	Node* current = head_;
	while (current) {
		std::cout << current->item_ << " ";
		current = current->next_;
	}
	std::cout << std::endl;
}

void DoubleLinkedList::backprint() {
	if (isEmpty()) {
		std::cout << std::endl;
		return;
	}

	Node* current = tail_;
	while (current) {
		std::cout << current->item_ << " ";
		current = current->prev_;
	}
	std::cout << std::endl;
}

DoubleLinkedList::Node* DoubleLinkedList::searchPtr(Node* xNode) {
	if (isEmpty()) return nullptr;

	Node* current = head_;

	while (current) {
		if (current == xNode) {
			return current;
		}
		current = current->next_;
	}
	return nullptr;
}

DoubleLinkedList::Node* DoubleLinkedList::searchPtr(int item) {
	if (isEmpty()) return nullptr;

	Node* current = head_;

	while (current) {
		if (current->item_ == item) {
			return current;
		}
		current = current->next_;
	}
	return nullptr;
}

bool DoubleLinkedList::search(int item) {
	return searchPtr(item) ? true : false;
}

void DoubleLinkedList::insert(Node* xNode) {
	if (this->searchPtr(xNode)) { return; }

	else if (this->isEmpty()) {
		head_ = xNode;
		tail_ = xNode;
		return;
	}

	else if (xNode->item_ < head_->item_) {
		xNode->next_ = head_;
		head_->prev_ = xNode;
		head_ = xNode;
	}

	else {
		Node* current = head_;

		while (current) {
			if (current->item_ > xNode->item_) {
				break;
			}
			current = current->next_;
		}

		if (current == nullptr) {
			xNode->next_ = nullptr;
			xNode->prev_ = tail_;
			tail_->next_ = xNode;
			tail_ = xNode;
		}
		else {
			xNode->next_ = current;
			xNode->prev_ = current->prev_;
			current->prev_->next_ = xNode;
			current->prev_ = xNode;
		}
	}
}

void DoubleLinkedList::insert(int item) {
	Node* newNode = new Node(item);
	this->insert(newNode);
}

void DoubleLinkedList::remove(Node* xNode) {
	
	Node* current = searchPtr(xNode);

	if (current == nullptr) {
		return;
	}
	else if (current == head_) {
		head_ = head_->next_;
		head_->prev_ = nullptr;
		delete current;
	}
	else if (current == tail_) {
		tail_ = tail_->prev_;
		tail_->next_ = nullptr;
		delete current;
	}
	else {
		current->prev_->next_ = current->next_;
		current->next_->prev_ = current->prev_;
		delete current;
	}
}

void DoubleLinkedList::remove(int item) {
	Node* current = searchPtr(item);
	this->remove(current);
}

//move operator
DoubleLinkedList& DoubleLinkedList::operator= (const DoubleLinkedList* other) {

	this->head_ = other->head_;
	this->tail_ = other->tail_;
	return *this;
}

//copy operator
DoubleLinkedList* DoubleLinkedList::operator= (const DoubleLinkedList& other) {
	Node* current = other.head_;

	while (current) {
		this->insert(current->item_);
		current = current->next_;
	}
	return this;
}