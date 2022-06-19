#include <iostream>
#include <vector>
#include <climits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    std::vector<int> singleNumber(vector<int>& nums)
    {
     int a = 0;
     int stek = nums[0];
     std::vector<int> rez = {0,0};
     int j = 0;
     int q = 0;
     for (int i=0; i<nums.size(); ++i)
        {
            if (stek == nums[i])
                a += 1;
            if ((i==nums.size()-1) && (a==1))
            {
                rez[j] = stek;
                ++j;
                ++q;
                stek = nums[q];
                i = -1;
                a = 0;
            }
            else
            {
               if (i==nums.size()-1)
                {
                   ++q;
                   stek = nums[q];
                   i = -1;
                   a = 0;
                }
            }
             if (j == 3)
                 i = 6;
        }
        int x = rez[0];
        int y = rez[1];
        return {x,y};
    }
};

int main()
{
    /*std::vector<int> nums = {1,2,1,3,2,5};
     int a = 0;
     int stek = nums[0];
     std::vector<int> rez = {0,0};
     int j = 0;
     int q = 0;
     for (int i=0; i<6; ++i)
        {
            if (stek == nums[i])
                a += 1;
            if ((i==5) && (a==1))
            {
                rez[j] = stek;
                ++j;
                ++q;
                stek = nums[q];
                i = -1;
                a = 0;
            }
            else
            {
               if (i==5)
                {
                   ++q;
                   stek = nums[q];
                   i = -1;
                   a = 0;
                }
            }
             if (j == 3)
                 return {x,y};
        }
//     printf("N = %d///%d\n", rez[0],rez[1]);
     int x = rez[0];
     int y = rez[1];
     printf("N = %d///%d\n", x,y);*/
    std::vector<int> nums = {1,2,1,3,2,5};
    Solution(nums);
     return 0;
}
