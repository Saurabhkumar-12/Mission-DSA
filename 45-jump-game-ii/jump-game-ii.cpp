class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        // We only need to iterate up to n - 2 because if we are already 
        // able to reach or exceed the last index, we don't need a jump from it.
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump's coverage area
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // Early exit if we can already reach the last index
                if (currentEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};