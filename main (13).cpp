#include<iostream>
#include<conio.h>

using namespace std;


class Treenode
{
    public:
    
    int data;
    Treenode* left;
    Treenode* right;
    
};

class binarysearchtree
{
    public:
    
    Treenode* root =nullptr;
    
    Treenode* create (int value)
    {
       
        Treenode* newnode =new Treenode();
        
        newnode->data=value;
        newnode->left=nullptr;
        newnode->right=nullptr;
        return newnode;
        
    }
    
    void insert(int value)
    {
         root=insertrt(root,value);
    }
    
    Treenode* insertrt(Treenode* root,int value)
    {
        if(root==nullptr)
        {
            return create(value);
            
        }
        
        else if(value< root->data)
        {
            root->left=insertrt(root->left,value);
            
        }
         else if(value> root->data)
        {
            root->right=insertrt(root->right,value);
            
        }
        
        return root;
        }
        
        void inorder(Treenode* node)
        {
            if(node!=nullptr)
            {
                inorder(node->left);
                cout<<node->data<<"  ";
                inorder(node->right);
                
                
            }
        }
         void preorder(Treenode* node)
        {
            if(node!=nullptr)
            { 
                cout<<node->data<<"  ";
                inorder(node->left);
                inorder(node->right);
                
                
            }
        }
        void postorder(Treenode* node)
        {
            if(node!=nullptr)
            { 
                
                inorder(node->left);
                inorder(node->right);
                cout<<node->data<<"  ";
                
                
            }
        }
};

int main()
{
    binarysearchtree obj;
    
    int n;
    
    char choice;
    
    
      do{
          cout<<"\nEnter an integer value to insert into the Binary Search Tree: ";
          cin>>n;
          
          obj.insert(n);
          
          cout<<"\n do you want to continue press (y(Y)/n(N) : ";
          cin>>choice;
      }while(choice=='y' || choice=='Y');
      
      
      cout<<"\n inorder traversal of binary tree is : ";
      
      obj.inorder(obj.root);
      cout<<"\n\n preorder traversal of binary tree is : ";
      
      obj.preorder(obj.root);
      
      
      cout<<"\n\n postorder traversal of binary tree is : ";
      
      obj.postorder(obj.root);
      
}