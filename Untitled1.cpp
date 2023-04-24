#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    char choice;
    do {
        std::cout << "Choose an option from the menu:\n";
        std::cout << "a) Find maximum integer from a set of numbers\n";
        std::cout << "b) Find minimum integer from a set of numbers\n";
        std::cout << "c) Find the average of a set of scores\n";
        std::cout << "d) Exit the program\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 'a') {
            std::vector<int> nums;
            int num;
            std::cout << "Enter a set of numbers, followed by -1 to indicate the end: ";
            while (std::cin >> num && num != -1) {
                nums.push_back(num);
            }
            if (nums.empty()) {
                std::cout << "You did not enter any numbers\n";
            } else {
                int max_num = *std::max_element(nums.begin(), nums.end());
                std::cout << "The maximum number is " << max_num << "\n";
            }
        } else if (choice == 'b') {
            std::vector<int> nums;
            int num;
            std::cout << "Enter a set of numbers, followed by -1 to indicate the end: ";
            while (std::cin >> num && num != -1) {
                nums.push_back(num);
            }
            if (nums.empty()) {
                std::cout << "You did not enter any numbers\n";
            } else {
                int min_num = *std::min_element(nums.begin(), nums.end());
                std::cout << "The minimum number is " << min_num << "\n";
            }
        } else if (choice == 'c') {
            std::vector<double> scores;
            double score;
            std::cout << "Enter a set of scores, followed by -1 to indicate the end: ";
            while (std::cin >> score && score != -1) {
                scores.push_back(score);
            }
            if (scores.empty()) {
                std::cout << "You did not enter any scores\n";
            } else {
                double average = std::accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
                std::cout << "The average score is " << average << "\n";
            }
        } else if (choice != 'd') {
            std::cout << "Invalid choice, please try again\n";
        }
    } while (choice != 'd');

    std::cout << "Exiting the program\n";

    return 0;
}


