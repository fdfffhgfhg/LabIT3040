template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<T> setsum;
    for(T u : a){
    	setsum.insert(u);
	}
	for(T u : b ){
		setsum.insert(u);
	}
	return setsum;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<T> intersection;
    for(T u : a){
    	if(b.find(u) != b.end()){
    		intersection.insert(u);
		}
	}
	return intersection;
}
// Ta Quoc Tuan 20225110
