#include "stdafx.h"
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

struct Point
{
	Point(int xCoord, int yCoord)
		: x(xCoord), y(yCoord) {}
	int x = 0;
	int y = 0;
};

enum class Direction
{
	left, right, up, down
};
map<Direction, Point> DirValues
{
	{ Direction::left,{ -1, 0 } },
	{ Direction::right,{ 1, 0 } },
	{ Direction::up,{ 0, -1 } },
	{ Direction::down,{ 0, 1 } }
};

Point GetZeroCoord(const vector<int> &matrix, unsigned matrixSize);
int GetZeroPos(const vector<int> &matrix);
int MatrixToInt(const vector<int> &matrix);
void GenerateNextMove(stack<vector<int>> &searchStack, set<int> &usedPermutations, unsigned matrixSize);



int main()
{
		vector<int> matrix{ 8,7,6,5,4,3,2,1,0};
		unsigned matrixSize = sqrt<int>(matrix.size());

		set<int> usedPermutations;
		stack<vector<int>> searchStack;
		searchStack.push(matrix);

		

		while (!searchStack.empty())
			GenerateNextMove(searchStack, usedPermutations, matrixSize);

		cout << usedPermutations.size() << endl;

	return 0;
}

void GenerateNextMove(stack<vector<int>> &searchStack, set<int> &usedPermutations, unsigned matrixSize)
{
	vector<int> currentMatrix = searchStack.top();
	usedPermutations.insert(MatrixToInt(currentMatrix));
	searchStack.pop();

	vector<Direction> actions;
	auto zero = GetZeroCoord(currentMatrix, matrixSize);

	if (zero.x > 0)
		actions.push_back(Direction::left);
	if (zero.x < matrixSize - 1)
		actions.push_back(Direction::right);
	if (zero.y > 0)
		actions.push_back(Direction::up);
	if (zero.y < matrixSize - 1)
		actions.push_back(Direction::down);

	for (auto act : actions)
	{
		vector<int> matrix(currentMatrix);
		int newZero = zero.x + DirValues.at(act).x + (zero.y + DirValues.at(act).y) * matrixSize;
		swap(matrix[GetZeroPos(matrix)], matrix[newZero]);

		if (usedPermutations.find(MatrixToInt(matrix)) == usedPermutations.end())
			searchStack.push(matrix);
	}
}

int MatrixToInt(const vector<int> &matrix)
{
	int result = 0;

	for (size_t i = 0; i < matrix.size(); i++)
		result = result * 10 + matrix[i];

	return result;
}

Point GetZeroCoord(const vector<int> &matrix, unsigned matrixSize)
{
	unsigned zeroPos = GetZeroPos(matrix);
	return Point((zeroPos % matrixSize) % matrixSize, zeroPos / matrixSize);
}

int GetZeroPos(const vector<int> &matrix)
{
	unsigned zeroPos = 0;
	while (zeroPos < matrix.size() && matrix[zeroPos] != 0)
		++zeroPos;
	return zeroPos;
}