// C++ program to find if a number is divisible by
// 11 or not
#include<bits/stdc++.h>
using namespace std;
 
// Function to find that number divisible by 11 or not
int check(string str)
{
    int n = str.length();
 
    // Compute sum of even and odd digit
    // sums
    int oddDigSum = 0, evenDigSum = 0;
    for (int i=0; i<n; i++)
    {
        // When i is even, position of digit is odd
        if (i%2 == 0)
            oddDigSum += (str[i]-'0');
        else
            evenDigSum += (str[i]-'0');
    }
 
    // Check its difference is divisible by 11 or not
    return ((oddDigSum - evenDigSum) % 11 == 0);
}
 
// Driver code
int main()
{
    string str = "76945";
    check(str)?  cout << "Yes" : cout << "No ";
    return 0;
}
