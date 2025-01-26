class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();

        //atleast 1 candy 
        vector<int> answer(n, 1);

        //left to right
        for(int i=1; i<n; i++){
            if(rating[i] > rating[i-1]){
                //ensures current gets more than previous 
                answer[i] = answer[i - 1] + 1;
            }
        }

        //right to left (n-2 because comparing current with right)
        for(int i = n-2; i>=0; i--){
            if(rating[i] > rating[i+1]){
                //curr gets more candy than right if rat high but if curr have more, it stays same
                answer[i] = max(answer[i], answer[i+1] + 1);
            }
        }
        
        int total = 0;
        for(int candy: answer){
            total = total + candy;
        }

        return total;
    }
}; 