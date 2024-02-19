#include "RBTree.h"
Node::Node(char k, char c, Node* p, Node* left, Node* right)
{
	color = c;
	key = k;
	parent = p;
	left_child = left;
	right_child = right;
}
std::ostream& operator<<(std::ostream& output, const Node& node)
{
	if (IS_NIL(node)) output << "NILL";
	else
	{
		output << "" << (node.color == RED_NODE ? "Red" : "Black");
		output << ", " << node.key;
	}
	return output;
}
RBTree::RBTree()
{
	root = new NIL;
}
RBTree::~RBTree()
{
	if (root)
	{
		delete root;
		root = NULL;
	}
}
Node* RBTree::get_root()
{
	return root;
}
void RBTree::left_rotate(Node* x)
{
	Node* y = x->right_child;
	x->right_child = y->left_child;
	if (!IS_NIL(y->left_child))
	{
		y->left_child->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else if (x == x->parent->left_child)
	{
		x->parent->left_child = y;
	}
	else
	{
		x->parent->right_child = y;
	}
	y->left_child = x;
	x->parent = y;
}
Node* RBTree::search(char key)
{
	Node* x = root;
	while (!IS_NIL(x) && key != x->key)
	{
		if (key < x->key)
		{
			x = x->left_child;
		}
		else
		{
			x = x->right_child;
		}
	}

	return x;
}

void RBTree::print_info(Node* x)
{
	std::cout << "Color: " << (x->color == RED_NODE ? "Red" : "Black");
	std::cout << "\nLeft child : " << (x->left_child->color == RED_NODE ? "Red" : "Black") << ", " << &x->left_child->key << "\n";
	std::cout << "Right child : " << (x->right_child->color == RED_NODE ? "Red" : "Black") << ", " << &x->right_child->key << "\n";
	std::cout << "Parent child : " << (x->parent->color == RED_NODE ? "Red" : "Black") << ", " << &x->parent->key << "\n";
}
void RBTree::transplant(Node* u, Node* v)
{
	if (u->parent == NULL)
	{
		root = v;
	}
	else if (u == u->parent->left_child)
	{
		u->parent->left_child = v;
	}
	else
	{
		u->parent->right_child = v;
	}
	v->parent = u->parent;
}
Node* RBTree::minimum(Node* x)
{
	while (!IS_NIL(x->left_child))
	{
		x = x->left_child;
	}
	std::cout << "" << (x->color == RED_NODE ? "Red" : "Black");
	std::cout << ", " << &x->key << "\n";
	return x;
}
void RBTree::right_rotate(Node* x)
{
	Node* y = x->left_child;
	x->left_child = y->right_child;
	if (!IS_NIL(y->right_child))
	{
		y->right_child->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else if (x == x->parent->right_child)
	{
		x->parent->right_child = y;
	}
	else
	{
		x->parent->left_child = y;
	}
	y->right_child = x;
	x->parent = y;
}
void RBTree::insert(char key)
{
	Node* z = new Node(key);
	z->color = RED_NODE;
	z->left_child = new NIL;
	z->right_child = new NIL;
	Node* y = NULL;
	Node* x = root;
	while (!IS_NIL(x))
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left_child;
		}
		else
		{
			x = x->right_child;
		}
	}
	z->parent = y;
	if (y == NULL)
	{
		root = z;
	}
	else if (z->key < y->key)
	{
		y->left_child = z;
	}
	else
	{
		y->right_child = z;
	}
	insert_fixup(z);
}
void RBTree::insert_fixup(Node* z)
{
	while (z->parent && z->parent->color == RED_NODE)
	{
		if (z->parent == z->parent->parent->left_child)
		{
			Node* y = z->parent->parent->right_child;
			if (y->color == RED_NODE)
			{
				z->parent->color = BLACK_NODE;
				y->color = BLACK_NODE;
				z->parent->parent->color = RED_NODE;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right_child)
				{
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = BLACK_NODE;
				z->parent->parent->color = RED_NODE;
				right_rotate(z->parent->parent);
			}
		}
		else
		{
			Node* y = z->parent->parent->left_child;
			if (y->color == RED_NODE)
			{
				z->parent->color = BLACK_NODE;
				y->color = BLACK_NODE;
				z->parent->parent->color = RED_NODE;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left_child)
				{
					z = z->parent;
					right_rotate(z);
				}
				z->parent->color = BLACK_NODE;
				z->parent->parent->color = RED_NODE;
				left_rotate(z->parent->parent);
			}
		}
		if (z == root) break;
	}
	root->color = BLACK_NODE;
}
void RBTree::remove(char key)
{
	Node* z = search(key);
	if (IS_NIL(z))
	{
		std::cout << "Key not found!" << std::endl;
		return;
	}
	Node* y = z;
	Node* x;
	char y_original_col = y->color;
	if (IS_NIL(z->left_child))
	{
		x = z->right_child;
		transplant(z, z->right_child);
	}
	else if (IS_NIL(z->right_child))
	{
		x = z->left_child;
		transplant(z, z->left_child);
	}
	else
	{
		y = minimum(z->right_child);
		y_original_col = y->color;
		x = y->right_child;
		if (y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			transplant(y, y->right_child);
			y->right_child = z->right_child;
			y->right_child->parent = y;
		}
		transplant(z, y);
		y->left_child = z->left_child;
		y->left_child->parent = y;
		y->color = z->color;
	}
	if (y_original_col == BLACK_NODE)
	{
		remove_fixup(x);
	}
}
void RBTree::remove_fixup(Node* x)
{
	while (x != root && x->color == BLACK_NODE)
	{
		Node* w;
		if (x == x->parent->left_child)
		{
			w = x->parent->right_child;
			if (w->color == RED_NODE)
			{
				w->color = BLACK_NODE;
				x->parent->color = RED_NODE;
				left_rotate(x->parent);
				w = x->parent->right_child;
			}

			if (w->left_child->color == BLACK_NODE && w->right_child->color ==
				BLACK_NODE)
			{
				w->color = RED_NODE;
				x = x->parent;
			}
			else
			{
				if (w->right_child->color == BLACK_NODE)
				{
					w->left_child->color = BLACK_NODE;
					w->color = RED_NODE;
					right_rotate(w);
					w = x->parent->right_child;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK_NODE;
				w->right_child->color = BLACK_NODE;
				left_rotate(x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left_child;
			if (w->color == RED_NODE)
			{
				w->color = BLACK_NODE;
				x->parent->color = RED_NODE;
				right_rotate(x->parent);
				w = x->parent->left_child;
			}

			if (w->right_child->color == BLACK_NODE && w->left_child->color ==
				BLACK_NODE)
			{
				w->color = RED_NODE;
				x = x->parent;
			}
			else
			{
				if (w->left_child->color == BLACK_NODE)
				{
					w->right_child->color = BLACK_NODE;
					w->color = RED_NODE;
					left_rotate(w);
					w = x->parent->left_child;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK_NODE;
				w->left_child->color = BLACK_NODE;
				right_rotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK_NODE;
}
int RBTree::tree_height(Node* node)
{
	if (!node) return -1;
	return (MAX(tree_height(node->left_child), tree_height(node->right_child)) + 1);
}
void RBTree::print()
{
	int height = tree_height(root);
	int counter = 1;
	for (int i = 0; i < height; ++i)
	{
		int offset = (1 << (height - i - 1)) - 1;
		int gap = (1 << (height - i)) - 1;
		for (int k = 0; k < offset; ++k)
		{
			std::cout << " ";
		}
		for (int j = 0; j < (1 << i); ++j)
		{
			int mask = 0;
			Node* itr = root;
			while (itr && !IS_NIL(itr) && mask < i)
			{
				if (counter & (1 << (i - mask - 1)))
				{
					itr = itr->right_child;
				}
				else
				{
					itr = itr->left_child;
				}
				mask++;
			}
			std::cout << (itr->color == RED_NODE ? "\033[31m" : "\033[34m");
			if (itr->key >= '!' && itr->key <= '~') std::cout << itr->key;
			else std::cout << " ";
			std::cout << "\033[0m";

			for (int k = 0; k < gap; ++k)
			{
				if (j + 1 < (1 << i)) std::cout << " ";
			}
			counter++;
		}
		std::cout << "\n";
	}
}