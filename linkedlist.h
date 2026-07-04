#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class LinkedList {
private:
	struct Node {
		T val;
		Node* next;
		Node(const T& v) : val(v), next(nullptr) {}
	};

	Node* head;

public:
	LinkedList() : head(nullptr) {}

	LinkedList(const T& val) : head(new Node(val)) {}

	LinkedList(const LinkedList& other) : head(nullptr) {
		*this = other;
	}
	LinkedList(LinkedList&& other) : head(other.head) {
		other.head = nullptr;
	}

	const LinkedList& operator=(const LinkedList<T>& other) {
		if (this == &other) return *this;

		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = nullptr;

		if (other.head != nullptr) {
			head = new Node(other.head->val);
			Node* currentNew = head;
			Node* currentOther = other.head->next;

			while (currentOther != nullptr) {
				currentNew->next = new Node(currentOther->val);
				currentNew = currentNew->next;
				currentOther = currentOther->next;
			}
		}
		return *this;
	}

	const LinkedList& operator=(LinkedList&& other) {
		if (this != &other) {
			Node* current = head;
			while (current != nullptr) {
				Node* nextNode = current->next;
				delete current;
				current = nextNode;
			}

			head = other.head;
			other.head = nullptr;
		}
		return *this;
	}

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	int length() const {
		int len = 0;
		Node* node = head;
		while (node != nullptr) {
			node = node->next;
			len++;
		}
		return len;
	}

	LinkedList& operator+=(const T& val) {
		if (head == nullptr) {
			head = new Node(val);
		}
		else {
			Node* addTo = head;
			while (addTo->next != nullptr) {
				addTo = addTo->next;
			}
			addTo->next = new Node(val);
		}
		return *this;
	}

	const T& operator[](int index) const {
		assert(index >= 0 && "Index out of bounds!");
		Node* node = head;
		while (index > 0 && node != nullptr) {
			node = node->next;
			index--;
		}
		assert(node != nullptr && "Index out of bounds!");
		return node->val;
	}

	LinkedList& operator-=(const T& val) {
		if (head == nullptr) return *this;

		if (head->val == val) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return *this;
		}

		Node* current = head;
		while (current->next != nullptr && current->next->val != val) {
			current = current->next;
		}

		if (current->next != nullptr) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}

		return *this;
	}

	friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
		Node* current = list.head;
		while (current != nullptr) {
			os << current->val << (current->next != nullptr ? ", " : "");
			current = current->next;
		}
		return os;
	}
};
#endif
