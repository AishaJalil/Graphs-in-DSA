//Maximum Bipartite Matching
//Ford Fulkrson Algorithem
// Bipartite graphs
// disjoint or union



#include <stack>
#include <bits/stdc++.h>
using namespace std;
#define V 6
  int graph[][V] = {{0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
					{0, 0, 0, 1, 0, 0},
					{0, 1, 0, 0, 0, 0},
					{1, 1, 0, 0, 0, 0},
					{1, 0, 1, 0, 0, 0}};
    

void SortUntil(int i, bool visited[V], stack<int>& s)
{
	visited[i] = true;
	
	for(int j=0; j<V; j++)
	{
		if(!visited[j] && graph[i][j] != 0)
		{
			SortUntil(j, visited, s);
		}
	}
	s.push(i);
}
void TopologicalSort()
{
	stack<int> s;
	bool visited[V] = {false};
	
	for(int i=0; i<V; i++)
	{
		if(visited[i] == false)
		{
			SortUntil(i, visited, s);
		}
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main() 
{ 
    TopologicalSort();
    return 0; 
} 










