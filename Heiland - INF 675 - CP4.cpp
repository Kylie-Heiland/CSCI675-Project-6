/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    int countPairs(TreeNode* root, int distance) {
        vector<vector<TreeNode*>> leaves; //Keeps track of the vector holding the paths. 
        vector<TreeNode*> currentPath; //Keeps tack of the current path the program is on.
        traverse(root, currentPath, leaves); //Goes through each of the nodes on the binary tree, keeping track of the leaves.
        //Loop through vector.
       //for(int i = 0; i < leaves.size(); i++)
        //{
        //    cout << leaves[i]->val << " ";
       // }
        //cout << leaves[0]->val << " " << leaves[1]->val;
        //cout << endl << "The following are leaf pairs" << endl;
        
        int countPairs = 0;
        //Now that we know where the leaves are, it is time to use that information to determine the distances between said leaves.
        TreeNode* searchNode = root; //This will be used to loop through the binary tree again, this time searching for the leaves.
        
        for(int i = 0; i < leaves.size() - 1; i++){//Loops through all of the leaves, except for the last leaf.
            for(int j = i + 1; j < leaves.size(); j++){ //Loops through the rest of the leaves, comparing to the current leaf. 
                //cout << findDistance(root, leaves[i]->val, leaves[j]->val) << endl;
                //Calculates the distance between two leaves by finding the levels of each leaves as well as their common ancestor.
                
                //Starts by finding the ancestor at the lowewst level that both leaves have in common. 
                //cout << leaves[i]->val << ", " << leaves[j]->val << endl;
                int dist = findDistance(leaves[i], leaves[j]); //Finds the distance between the two leaves.
                if(dist <= distance){ //If the distance is smaller or equal in size of what we are looking for:
                    //int dist2 = getLevel(lca, leaves[j], 0);
                   // if(dist2 <= distance && dist1 + dist2 <= distance) 
                    countPairs++;
                }  
            }

        }
        return countPairs;
    }
    
    //Traverse through tree.
    void traverse(TreeNode* node, vector<TreeNode*>& currentPath, vector<vector<TreeNode*>>& leaves)
    {
        if (node == NULL)
            return;
    
        currentPath.push_back(node); //Adds the path that the current path is now going down on.

        //First check if node is a leaf.
        if(node->left == NULL && node->right == NULL) //If the node has no children, it is considered a node. 
           leaves.push_back(currentPath); //Adds this vector path to the vector of leaves paths.
        else {
            //Then recur on left subtree
            traverse(node->left, currentPath, leaves);
    
            //Now recur on right subtree
            traverse(node->right, currentPath, leaves);
        }
        currentPath.pop_back(); //removes the path current path is currently going down on. 
    }
/*
    //Finds the lowest node that both of the leaves have in common. 
    TreeNode* LowestCommonAncestor(TreeNode* node, TreeNode* leaf1, TreeNode* leaf2) { 
        if (node == NULL || node == leaf1 || node == leaf2){ //If the current node is NULL or is equal to first or second leaf, then it is the LCA. 
            return node;
        }
        //Finds the LCA between the leaves using the left child of the node as the starting point. 
        TreeNode* left = LowestCommonAncestor(node->left, leaf1, leaf2); 
        //Finds the LCA using the right child as the starting point. 
        TreeNode* right = LowestCommonAncestor(node->right, leaf1, leaf2);
        //Compares the results from the above two statements. 
        if (left != NULL && right != NULL){ //If both left and right nodes have LCA's, then the current node is returned. 
            return node;
        }
        if (left != NULL){ //However, if the right does not have an LCA, but the left does,
            return left; //find LCA of node's left child.
        }
        return right; //If the left does not have a node, but the right does, find LCA of node's right child.
    }
        
    //Finds the level of the node, starting at the LCA between the two leaves.
    int getLevel(TreeNode *node, TreeNode* leaf, int level) {
        if(node == NULL) return -1; //If the node is empty, then no value was found.
        if(node == leaf) return level; //If the node's value matches leaf 1's value, then the current level is returned.  
        int left = getLevel(node->left, leaf, level+1); //Searches for leafValue in the left subtree.
        if (left == -1) //If the leafValue was not found, then search for it on right subtree.
            return getLevel(node->right, leaf, level+1);
        return left; //Otherwise, return level from left subtree.
    } */
    //Calculates the distance between two leaves by finding the levels of each leaves as well as their common ancestor.
    int findDistance(vector<TreeNode*>& a, vector<TreeNode*>& b) {
        int i = 0; 
        while(i < b.size() && i < a.size() && a[i] == b[i]) //Loops as long as i remains smaller than both leaf a and leaf b, and leaf a and b equal one another. 
            i++;
       /* //Starts by finding the ancestor at the lowewst level that both leaves have in common. 
        TreeNode* lca = LowestCommonAncestor(root, a , b);
        //Counts how many nodes it takes to get to the first leaf.
        int dist1 = getLevel(lca, a, 0);
        //Counts how many nodes it takes to get to the second leaf.
        int dist2 = getLevel(lca, b, 0);
        //By adding both values together, the shortest distance between the leafs has been found.*/
        return (a.size() - i) + (b.size() - i);
    }
};