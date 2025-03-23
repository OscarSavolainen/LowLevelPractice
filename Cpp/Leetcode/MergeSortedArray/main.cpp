// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two 
// integers m and n, representing the number of elements in nums1 and nums2 respectively.
//
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//
// The final sorted array should not be returned by the function, but instead be stored inside the 
// array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
// denote the elements that should be merged, and the last n elements are set to 0 and should be 
// ignored. nums2 has a length of n.
//
//  
//
// Example 1:
//
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
//
// Example 2:
//
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
//
// Example 3:
//
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
//
//  
//
// Constraints:
//
//     nums1.length == m + n
//     nums2.length == n
//     0 <= m, n <= 200
//     1 <= m + n <= 200
//     -109 <= nums1[i], nums2[j] <= 109
//
//  
//
// Follow up: Can you come up with an algorithm that runs in O(m + n) time?



#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  // We start at the end, and add values to the end of nums1 depending on which is bigger
  int m_count = m-1;
  int n_count = n-1;
  
  // Go from front to back
  for (int i = m+n-1; i > -1; i--){
    // Guards
    if ((m_count < 0) && (n_count < 0)) {
      return;
    }
    if (m_count < 0) {
      nums1[i] = nums2[n_count];
      n_count--;
      if (n_count < 0){
        return;
      }
      continue;
    }
    if (n_count < 0) {
      nums1[i] = nums1[m_count];
      m_count--;
      if (m_count < 0){
        return;
      }
      continue;
    }
    if ((m_count < 0) & (n_count < 0)){
      return;
    }

    // Conditon on which array we sample from
    if (nums1[m_count] >= nums2[n_count]) {
      nums1[i] = nums1[m_count];
      m_count--;
    } else {
      nums1[i] = nums2[n_count];
      n_count--;
    }
  }
}

int main() {
  int m = 3;
  int n = 3;
  vector<int> nums1 = {1, 2, 5, 0, 0, 0};
  vector<int> nums2 = {-11, 2, 5};
  // vector<int> nums1 = {1,2,3,0,0,0};
  // vector<int> nums2 = {4,5,6};
  // vector<int> nums1 = {4,5,6,0,0,0};
  // vector<int> nums2 = {1,2,3};
  // expected = {-11, 1, 2, 2, 5, 5}

  merge(nums1, m, nums2, n);
  for (int i = 0; i < m+n; i++){
    cout << " " << nums1[i];
  }
  cout << "\n";

  return 0;
}
