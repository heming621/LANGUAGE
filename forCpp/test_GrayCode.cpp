#include <iostream>
#include <vector>
using namespace std;
class GrayCode
{
    public:
	vector<int> getGray(int n)
	{
	    vector<int> vi;
	    for(int i = 0; i < n; i++)
		vi.push_back(i^(i>>1));
	    
	    return vi;
	}
	
};
int main()
{
    GrayCode gc = new GrayCode();
    vector<int> vi;
    vi = gc.getGray(4);
    for(int i = 0; i < vi.size(); i++)
	cout<<vi[i]<<"\t";
    cout<<endl;
    return 0;
}
