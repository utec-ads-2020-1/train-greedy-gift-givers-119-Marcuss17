#include<bits/stdc++.h>

using namespace std;

struct Gifter{
    string name;
    int money, numPeopleToGift;
    vector<string> peopleToGift;
    int netWorth;
};

int main(){
    int numPeople;
    vector<Gifter> gifters;
    vector<string> names;
    int flag = 0;
    while(cin >> numPeople){
        gifters.clear();
        string name;
        names.clear();
        for(int i = 0; i < numPeople; i++){
            cin >> name;
            names.push_back(name);
        }
        for(int i = 0; i < numPeople; i++){
            Gifter gifter;
            cin >> gifter.name >> gifter.money >> gifter.numPeopleToGift;
            string nameToGift;
            if(gifter.numPeopleToGift > 0) {
                gifter.peopleToGift.clear();
                for(int j = 0; j < gifter.numPeopleToGift; j++){
                    cin >> nameToGift;
                    gifter.peopleToGift.push_back(nameToGift);
                }
            }
            gifters.push_back(gifter);
        }
        int realMoney, dividedCash, netWorth, left;
        for(auto it = gifters.begin(); it != gifters.end(); it++){
            if((*it).numPeopleToGift > 0){
                realMoney = (*it).money/(*it).numPeopleToGift;
                realMoney *= (*it).numPeopleToGift;
            }else{ realMoney = 0;};
            netWorth = realMoney;
            for(auto it2 = gifters.begin(); it2 != gifters.end(); it2++){
                if(!((*it2).peopleToGift).empty()){
                auto it3 = (*it2).peopleToGift.end();
                it3--;
                auto it4 = find((*it2).peopleToGift.begin(), it3, (*it).name);
                if(*it4 == (*it).name){
                    if((*it2).money > 0){
                        dividedCash = (*it2).money / (*it2).numPeopleToGift; 
                    }else{ dividedCash = 0;};
                    netWorth -= dividedCash;   
                }
                } 
            }
            netWorth *= -1; 
            (*it).netWorth = netWorth;
        }
        if(flag == 1){
            cout << '\n';
        }
        flag = 1;
        for(auto it5: names){
            for(auto it6: gifters){
                if(it5 == it6.name){
                    cout << it6.name << " " << it6.netWorth << endl;
                }
            }
        }
    } 
    return 0;
}

