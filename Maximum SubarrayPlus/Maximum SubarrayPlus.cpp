#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());
        sum[0]=nums[0];
        int result=nums[0];
        int low=0;int high=0;
        for(int i=1;i<nums.size();++i){
        	sum[i]=max(sum[i-1]+nums[i],nums[i]);
        	if(sum[i-1]+nums[i]<nums[i]){
        		low=i;
        		sum[i]=nums[i];
			}else{
				sum[i]=sum[i-1]+nums[i];
			}
			if(result<sum[i]){
				result=sum[i];
				high=i;
			}
		}
		vector<int> results;
		if(result<0){
			results.push_back(0);
			results.push_back(*nums.begin());
			results.push_back(nums[nums.size()-1]);
			return results;
		}
		results.push_back(result);
		results.push_back(nums[low]);
		results.push_back(nums[high]);
		return results;
    }
};
int main(){
	vector<int> arr={-1,-2,-3,-4};
	Solution s;
	auto x=s.maxSubArray(arr);
	cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
}
