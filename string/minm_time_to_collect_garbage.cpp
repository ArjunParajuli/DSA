#include<iostream>
#include<string>
#include<vector>

using namespace std;

 int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickTimeP=0, pickTimeG=0, pickTimeM=0;
        int travelTimeP=0,travelTimeG=0,travelTimeM=0;

        // for finding upto which index each truck has to travel
        int lastindexForP=0, lastindexForG=0, lastindexForM=0;

        // calculate picktime and find upto which index truck has to travel
        for(int i=0;i<garbage.size();i++){
            for(char ch : garbage[i]){
                if(ch == 'P'){
                    pickTimeP++;
                    lastindexForP=i; // update index to be travelled upto i
                }else if(ch == 'G'){
                    pickTimeG++;
                    lastindexForG=i;
                }else{
                    pickTimeM++;
                    lastindexForM=i;
                }
            }
        }
        // now find traveltme
        for(int i=0;i<lastindexForP;i++){
            travelTimeP += travel[i]; 
        }
        for(int i=0;i<lastindexForG;i++){
            travelTimeG += travel[i]; 
        }
        for(int i=0;i<lastindexForM;i++){
            travelTimeM += travel[i]; 
        }
        return (pickTimeP+pickTimeG+pickTimeM+travelTimeP+travelTimeG+travelTimeM);
    }

int main(){
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2 ,4, 3};
    cout << garbageCollection(garbage, travel);

    return 0;
}