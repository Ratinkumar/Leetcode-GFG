class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds=time / (n-1);
        int Rem_time=time % (n-1);

        if(rounds % 2 ==1) // if round is odd
        {
            return Rem_time==0 ? n : n - Rem_time;
        }
        else // if even
        {
            return Rem_time==0 ? 1 : Rem_time+1;
        }
    }
};