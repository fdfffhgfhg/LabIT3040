struct compare{
	bool compare(pair<int,int> a , pair<int,int> b){
		return a.second > b.second ; 
	} 
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    priority_queue<pair<int,int> , vector<pair<int,int>>, compare> q;
	// Khoi tao khoang cach tu 0 toi tat ca cac dinh khac
	vector<int> dist(adj.size());
	int dist_size = dist.size();
	for(int i = 0;i < dist_size ; i++){
		dist[i] = INT_MAX;
	} 
	dist[0] = 0;     // 0 Max max max max max ...
	// khoi tao gia tri cho hang doi uu tien
	for(int i = 0;i < dist_size ; i++){
		q.push({i,dist[i]});
	}
	
	while(!q.empty()){
		pair<int,int> u_pair = q.top(); q.pop();
		int u = u_pair.first;
		for(auto v_pair : adj[u]){
			int v = v_pair.first;
			int weight = v_pair.second;
			 if(dist[v] > dist[u] + weight){
			 	dist[v] = dist[u] + weight;
			 	q.push({v,dist[v]});
			 }
		}
	}
	return dist;
}
// Ta Quoc Tuan 20225110
