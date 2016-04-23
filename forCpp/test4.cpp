#include <iostream>
int main()
{
    int val,valcur;
    int cnt=1;
    while(std::cin>>val)
    {
	while(std::cin>>valcur)
	{
	    if(val==valcur){
		cnt++;
	    }
	    else{
		std::cout<<val<<" appears "<<cnt<<" times"<<std::endl;
		cnt=1;
	    }
	    val = valcur;
	}
	std::cout<<valcur<<" appears "<<cnt<<" times"<<std::endl;
    }
    return 0;
}
