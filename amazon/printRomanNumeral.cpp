/*Rules:
"M" = 1000	"D" = 500	"C" = 100	"L" = 50	"X" = 10	"V" = 5		"I" = 1
To find the value of a set of roman numerals you add up the value of the characters.A power of ten can only be
repeated three times i.e., XXX = 30, XXXX is not valid.Those that are not powers of ten can only appear once,
i.e. VV is not valid.The numbers must read highest-lowest from the left to the right.If a letter of a smaller value
appears before a number of a higher value, then the smaller number is to be subtracted from the higher value.
ex: IX = 9.You can subtract only powers of ten i.e., I, X, C Only one character can be used to subtract from a larger
character. eg IIX = 8 is not allowed.You can't subtract a number from one that is more than 10 times greater.
That is, you can only subtract I from V or X, X from L or C, etc.For e.g., IC can not be used for 99. It must be XCIX.
*/

//343 CCCXLIII
//34  XXXIV
//567 DLXVII
//678 DCLXXVIII

#include<iostream>
#include<vector>
using namespace std;

string printRomanNumeral(int n) {

vector<int> digits;
int num=n;
while(num!=0)
{
	digits.push_back(num%10);
	num/=10;
}
/*for(int i=0,j=digits.size()-1; i<=digits.size()/2 ; ++i,--j)
{
	int t=digits[i];
	digits[i]=digits[j];
	digits[j]=t;
}*/
string result,strdig[10];
for(int i=0;i<digits.size();++i)
{
		switch(digits[i])
		{
			case 1:
				switch(i)
				{
					case 0:
						strdig[i]+="I";
					break;
					case 1:
						strdig[i]+="X";
					break;
					case 2:
						strdig[i]+="C";
					break;
					case 3:
						strdig[i]+="M";
					break;

				}
			break;
			case 2:
				switch(i)
				{
						case 0:
							strdig[i]+="II";
						break;
						case 1:
							strdig[i]+="XX";
						break;
						case 2:
							strdig[i]+="CC";
						break;
						case 3:
							strdig[i]+="MM";
						break;

				}
			break;
			case 3:
					switch(i)
					{
						case 0:
							strdig[i]+="III";
						break;
						case 1:
							strdig[i]+="XXX";
						break;
						case 2:
							strdig[i]+="CCC";
						break;
						case 3:
							strdig[i]+="MMM";
						break;

					}
			break;
			case 4:
					switch(i)
					{
						case 0:
							strdig[i]+="IV";
						break;
						case 1:
							strdig[i]+="XL";
						break;
						case 2:
							strdig[i]+="CD";
						break;
						case 3:
							strdig[i]+="MMMM";
						break;

					}
			break;
			case 5:
					switch(i)
					{
						case 0:
							strdig[i]+="V";
						break;
						case 1:
							strdig[i]+="L";
						break;
						case 2:
							strdig[i]+="D";
						break;
						case 3:
							strdig[i]+="*";
						break;

					}
			break;
			case 6:
					switch(i)
					{
						case 0:
							strdig[i]+="VI";
						break;
						case 1:
							strdig[i]+="LX";
						break;
						case 2:
							strdig[i]+="DC";
						break;
						case 3:
							strdig[i]+="*";
						break;

					}
			break;
			case 7:
					switch(i)
					{
						case 0:
							strdig[i]+="VII";
						break;
						case 1:
							strdig[i]+="LXX";
						break;
						case 2:
							strdig[i]+="DCC";
						break;
						case 3:
							strdig[i]+="8";
						break;

					}
			break;
			case 8:
					switch(i)
				{
						case 0:
							strdig[i]+="VIII";
						break;
						case 1:
							strdig[i]+="LXXX";
						break;
						case 2:
							strdig[i]+="DCCC";
						break;
						case 3:
							strdig[i]+="8";
						break;

				}
			break;
			case 9:
					switch(i)
				{
						case 0:
							strdig[i]+="IX";
						break;
						case 1:
							strdig[i]+="XC";
						break;
						case 2:
							strdig[i]+="CM";
						break;
						case 3:
							strdig[i]+="*";
						break;

				}
			break;
		}
}
for(int i=9;i>=0;i--)
	result+=strdig[i];
return result;
}

int main()
{
	int n;
	cout<<"Enter Decimal no (1-4999):";
	cin>>n;
cout<<printRomanNumeral(n);
	return 0;
}