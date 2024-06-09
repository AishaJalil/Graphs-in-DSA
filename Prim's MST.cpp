class MinHeapNode {
public:
	int v;
	int key;

	MinHeapNode(int v, int key) {
		this->key = key;
		this->v = v;
	}
};

// Structure to represent a min heap
class MinHeap {

public:
	int count;
	int size;
	MinHeapNode** array;


	MinHeap(int s) {
		array = new MinHeapNode * [s] {NULL};
		count = 0;
		size = s;
	}

	void insert(int vertice, int key) {
		MinHeapNode* d = new MinHeapNode(vertice, key);
		count++;
		array[count - 1] = d;
		heapify_up(count - 1);
	}

	MinHeapNode* remove() {
		if (array[0] == NULL)
			return NULL;

		MinHeapNode* temp = array[0];
		array[0] = array[count - 1];
		array[count - 1] = NULL;
		count--;
		heapify_down(0);
		return temp;
	}

	void heapify_up(int i) {
		int parent = (i - 1) / 2;

		if (parent >= 0) {
			if (array[i]->key < array[parent]->key) {
				MinHeapNode* temp = array[i];
				array[i] = array[parent];
				array[parent] = temp;

				heapify_up(parent);
			}
		}
	}

	void heapify_down(int i) {
		int smallest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < count && array[left] != NULL && array[left]->key < array[smallest]->key) {
			smallest = left;
		}

		if (right < count && array[right] != NULL && array[right]->key < array[smallest]->key) {
			smallest = right;
		}

		if (smallest != i) {
			MinHeapNode* temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			heapify_down(smallest);
		}
	}


};

void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
		<< graph[i][parent[i]] << " \n";
}

void PrimMST(int graph[][V]) {
	int parent[V]; // Array to store constructed MST
	bool visitedP[V] = { false };
    int distanceP[V];
	MinHeap minHeap(V);

	for (int v = 1; v < V; ++v) {
		parent[v] = -1;
		distanceP[v] = INT_MAX;
	}

	distanceP[0] = 0;
	minHeap.insert(0, distanceP[0]);

	for (int vertices = 0; vertices < V - 1; vertices++) {
		MinHeapNode* minimum = minHeap.remove();
		int u = minimum->v;
		//cout << u << endl;

		visitedP[u] = true;

		for (int v = 0; v < V; v++) {
			if (graph[u][v] && visitedP[v] == false && graph[u][v] < distanceP[v]) {
				distanceP[v] = graph[u][v];
				parent[v] = u;
				minHeap.insert(v, distanceP[v]);
			}
		}
	}

	printMST(parent, graph);
}



