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
                preorder(node->left);
                preorder(node->right);
                
                
            }
        }
        void postorder(Treenode* node)
        {
            if(node!=nullptr)
            { 
                
                postorder(node->left);
                postorder(node->right);q
                cout<<node->data<<"  ";
                
                
            }
        }
        
        void deletevalue(int key)
        {
        root = deletenode(root, key);
        }
        
        Treenode* deletenode(Treenode* root,int key)
        
        {
            if(root ==nullptr)
            {
                return root;
            }
            
            else if(key <root->data)
            {
                root->left=deletenode(root->left,key);
            }
            else if(key> root->data)
            {
                root->right=deletenode(root->right,key);
            }
            
            else
            {
                if(root->left==nullptr)
                {
                    Treenode* temp=root->right;
                    delete root;
                    return temp;
                    
                }
               else if(root->right==nullptr)
                {
                    Treenode* temp=root->left;
                    delete root;
                    return temp;
                    
                }
                
                Treenode* temp=minvalue(root->right);
                root->data=temp->data;
                root->right=deletenode(root->right,temp->data);
                
            }
            return root;
        }
        Treenode* minvalue(Treenode* node)
        {
            Treenode* current=node;
            
            while(current && current->left!=nullptr)
            {
                current=current->left;
                
            }
            return current;
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
      
      int num;
      
      char ch;
      
      cout<<"\n enter y for performing deletion (n for no) : ";
      cin>>ch;
      
      if(ch=='y'||ch=='Y')
      {
          cout<<"\n enter the value you want to delete : ";
          cin>>num;
          
          obj.deletevalue(num);
          
           
      cout<<"\n inorder traversal of binary tree after deletion is : ";
      
      obj.inorder(obj.root);
      }
      else
      {
           cout<<"\n no items are deleted and the inorder traversal of the binarysearchtree is :";
           obj.inorder(obj.root);
           
      }
      
      
      
}