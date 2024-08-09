#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
code help queue assignment
algo:
- Begin by sorting the deck in ascending order. This will help us to start with the smallest card.
- initialize a queue q that stores the indices of the cards in the sorted deck.
- Simulate the process of revealing cards: It iterates over each card in the sorted deck. For each card:
    -It reveals the card by setting its position in the ans vector.
    -It checks if there are more cards left to reveal. If so, it moves the next card in the queue to the back. This simulates the process of 
     moving the next card to the bottom of the deck after revealing the current card.
*/

 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        queue<int> q;
        sort(deck.begin(), deck.end());
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        for(int i=0;i<deck.size();i++){
            ans[q.front()] = deck[i];
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }

    int main(){

        return 0;
    }