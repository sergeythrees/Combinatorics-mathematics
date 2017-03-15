#include "stdafx.h"
#include "CGraph.h"

using namespace std;

int main(int argc, char *argv[])
{
	string path1 = "M1.csv";
	string path2 = "M2.csv";
	if (IsValidArgumentsCount(argc, 3))
	{
		path1 = argv[1];
		path2 = argv[2];
	}
	ifstream input1(path1);
	ifstream input2(path2);
	CGraph graph1;
	CGraph graph2;

	graph1.FillFromStream(input1);
	graph2.FillFromStream(input2);

	auto cyclesCounts1 = graph1.GetCyclesCounts();
	auto cyclesCounts2 = graph2.GetCyclesCounts();

	cout << "Graphs have the following counts of cycles:" << endl;

	PrintMapToStream(cyclesCounts1, cout);
	PrintMapToStream(cyclesCounts2, cout);

	cout << "Graphs are " << ((cyclesCounts1 == cyclesCounts2) ? "isomorphic" : "not isomorphic")
		<< endl;
}

