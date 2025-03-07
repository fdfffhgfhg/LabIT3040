void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // B?t d?u t? d?nh s? 1
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    while(!Q.empty()){
    	int u = Q.front(); 
    	if(!visited[u]){
    		visited[u] = true;
    		cout<<u<<'\n';
		}
		if(!adj[u].empty()){
			for(int v : adj[u]){
				if(!visited[v]){
					Q.push(v);
				}
			}
		}
	}
}
// Ta Quoc Tuan 20225110
