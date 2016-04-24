/*
 * link:http://blog.csdn.net/littlexidong/article/details/9147855
 * */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <stdio.h>
using namespace std;

const int kMinSupport = 2;
map<list<string>, int> FreqPattern;
struct TreeNode;
struct TreeNode
{
        int count;
        string tag;
        map<string, TreeNode*> children;
        TreeNode* parent;
        TreeNode* Sibling;
        //5 members need to be initialized.
	TreeNode(string tag, TreeNode* parent, int count=1):tag(tag),parent(parent),count(count)
        {
	    Sibling = NULL;
	    children.clear();
	}

	bool IsRoot()
	{
	    return (parent==NULL);
	}

	void dump(int k)
	{
	    for(int i=0; i<k; i++)
	    {
		printf("------------");
	    }
	    if(IsRoot())
		printf("\nRoot\n");
	    else
		printf("%s:%d",tag.c_str(),count);
	    map<string, TreeNode*>::iterator it;
	    for(it = children.begin(); it!=children.end(); it++)
	    {
		printf("|");
		it->second->dump(k+1);
	    }
	}
};

void GenConditionalTree(map<vector<string>, int> &task,
	map<string, TreeNode*> &head, 
	TreeNode &root,
	map<string, int> &FreqTable,
	vector<string> &rank,
	bool prune);


map<string, int> *gFreqTable = NULL;
bool Compare(string a, string b)
{
    int aw = (*gFreqTable)[a];
    int bw = (*gFreqTable)[b];
    return (aw>bw);
}


void GenPermutation(vector<string> &prefix_set, int start, list<string> &result, int freq, int suffix_len)
{
    if(start==prefix_set.size()-1)
    {
	result.push_back(prefix_set[start]);
	if(result.size()<=suffix_len)
	    return;
	
	list<string>::iterator it;
	printf("{");
	for(it=result.begin(); it!=result.end(); it++)
	    printf("%s ",it->c_str());
	printf("}#%d \n",freq);

	result.pop_back();
	if(result.size()>suffix_len)
	{
	    printf("{");
	    int i;
	    for(i=0, it=result.begin(); it!=result.end(); i++,it++)
	    {
		printf("%s",it->c_str());
		if(i!=result.size()-1)
		    printf(",");
	    }
	    printf("}#%d\n",freq);
	}
        return;
    }

    result.push_back(prefix_set[start]);
    GenPermutation(prefix_set, start+1, result, freq, suffix_len);
    result.pop_back();
    GenPermutation(prefix_set, start+1, result, freq, suffix_len);
}

void FpGrowth(TreeNode &main, string &tag, int tag_freq, map<string, TreeNode*> &head, list<string>& suffix)
{
    map<vector<string>,int> sub_task;
    TreeNode* n = head[tag];
    vector<string> prefix_path;
    do
    {
	TreeNode* leaf = n;
	prefix_path.clear();
	int count = leaf->count;
	
	while((leaf=leaf->parent)!=NULL)
	{
	    if(leaf->IsRoot())
		break;
	    prefix_path.push_back(leaf->tag);
	}
	if(prefix_path.size()>0)
	    sub_task[prefix_path] = count;
    }while((n=n->Sibling)!=NULL);
}




int main()
{
    return 0;
}
