#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(){
    pair<int, string> p1 (3,"Sharaf");
    pair<int, string> p2 (4, "Sami");
    pair<int, string> p3 (2, "Lynne");

    map<int, string> mp {p1,p2,p3};

    auto it = mp.begin();
    while (it != mp.end()) 
    {
        cout << (*it).first << (*it).second << " : ";
        it++;
    }
    cout << endl;

    mp[3] = "Saif";

    it = mp.begin();
    while (it != mp.end()) 
    {
        cout << (*it).first << (*it).second << " : ";
        it++;
    }
    cout << endl;

    try{
        if (mp.at(5) == "sharaf")
            cout << "11";
        else
            cout << "222";
        cout << endl;
    }
    catch(...){
        cout << "map key is not found" << endl;
    }

    it = mp.begin();
    mp.erase(it);

    mp.insert({9, "Wesam"});

    auto rit = mp.rbegin();
    while (rit != mp.rend()) 
    {
        cout << rit->first << rit->second << " : ";
        rit++;
    }
    cout << endl;

}