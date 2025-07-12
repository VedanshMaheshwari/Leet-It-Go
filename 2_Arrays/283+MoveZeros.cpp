    #include<iostream>;
    #include<vector>;
    #include<algorithm>;
    using namespace std;

void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(i<nums.size()){
            if(nums[i] == 0){   
                i++;
            }else{
              swap(nums[j], nums[i]);
                j++, i++;
            }

        }
}

void moveZeroes(vector<int>& nums) {
    int i = 0;
    int a = nums.size();
    int j = 0;
    for(; j < a; j++){
        if(nums[j] != 0){
            swap(nums[j], nums[i]);
            i++;
        }
    }
}
