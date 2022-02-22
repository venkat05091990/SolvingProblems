#include<iostream>
#include<queue>
#include<cstdlib>

using namespace std;

// node
class Node
{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key)
	{
		this->key = key;
		left= right = NULL;
	}
};

// build the tree
Node* buildTree()
{
    int key;
    cin>>key;
    
    // base case
    if(key==-1)
    {
        return NULL;
    }
    
    // create new node
    Node* t = new Node(key);
    
    t->left = buildTree();
    t->right = buildTree();
    
    return t;
}

void printLevelOrder(Node *root)
{
    // queue to put nodes
    queue<Node*> q;
    
    //push the root and end of level NULL
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        // first in the queue fifo
        Node* temp = q.front();   
        
        if(temp==NULL)
        {   
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            //print the node key
            cout<<temp->key<<" ";
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int height(Node* root)
{
    // base case
    if(root==NULL)
    {
        return 0;
    }
    
    // rec case
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    return 1 + max(h1,h2);
    
    return 0;
}

int diameter(Node* root)
{
    // base case
    if(root==NULL)
    {
        return 0;
    }
    
    // rec case
    int lh = height(root->left);
    int rh = height(root->right);
    
    return max( lh+rh , max(diameter(root->left), diameter(root->right)) );
}

class HDPair
{
public:
    int height;
    int diameter;
};


HDPair diameter_optimized(Node* root)
{
    HDPair p;
    
    // base case
    if(root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    
    // rec case
    HDPair Left = diameter_optimized(root->left);
    HDPair Right = diameter_optimized(root->right);
    
    p.height = 1+max(Left.height,Right.height);
    
    int D1 = Left.height+Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;
    
    p.diameter = max(D1,max(D2,D3));
    return p;
}

int replaceWithDescendentSum(Node* root)
{
    // base case
    if(root==NULL)
    {
        return 0;
    }
    
    //rec case
    int left_sum = replaceWithDescendentSum(root->left);
    int right_sum = replaceWithDescendentSum(root->right);
    
    // total desc sum
    int total_descendent_sum = left_sum + right_sum;
    
    // replace with total_descendent_sum
    int current = root->key;
    if(root->left != NULL or root->right != NULL)
    {
        root->key = total_descendent_sum;
    }
    
    return total_descendent_sum + current;
}

class isBalancedT
{
public:
    bool isBalanced;
    int height;
};

isBalancedT isBalancedTree(Node* root)
{
    isBalancedT o;
    
    if(root==NULL)
    {
        o.isBalanced=true;
        o.height=0;
        return o;
    }
    
    isBalancedT Left = isBalancedTree(root->left);
    isBalancedT Right = isBalancedTree(root->right);
    
    int diff_height = abs(Left.height - Right.height);
    o.isBalanced = (diff_height<=1);
    o.height = 1+max(Left.height,Right.height);
    
    return o;
}

int main()
{
    //vector<int> tree_ids = {1,2,3,4,5,-1,-1,-1,6,-1,-1,-1,-1};
    
    //building the tree
    Node* root = buildTree();
    
    cout<<"---------"<<endl;
    cout<<"Level Order Traversal"<<endl;
    //print the level order
    printLevelOrder(root);
    
    cout<<"---------"<<endl;
    cout<<"height :"<<height(root)<<endl;
    
    cout<<"---------"<<endl;
    cout<<"diameter : "<<diameter(root)<<endl;

    cout<<"---------"<<endl;
    cout<<"diameter : "<<diameter_optimized(root).diameter<<endl;
    
    cout<<"---------"<<endl;
    cout<<"Tree replaced with descendant sum"<<endl;
    replaceWithDescendentSum(root);
    printLevelOrder(root);
    

    cout<<"--------"<<endl;
    cout<<"isBalancedTree : "<<isBalancedTree(root).isBalanced<<endl;
    
    
    return 0;
}
