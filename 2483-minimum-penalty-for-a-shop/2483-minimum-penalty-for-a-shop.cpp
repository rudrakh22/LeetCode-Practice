class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int prefixN = 0;
        int suffixY = 0;
       
        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y'){
                suffixY++;
            }
        }

        int minPenalty = suffixY;
        int bestHour = 0;

        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y'){
                suffixY--;
            }
            else{
                prefixN++;
            }

            int penalty = prefixN + suffixY;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        return bestHour;
    }
};