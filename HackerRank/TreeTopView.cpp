#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Solution {
	public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }
               return root;
           }
        }

/*
class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

*/

void topView(Node * root) {
    if (root == NULL) {
        return;
    }

    map<int, int> view;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        Node* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (view.find(hd) == view.end()) {
            view[hd] = node->data;
        }

        if (node->left != NULL) {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right != NULL) {
            q.push(make_pair(node->right, hd + 1));
        }
    }

    for (map<int, int>::iterator it = view.begin(); it != view.end(); ++it) {
        cout << it->second << " ";
    }
}

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
