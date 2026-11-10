class Solution {
public:
    int calPoints(vector<string>& operations) {
         stack<int> st;

        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] == "C") {
                st.pop();
            }

            else if (operations[i] == "D") {
                int x = st.top();
                st.push(2 * x);
            }

            else if (operations[i] == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();
                st.pop();

                int sum = first + second;

                st.push(second);
                st.push(first);

                st.push(sum);
            }

            else {
                st.push(stoi(operations[i]));
            }
        }

        int total = 0;

        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};