#include "cbigmath.h"

string coefficients[Expansion_N] = {
  "-0.41192476193140604",  //c_0
  "1.448374859966958",  //c_1
  "-0.4787956360804496",  //c_2
  "0.19006596140004947",  //c_3
  "-0.07514327383754171",  //c_4
  "0.027372611538102647",  //c_5
  "-0.008613805191513568",  //c_6
  "0.002125198690495572",  //c_7
  "-0.00030974187424989957",  //c_8
  "-2.8425304021790032e-05",  //c_9
  "3.1574011823125886e-05",  //c_10
  "-7.660655631569276e-06",  //c_11
  "-1.872084185085391e-07",  //c_12
  "5.739068454660167e-07",  //c_13
  "-8.835792388212124e-08",  //c_14
  "-2.7990664582658143e-08",  //c_15
  "8.642066284757234e-09",  //c_16
  "1.510183795404218e-09",  //c_17
  "-5.993003940782194e-10",  //c_18
  "-1.2260171933684256e-10",  //c_19
  "3.121053146165201e-11",  //c_20
  "1.1495634724060384e-11",  //c_21
  "-4.162985895191632e-13",  //c_22
  "-8.182890880769642e-13",  //c_23
  "-1.3633331790924453e-13",  //c_24
  "2.2165379864935465e-14",  //c_25
  "1.42618449829654e-14",  //c_26
  "2.3617641139851644e-15",  //c_27
  "-2.5944204737896404e-16",  //c_28
  "-2.327505061673471e-16",  //c_29
  "-5.553307423930173e-17",  //c_30
  "-2.4316713521482548e-18",  //c_31
  "2.9356423209635676e-18",  //c_32
  "1.170741677716852e-18",  //c_33
  "2.0742704301527369e-19",  //c_34
  "-7.492853308064223e-21",  //c_35
  "-1.7209932229283386e-20",  //c_36
  "-5.723671671361958e-21",  //c_37
  "-8.66065957494793e-22",  //c_38
  "9.448770298012597e-23",  //c_39
  "9.759376842903619e-23",  //c_40
  "2.860005240466455e-23",  //c_41
  "3.0338146028296227e-24",  //c_42
  "-1.089889003978613e-24",  //c_43
  "-6.095076622866355e-25",  //c_44
  "-1.1545857715635467e-25",  //c_45
  "1.389282633978278e-26",  //c_46
  "1.3612763598694797e-26",  //c_47
  "1.6715252546661142e-27",  //c_48
  "-1.2345329282270834e-27",  //c_49
  "1.1319654261284479e-28",  //c_50
};

CBigNum ln(const CBigNum& a) {
    CBigNum num = a;
    long long scaled_k = 0;
    
    while (num < 1) {
  		num <<= 1;
  		scaled_k++;
    }
    
    // Check the natural first
    if (num <= 0) {
        throw "Log Natural Error: Natural must be positive.";
    }
    
    // Handle numbers greater than 1 by reducing them
    long long k = 0;
    while (num > 10) {
        num >>= 1;
        k++;
    }

    CBigNum x = (num - 1)/(num + 1);
    CBigNum xx = x*x;
    long long nk = 2*log_N+1;
    CBigNum y = CBigNum(1)/nk;
    
    for(int i = 0; i < log_N; i++)
    {
      nk = nk - 2;
      y = CBigNum(1)/nk+xx*y;
      y.round(num.getResFracBits()+1);
    }

    // Adding the correction term for the number of divisions we performed
    CBigNum result = 2.0*x*y + (k-scaled_k) * ln10;

    result.round(num.getResFracBits());
    result.setResFracBits(num.getResFracBits());
    return result;
}

CBigNum cheby_ln(const CBigNum& a) {
    CBigNum num = a;
    long long scaled_k = 0;
    
    while (num < 1) {
  		num <<= 1;
  		scaled_k++;
    }
    
    // Check the natural first
    if (num <= 0) {
        throw "Log Natural Error: Natural must be positive.";
    }
    
    // Handle numbers greater than 1 by reducing them
    long long k = 0;
    while (num > 10) {
        num >>= 1;
        k++;
    }

    // The Summary
    CBigNum sum(0);

    // Recursively compute Chebyshev terms
    // T_0(x) = 1
    CBigNum T0(1);
    // T_1(x) = x
    CBigNum x = num - 1;
    CBigNum T1 = x;
    
    // Add first two terms of the series
    sum += T0 * coefficients[0];
    sum += T1 * coefficients[1];
		
		CBigNum Tn(0);
    for (int n = 2; n < Expansion_N; n++) {
    	  // Recursion: T_{n+1}(x) = 2xT_n(x) - T_{n-1}(x)
        Tn = 2 * x * T1 - T0;
        // Use pre-calculated Chebyshev coefficients
        sum += (Tn * coefficients[n]);
				
        // Update T_{n-1} and T_n for next iteration
        T0 = T1;
        T1 = Tn;
				
        // Round the result at each step
        sum.round(num.getResFracBits());
        T0.round(num.getResFracBits());
        T1.round(num.getResFracBits());
    }

    // Adding the correction term for the number of divisions we performed
    CBigNum result = sum + (k - scaled_k)*ln10;

    result.round(num.getResFracBits());
    result.setResFracBits(num.getResFracBits());
    return result;
}

