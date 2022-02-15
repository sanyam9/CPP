#include<bits/stdc++.h>
using namespace std;

/*
   1. Store next smaller indices both right and left
   2. Elements with no smaller index on right = array length
   3. Elements with no smaller index on left = -1
   4. Area = (RightIdx - LeftIdx - 1) * Height;

*/
int largestRectangleArea(vector<int>& height) {
   vector<int> smallerRightIdx(height.size(),height.size());
   vector<int> smallerLeftIdx(height.size(),-1);
   stack<int> stack;

   for(int i = 0 ; i<height.size() ; i++){
       while(!stack.empty() && height[stack.top()]>=height[i])
           stack.pop();
       if(!stack.empty())
           smallerLeftIdx[i] = stack.top();
       stack.push(i);
   }

   while(!stack.empty()) stack.pop();

   for(int i = height.size()-1 ; i>=0 ; i--){
       while(!stack.empty() && height[stack.top()]>=height[i])
           stack.pop();
       if(!stack.empty())
           smallerRightIdx[i] = stack.top();
       stack.push(i);
   }

   int maxArea = 0;

   for(int i = 0 ; i<height.size() ; i++){

       int width = smallerRightIdx[i] - smallerLeftIdx[i] - 1;
       int area = height[i] * width;
       maxArea = max(maxArea,area);

   }
   return maxArea;
}

int main(){

    std::vector<int> v{2,1,5,6,2,3};
    std::cout << largestRectangleArea(v) << '\n'; return 0;
}
