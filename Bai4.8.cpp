
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
   map<T, double> c;
    for(auto v : a){
        int index = 0;
        for(auto u : b){
            if(v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
    }

    for(auto v : b){
        int index = 0;
        for(auto u : a){
            if(v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
    }
    return c;
}
// Ta Quoc Tuan 20225110
template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    map<T,double> intersection;
    for(auto u : a){
    	for(auto v : b){
    		if(u.first == v.first){
    			intersection.insert({u.first,min(u.second,v.second)});
			}
		}
	}
	return intersection;
}
