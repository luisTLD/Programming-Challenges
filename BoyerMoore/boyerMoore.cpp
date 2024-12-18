#include <iostream>
#include <vector>

class BoyerMoore {
private:
    std::vector<int> last_occurrences;  // Last occurrence of each character
    std::vector<int> good_suffixes;     // Good suffix shifts
    std::vector<unsigned char> pattern; // Pattern to search
    int comparisons;                    // Count of comparisons made

public:
    BoyerMoore() : comparisons(0) {}

    // Build good suffix array for the pattern
    void buildSuffixesArray()
    {
        int patternLen = pattern.size();
        good_suffixes.resize(patternLen);
        good_suffixes[patternLen - 1] = 1;

        std::string pattern_str(pattern.begin(), pattern.end());

        for (int i = patternLen - 2; i >= 0; i--) {
            std::string suffix = pattern_str.substr(i + 1);

            int suffixShift = calculateSuffixShift(i, suffix, pattern_str);
            if (suffixShift != -1)
            {
                good_suffixes[i] = suffixShift;
            }
            else 
            {
                good_suffixes[i] = calculatePrefixShift(suffix, pattern_str);
            }
        }
    }

    // Calculate shift for suffix match
    int calculateSuffixShift(int i, const std::string &suffix, const std::string &pattern)
    {
        char c = pattern[i];
        int shift = -1;
        int len = suffix.length();

        for (int j = i; shift == -1 && j > 0; j--)
        {
            if (c != pattern[j - 1])
            {
                std::string str = pattern.substr(j, len);
                if (str == suffix)
                {
                    shift = i - j + 1;
                }
            }
        }

        return shift;
    }

    // Calculate shift based on prefix match
    int calculatePrefixShift(const std::string &suffix, const std::string &pattern)
    {
        bool was_found = false;
        std::string temp_suffix = suffix;

        while (!was_found && !temp_suffix.empty())
        {
            if (pattern.rfind(temp_suffix, 0) == 0)
            {
                was_found = true;
            }
            else
            {
                temp_suffix = temp_suffix.substr(1);
            }
        }

        return !was_found ? pattern.length() + 1 : pattern.length() - temp_suffix.length();
    }

    // Build last occurrence table for the pattern
    void buildLastOccurrencesTable()
    {
        last_occurrences.assign(256, -1);
        for (size_t i = 0; i < pattern.size(); i++)
        {
            last_occurrences[pattern[i] + 128] = i;
        }
    }

    // Calculate shift based on last occurrence of a character
    int calcLastOccShift(int i, int j, const std::vector<unsigned char> &sequence)
    {
        return j - last_occurrences[sequence[i + j] + 128];
    }

    // Set the pattern and build internal tables
    void setPattern(const std::vector<unsigned char> &pattern_input)
    {
        pattern = pattern_input;
        buildSuffixesArray();
        buildLastOccurrencesTable();
    }

    // Get the number of comparisons made
    int getComparisons() const { return comparisons; }

    // Match the pattern against a string
    std::vector<int> match(const std::string &search_text)
    {
        return match(std::vector<unsigned char>(search_text.begin(), search_text.end()));
    }

    // Match the pattern against a byte sequence
    std::vector<int> match(const std::vector<unsigned char> &search_sequence)
    {
        comparisons = 0;
        std::vector<int> indices;
        int last_occurrence_shift;
        int i = 0, j = pattern.size() - 1;
        int maxIndex = search_sequence.size() - pattern.size();

        // Search the pattern in the sequence
        while (i <= maxIndex)
        {
            if (search_sequence[i + j] == pattern[j])
            {
                if (j-- == 0)
                {
                    indices.push_back(i++);  // Pattern found, add index
                    j = pattern.size() - 1;  // Reset pattern position
                }
            }
            else
            {
                last_occurrence_shift = calcLastOccShift(i, j, search_sequence);
                i += std::max(last_occurrence_shift, good_suffixes[j]);  // Move by the max shift
                j = pattern.size() - 1;
            }

            comparisons++;  // Count comparisons
        }

        return indices;
    }

    // Print internal structures (for debugging)
    void printInternalStructures() 
    {
        printGoodSuffixesArray();
        printLastOccurrenceTable();
    }

    // Print the good suffix array
    void printGoodSuffixesArray()
    {
        for (int i : good_suffixes)
        {
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    // Print the last occurrence table
    void printLastOccurrenceTable()
    {
        for (size_t i = 0; i < last_occurrences.size(); i++)
        {
            if (last_occurrences[i] != -1)
            {
                std::cout << char(i - 128) << " - " << last_occurrences[i] << std::endl;
            }
        }
    }
};
