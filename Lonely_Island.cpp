#include <iostream>
#include <vector>

bool checked[100]; // dapet error klo pake vector(???)

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

void DFS(graph islands, int x){
	int accessible = 0;
	std::cout << "nodes " << x << '\n';
	if (!checked[x]){
		checked[x] = true;
		for (int i : islands.nodes[x].adj){
			if (!checked[i]) accessible++;
		}
		std::cout << "asdasd" << x << ' ' << accessible << '\n';
		if (accessible > 0){
			for (int to : islands.nodes[x].adj){
				// std::cout << "debug" << accessible << ' ' << to << '\n';
				islands.nodes[x].adj.erase(islands.nodes[x].adj.begin()+x-1);
				DFS(islands, to);
			}
		}else{
			std::cout << "salah satu ujungnya adalah pulau ke-" << x << '\n';
		}
	}
}

int main(){
	int n, a, b, i=0, start;
	graph islands;
	node curr;
	
	std::cin >> n;
	addNode(islands, n);
	for (int i=0;i<n;i++){
		checked[i] = false;
	}
	
	// Input
	std::cin >> n;
	for (int i=0;i<n;i++){
		std::cin >> a >> b;
		
		addBridge(islands, a, b);
	}
	
	std::cin >> start;
	
	DFS(islands, start);
	
	// Output islands bridge
	// for (node temp : islands.nodes){
		// for (int to : temp.adj){
			// std::cout << i << ' ' << to << '\n';
		// }
		// i++;
	// }
	
	std::cin >> a;
	return 0;
}