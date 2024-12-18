#include <iostream>
#include <vector>

#include "boyerMoore.cpp"  // Include the BoyerMoore class implementation

int main() {
    BoyerMoore bm;  // Create a BoyerMoore object

    // Read the pattern to search for
    std::string pattern_input;
    std::cout << "Enter the pattern you want to search for: ";
    std::getline(std::cin, pattern_input);

    // Convert the pattern to a vector of unsigned chars (bytes)
    std::vector<unsigned char> pattern(pattern_input.begin(), pattern_input.end());
    bm.setPattern(pattern);  // Set the pattern in the BoyerMoore object

    // Read the text where the pattern will be searched
    std::string text_input;
    std::cout << "Enter the text to search the pattern in: ";
    std::getline(std::cin, text_input);

    // Perform the search
    std::vector<int> matches = bm.match(text_input);

    // Display the matching indices
    std::cout << "Pattern found at indices: ";
    for (int index : matches)
    {
        std::cout << index << " ";  // Print each match index
    }
    std::cout << std::endl;

    return 0; 
}
