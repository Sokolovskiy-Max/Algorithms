//#include <iostream>
//#include <vector>
//
//
//struct Node
//{
//	int key;
//	int height = 1;
//	Node* left = nullptr;
//	Node* right = nullptr;
//};
//
//unsigned char height(Node* p) {
//	return p ? p->height : 0;
//} 
//
//int bfact(Node* p) {
//	return height(p->right) - height(p->left);
//}
//
//void fixheight(Node* p) {
//	int height_left = height(p->left);
//	int height_right = height(p->right);
//	p->height = (height_left > height_right ? height_left : height_right) + 1;
//}
//
//Node* RotateRight(Node* p)
//{
//	Node* q = p->left;
//	p->left = q->right;
//	q->right = p;
//	fixheight(p);
//	fixheight(q);
//	return q;
//}
//
//Node* BigRotateRight(Node* p) {
//	RotateLeft(p->left);
//	RotateRight(p);
//}
//
//Node* RotateLeft(Node* q)
//{
//	Node* p = q->right;
//	q->right = p->left;
//	p->left = q;
//	fixheight(q);
//	fixheight(p);
//	return p;
//}
//
//Node* BigRotateLeft(Node* p) {
//	RotateRight(p->right);
//	RotateLeft(p);
//}
//
//Node* balance(Node* p)
//{
//	fixheight(p);
//	if (bfact(p) == 2) {
//		if (bfact(p->right) < 0)
//			p->right = RotateRight(p->right);
//		return RotateLeft(p);
//	}
//	if (bfact(p) == -2) {
//		if (bfact(p->left) > 0)
//			p->left = RotateLeft(p->left);
//		return RotateRight(p);
//	}
//	return p;
//}
//
//Node* insert(Node* p, int k) // вставка ключа k в дерево с корнем p
//{
//	if (!p) return new Node(k);
//	if (k < p->key)
//		p->left = insert(p->left, k);
//	else
//		p->right = insert(p->right, k);
//	return balance(p);
//}
//
//Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
//{
//	return p->left ? findmin(p->left) : p;
//}
//
//Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
//{
//	if (p->left == 0)
//		return p->right;
//	p->left = removemin(p->left);
//	return balance(p);
//}
//
//Node* remove(Node* p, int k) // удаление ключа k из дерева p
//{
//	if (!p) return 0;
//	if (k < p->key)
//		p->left = remove(p->left, k);
//	else if (k > p->key)
//		p->right = remove(p->right, k);
//	else //  k == p->key 
//	{
//		Node* q = p->left;
//		Node* r = p->right;
//		delete p;
//		if (!r) return q;
//		Node* min = findmin(r);
//		min->right = removemin(r);
//		min->left = q;
//		return balance(min);
//	}
//	return balance(p);
//}