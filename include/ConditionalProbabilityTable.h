/* 
 * bayonet - C++ Bayesian networks library
 * Copyright (C) 2015  Massimiliano Patacchiola
 * Author: Massimiliano Patacchiola
 * email:  
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
*/

#include <initializer_list>
#include <map>
#include<vector>

namespace bayonet{

class ConditionalProbabilityTable {

 public:
  ConditionalProbabilityTable(unsigned int NodeStatesNumber, std::vector<unsigned int> parentsStatesList);
  ~ConditionalProbabilityTable();

  std::vector<double> GetProbabilities(std::vector<unsigned int> parentsStates);
  bool SetProbabilities(std::vector<unsigned int> parentsStates, std::vector<double> probabilities);
  void Print();
  void PrintProbabilities(std::vector<unsigned int> parentsStates);


 private:
  unsigned int totalRows;
  unsigned int totalColumns;
  std::map<std::vector<unsigned int>,std::vector<double>> conditionalMap;


};

}
