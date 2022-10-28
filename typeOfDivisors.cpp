//Auth: Tushal
//Github: https://github.com/Darkshadow0001boss

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string solution(ll n)
{
	ll even = 0, odd = 0;
	for (ll i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i % 2 == 0)
			{
				even++;
			}
			if ((n / i) % 2 == 0)
			{
				if (n / i == i)
				{
					even--;
				}
				even++;
			}
			if ((n / i) % 2 != 0)
			{
				if (n / i == i)
				{
					odd--;
				}
				odd++;
			}
			if (i % 2 != 0)
			{
				odd++;
			}
		}
	}

	if (even > odd)
	{
		return "More Even Divisors";
	}
	else if (even < odd)
	{
		return "More Odd Divisors";
	}
	else
		return "Equal no. of even and odd divisors";
}

int main()
{
	ll n;
	cin >> n;
	string answer = solution(n);
	cout << answer << endl;
}
//Time complexity = O(sqrt(n))
