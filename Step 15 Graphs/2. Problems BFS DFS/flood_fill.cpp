#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // The floodFill function implements a Breadth-First Search (BFS)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Get the initial color of the starting pixel
        int oldColor = image[sr][sc];

        // If the starting pixel already has the target color, no work is needed.
        if (oldColor == color) {
            return image;
        }

        int n = image.size();
        int m = image[0].size();

        // Queue for BFS, storing coordinates {row, col}
        queue<pair<int, int>> q;
        
        // Start the fill process
        q.push({sr, sc});
        image[sr][sc] = color; // Change the color of the starting pixel

        // Delta arrays for navigating neighbors (Up, Right, Down, Left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the neighbor is within bounds and has the original color
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor) {
                    // Change its color and add it to the queue to process its neighbors
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return image;
    }
};

// Helper function to print the 2D vector
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

// Main function to test the code
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Define the initial image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    // Define the starting pixel and the new color
    int startRow = 1;
    int startCol = 1;
    int newColor = 2;

    cout << "Original Image:" << endl;
    printImage(image);
    
    cout << "\nStarting Flood Fill at (" << startRow << ", " << startCol << ") with color " << newColor << "..." << endl;

    // Call the floodFill function
    vector<vector<int>> result = sol.floodFill(image, startRow, startCol, newColor);

    cout << "\nImage After Flood Fill:" << endl;
    printImage(result);

    return 0;
}