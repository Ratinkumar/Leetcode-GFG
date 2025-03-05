class Solution {
public:
    long long coloredCells(int n) {
        long long colored=1;
        int add=4;
        while(--n)
        {
            colored+=add;
            add+=4;
        }
        return colored;
    }
};