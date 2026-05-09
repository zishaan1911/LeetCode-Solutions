class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
       int score = 0;
    int counter = 0;

    for (const std::string& event : events) {
        // Stop processing if we reach 10 wickets
        if (counter == 10) {
            break;
        }

        if (event == "W") {
            counter++;
        } else if (event == "WD" || event == "NB") {
            score += 1;
        } else {
            // This handles "0", "1", "2", "3", "4", "6"
            score += std::stoi(event);
        }
    }

    return {score, counter}; 
    }
};