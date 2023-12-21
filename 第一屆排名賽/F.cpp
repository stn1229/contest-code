#include <iostream>

using namespace std;

int main( void )
{
	int g , f , c , e , d , b , n , a ;
	
	long long int Fib[ 100 ];
	
	Fib[ 0 ] = 1;
	Fib[ 1 ] = 2;
	
	for( a = 2 ; a < 100 ; a ++)
	{
		Fib[ a ] = Fib[ a - 1 ] + Fib[ a - 2 ];	
	}
	//cout << Fib[ 97 ] << endl;
	long long int input;

	cin >> n;
	
	int ans[ 100 ];
	
	for( b = 0 ; b < n ; b ++ )
	{
		if( n > 500 )break;
		
		int judge = 0;
		
		e = 0;
		
		cin >> input;
	
		cout << input <<" = ";
	
		for( c = 0 ; c < 100 ; c ++ )
		{
			ans[c] = -1;
		}
		
		for( d = 90 ; d >= 0 ; d -- )
		{
			if( Fib[d] <= input )
			{
				judge= 1;
				input -= Fib[d];
				ans[e] = 1;
				
				e++;
			
			}else if(judge == 1 && input < Fib[d] )
			{
				ans[e] = 0;
	
				e++;
			}
		}
		
		for(int i = 0 ; i < 100 ; i ++ )
		{
			if( ans[i] != -1)cout << ans[i];
		}
		cout << " (fib)" << endl;
	}
	
	return 0;
}
