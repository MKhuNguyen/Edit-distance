/*
    Matthew Khu Nguyen
    5/6/2022
    CPSC 485 : Computational Bioinformatics 
    Edit distance calculator - finds the edit distance 
        (total number of additions/deletions/substitutions between two strings)
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;

int main()
{
    std::string word1, word2;

    std::cout << "Input the first word: ";
    std::cin >> word1;
    std::cout << "Input the second word: ";
    std::cin >> word2;

    // create a vector of vectors with same amount of rows as word1's length
    // +1 to account for gel
    int len1 = word1.length() + 1;
    int len2 = word2.length() + 1;

    // create len1 + 1 amount of rows
    std::vector<std::vector<int>> matrix(len1);
    // create len2 + 1 amount of columns
    for (int i = 0; i < len1; i++)
        matrix[i] = std::vector<int>(len2);

    // first row
    for (int j = 0; j < len2; j++)
    {
        matrix[0][j] = j;
        std::cout << "Row: 0" << "\nColumn: " << j << "\nScore: " << matrix[0][j] << std::endl;
    }

    // rest of rows
    for (int i = 1; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            // if first column
            if (j == 0)
                matrix[i][j] = i;
            // if match
            else if (word1[i-1] == word2[j])
                matrix[i][j] = std::min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]);
            // if mismatch
            else // if (word1[i-1] != word2[j])
                matrix[i][j] = std::min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]) + 1;

            std::cout << "+ Row: " << i << "\nColumn: " << j << "\nScore: " << matrix[i][j] << std::endl;
        }

    }

    std::cout << "Oh it's the end of the program." << std::endl;
    return 0;
}