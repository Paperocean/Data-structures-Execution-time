	#include "listAdjacency.h"

	ListAdjacency::ListAdjacency(int size) {
		this->size = size;
		list = new Node * [size];
		for (int i = 0; i < size; i++) {
			list[i] = new Node{ -1, -1, nullptr };
		}
		vertexLabels = new string[size];
	}

	ListAdjacency::~ListAdjacency() {
		for (int i = 0; i < size; i++) {
			Node* current = list[i];
			while (current != nullptr) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}
		delete[] list;
	}

	void ListAdjacency::addEdge(int i, int j, int w) {
		Node* current = list[i];
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ j, w, nullptr };
	}

	void ListAdjacency::removeEdge(int i, int j) {
		Node* current = list[i];
		Node* previous = nullptr;
		while (current != nullptr) {
			if (current->vertex == j) {
				if (previous == nullptr) {
					list[i] = current->next;
				}
				else {
					previous->next = current->next;
				}
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}
	}
	int ListAdjacency::getWeight(int i, int j)
	{
		Node* current = list[i];
		while (current != nullptr) {
			if (current->vertex == j) {
				return current->weight;
			}
			current = current->next;
		}
		return -1;
	}

	void ListAdjacency::printList()
	{
		for (int i = 0; i < size; i++) {
			Node* current = list[i];
			while (current != nullptr) {
				cout << current->vertex << ": " << current->weight << " ";
				current = current->next;
			}
			cout << endl;
		}
	}

	string* ListAdjacency::getVertexLabel() {
		return vertexLabels;
	}

	void ListAdjacency::displayEdges()
	{
		for (int v = 0; v < size; v++) {
			if (!vertexLabels[v].empty()) {
				for(int i = 0; i < size; i++) {
					if (!vertexLabels[i].empty() && getWeight(v, i) != -1)
						cout << "Edge: " << vertexLabels[v] << " -> " << getWeight(v,i) << " -> " << vertexLabels[i] << endl;
				}
			}
		}
	}

	void ListAdjacency::setVertexLabel(int vertex, string vertexLabel)
	{
		vertexLabels[vertex] = vertexLabel;
	}