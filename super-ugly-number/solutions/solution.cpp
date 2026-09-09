class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long k=primes.size();
        vector<long long>pointer(k,0);
        vector<long long>nl(n,1);
        for(long long i=1;i<n;i++){
            long long sum = LLONG_MAX;
            for(long long j=0;j<k;j++){
                long long val = nl[pointer[j]] * primes[j];
                if(val<sum){
                    sum=val;
                
                }
            }
            nl[i]=sum;
            for (int j = 0; j < k; j++) {
                if (nl[pointer[j]] * primes[j] == nl[i]) {
                    pointer[j]++;
                }
            }            
            
        }
        return nl[n-1];
    }
};