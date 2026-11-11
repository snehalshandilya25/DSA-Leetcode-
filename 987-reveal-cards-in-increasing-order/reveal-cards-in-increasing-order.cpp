class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
          // Step 1: Sort the deck
        sort(deck.begin(), deck.end());

        // Step 2: Create an empty deque
        deque<int> dq;

        // Step 3: Traverse from largest to smallest
        for(int i = deck.size() - 1; i >= 0; i--) {

            // Step 4: Move the last element to the front
            if(!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            // Step 5: Insert current card at the front
            dq.push_front(deck[i]);
        }

        // Step 6: Convert deque into vector
        return vector<int>(dq.begin(), dq.end());
    }
};