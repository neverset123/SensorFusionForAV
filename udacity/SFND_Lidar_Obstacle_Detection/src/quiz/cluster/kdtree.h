/* \author Aaron Brown */
// Quiz on implementing kd tree

#include "../../render/render.h"
#include <cmath>


// Structure to represent node of kd tree
struct Node
{
	std::vector<float> point;
	int id;
	Node* left;
	Node* right;

	Node(std::vector<float> arr, int setId)
	:	point(arr), id(setId), left(NULL), right(NULL)
	{}

	~Node()
	{
		delete left;
		delete right;
	}
};

struct KdTree
{
	Node* root;

	KdTree()
	: root(NULL)
	{}

	~KdTree()
	{
		delete root;
	}

	void insertNode(Node *&node, std::vector<float> data, int id, int depth)
	{
		if(node == NULL)
		{
			node = new Node(data, id);
		}
		else
		{
			if(data[depth%2]<node->point[depth%2])
			{
				insertNode(node->left, data, id, depth+1);
			}
			else{
				insertNode(node->right, data, id, depth+1);
			}
			
		}
	}

	void insert(std::vector<float> point, int id)
	{
		// TODO: Fill in this function to insert a new point into the tree
		// the function should create a new node and place correctly with in the root 
		insertNode(root, point, id, 0);
	}

	float distance(std::vector<float> point1, std::vector<float> point2)
	{
		float sum = 0;
		for(int i=0; i<point1.size(); i++)
		{
			sum += pow(point1[i]-point2[i], 2);
		}
		return sqrt(sum);

	}

	void searchNode(Node *&node, std::vector<float> target, int depth, float distanceTol, std::vector<int> &ids) 
	{
		if(node == NULL)
		{
			return;
		}
		else{
			if(distance(target, node->point)<=distanceTol)
			{
				ids.push_back(node->id);
				searchNode(node->left, target, depth+1, distanceTol, ids);
				searchNode(node->right, target, depth+1, distanceTol, ids);
			}
			else{
				if(target[depth%2]<node->point[depth%2])
				{
					searchNode(node->left, target, depth+1, distanceTol, ids);
				}
				else{
					searchNode(node->right, target, depth+1, distanceTol, ids);
				}
			}
		}

	}

	// return a list of point ids in the tree that are within distance of target
	std::vector<int> search(std::vector<float> target, float distanceTol)
	{
		std::vector<int> ids;
		searchNode(root, target, 0, distanceTol, ids);
		return ids;
	}
	

};




