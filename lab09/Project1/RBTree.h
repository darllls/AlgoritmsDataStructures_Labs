#ifndef H_RBTREE
#define H_RBTREE
#include <iostream>
enum NodeColors
{
	RED_NODE = 0,
	BLACK_NODE = 1
};
class Node
{
public:
	Node(char key, char color = RED_NODE, Node* p = NULL, Node* left = NULL,
		Node* right = NULL);
	~Node() {};
	char key;
	char color;
	Node* parent;
	Node* left_child;
	Node* right_child;
	friend std::ostream& operator<<(std::ostream& output, const Node& node);
};
#define NIL Node(-127, BLACK_NODE)
inline bool IS_NIL(Node node) {
	return (node.key == -127 && node.color ==
		BLACK_NODE);
}
inline bool IS_NIL(Node* node) {
	return (node->key == -127 && node->color ==
		BLACK_NODE);
}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
class RBTree
{
public:
	RBTree();
	~RBTree();
	Node* get_root();
	void left_rotate(Node* node);
	void right_rotate(Node* node);
	Node* search(char key);
	void print_info(Node* x);
	void transplant(Node* u, Node* v);
	Node* minimum(Node* x);
	void insert(char key);
	void insert_fixup(Node* z);
	void remove(char key);
	void remove_fixup(Node* x);
	int tree_height(Node* node);
	void print();
private:
	Node* root;
};
#endif