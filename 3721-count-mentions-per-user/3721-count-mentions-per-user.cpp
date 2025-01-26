class Solution {
public:

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
         sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        int timestampA = stoi(a[1]);
        int timestampB = stoi(b[1]);
        
        if (timestampA == timestampB) {
            // Prioritize "OFFLINE" events before "MESSAGE" events if timestamps are the same
            return a[0] == "OFFLINE";  // "OFFLINE" should come first
        }
        return timestampA < timestampB;  // Otherwise, sort by timestamp
    });

        int n = events.size();
        vector<int> offlineTime(numberOfUsers, -1);
        vector<int> res(numberOfUsers, 0);

        for (auto it : events) {
            string message = it[0];
            int time = stoi(it[1]);
            string users = it[2];

            if (message == "OFFLINE") {
                int userid = stoi(users);
                offlineTime[userid] = time + 60; 
            } 
            else {
                if (users == "ALL") {
                    for (int i = 0; i < res.size(); i++) {
                        res[i] += 1; 
                    }
                }
                else if (users == "HERE") {
                    for (int i = 0; i < res.size(); i++) {
                        if (offlineTime[i] <= time) {
                            res[i] += 1;
                        }
                    }
                }
                else { 
                    stringstream ss(users);
                    string user;
                    while (ss >> user) {
                        if (user.find("id") != string::npos) {
                            int userId = stoi(user.substr(2));
                            
                                res[userId]++;
                            
                        }
                    }
                }
            }
        }
        return res;
    }
};