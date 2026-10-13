class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<int> calls;
        int prev = 0;

        for (const string& log : logs) {
            int first = log.find(':');
            int last = log.find(':', first + 1);

            int id = stoi(log.substr(0, first));
            int time = stoi(log.substr(last + 1));

            if (log[first + 1] == 's') {
                if (!calls.empty())
                    times[calls.top()] += time - prev;

                calls.push(id);
                prev = time;
            } else {
                times[calls.top()] += time - prev + 1;
                calls.pop();
                prev = time + 1;
            }
        }

        return times;
    }
};