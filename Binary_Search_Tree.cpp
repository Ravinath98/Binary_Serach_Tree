#include <iostream>


using namespace std;

struct node  //node structure...
{
	int data;
	struct node* left;
	struct node* right;

};


class BST   //Binary search Tree class..
{


public:

	node* insertValue(node* temp, int x);  //insert value to the tree..
	node* deleteGiven(node* temp, int d);  //delete a givent value from the tree..
	node* findMaximum(node* temp);			//finding the maximum value in the tree..
	node* findMinumum(node* temp);			//finding the minimum value in the tree..
	void printInOrder(node* temp);			//print the tree in order ...
	void printPreOrder(node* temp);			//print the tree pre order...
	void printPostOrder(node* temp);		//print the tree post order..
	node* searchValue(node* temp, int f);	//search a given value in the tree..
	int NoOfNodes(node* temp, int counting); //counting the number of nodes...
	void deleteTree(node* temp);			//delet entire tree...
	int getHeight(node* temp);				//get the height of the tree..
};



node* BST::findMaximum(node* temp)   //find max fuction..
{
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->right == NULL) //then temp will be the maximum..
	{
		return temp;
	}
	else
	{
		return findMaximum(temp->right);   //return max...
	}
}

node* BST::findMinumum(node* temp)   //find min fuction..
{
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->left == NULL)
	{
		return temp;
	}
	else
	{
		return findMinumum(temp->left);  //return minimum..
	}
}

node* BST::insertValue(node* temp, int x)  //insert value fuction..
{
	if (temp == NULL)  //if tree is empty...
	{
		temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;

	}

	else
	{
		if (x < temp->data)
		{
			temp->left = insertValue(temp->left, x);
		}
		else
		{
			temp->right = insertValue(temp->right, x);
		}
	}
	return temp;



}



node* BST::deleteGiven(node* temp, int d)  //delete a node with a given value...
{
	node* n;
	if (temp == NULL)
	{
		return NULL;
	}
	else if (d < temp->data)
	{
		temp->left = deleteGiven(temp->left, d);
	}
	else if (d > temp->data)
	{
		temp->right = deleteGiven(temp->right, d);
	}
	else if (temp->left && temp->right) //if 2 childeren present in deleteing element..
	{
		n = findMinumum(temp->right);
		temp->data = n->data;
		temp->right = deleteGiven(temp->right, n->data);
	}
	else //if one child or no child present in deleting element...
	{
		n = temp;
		if (temp->left == NULL && temp->right == NULL)
		{
			temp = NULL;
		}
		else if (temp->left == NULL)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
		delete temp;
	}
	return temp;

}



void BST::printInOrder(node* temp)   //print the tree in In order...
{
	if (temp != NULL)
	{
		printInOrder(temp->left);
		cout << temp->data << " ";
		printInOrder(temp->right);
	}

}

void BST::printPostOrder(node* temp)   //print the tree in Post order...
{
	if (temp != NULL)
	{
		printPostOrder(temp->left);
		printPostOrder(temp->right);
		cout << temp->data << " ";
	}
}

void BST::printPreOrder(node* temp)   //print the tree in Pre order...
{
	if (temp != NULL)
	{
		cout << temp->data << " ";
		printPreOrder(temp->left);
		printPreOrder(temp->right);
	}
}

node* BST::searchValue(node* temp, int f) //search an existing element...
{
	if (temp == NULL)
	{
		return NULL;
	}
	else if (temp->data == f)
	{
		return temp;
	}
	else
	{
		if (f < temp->data)
		{
			return searchValue(temp->left, f);  //return search value address..
		}
		else
		{
			return searchValue(temp->right, f);	//return search value address..
		}
	}

}

int BST::NoOfNodes(node* temp, int counting)  //counting nodes fuction..
{
	if (temp == NULL)
	{
		return 0;
	}
	if (temp->left != NULL)
	{
		counting = counting + 1;
		counting = NoOfNodes(temp->left, counting);
	}
	if (temp->right != NULL)
	{
		counting = counting + 1;
		counting = NoOfNodes(temp->right, counting);
	}

	return counting;  //return counting value...
}

void BST::deleteTree(node* temp)  //delete the entire tree fuction...
{
	if (temp != NULL)
	{
		deleteTree(temp->left);
		deleteTree(temp->right);

		delete temp;
	}
	else
	{
		return;
	}

}

int BST::getHeight(node* temp)  //getting the height fuction...
{
	int leftDepth;  //left tree depth
	int rightDepth;	//right tree depth
	if (temp == NULL)
	{
		return 0;
	}
	else
	{
		leftDepth = getHeight(temp->left);
		rightDepth = getHeight(temp->right);
	}
	if (leftDepth > rightDepth)  //get the largest depth..
	{
		return leftDepth + 1;
	}
	else
	{
		return rightDepth + 1;
	}


}


int main()
{
	BST tree;  //BST object...
	node* temp = NULL;

	int NoOfNodes;
	int nodeData;
	cout << "Enter Number of Nodes in the tree : ";
	cin >> NoOfNodes;   //no of nodes..
	cout << "Enter Tree data : " << endl;

	for (int i = 0; i < NoOfNodes; i++)  //insert the linked list....
	{
		cin >> nodeData;
		temp=tree.insertValue(temp,nodeData);
	}

	while (true)
	{

		int select;  //select a choice...
		cout << endl;
		cout << "1  - Insert New Value" << endl;
		cout << "2  - Delete a given Value" << endl;
		cout << "3  - Print the Tree Pre-order" << endl;
		cout << "4  - Print the Tree In-order" << endl;
		cout << "5  - Print the Tree Post-order" << endl;
		cout << "6  - Search Given Value" << endl;
		cout << "7  - Number of nodes in the current Tree" << endl;
		cout << "8  - Height of the Tree" << endl;
		cout << "9  - Smallest Value in the Tree" << endl;
		cout << "10 - Largest Value in the Tree" << endl;
		cout << "11 - Delete entire Tree" << endl;
		cout << "0  - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> select;

		//selecting choices...
		if (select == 1)
		{
			int dataElement;
			cout << "Enter Tree Node Data : ";
			cin >> dataElement;
			temp=tree.insertValue(temp, dataElement);

			cout << "BST in In order(after update)   : ";
			tree.printInOrder(temp);
			cout << endl;
			cout << "BST in Pre order(after update)  : ";
			tree.printPreOrder(temp);
			cout << endl;
			cout << "BST in Post order(after update) : ";
			tree.printPostOrder(temp);


		}
		else if (select == 2)
		{
			int dataElement;
			cout << "Enter Value want to Delete : ";
			cin >> dataElement;
			tree.deleteGiven(temp, dataElement);

			cout << "BST in In order(after update)   : ";
			tree.printInOrder(temp);
			cout << endl;
			cout << "BST in Pre order(after update)  : ";
			tree.printPreOrder(temp);
			cout << endl;
			cout << "BST in Post order(after update) : ";
			tree.printPostOrder(temp);


		}
		else if (select == 3)
		{

			cout << "Tree in Pre-order : ";
			tree.printPreOrder(temp);
		}
		else if (select == 4)
		{

			cout << "Tree in In-order : ";
			tree.printInOrder(temp);
		}
		else if (select == 5)
		{

			cout << "Tree in Post-order : ";
			tree.printPostOrder(temp);
		}
		else if (select == 6)
		{
			int value;
			cout << "Enter the value want to search : ";
			cin >> value;
			cout << "searching value address : " << tree.searchValue(temp, value);
		}
		else if (select == 7)
		{
			int counting = 0;
			cout << "Number of Nodes in current Tree : ";
			cout << tree.NoOfNodes(temp, counting) + 1;

		}
		else if (select == 8)
		{
			cout << "Height of the Tree : ";
			cout << tree.getHeight(temp);
		}
		else if (select == 9)
		{
			cout << "Smallest Value in the Tree : ";
			cout << tree.findMinumum(temp)->data;
		}
		else if (select == 10)
		{
			cout << "Largest Value in the Tree : ";
			cout << tree.findMaximum(temp)->data;
		}
		else if (select == 11)
		{
			tree.deleteTree(temp);
			temp = NULL;


		}
		else
		{
			return 0;
		}

		cout << endl << endl;
	}




}
