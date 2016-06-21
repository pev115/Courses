#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Coursework in Python 
from IDAPICourseworkLibrary import *
from numpy import *
#
# Coursework 1 begins here
#
# Function to compute the prior distribution of the variable root from the data set
def Prior(theData, root, noStates):
    prior = zeros((noStates[root]), float )
# Coursework 1 task 1 should be inserted here
    
#Calculate the prior distribution : for each state of the variable
#find the number of occurances of this state in the data points and 
#divide by the total number of data points
    for i in range(noStates[root]) :
      prior[i] = list(theData[:,root]).count(i)/float(theData.shape[0])
    
# end of Coursework 1 task 1
    return prior
  
  
  
# Function to compute a CPT with parent node varP and xchild node varC from the data array
# it is assumed that the states are designated by consecutive integers starting with 0
def CPT(theData, varC, varP, noStates):
  cPT = zeros((noStates[varC], noStates[varP]), float )
# Coursework 1 task 2 should be inserte4d here
 
#for each of the states of the parent and the child variables find P(VarC|VarP) = N_candp/N_p 
#where N_x is the number of datapoints with state x 
  for i in range(noStates[varP]) :
     for j in range(noStates[varC]):
       #Find the number of occurences of state i of varP
	N_p = list(theData[:, varP]).count(i)
	# find the number of occurences of both states i and j of varP and varC
	N_candp = list(theData[theData[:,varP]==i][:,varC]).count(j)
	#divide to get the conditional probability
	#If N_p is 0 ie there is no occurence of value i in the data, this will give nan (division by 0)
	#we will allow this in order to reflect this insufficient data state.
	#Note that the bigger the dataset the lower the probability of this occuring
	cPT[j,i] = float(N_candp)/float(N_p)  
   
# end of coursework 1 task 2
  return cPT
  
  
  
# Function to calculate the joint probability table of two variables in the data set
def JPT(theData, varRow, varCol, noStates):
    jPT = zeros((noStates[varRow], noStates[varCol]), float )
#Coursework 1 task 3 should be inserted here 

#find the number of datapoints by looking at the number of rows
    dtpts = float(theData.shape[0])
#for each of the states of the two variables we want to have the JPT
    for i in range(noStates[varCol]):
      for j in range(noStates[varRow]):
	#find the number of datapoints having both those states
	#list all the datapoints in column varRow that are in a row where 
	#varCol = i and count the number of occurances of j
	N_rowandcol = list(theData[theData[:,varCol]==i][:,varRow]).count(j)
	#find the joint probability P(varRow & varCol) = N_rowandcol/dtpts
	jPT[j,i] = float(N_rowandcol)/float(dtpts)
    
# end of coursework 1 task 3
    return jPT
  
  
  
  
  
#
# Function to convert a joint probability table to a conditional probability table
def JPT2CPT(aJPT):
#Coursework 1 task 4 should be inserted here 

  for j in range( aJPT.shape[1]):
    #sum the values in the colum : eliminate the corresponding variable
    p_b = sum(aJPT[:,j])
    for i in range( aJPT.shape[0]):
    # Get the conditional probability : P(A|B) = P(A&B)/P(B) . If P(B) is in this case
    #we get nan, we will allow this as it reflects the fact that we have a data set that is
    #too small
	aJPT[i,j] =  aJPT[i,j]/float(p_b)     
	   
   
# coursework 1 taks 4 ends here
    return aJPT

#
# Function to query a naive Bayesian network
def Query(theQuery, naiveBayes): 
  rootPdf = zeros((naiveBayes[0].shape[0]), float)
# Coursework 1 task 5 should be inserted here

  for i in range(rootPdf.shape[0]): #for each of the states of the root
    #initialise the likelyhood information to 1
    likelyhood_info = float(1.0)
    for j in range(len(naiveBayes)-1): # for each of the CPT's
      #Calculate the likelyhood: the product of the conditional probabilities 
      likelyhood_info = likelyhood_info* float(naiveBayes[j+1][theQuery[j],i])
    #update the root probabilty for each state : P(R) = Prior*likelyhood_info
    rootPdf[i] = float(naiveBayes[0][i])*likelyhood_info
  
#Normalise 
  Sum =float(sum(rootPdf))
#if the sum is 0, return the distribution (no state of the root can occure)
  if Sum == 0 :
     return rootPdf

#if sum != 0 divide each element by the  sum to normalise the distribution and return   
  for k in range(len(rootPdf)):
    rootPdf[k] = rootPdf[k]/Sum
   
# end of coursework 1 task 5
  return rootPdf
  
  
#
# End of Coursework 1
#





#
# Coursework 2 begins here
#

from math import *

# Calculate the mutual information from the joint probability table of two variables
def MutualInformation(jP):
  mi=0.0
# Coursework 2 task 1 should be inserted here
#Calculate the mutual information : Dep(A,B) = S_AxB P(ai&bj)*log_2((Pai&bj)/(P(ai)P(bj)))
#here P(ai) = p_row , P(bj) = p_col , P(ai&bj) = jP[i,j]. We get:
  for j in range(jP.shape[1]):
    for i in range(jP.shape[0]):
      p_col= sum(jP[:,j]) 
      p_row= sum(jP[i])
      if (jP[i,j] == 0 or (p_col*p_row) == 0):
	mi += 0.0
      else:
	mi +=  jP[i,j]*log((jP[i,j]/(p_col*p_row)),2)
# end of coursework 2 task 1	
  return mi
  
  
  
  

 

# construct a dependency matrix for all the variables
def DependencyMatrix(theData, noVariables, noStates):
  MIMatrix = zeros((noVariables,noVariables))
# Coursework 2 task 2 should be inserted here
#Each element of the dependencyMatrix is the Mutual Information for the
#a possible combination of the vartiables in the data
  for j in range(noVariables):
      for i in range(noVariables):
	if(i==j) :
	    MIMatrix[i,j] = 0.0
	else:
	  #calculate the joint probability table
	  jpt= JPT(theData, i, j, noStates)
	  #extract the mutual information from the joint probabilities
	  MIMatrix[i,j]= MutualInformation(jpt)

# end of coursework 2 task 2
  return MIMatrix




 
def DependencyList(depMatrix):
  depList=[]
# Coursework 2 task 3 should be inserted here
#extract the depedency list from the mutual information matrix: Only consider
#the upper half of the dependency matrix because as it is symmetric
  for i in range(depMatrix.shape[0]):
    for j in range(i,depMatrix.shape[1]):
      depList.append([depMatrix[i,j],i,j])
  #sort the dependency list in order of depedencies
  depList.sort(key = lambda value:value [0], reverse=True)

# end of coursework 2 task 3
  return array(depList)  
  
  
  

# Functions implementing the spanning tree algorithm
# Coursework 2 task 4

#function that checks whether there is a loop that is formed by adding the 
#doublet to the spanningTree. If it does, returns true, else false
def makeLoop(doublet, spanningTree):
  #make a copy of the spanningTree not to modify its values by the test
  tree_copy = list(spanningTree)
  #extract the two values of the doublet
  start_value = doublet[0]
  end_value = doublet[1]
  #check recursively for a loop
  return recursiveLoopSearch(start_value, end_value, tree_copy)
      
#function that recursively looks for a loop
def recursiveLoopSearch(start_value,end_value,tree_copy):
  #if a loop is found, return TRUE
  if(start_value == end_value ):
    return True

  for i in tree_copy:
    #if the start value is found in the spannigTree, set its connected pair
    #to the new start value
    if (i[0]== start_value or i[1] == start_value):
      if(i[0] == start_value):
	new_start_value = i[1]
      else:
	new_start_value = i[0]
    #make a copy of the tree and delete the doublet found
      new_tree_copy = list (tree_copy)
      new_tree_copy.remove([i[0],i[1]])
      #call the function recursively, and if a loop is found cascade the true
      #result
      if(recursiveLoopSearch(new_start_value,end_value, new_tree_copy)==True):
	return True
  #if no loop is found at the end of the recursion, propagate the false result
  return False

#Function that returns the spanning tree of the variables in the dataset,
#given the dependency list
def SpanningTreeAlgorithm(depList, noVariables):
  spanningTree =[]
  #delete the first column of the dependency list (as they are already ordered)
  newlist= delete(depList, 0,1).tolist()

  #for each element down the dependency list, try to establish a connection
  #only establish the connection if it does not result in a loop
  for element in newlist:
    if (makeLoop(element, spanningTree)==False):
      spanningTree.append(element)

  return array(spanningTree)


#
# End of coursework 2
#
  
  


#
# Coursework 3 begins here
#
# Function to compute a CPT with multiple parents from he data set
# it is assumed that the states are designated by consecutive integers starting with 0
def CPT_2(theData, child, parent1, parent2, noStates):
    cPT = zeros([noStates[child],noStates[parent1],noStates[parent2]], float )
# Coursework 3 task 1 should be inserted here
   

# End of Coursework 3 task 1           
    return cPT
#
# Definition of a Bayesian Network
def ExampleBayesianNetwork(theData, noStates):
    arcList = [[0],[1],[2,0],[3,2,1],[4,3],[5,3]]
    cpt0 = Prior(theData, 0, noStates)
    cpt1 = Prior(theData, 1, noStates)
    cpt2 = CPT(theData, 2, 0, noStates)
    cpt3 = CPT_2(theData, 3, 2, 1, noStates)
    cpt4 = CPT(theData, 4, 3, noStates)
    cpt5 = CPT(theData, 5, 3, noStates)
    cptList = [cpt0, cpt1, cpt2, cpt3, cpt4, cpt5]
    return arcList, cptList
# Coursework 3 task 2 begins here

# end of coursework 3 task 2
#
# Function to calculate the MDL size of a Bayesian Network
def MDLSize(arcList, cptList, noDataPoints, noStates):
    mdlSize = 0.0
# Coursework 3 task 3 begins here


# Coursework 3 task 3 ends here 
    return mdlSize 
#
# Function to calculate the joint probability of a single data point in a Network
def JointProbability(dataPoint, arcList, cptList):
    jP = 1.0
# Coursework 3 task 4 begins here


# Coursework 3 task 4 ends here 
    return jP
#
# Function to calculate the MDLAccuracy from a data set
def MDLAccuracy(theData, arcList, cptList):
    mdlAccuracy=0
# Coursework 3 task 5 begins here


# Coursework 3 task 5 ends here 
    return mdlAccuracy
#
# End of coursework 2
#
# Coursework 3 begins here
#
def Mean(theData):
    realData = theData.astype(float)
    noVariables=theData.shape[1] 
    mean = []
    # Coursework 4 task 1 begins here



    # Coursework 4 task 1 ends here
    return array(mean)


def Covariance(theData):
    realData = theData.astype(float)
    noVariables=theData.shape[1] 
    covar = zeros((noVariables, noVariables), float)
    # Coursework 4 task 2 begins here


    # Coursework 4 task 2 ends here
    return covar
def CreateEigenfaceFiles(theBasis):
    adummystatement = 0 #delete this when you do the coursework
    # Coursework 4 task 3 begins here

    # Coursework 4 task 3 ends here

def ProjectFace(theBasis, theMean, theFaceImage):
    magnitudes = []
    # Coursework 4 task 4 begins here

    # Coursework 4 task 4 ends here
    return array(magnitudes)

def CreatePartialReconstructions(aBasis, aMean, componentMags):
    adummystatement = 0  #delete this when you do the coursework
    # Coursework 4 task 5 begins here

    # Coursework 4 task 5 ends here

def PrincipalComponents(theData):
    orthoPhi = []
    # Coursework 4 task 3 begins here
    # The first part is almost identical to the above Covariance function, but because the
    # data has so many variables you need to use the Kohonen Lowe method described in lecture 15
    # The output should be a list of the principal components normalised and sorted in descending 
    # order of their eignevalues magnitudes

    
    # Coursework 4 task 6 ends here
    return array(orthoPhi)

#
# main program part for Coursework 1
#
noVariables, noRoots, noStates, noDataPoints, datain = ReadFile("Neurones.txt")
theData = array(datain)
AppendString("results.txt","Coursework One Results by Pierre Eugene Valassakis (pev115, 00644379)")
AppendString("results.txt","") #blank line
AppendString("results.txt","The prior probability of node 0")
prior = Prior(theData, 0, noStates)
AppendList("results.txt", prior)
#
# continue as described
#
#

#Question 1.2
#Calculate  P(2|0) and display it on the results file
AppendString("results.txt","The conditional probability matrix P(2|0) calculated from the data")
cpt = CPT(theData, 2,0,noStates)
AppendArray("results.txt", cpt)

#Question 1.3
#Calculate the joint probability matrix P(2&0) and display it on the results file
AppendString("results.txt", " The joint  probability matrix P(2&0) calculated from the data")
jpt = JPT(theData,2,0,noStates)
AppendArray("results.txt", jpt)

#Question 1.4
#Calculate the conditional probability matrix P(2|0) from P(2&0) and display it on the results file
AppendString("results.txt", " The conditional probability matrix P(2|0) calculated from the joint probability matrix P(2&0)")
jpt2cpt = JPT2CPT(jpt)
AppendArray("results.txt", jpt2cpt)

#Question 1.5

#Calculate the conditional probability tables for the different variables
cpt1= CPT(theData, 1,0, noStates)
cpt2= CPT(theData, 2,0, noStates)
cpt3 = CPT(theData, 3,0, noStates)
cpt4 = CPT(theData, 4,0, noStates)
cpt5 = CPT(theData, 5,0, noStates)

#Query the network with the queries [4,0,0,0,5] and [6,5,2,5,5] and display the results in the results file

AppendString("results.txt", "The results of queries [4,0,0,0,5] and [6,5,2,5,5] on the naive network")
AppendString("results.txt", "For query [4,0,0,0,5] :")
queryresult1 = Query([4,0,0,0,5],[prior, cpt1,cpt2,cpt3,cpt4,cpt5] )
AppendList("results.txt",queryresult1)

AppendString("results.txt", "For query [6,5,2,5,5] :")
queryresult2 = Query([6,5,2,5,5],[prior, cpt1,cpt2,cpt3,cpt4,cpt5] )
AppendList("results.txt",queryresult2)








 
#
# main program part for Coursework 2
#
noVariables, noRoots, noStates, noDataPoints, datain = ReadFile("HepatitisC.txt")
theData = array(datain)
AppendString("IDAPIResults02.txt","") #blank line
AppendString("IDAPIResults02.txt","Coursework Two results by Pierre Eugene Valassakis (pev115, 00644379)")
AppendString("IDAPIResults02.txt","") #blank line


AppendString("IDAPIResults02.txt","2. The dependency matrix for the HepatitisC data is:")
miMatrix = DependencyMatrix(theData, noVariables, noStates)
AppendArray("IDAPIResults02.txt", miMatrix)

AppendString("IDAPIResults02.txt","3. The dependency list for the HepatitisC data set is:")
deplist = DependencyList(miMatrix)
AppendArray("IDAPIResults02.txt",deplist)


AppendString("IDAPIResults02.txt","4. The spanning tree for the HepatitisC data set is (from 2.4):")
tree = SpanningTreeAlgorithm(deplist, noVariables)
AppendArray("IDAPIResults02.txt",tree)
















