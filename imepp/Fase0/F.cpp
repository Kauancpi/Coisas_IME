#include <iostream>
#include <vector>
#include <string>

// Function to check if a sequence contains the pattern
bool containsPattern(const std::string &sequence, const std::string &pattern) {
    return sequence.find(pattern) != std::string::npos;
}

// Dynamic Programming function to count sequences containing the pattern
int countSequencesWithPattern(int N, const std::string &pattern) {
    if (N % 2 != 0) return 0;  // No balanced sequence possible if N is odd
    int M = pattern.size();

    // DP table to store counts
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
    dp[0][0] = 1;  // Base case: one way to have a sequence of length 0

    // Variables to keep track of sequences containing the pattern
    int count = 0;

    // Build DP table
    for (int len = 1; len <= N; ++len) {
        for (int balance = 0; balance <= len; ++balance) {
            if (balance > 0) {
                // Add +1 (increase balance)
                dp[len][balance] += dp[len - 1][balance - 1];
            }
            if (balance < len) {
                // Add -1 (decrease balance)
                dp[len][balance] += dp[len - 1][balance + 1];
            }

            // Check if the current sequence contains the pattern
            if (balance == 0 && len == N) {
                std::string currentSequence;
                for (int i = 0; i < len; ++i) {
                    currentSequence += (dp[len][i] > dp[len][i + 1]) ? "(" : ")";
                }
                if (containsPattern(currentSequence, pattern)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    int N;
    std::string pattern;

    std::cin >> N;
    std::cin >> pattern;

    int result = countSequencesWithPattern(N, pattern);
    std::cout  << result%998244353;

    return 0;
}