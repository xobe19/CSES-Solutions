#include <bits/stdc++.h>
using namespace std;


int main() {
int n; cin >> n;
vector<array<int, 2>> orig(n);
multiset<array<int, 2>> sorted;
map<int, multiset<int>> avail_rooms;
map<array<int, 2>, vector<int> > answ;
for(int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
   orig[i] = {a, b}; 
   sorted.insert({a, b});

}
int l = 0;
for(auto&x:sorted){
    auto it = avail_rooms.lower_bound(x[0]);
    if(it != avail_rooms.begin()) {
        it--;
        answ[x].push_back(*((*it).second.begin()));

    avail_rooms[x[1]].insert(*((*it).second.begin()));
        if((*it).second.size() == 1) {
           avail_rooms.erase(it); 
        }
        else 
        (*it).second.erase((*it).second.begin());
       
    }
    else {
        l++;
        answ[x].push_back(l);

    avail_rooms[x[1]].insert(l);
    }

}

cout << l << "\n";
for(int i = 0; i < orig.size(); i++) {
    auto&xyz = answ[orig[i]];
    cout << xyz[xyz.size()-1] << " ";
    xyz.pop_back();
}

}