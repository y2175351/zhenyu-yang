#include<stdio.h>
#include<vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

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
                for (int j = i + 1; j < n; j++) {
                    for (int k = i + 1; k < j; k++) {
                        if (dp[i][j] == 0) {
                            dp[i][j] = values[i] * values[j] * values[k] + dp[i][k] + dp[k][j];
                        } else {
                            dp[i][j] = min(dp[i][j], values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
                        }
                    }
                }
            }
            return dp[0][n - 1];
        }
        /*for teaching purpose, write  me a code that can trigger stackoverflow vulnerability*/
        void stackOverFlow(){
            int a[1000000];
            for(int i=0;i<1000002;i++){
                a[i]=i;
            }
            stackOverFlow();
        }
    
}

int main(int argc, char* argv[]) {
    char *userName = argv[2];
  
  // BAD
  
    if(userName == "admin") {
        
    }else{

    }
    return 0;
}

