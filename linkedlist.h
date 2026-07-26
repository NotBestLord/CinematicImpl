#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <cassert>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;

template <class T>
class LinkedList {
private:
	struct Node {
		T val;
		shared_ptr<Node> next;
		explicit Node(T v) : val(std::move(v)), next(nullptr) {}
	};

	shared_ptr<Node> head;

	void clear() {
		while (head) {
			head = head->next;
		}
	}

public:
	LinkedList() : head(nullptr) {}

	explicit LinkedList(T val) : head(make_shared<Node>(std::move(val))) {}

	LinkedList(const LinkedList& other) : head(nullptr) {
		*this = other;
	}

	LinkedList(LinkedList&& other) noexcept : head(std::move(other.head)) {}

	LinkedList& operator=(const LinkedList<T>& other) {
		if (this == &other) return *this;
		clear();
		if (other.head != nullptr) {
			head = make_shared<Node>(other.head->val);
			Node* currentNew = head.get();
			Node* currentOther = other.head->next.get();
			while (currentOther != nullptr) {
				currentNew->next = make_shared<Node>(currentOther->val);
				currentNew = currentNew->next.get();
				currentOther = currentOther->next.get();
			}
		}
		return *this;
	}

	LinkedList& operator=(LinkedList&& other) noexcept {
		if (this != &other) {
			clear();
			head = std::move(other.head);
		}
		return *this;
	}

	~LinkedList() {
		clear();
	}

	int length() const {
		int len = 0;
		Node* node = head.get();
		while (node != nullptr) {
			node = node->next.get();
			len++;
		}
		return len;
	}

	LinkedList& operator+=(T val) {
		auto newNode = make_shared<Node>(std::move(val));
		if (head == nullptr) {
			head = std::move(newNode);
		}
		else {
			Node* addTo = head.get();
			while (addTo->next != nullptr) {
				addTo = addTo->next.get();
			}
			addTo->next = std::move(newNode);
		}
		return *this;
	}

	const T& operator[](int index) const {
		assert(index >= 0 && "Index out of bounds!");
		Node* node = head.get();
		while (index > 0 && node != nullptr) {
			node = node->next.get();
			index--;
		}
		assert(node != nullptr && "Index out of bounds!");
		return node->val;
	}

	T& operator[](int index) {
		assert(index >= 0 && "Index out of bounds!");
		Node* node = head.get();
		while (index > 0 && node != nullptr) {
			node = node->next.get();
			index--;
		}
		assert(node != nullptr && "Index out of bounds!");
		return node->val;
	}

	LinkedList& operator-=(const T& val) {
		if (head == nullptr) return *this;
		if (head->val == val) {
			head = head->next;
			return *this;
		}
		Node* current = head.get();
		while (current->next != nullptr && current->next->val != val) {
			current = current->next.get();
		}
		if (current->next != nullptr) {
			current->next = current->next->next;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
		Node* current = list.head.get();
		while (current != nullptr) {
			os << current->val << (current->next != nullptr ? ", " : "");
			current = current->next.get();
		}
		return os;
	}
};
#endif