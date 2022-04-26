template <typename TKey, typename TValue>
class BinarySearchTree {
  struct TreeNode {
    TKey key;
    TValue value;

    TreeNode *left, *right, *parent;

    TreeNode(TKey &_key, TValue &_value)
        : key{_key}
        , value{_value}
        , left{nullptr}
        , right{nullptr}
        , parent{nullptr} {}
  };

public:
  BinarySearchTree()
      : root{nullptr} {}

  void insert(TKey &&key, TValue &&value) {
    TreeNode *newNode = new TreeNode(key, value);
    if (root != nullptr) {
      insertInternal(root, newNode);
    } else {
      root = newNode;
    }
  }

  bool searchIterative(TKey &&key) {
    TreeNode *node = root;

    while (node != nullptr) {
      if (node->key > key) {
        node = node->left;
      } else if (node->key < key) {
        node = node->right;
      } else {
        return true;
      }
    }
    return false;
  }

  TreeNode *getNode(TKey &&key) {
    TreeNode *node = root;

    while (node != nullptr) {
      if (node->key > key) {
        node = node->left;
      } else if (node->key < key) {
        node = node->right;
      } else {
        return node;
      }
    }

    return nullptr;
  }

  void transplant(TreeNode *u, TreeNode *v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u->parent->left == u) {
      u->parent->left = v;
    } else if (u->parent->right == u) {
      u->parent->right = v;
    }

    if (v != nullptr) {
      v->parent = u->parent;
    }
  }

  TreeNode *treeMinimum(TreeNode *root) {
    TreeNode *node = root;
    while (node != nullptr) {
      node = node->left;
    }
    return node;
  }

  void remove(TKey &&key) {
    TreeNode *node = getNode(std::move(key));

    if (node == nullptr) {
      return;
    }

    if (node->left == nullptr) {
      transplant(node, node->right);
    } else if (node->right == nullptr) {
      transplant(node, node->left);
    } else {
      TreeNode *successorNode = treeMinimum(node->right);
      if (successorNode->parent != node) {
        transplant(successorNode, successorNode->right);
        successorNode->right = node->right;
        successorNode->right->parent = successorNode;
      }
      transplant(node, successorNode);
      successorNode->left = node->left;
      successorNode->left->parent = successorNode;
    }

    delete node;
  }

private:
  TreeNode *root;

  void insertInternal(TreeNode *node, TreeNode *newNode) {
    if (node->key > newNode->key) {
      if (node->left != nullptr) {
        insertInternal(node->left, newNode);
      } else {
        node->left = newNode;
        newNode->parent = node;
        return;
      }
    }

    if (node->key < newNode->key) {
      if (node->right != nullptr) {
        insertInternal(node->right, newNode);
      } else {
        node->right = newNode;
        newNode->parent = node;
        return;
      }
    }

    if (node->key == newNode->key) {
      node->value = newNode->value;
    }
  }
};