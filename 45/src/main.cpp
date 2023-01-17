#include <vector>
#include <memory>
#include <functional>
#include <queue>
#include <cassert>

//#include <iostream>

/* The problem:
Given a binary tree, implement a column-order traversal.

Each node is in a column, either -1 (left child) or +1 (right child) 
from its parent. Nodes in the same column should be traversed by 
distance from the root and by their value if the distance also matches.
*/

// Tree node type
struct Node {
    int value = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};

// Tree type, root is the root node of the tree
struct Tree {
    Tree(const std::vector<int>& in);   
    Node* root = nullptr;
private:
    std::vector<std::unique_ptr<Node>> nodes;
};

// Your solution:
void sew(size_t mrow_, int mcol_, Node* ptr, std::function<void(Node*)> &visitor){
    
    if(mrow_ > 0){
        sew(mrow_ - 1, mcol_, ptr->left, visitor);
    }else{
        if(ptr->left != nullptr) visitor(ptr->left);
    }

    if(mcol_ > 0){
        if(ptr != nullptr) visitor(ptr);
    }else{return;}
    
    if(mrow_ > 0){
        sew(mrow_ - 1, mcol_, ptr->right, visitor);
    }else{
        if(ptr->right != nullptr) visitor(ptr->right);
    }
}

void column_order(const Tree& tree, std::function<void(Node*)> visitor) {
    // Retrieve max used rows in the tree...
    size_t mrow_{0};
    Node *ptr0{tree.root}, *ptr{ptr0};
    if(ptr != nullptr) mrow_++;
    while(ptr->left != nullptr){
        mrow_++;
        ptr = ptr->left;
    }

    // Retrieve max used columns in the tree...
    int mcol_{-1}, mcol_max{1};
    for(size_t row = 1; row < mrow_; row++) mcol_max *= 2;
    ptr = ptr0;
    do{
        mcol_++;
        
        // Bitwise implementation to traverse the tree...
        bool a[mrow_ - 1];
        
        for(size_t i = 0; i < mrow_; i++){
            a[i] =  0 != (mcol_ & (1 << (mrow_ - i - 1)));
        }
        //

        ptr = ptr0;
        for(size_t i = 1; i < mrow_; i++){
            if(a[i]){
                ptr = ptr->right;
            }else{
                ptr = ptr->left;
            }
        }
    }while((ptr != nullptr) && (mcol_ < mcol_max));

    ptr = ptr0; // Reset pointer to the parent root
    sew(mrow_ - 2, mcol_, ptr, visitor); // Sew the tree according to the exercise...

}

int main(){
    std::vector<std::pair<std::vector<int>,std::vector<int>>> test_cases;

    // ORIGINAL
    //test_cases.push_back({{1,2,3,4,5},{4,2,1,5,3}});
    //test_cases.push_back({{1,2,3,-1,4,5,-1,-1,7,6,-1,9,-1,-1,8}, {2,6,1,4,5,8,9,3,7}});
    //test_cases.push_back({{1,2,3,4,5,6,7}, {4,2,1,5,6,3,7}});
    //test_cases.push_back({{1,2,-1,3,-1,4,-1},{4,3,2,1}});
    //test_cases.push_back({{1,-1,2,-1,3,-1,4},{1,2,3,4}});

    // ADAPTED TEST CASES
    test_cases.push_back({{1,2,3,4,5}, {4,2,5,1,3}});
    test_cases.push_back({{1,2,3,1,4,5,1,1,11,7,6,1,9,1,1,8}, {8,1,1,11,2,7,4,6,1,1,5,9,3,1,1,1}});
    test_cases.push_back({{1,2,3,4,5,6,7}, {4,2,5,1,6,3,7}});
    test_cases.push_back({{1,2,3,4,5,6,7,8,9}, {8,4,9,2,5,1,6,3,7}});

    for (auto &tc : test_cases) {
        Tree t(tc.first);
        std::vector<int> data;
        column_order(t, [&data](Node* node) {
            data.push_back(node->value);
        });
        assert(std::ranges::equal(tc.second, data));
    }

    // My tests implementations...
    //Tree t({1,2,3,4,5,6,7,8,9});
    //std::vector<int> data;
    //column_order(t, [&data](Node* node) {
    //    std::cout << "Data: " << node->value << std::endl;
    //    data.push_back(node->value);
    //});
    //std::vector<int> wewe{4,2,5,1,6,3,7};
    //assert(std::ranges::equal(wewe, data));
}

// Support code
Tree::Tree(const std::vector<int>& in){
    if (in.empty()) return;

    std::queue<Node*> q;
    auto it = in.begin();
    nodes.push_back(std::make_unique<Node>(*it,nullptr,nullptr));
    q.push(nodes.back().get());
    root = q.front();
    it++;

    while (it != in.end()){
        if (*it > 0){
            auto left = std::make_unique<Node>(*it,nullptr,nullptr);
            q.front()->left = left.get();
            q.push(left.get());
            nodes.push_back(std::move(left));
        }
        it++;

        if (it == in.end()) break;
        if (*it > 0){
            auto right = std::make_unique<Node>(*it,nullptr,nullptr);
            q.front()->right = right.get();
            q.push(right.get());
            nodes.push_back(std::move(right));
        }
        it++;

        q.pop();
    }
}