#include <iostream>

using namespace std;

void _count( long long int );

int main( void )
{
	long long int input;
	
	while( cin >> input )
	{
		if( input < 1 || input > 2147483647 )break;
		if( input == 0 )break;
		
		_count( input );
	}
	
	return 0;
}

void _count( long long int input )
{
	int c , b , ans = 0 , a = 0;
	
	int abc[100];
	
	for( b = 0 ; b < 100 ; b ++ )
	{
		abc[b] = - 1;
	}
	
	while( 1 )
	{
		if( input % 2 == 0 )
		{
			input /= 2;
			
			abc[ a ] = 0;
		}
		
		else
		{
			ans ++;
			
			input /= 2;
			
			abc[ a ] = 1;
		}
		
		a ++;
		
		if( input == 0 )break;
	}
	
	cout << "The parity of ";
	
	for( c = 99 ; c >= 0 ; c -- )
	{
		if( abc[ c ] != - 1 )
		{
			cout << abc[ c ];
		}
	}
	
	cout << " is " << ans << " (mod 2)." << endl;
	
}
