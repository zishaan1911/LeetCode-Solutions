#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> scoreValidator(std::vector<std::string>& events) {
        int score = 0;
        int counter = 0;

        for (const std::string& event : events) {
            if (counter == 10) {
                break;
            }

            if (event == "W") {
                counter++;
            } else if (event == "WD" || event == "NB") {
                score += 1;
            } else {
                // The event is a number ("0", "1", "2", "3", "4", "6")
                score += std::stoi(event);
            }
        }

        return {score, counter};
    }
};