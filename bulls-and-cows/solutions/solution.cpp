class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        int bulls = 0;
        int cows = 0;
        int secretCount[10] = {0};
        int guessCount[10] = {0};

        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }

        for (int d = 0; d < 10; ++d) {
            cows += std::min(secretCount[d], guessCount[d]);
        }

        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};