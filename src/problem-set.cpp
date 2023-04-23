#include<stdio.h>
#include<vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <sqlite3.h>
using namespace std;
class Solution{
    public:
        /* Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.*/
        /*problem 1027*/
        int longestArithSeqLength(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            vector<unordered_map<int, int>> dp(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    int diff = nums[i] - nums[j];
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                    ans = max(ans, dp[i][diff]);
                    }
            }
            return ans + 1;
        }
        /*You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).

        You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

        Return the smallest possible total score that you can achieve with some triangulation of the polygon.*/
        /*problem 1039*/
        int minScoreTriangulation(vector<int>& values){
            int n = values.size();
            vector<vector<int>> dp(n, vector<int>(n));
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 2; j < n; j++) {
                    for (int k = i + 1; k < j; k++) {
                        if (dp[i][j] == 0) {
                            dp[i][j] = dp[i][k] + values[i] * values[j] * values[k] + dp[k][j];
                        }
                        else {
                            dp[i][j] = min(dp[i][j], dp[i][k] + values[i] * values[j] * values[k] + dp[k][j]);
                        }
                    }
                }
            }
            return dp[0][n - 1];
        }

        /*write me a code that able to calculate 3 sums without looping*/
        int t_sums(vector<int>& nums, int target){
            int n = nums.size();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] + nums[j] + nums[k] == target) {
                            ans++;
                        }
                    }
                }
            }
            return ans;
        }

        /*the function can pass the user input to  Mydatabase*/ 
        void pass_input_to_database(){
            sqlite3* db;
            sqlite3_open("test.db", &db);

            //get user input for username and password
            char username[20];
            char password[20];
            printf("Please enter your username: ");
            scanf("%s", username);
            printf("Please enter your password: ");
            scanf("%s", password);
            //insert the user input into the database
            std::string sql = "SELECT * FROM users WHERE username = '" + std::string(username) + "' AND password = '" + std::string(password) + "'";
        }



};

int main(int argc, char* argv[]) {
    printf("hello world1213\n");
    return 0;
}

