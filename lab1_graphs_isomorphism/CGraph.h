#pragma once
#include "stdafx.h"
#include "ReadWriteFunctions.h"

class CGraph
{
public:

	void FillFromStream(std::istream& strm)
	{
		std::string line;
		std::getline(strm, line);
		size_t matrixSize = line.length();

		m_matrix.assign(matrixSize, std::vector<bool>());
		for (size_t i = 0; i < matrixSize; ++i)
		{
			FillBoolVectorFromLine(line, m_matrix[i], '1', '0');
			std::getline(strm, line);
		}
	}

	std::map<size_t, size_t>  GetCyclesCounts()
	{
		std::vector<size_t> cycle;
		std::map<size_t, size_t>  cyclesCounts;

		size_t cycleBegin = SIZE_MAX;
		for (size_t row = 0; row < m_matrix.size(); ++row)
		{
			FindCycle(m_matrix, row, cycle, cyclesCounts, cycleBegin);
		}

		return cyclesCounts;
	}

private:
	std::vector<std::vector<bool>> m_matrix;

	void FindCycle(std::vector<std::vector<bool>> & matrix,
		size_t row, std::vector<size_t> & cycle,
		std::map<size_t, size_t> & cyclesCounts, size_t & cycleBegin)
	{
		for (size_t column = 0; column < matrix[row].size(); ++column)
		{
			if (matrix[row][column])
			{
				if (cycleBegin == SIZE_MAX)
				{
					cycleBegin = row;
				}
				cycle.push_back(row);
				matrix[row][column] = false;
				if (column == cycleBegin)
				{
					cycleBegin = SIZE_MAX;
					if (cyclesCounts.find(cycle.size()) == cyclesCounts.end())
					{
						cyclesCounts.emplace(cycle.size(), 1);
					}
					else
					{
						++(cyclesCounts.at(cycle.size()));
					}
					cycle = std::vector<size_t>();
					break;
				}
				FindCycle(matrix, column, cycle, cyclesCounts, cycleBegin);
				break;
			}
		}
	}
};
