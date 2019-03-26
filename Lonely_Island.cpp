#include <iostream>
#include <vector>

struct node{
	std::vector<int> adj;
};

struct graph{
	std::vector<node> nodes;
};

void addNode(graph& g, int count){
	for(int i=0;i<count;i++){
		node temp;
		g.nodes.push_back(temp);
	}
}

void addBridge(graph& g, int a, int b){
	g.nodes[a].adj.push_back(b);
	g.nodes[b].adj.push_back(a);
}

int main(){
	int n, a, b, i=0;
	graph islands;
	
	std::cin >> n;
	addNode(islands, n);
	
	// Input
	std::cin >> n;
	for (int i=0;i<n;i++){
		std::cin >> a >> b;
		
		addBridge(islands, a, b);
	}
	// Output
	for (node temp : islands.nodes){
		for (int to : temp.adj){
			std::cout << i << ' ' << to << '\n';
		}
		i++;
	}
	
	std::cin >> a;
	return 0;
}