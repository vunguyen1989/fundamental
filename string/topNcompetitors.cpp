#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
#include <functional>

using namespace std;

//Sử dụng map vs multimap
vector<string> findTop_map_multimap(int N, int topCompetitor, vector<string> competitors, vector<string> reviews){
    vector<string> ret;
    map<string, int> m;
    multimap<int, string, greater <int>> n;
    int cnt;
    for (int i = 0; i < competitors.size(); i++){
        cnt = 0;
        for (int j = 0; j < reviews.size(); j++){
            if (reviews[j].find(competitors[i]) != string::npos) 
                cnt++; 
        }
        m[competitors[i]] = cnt;
    }

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        n.insert(make_pair((*it).second, (*it).first)); //[(*it).second] = (*it).first; 
    }
    
    multimap<int, string>::iterator it = n.begin();
    for (int i = 0; i < min(N, topCompetitor); i++) {       
        ret.push_back((*it).second);
        it++;
    }

    return ret;
}

//Sử dụng map vs set
vector<string> findTop_map_set_Lamda(int N, int topCompetitor, vector<string> competitors, vector<string> reviews){
    vector<string> ret;
    map<string, int> m;
    int cnt;
    for (int i = 0; i < competitors.size(); i++){
        cnt = 0;
        for (int j = 0; j < reviews.size(); j++){
            if (reviews[j].find(competitors[i]) != string::npos) 
                cnt++; 
        }
        m[competitors[i]] = cnt;
    }

    typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
			[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
			{
				return elem1.second > elem2.second;
			};
    std::multiset<std::pair<std::string, int>, Comparator> s(m.begin(), m.end(), compFunctor);
    
    std::multiset<std::pair<std::string, int>>::iterator it = s.begin();
    int limit = min(N, topCompetitor);
    limit = min(limit, (int)competitors.size());
    for (int i = 0; i < limit; i++) {       
        ret.push_back((*it).first);
        it++;
    }

    return ret;
}

bool sortbysec(pair<string, int> e1, pair<string, int> e2){
    return e1.second > e2.second;
}
//sử dụng vector
vector<string> findTop_vetor_sortbysecond(int N, int topCompetitor, vector<string> competitors, vector<string> reviews){
    vector<string> ret;
    vector <pair<string, int>> v;

    int cnt;
    for (int i = 0; i < competitors.size(); i++){
        cnt = 0;
        for (int j = 0; j < reviews.size(); j++){
            if (reviews[j].find(competitors[i]) != string::npos) 
                cnt++; 
        }
        v.push_back(make_pair(competitors[i], cnt));
    }

    sort(v.begin(), v.end(), sortbysec);
    int limit = min(N, topCompetitor);
    limit = min(limit, (int)competitors.size());
    for (int i = 0; i < limit; i++) {       
        ret.push_back(v[i].first);
    }

    return ret;
}

int main(){
    vector<string> competitors = {"samsung", "htc", "intel", "ngon"};
    vector<string> reviews = {"intel ngon nhat", "intel good", 
    "htc cung dc", "htc ngon", 
    "samsung ghe nhat",  "samsung", "samsung"};

    vector<string> ret = findTop_vetor_sortbysecond(4, 4, competitors, reviews);

    for (int i = 0; i < ret.size(); i++){
        cout<< ret[i] << " : ";
    }
    cout << endl;

    return 0;
}