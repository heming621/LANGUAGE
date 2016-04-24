#include <iostream>
#include <cstring>
using namespace std;
void palindrome(char str[], int len);
int main()
{


    char str[]="abcdcba";
    cout<<strlen(str)<<endl;;
    palindrome(str,strlen(str));
    
    string str2;
    cin>>str2;

    return 0;
}
void palindrome(string &str, int len)
{
    string *strBeg = &str;
    string *strEnd = &(str+len-1);
}
void palindrome(char str[], int len)
{
    char *beg = str;
    char *end = str+len-1;
    while(beg!=end)
    {
	if((*beg)!=(*end))
	{
	    cout<<"This is not a palindrome!"<<endl;
	    break;
	}
	else
	{
	    beg++;
	    end--;
	}
    }
    cout<<"This is a palindrome!\n";
}




