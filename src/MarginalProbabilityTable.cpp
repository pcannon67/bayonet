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


#include <iostream>
#include "MarginalProbabilityTable.h"

namespace bayonet{

/**
* The constructor of the object.
*
* @param totVariables the total number of variable to insert in the table
* @param totStates the total number of states each variable must take
**/
MarginalProbabilityTable::MarginalProbabilityTable(unsigned int totVariables, unsigned int totStates){

 //Local variables
 std::vector<double> states_vector;
 states_vector.reserve(totStates);
 double probability = (double) 1 / (double) totStates;

 //Filling the states_vector
 for(unsigned int i_stat=0; i_stat<totStates; i_stat++){
  states_vector.push_back(probability);
 }

 //Filling the marginal table
 for(unsigned int i_var=0; i_var<totVariables; i_var++){
  marginalTable.push_back(states_vector);
  //std::cout << " --- " << std::endl;
 }
}

/**
* The constructor of the object.
*
* @param variablesTotStatesVector a vector of integers representing the total number of states
* for each variable.
**/
MarginalProbabilityTable::MarginalProbabilityTable(std::vector<unsigned int> variablesTotStatesVector){
 //Cyclyng through the input vector
 for(auto it=variablesTotStatesVector.begin(); it!=variablesTotStatesVector.end(); ++it){
   //Filling the states_vector
  std::vector<double> states_vector;
  states_vector.reserve(*it);
  double probability = (double) 1 / (double) *it;
  for(unsigned int i_stat=0; i_stat<*it; i_stat++){
   states_vector.push_back(probability); 
  }
  marginalTable.push_back(states_vector);
 }
}

MarginalProbabilityTable::~MarginalProbabilityTable(){};

/**
* It set the probabilities associated with a certain variable
*
* @param variableIndex the index of the variable
* @param stateIndex the index of the state
* @param probability the value to set
**/
bool MarginalProbabilityTable::SetProbability(unsigned int variableIndex, unsigned int stateIndex, double probability){
 if(variableIndex > marginalTable.size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return false; 
 }

 if(variableIndex > marginalTable[variableIndex].size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return false; 
 } 

 marginalTable[variableIndex][stateIndex] = probability;
 return true;
}

/**
* It get the probability associated with a certain variable and state
*
* @param variableIndex the index of the variable
* @param stateIndex the index of the state
**/
double MarginalProbabilityTable::GetProbability(unsigned int variableIndex, unsigned int stateIndex){
 if(variableIndex > marginalTable.size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return false; 
 }

 if(variableIndex > marginalTable[variableIndex].size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return false; 
 } 

 return marginalTable[variableIndex][stateIndex];
}


/**
* It set the probabilities associated with a certain variable 
*
* @param index the index of the variable
* @param probabilitiesVector the probabilities of the variable
**/
bool MarginalProbabilityTable::SetProbabilities(unsigned int index, std::vector<double> probabilitiesVector){
 if(index > marginalTable.size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return false; 
 }
 marginalTable[index] = probabilitiesVector;
 return true;
}

/**
* It get the probabilities associated with a certain variable
*
* @param index the index of the variable
**/
std::vector<double> MarginalProbabilityTable::GetProbabilities(unsigned int index){
 if(index > marginalTable.size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  std::vector<double> void_vector;
  void_vector.reserve(1);
  return void_vector; 
 }
 return marginalTable[index];
}

/**
* It prints the probabilities associated with each variable
*
**/
void MarginalProbabilityTable::Print(){
 unsigned int var_counter=0;
 for(auto it_var=marginalTable.begin(); it_var!=marginalTable.end(); ++it_var){
   std::cout << "===== VARIABLE: " << var_counter << " =====" << std::endl;
  unsigned int states_counter=0;
  for(auto it_state=it_var->begin(); it_state!=it_var->end(); ++it_state){
   std::cout << "STATE: " << states_counter << " ..... " << *it_state << std::endl;
   states_counter++;
  } 
 var_counter++;
 }
}


/**
* It prints the probabilities associated with each variable
*
**/
void MarginalProbabilityTable::PrintVariable(unsigned int index){
 if(index > marginalTable.size()){
  std::cerr << "ERROR: Marginal Table out of range index." << std::endl;
  return; 
 }
  std::cout << "===== VARIABLE: " << index << " =====" << std::endl;
  unsigned int states_counter=0;
  for(auto it_state=marginalTable[index].begin(); it_state!=marginalTable[index].end(); ++it_state){
   std::cout << "STATE: " << states_counter << " ..... " << *it_state << std::endl;
   states_counter++;
  } 
}





} //namespace


