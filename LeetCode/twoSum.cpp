#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // to store the complement and its index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // calculate the complement of current element
        
        // Check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // Return the indices if the pair is found
            return {num_map[complement], i};
        }
        
        // Store the current element and its index in the map
        num_map[nums[i]] = i;
    }
    
    // Return an empty vector if no solution (although the problem guarantees one solution)
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    // Print the result
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
