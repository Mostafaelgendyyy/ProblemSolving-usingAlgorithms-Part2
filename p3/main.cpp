#include <iostream>
using namespace std;
class Edge {
	int u, v, weight;
public:
    int getU() const {
        return u;
    }

    void setU(int u) {
        Edge::u = u;
    }

    int getV() const {
        return v;
    }

    void setV(int v) {
        Edge::v = v;
    }

    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        Edge::weight = weight;
    }
};

class SubTree
{
    int parent;
    int Rnk;
public:
    int getParent() const {
        return parent;
    }

    void setParent(int parent) {
        SubTree::parent = parent;
    }

    int getRnk() const {
        return Rnk;
    }

    void setRnk(int Rnk) {
        SubTree::Rnk = Rnk;
    }
};

int CompareWeight(const void* a, const void* b)
{
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    if(a1->getWeight() > b1->getWeight())
        return true;
    return false;
}

int SearchMST(SubTree sub_trees[], int i)
{
    if (sub_trees[i].getParent() != i)
    {
        sub_trees[i].setParent(SearchMST(sub_trees, sub_trees[i].getParent()));
    }
    return sub_trees[i].getParent();
}
void Compine2Subtrees(SubTree sub_trees[], int x, int y)
{
    int xroot = SearchMST(sub_trees, x);
    int yroot = SearchMST(sub_trees, y);

    if (sub_trees[xroot].getRnk() < sub_trees[yroot].getRnk())
    {
        sub_trees[xroot].setParent(yroot);
    }
    else if(sub_trees[xroot].getRnk() == sub_trees[yroot].getRnk())
    {
        sub_trees[yroot].setParent(xroot);
        sub_trees[xroot].setRnk(sub_trees[xroot].getRnk() + 1);
    }
    else
    {
        sub_trees[yroot].setParent(xroot);
    }
}

int main()
{
	int NumVertices, NumEdges;
	cin >> NumVertices >> NumEdges;
    Edge* edge =new Edge[NumEdges];

	for (int i = 0; i < NumEdges; ++i)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		edge[i].setU(u);
		edge[i].setV(v);
		edge[i].setWeight(weight);
	}

    qsort(edge, NumEdges, sizeof(edge[0]), CompareWeight);

	Edge MST [NumVertices - 1];
	int MST_size = 0;

	SubTree *Sub = new SubTree[NumVertices];
    for (int v = 0; v < NumVertices; ++v)
    {
        Sub[v].setParent(v);
        Sub[v].setRnk(0);
    }

    for(int i = 0; i < NumEdges; i++)
    {
    	Edge min_Edge = edge[i];
    	int x = SearchMST(Sub, min_Edge.getU() - 1);
    	int y = SearchMST(Sub, min_Edge.getV() - 1);
    	if (x != y)
    	{
    	    MST[MST_size] = min_Edge;
            Compine2Subtrees(Sub, x, y);
    	}
        MST_size++;
    	if(MST_size == NumVertices - 1)
    	{
    		break;
    	}
    }
    int TWeightofMST = 0;
    for(int i = 0; i < NumVertices - 1; i++)
    {
        TWeightofMST += MST[i].getWeight();
    }
    cout << endl;
    cout << TWeightofMST;
    return 0;
}