#include <iostream>
using namespace std;

struct node{
	int info;
	node* left;
	node* right;
	
	node(int info){
		this->left = NULL;
		this->right = NULL;
		this->info = info;
	}
		
};


class TREE{
	public:
		node* root;
		node* newNode;
		int height;
		int leafHeight;
		bool isBalanced;
		bool firstNode;
		int counter;
		
		
	TREE(){
		this->isBalanced = true;
		this->firstNode = true;
		this->counter = 0;
		this->leafHeight = 0;
		this->height = 0;
		this->root = NULL;
		this->newNode = NULL;
	}
	
	void insert(node* temp,int info){
		
		if(root == NULL){
			root = new node(info);
			return;
		}
		
		if(info > temp->info){
			if(temp->right == NULL){
				temp->right = new node(info);
			} else {
				insert(temp->right, info);
			}
		} else if(info < temp->info){
			if(temp->left == NULL){
				temp->left = new node(info);
			} else {
				insert(temp->left, info);
			}
		} else {
			cout << endl << "Duplicate Not Allowed in Tree !"<< endl << endl;
			return;
		}
	}
	
	
	node* Deletion(node* temp, int info){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return NULL;
		}
		
		if(temp->info == info){
			// Leaf Node
			if(temp->left == NULL && temp->right == NULL){
				delete temp;
				temp = NULL;
				return NULL;
			}
			// Only Left Child
			if(temp->left != NULL && temp->right == NULL){
				newNode = temp->left;
				delete temp;
				temp = NULL;
				return newNode;
			}
			// Only Right Child
			if(temp->left == NULL && temp->right != NULL){
				newNode = temp->right;
				delete temp;
				temp = NULL;
				return newNode;
			}
			// Has Two Childs
			if(temp->left != NULL && temp->right != NULL){
				node* minimumNode = minimum(temp->right);
				temp->info = minimumNode->info;
				minimumNode->info = info;
			
				temp->right = Deletion(temp->right, info);
				return temp;
			}
			
		}
		
		
		if(info > temp->info){
			if(temp->right != NULL){
				temp->right = Deletion(temp->right, info);
			}
		} else if(info < temp->info){
			if(temp->left != NULL){
				temp->left = Deletion(temp->left, info);
			}
		}
		
		return temp;		
	}
	
	
	node* minimum(node* temp){
		
		if(temp->left == NULL){
			return temp;
		}
		
		return minimum(temp->left);
		
	}
	
	
	void TreeHeight(node* temp, int localHeight){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return;
		}
		
		if(temp->left != NULL){
			TreeHeight(temp->left, localHeight+1);
		} 
		
		if(height < localHeight){
			height = localHeight;
		}
		
		if(temp->right != NULL){
			TreeHeight(temp->right, localHeight+1);
		} 
			
	}
	
	
	void PrintByLevel(node* temp, int level){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return;
		}
		
		if(level == 1){
			cout << temp->info << " ";
		} else {
			PrintByLevel(temp->left, level - 1);
			PrintByLevel(temp->right, level -1);
		}
	}
	
	
	void checkBalance(node* temp){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return ;
		}

		if(temp->left == NULL && temp->right == NULL){
			if(firstNode){
				leafHeight = counter;
				firstNode = !firstNode;
			}
			if(!firstNode){
				if(leafHeight != counter){
					isBalanced = false;
					return ;
				}
			}
			
		}
		
		
		if(temp->left != NULL){
			counter++;
			checkBalance(temp->left);
		}
		
		if(temp->right != NULL){
			counter++;
			checkBalance(temp->right);
		}
		
		counter--;
				
	}
	
	void preOrder(node* temp){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return;
		}
		
		cout << temp->info <<  " ";
		
		if(temp->left != NULL){
			preOrder(temp->left);
		}
		
		if(temp->right != NULL){
			preOrder(temp->right);
		}
		
	}
	
	
	void inOrder(node* temp){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return;
		}
		
		
		if(temp->left != NULL){
			inOrder(temp->left);
		}
		
		cout << temp->info <<  " ";
		
		if(temp->right != NULL){
			inOrder(temp->right);
		}
		
	}
	
	
	void postOrder(node* temp){
		if(root == NULL){
			cout << endl << "Tree is Empty !" << endl << endl;
			return;
		}
		
		
		if(temp->left != NULL){
			postOrder(temp->left);
		}
		
		if(temp->right != NULL){
			postOrder(temp->right);
		}
		
		cout << temp->info <<  " ";
	}
	
};

int main(){
	
	TREE object;
	
	int option;
	int info;
	
	do{
		cout << "1. Insert" << endl;
		cout << "2. Delete" << endl;
		cout << "3. PreOrder" << endl;
		cout << "4. InOrder" << endl;
		cout << "5. PostOrder" << endl;
		cout << "6. Print By Level" << endl;
		cout << "7. Height of Tree" << endl;
		cout << "8. Check Balance" << endl;
		cout << "0. Exit" << endl;
		cout << endl << "Your Option: ";
		cin >> option;
		
		if(option == 1){
			cout << endl << "Enter Info: ";
			cin >> info;
			object.insert(object.root,info);
			cout << endl;
		} else if(option == 2){
			cout << endl << "Enter Info to Delete: ";
			cin >> info;
			object.Deletion(object.root,info);
		} else if(option == 3){
			cout << endl << "The Tree is: ";
			object.preOrder(object.root);
			cout << endl << endl;
		} else if(option == 4){
			cout << endl << "The Tree is: ";
			object.inOrder(object.root);
			cout << endl << endl;
		} else if(option == 5){
			cout << endl << "The Tree is: ";
			object.postOrder(object.root);
			cout << endl << endl;
		} else if(option == 6){
			// find height before calling level traversing
			object.TreeHeight(object.root, 1);
			// now send level from 0 till height
			for(int i=1; i<=object.height; i++){
				cout << endl << "Level " << i-1 << ": ";
				object.PrintByLevel(object.root, i);	
			}
			
			cout << endl << endl;
		} else if(option == 7){
			object.TreeHeight(object.root,0);
			if(object.root != NULL){
				cout << endl << "Tree Height: " << object.height << endl << endl;	
			}
		} else if(option == 8){
			
			if(object.root != NULL){	
			
				object.isBalanced = true;
				object.firstNode = true;
				object.counter = 0;
				object.leafHeight = 0;	
								
				object.checkBalance(object.root);
				
				if(object.isBalanced){
					cout << endl << "Tree is Balanced ! " << endl << endl;
				} else {
					cout << endl << "Tree is Not Balanced ! " << endl << endl;
					
				}
				
			} else {
				cout << endl << "Tree is Empty !" << endl << endl;
			}

				
		} else if(option == 0){	
			cout << endl << "Program is Exiting . . ." << endl << endl;
			break;
		} else {
			cout << endl << "Invalid Input " << endl << endl;
		}
		
	}while(option != 0);
	
	return 0;
}