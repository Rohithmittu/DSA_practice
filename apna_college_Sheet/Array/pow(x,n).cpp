class Solution {
public:
    double myPow(double x, int n) {

        double result = 1.0;
        long exponent = n;

        // Handle negative powers
        if (n < 0) {
            exponent = -exponent;
        }

        while (exponent > 0) {
            if (exponent % 2 == 1) { // If odd exponent
                result *= x;
            }
            x *= x;
            exponent /= 2; // Divide exponent by 2
        }

        // If original exponent was negative, take reciprocal
        if (n < 0) {
            return 1.0 / result;
        } else {
            return result;
        }


    }
};