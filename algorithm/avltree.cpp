#include <iostream>

// template <class T>
// struct avl_tree {
//   struct node {
//     T key;
//     int size, height;
//     node *child[2];
//     node(const T &key) : key(key), size(1), height(1) {
//       child[0] = child[1] = 0;
//     }
//   } *root;
//
//   typedef node *pointer;
//
//   avl_tree() { root = NULL; }
//
//   pointer find(const T &val) { return find(root, val); };
//   node* find(node *t, const T &val) {
//     if (t == NULL) return NULL;
//     if (t->key == val) return t;
//
//     return find(t->child[val >= t->key], val);
//   }
//
//   void insert(const T& val) { root = insert(root, new node(val)); }
//   node* insert(node* t, node* x) {
//     if (t == NULL) return x;
//
//     t->child[x->key >= t->key] = insert(t->child[x->key >= t->key], x);
//     t->size += 1;
//
//     return balance(t);
//   }
//
//   void erase(const T& val) { root = erase(root, val); }
//   node *erase(node *t, const T& x) {
//     if (t == NULL) return NULL;
//     if (x == t->key) {
//       return move_down(t->child[0], t->child[1]);
//     } else {
//       t->child[x >= t->key] = erase(t->child[x >= t->key], x);
//       t->size -= 1;
//       return balance(t);
//     }
//   }
//
//   node *move_down(node *t, node *rhs) {
//     if (t == NULL) return rhs;
//     t->child[1] = move_down(t->child[1], rhs);
//     return balance(t);
//   }
//
// #define ht(t) (t ? t->height : 0)
//
//   node *rotate(node *t, int l, int r) {
//     node *s = t->child[r];
//     t->child[r] = s->child[l];
//     s->child[l] = balance(t);
//
//     return balance(s);
//   }
//
//   node *balance(node *t) {
//     for (int i = 0; i < 2; i++) {
//       if (ht(t->child[!i]) - ht(t->child[i]) < -1) {
//         if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0)
//           t->child[i] = rotate(t->child[i], i, !i);
//
//         return rotate(t, !i, i);
//       }
//     }
//
//     if (t) t->height = std::max(ht(t->child[0]), ht(t->child[1])) + 1;
//
//     return t;
//   }
// };

#define ht(t) (t ? t->height : 0)

template <class T>
struct AvlTree {
  struct Node {
    T key;
    int height;
    Node *child[2];
    Node(T val) : key(val) {}
  } *root;

  AvlTree() { root = NULL; }

  Node *find(T val) { return find(root, val); }
  Node *find(Node *t, T val) {
    if (t == NULL) { return NULL; }
    if (t->key == val) { return t; }

    return find(t->child[t->key >= val], val);
  }

  void insert(T val) { root = insert(root, new Node(val)); }
  Node *insert(Node *t, Node *x) {
    if (t == NULL) { return x; }

    t->child[t->key >= x->key] = insert(t->child[t->key >= x->key], x);

    return balance(t);
  }

  void erase(T val) { root = erase(root, val); }
  Node *erase(Node *t, T val) {
    if (t == NULL) { return NULL; }
    if (t->key == val) { return move_down(t->child[0], t->child[1]); }

    t->child[t->key >= val] = erase(t->child[t->key >= val], val);

    return balance(t);
  }

  Node *move_down(Node *t, Node *rhs) {
    if (t == NULL) { return rhs; }

    t->child[1] = move_down(t->child[1], rhs);

    return balance(t);
  }

  Node *rotate(Node *t, int l, int r) {
    auto s = t->child[r];
    t->child[r] = s->child[l];
    s->child[l] = balance(t);
    return balance(s);
  }

  Node *balance(Node *t) {
    for (int i = 0; i < 2; i++) {
      if (ht(t->child[i]) - ht(t->child[!i]) > 1) {
        if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0) {
          t->child[i] = rotate(t->child[i], i, !i);
        }

        return rotate(t, !i, i);
      }
    }

    if (t) t->height = std::max(ht(t->child[0]), ht(t->child[1])) + 1;

    return t;
  }
};

int main() {
  AvlTree<int> t;

  for (auto i : { 5, 1,2,4,1,1,45,6,7,1,2,5,6,7 }) {
    t.insert(i);
  }

  std::cout << t.find(45) << std::endl;
  std::cout << t.find(46) << std::endl;
}
