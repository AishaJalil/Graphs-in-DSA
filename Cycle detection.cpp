#include <iostream>
using namespace std;
# define V 4
class Node {
public:
    int data;
    Node* next;    
    bool visited;
    Node() : data(0), next(NULL) , visited(false){}
    Node(int data) : data(data), next(NULL) , visited(false) {}
};


class Queue {
public:
    Node* front;
    Node* rear;

    Queue() : front(NULL), rear(NULL) {}

    void Enqueue(Node* data) {
        if (front == NULL) {
            front = rear = data;
        } else {
            rear->next = data;
            rear = rear->next;
        }
    }

    Node* Dequeue() {
        if (front == NULL) {
            return NULL;
        }

        Node* temp = front;
        front = front->next;
        return temp;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

class Graph {
public:
    int vertex;
    Node** edge;

    Graph(int vertex) {
    	this->vertex = vertex;
    	edge = new Node*[vertex];
        for (int i = 0; i < vertex; ++i) {
            edge[i] = NULL; // Initialize array elements to NULL
        }
    }

    void InsertEdges(int to, int from) {
        Node* nn = new Node(to);
        nn->next = edge[from];
        edge[from] = nn;
        
        nn = new Node(from);
        nn->next = edge[to];
        edge[to] = nn;
    }
    void Display()
    {
    	for(int i=0; i <= vertex; i++)
    	{
    		cout<<"Veretx "<<i<<" is connected to : ";
    		
    		Node *temp = edge[i];
    		while(temp != NULL)
    		{
    			cout<< (temp->data)<<" ";
    			temp = temp->next;
			}
    		cout<<" Vertices.\n";
    		
		}
	}
	bool isCycleUntil(int curr, bool* v, bool* s)
	{
		v[curr] = true;
		s[curr] = true;
		
		Node* temp = edge[curr];
		
		while(temp != NULL)
		{
			if(s[temp->data])
			{
				return true;
			}
			else if(!v[temp->data] && isCycleUntil(temp->data, v,s))
			{
				return true;
			}
			temp = temp->next;
		}
		
		s[curr] = false;
		return false;
	}
	
	bool isCyclic()
   {
    bool* visited = new bool[V];
    bool* s = new bool[V];
    for (int i = 0; i < V; i++)
    {
    	visited[i] = false;
    	s[i] = false;
    	
	}
        
    for (int u = 0; u < V; u++) {
 
        if (!visited[u])
            if (isCycleUntil(u, visited, s))
                return true;
    }
    return false;
   }

};

int main() {
    
    Graph g(4);
    g.InsertEdges(0, 1);
    g.InsertEdges(0, 2);
    g.InsertEdges(2, 1);
    g.InsertEdges(3, 2);
    
  
    g.Display();
    //g.BreadthFirstSearch();
    g.isCyclic()?cout<<"Cyclic":cout<<"Acyclic";
    return 0;
}
