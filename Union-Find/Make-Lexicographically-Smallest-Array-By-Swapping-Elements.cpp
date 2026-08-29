/* Firstly i loved this question ;) Why because the intution is awesome . On reading the problem statement the first intution i got was to swap only consecutive elements , which is of course lame . Because you will not necesarily have an option to swaping of all the elements (if this was just return sorted(nums) 
Now the main idea here is Transitive property and Grouping . 
if a can be swapped with b 
b can be swapped with c 
then a can be swapped with c

First we need to have a deep copied sorted nums then .....
Now Think of this as grouping the elements list that can be swapped internally
sort each of the groups internally and rearranging will work best .

Now we will have 2 hash maps numToGroup where we have 
num -> currGroup 
and also groupToList
where we have 

currGroup-> {list of num belonging to that group
i am jyoti and i will never give up */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        unordered_map<int,int> numToGroup;
        unordered_map<int,list<int>> groupToList;
        
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(),numsSorted.end());
        int currGroup = 0;
        numToGroup.insert(pair<int,int>(numsSorted[0],currGroup));
        groupToList.insert(pair<int,list<int>>(currGroup,list<int>(1,numsSorted[0])));

        for(int i = 1; i < n; i++){
            if(numsSorted[i]-numsSorted[i-1] > limit)currGroup++;

            numToGroup.insert(pair<int,int>(numsSorted[i],currGroup));
            if(groupToList.find(currGroup) == groupToList.end()){
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }
        return nums;
    }
};