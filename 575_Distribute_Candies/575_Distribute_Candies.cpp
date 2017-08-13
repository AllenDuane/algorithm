class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int counts=1;
        sort(begin(candies),end(candies));
        for(int i=1;i<candies.size();i++){
            if(candies[i]!=candies[i-1])
                counts++;
        }

        return counts<candies.size()/2 ? counts:candies.size()/2;
        //return min(counts,candies.size()/2);
    }
};


//Faster

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
       int counts=0;
        bitset<200001> hash;
        for(int i:candies){
            if(!hash.test(i+100000)){
                hash.set(i+100000);
                counts++;
            }
        }
        return counts<candies.size()/2 ? counts:candies.size()/2;
    }
};
