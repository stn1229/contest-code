#include <iostream>


using namespace std;

int gcd( long long int a , long long int b )
{
	while( a = a % b )
	{
		swap( a , b );
	}
	
	return b;
}

int main( void )
{
	long long int a , b  , input;
	
	while( cin >> input )
	{
		long long int ans = 0;
		
		if( input == 0 )
		{
			break;
		}
		
		for( a = 1 ; a < input ; a ++ )
		{
			for( b = a + 1 ; b <= input ; b ++ )
			{
				ans += gcd( a , b );
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
