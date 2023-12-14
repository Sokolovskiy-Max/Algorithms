//#include <iostream>
//#include <cmath>
//struct Node {
//  int pairs;
//  int open; // unused
//  int closed; // unused
//
//  Node() { pairs = open = closed = 0; }
//};
//
//int getMid(int s, int e) { return s + (e - s) / 2; }
//
//Node merge(Node leftChild, Node rightChild) {
//  Node parentNode;
//  int minMatched = std::min(leftChild.open, rightChild.closed);
//  parentNode.pairs
//    = leftChild.pairs + rightChild.pairs + minMatched;
//  parentNode.open
//    = leftChild.open + rightChild.open - minMatched;
//  parentNode.closed
//    = leftChild.closed + rightChild.closed - minMatched;
//  return parentNode;
//}
//
//void constructSTUtil(char str[], int ss, int se, Node* st,
//  int si) {
//
//  if (ss == se) {
//    st[si].pairs = 0;
//    st[si].open = (str[ss] == '(' ? 1 : 0);
//    st[si].closed = (str[ss] == ')' ? 1 : 0);
//
//    return;
//  }
//  int mid = getMid(ss, se);
//  constructSTUtil(str, ss, mid, st, si * 2 + 1);
//  constructSTUtil(str, mid + 1, se, st, si * 2 + 2);
//  st[si] = merge(st[si * 2 + 1], st[si * 2 + 2]);
//}
//Node* constructST(char str[], int n) {
//  int x = (int)(std::ceil(std::log2(n)));
//  int max_size = 2 * (int)std::pow(2, x) - 1;
//  Node* st = new Node[max_size];
//  constructSTUtil(str, 0, n - 1, st, 0);
//
//  return st;
//}
//
//Node queryUtil(Node* st, int ss, int se, int qs, int qe,
//  int si) {
//  // No overlap
//  if (ss > qe || se < qs) {
//
//    // returns a Node for out of bounds condition
//    Node nullNode;
//    return nullNode;
//  }
//
//  // Complete overlap
//  if (ss >= qs && se <= qe) {
//    return st[si];
//  }
//
//  int mid = getMid(ss, se);
//  Node left = queryUtil(st, ss, mid, qs, qe, si * 2 + 1);
//  Node right = queryUtil(st, mid + 1, se, qs, qe, si * 2 + 2);
//  Node res = merge(left, right);
//  return res;
//}
//
//int query(Node* st, int qs, int qe, int n) {
//  Node res = queryUtil(st, 0, n - 1, qs, qe, 0);
//  return 2 * res.pairs;
//}
//
//int main() {
//  char str[] = "())(())(())(";
//  int n = strlen(str);
//  Node* st = constructST(str, n);
//  int startIndex = 0, endIndex = 11;
//  std::cout <<  query(st, startIndex, endIndex, n) << '\n';
//
//  startIndex = 1, endIndex = 2;
//  std::cout << query(st, startIndex, endIndex, n) << '\n';
//
//  return 0;
//}