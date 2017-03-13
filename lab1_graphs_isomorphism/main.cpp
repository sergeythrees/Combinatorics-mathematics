#include "stdafx.h"
#include "CGraph.h"

using namespace std;

int main()
{
	ifstream input1("1.txt");
	ifstream input2("2.txt");
	CGraph graph1;
	CGraph graph2;

	graph1.FillFromStream(input1);
	graph2.FillFromStream(input2);

	auto cyclesCounts1 = graph1.GetCyclesCounts();
	auto cyclesCounts2 = graph2.GetCyclesCounts();

	cout << "Graphs have the following counts of cycles:" << endl;
	PrintVectorToStream(cyclesCounts1, cout);
	PrintVectorToStream(cyclesCounts2, cout);

	cout << "Graphs are " << ((cyclesCounts1 == cyclesCounts2) ? "isomorphic" : "not isomorphic")
		<< endl;
}

