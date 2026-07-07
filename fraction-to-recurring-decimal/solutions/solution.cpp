class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += '-';

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;

        res += '.';
        
        unordered_map<long long, int> seen;
        string fractional_part;
        
        while (rem != 0) {
            if (seen.count(rem)) {
                fractional_part.insert(seen[rem], "(");
                fractional_part += ')';
                break;
            }
            
            seen[rem] = fractional_part.size();
            rem *= 10;
            fractional_part += to_string(rem / d);
            rem %= d;
        }
        
        return res + fractional_part;
    }
};