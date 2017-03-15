#include "stdafx.h"
#include "CGraph.h"

using namespace std;

int main(int argc, char *argv[])
{	
	map<map<size_t, size_t>, string> graphsFormulas;
	map<map<size_t, size_t>, vector<string>> isomorphGraphs;
	for (int argumentIndex = 1; argumentIndex < argc ; ++argumentIndex)
	{
		ifstream strm(argv[argumentIndex]);
		CGraph graph(strm);
		auto cycles = graph.GetCyclesCounts();
		if (graphsFormulas.find(cycles) != graphsFormulas.end())
		{
			if (isomorphGraphs.find(cycles) != isomorphGraphs.end())
			{
				isomorphGraphs.at(cycles).push_back(argv[argumentIndex]);
			}
			else
			{
				isomorphGraphs.emplace(cycles, 
					vector<string>(
						{ graphsFormulas.at(cycles) ,argv[argumentIndex] }));
			}
		}
		graphsFormulas.emplace(cycles, argv[argumentIndex]);
		cout << "Graph " << argv[argumentIndex] << " formula: ";
		PrintMapToStream(cycles, cout);
		cout << endl;
	}

	cout << "Isomorph graphs " << endl;
	for (auto current : isomorphGraphs)
	{
		for (auto curr : current.second)
		{
			cout << curr << " ";
		}
		cout << endl;
	}
	
}
